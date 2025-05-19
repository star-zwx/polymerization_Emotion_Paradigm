#include "videoMainpage.h"
#include <QDateTime>
#include <QLabel>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>
#include <QFileDialog>
#include <iostream>

// 构造函数
VideoMainPage::VideoMainPage(const QString &filenameJson ,QWidget *parent)
    : QMainWindow(parent), currentTrial(0), totalTrials(0), isFullScreen(false)  // 初始化当前试次为0，总试次为0，并添加全屏标志
{
    stack = new QStackedWidget(this);  // 创建一个堆栈窗口部件

    // 创建各个页面
    instruction = new VideoIntrtionPage(this);
    fixation = new VideoFixationPage(this);
    video = new Videoplayer(this);
    rating = new VideoRatingPage(this);
    rest = new RestPage(this);

    // 将页面添加到堆栈窗口部件中
    stack->addWidget(instruction);
    stack->addWidget(fixation);
    stack->addWidget(video);
    stack->addWidget(rating);
    stack->addWidget(rest);

    setCentralWidget(stack);  // 设置堆栈窗口部件为中央窗口部件
    resize(800, 600);  // 调整窗口大小

    // 信号与槽连接
    connect(instruction, &VideoIntrtionPage::instructionDone, this, &VideoMainPage::toFixation);  // 说明页完成后切换到凝视页
    connect(fixation, &VideoFixationPage::fixationFinished, this, &VideoMainPage::toVideo);  // 凝视页完成后切换到视频页
    connect(video, &Videoplayer::videoFinished, this, &VideoMainPage::toRating);  // 视频页完成后切换到评分页
    connect(rating, &VideoRatingPage::ratingFinished, this, &VideoMainPage::saveRating);  // 评分页完成后保存评分
    connect(rest, &RestPage::restFinished, this, &VideoMainPage::toNextTrial);  // 休息页完成后切换到下一个试次



    //打开json文件读取刺激材料信息
    QFileInfo fileInfo(filenameJson);

    // 获取路径部分（不包括文件名）
    QString pathWithoutFile = fileInfo.path();

    qDebug() << "视频路径"<<pathWithoutFile;
    QFile jsonFile(filenameJson);  // 创建文件对象

            if (jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)) {  // 以只读模式打开文件
                QByteArray jsonData = jsonFile.readAll();  // 读取文件内容
                QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);  // 解析JSON数据
                if (jsonDoc.isObject()) {  // 如果是JSON对象
                    QJsonObject jsonObj = jsonDoc.object();  // 获取JSON对象
                    if (jsonObj.contains("videos") && jsonObj["videos"].isArray()) {  // 如果包含视频数组
                        QJsonArray videosArray = jsonObj["videos"].toArray();  // 获取视频数组
                        totalTrials = videosArray.size();  // 设置总试次数
                        for (const QJsonValue &videoValue : videosArray) {  // 遍历视频数组
                            if (videoValue.isObject()) {  // 如果是JSON对象
                                QJsonObject videoObj = videoValue.toObject();  // 获取视频对象
                                QString videoPath = pathWithoutFile+'/'+videoObj["path"].toString();  // 获取视频路径
                                qDebug() << "file"<<videoPath;
                                QString videoLabel = videoObj["label"].toString();  // 获取视频标签
                                videoPaths.append(videoPath);  // 添加到视频路径列表
                                videoLabels.append(videoLabel);  // 添加到视频标签列表
                            }
                        }
                    }
                    //这里写解析串口和marker的代码

                                    if (jsonObj.contains("MarkerInfo") &&  jsonObj["MarkerInfo"].isArray()){
                                        //获取事件串口的配置信息
                                        QJsonArray markerCom = jsonObj["MarkerInfo"].toArray();
                                        for (const QJsonValue &makerValue : markerCom) {  // 遍历视频数组
                                            if (makerValue.isObject()) {  // 如果是JSON对象
                                                QJsonObject markerObj = makerValue.toObject();  // 获取对象
                                                comType = markerObj["Type"].toString();//获取串口类型
                                                portName = markerObj["PortName"].toString(); //获取串口名称
                                                BaudRate = markerObj["BaudRate"].toInt();//获取串口波特率
                                                DataBits = markerObj["DataBits"].toInt();//获取数据为长度
                                                Parity = markerObj["Parity"].toString();//获取校验位
                                                StopBits = markerObj["StopBits"].toInt();//获取停止位长度
                                                FlowControl = markerObj["FlowControl"].toString();//或者数据流控配置
                                                PreFix = markerObj["PreFix"].toString();//获取16进制指令前缀

                                            }
                                        }

                                    }//串口配置获取结束
                                }
                                jsonFile.close();  // 关闭文件
                            } else {
                                qDebug() << "Failed to open JSON file.";  // 打开文件失败
                            }



    // 打开评分记录文件
    QString filename = "ratings_" + QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss") + ".txt";  // 生成文件名
    logFile.setFileName(filename);  // 设置文件名
    if (logFile.open(QIODevice::WriteOnly | QIODevice::Text)) {  // 以写入模式打开文件
        logStream = new QTextStream(&logFile);  // 创建文本流
        *logStream << "Trial---Valence---Arousal---Dominance---Liking\n";  // 写入表头
    }

    serialConnet(); //开始连接串口

    p_scontrol = new SControl(this); // 创建控制块对象
    //测试代码
    //    if(p_scontrol != nullptr){
    //        std::cout << "memony successful~" << std::endl;
    //        p_scontrol->SetMarkData(hexStr_To_Hexchar("0011"));

    //        // 打标
    //        if (m_serial != nullptr) // 如果串口不为空
    //        {
    //            p_scontrol->COMMark(m_serial); // 发送标记数据
    //        }
    //    }//打标测试成功~
    stack->setCurrentWidget(instruction);  // 设置当前页面为说明页

    //发送介绍页打标
    p_scontrol->SetMarkData(hexStr_To_Hexchar("55"));

    // 打标
    if (m_serial != nullptr) // 如果串口不为空
    {
        p_scontrol->COMMark(m_serial); // 发送标记数据
    }
}

// 切换到凝视页
void VideoMainPage::toFixation() {
    stack->setCurrentWidget(fixation);  // 设置当前页面为凝视页
    //发送凝视打标
    p_scontrol->SetMarkData(hexStr_To_Hexchar("66"));

    // 打标
    if (m_serial != nullptr) // 如果串口不为空
    {
        p_scontrol->COMMark(m_serial); // 发送标记数据
    }
    fixation->start();  // 开始凝视
}

// 切换到视频页
void VideoMainPage::toVideo() {
    // 获取当前试次的视频路径
    QString videoPath = videoPaths[currentTrial];  // 获取当前试次的视频路径
    video->setVideo(videoPath);  // 设置视频路径
    stack->setCurrentWidget(video);  // 设置当前页面为视频页
    video->play();  // 播放视频
    //播放视频的时候向串口发送marker
    p_scontrol->SetMarkData(hexStr_To_Hexchar(videoLabels[currentTrial]));

    // 打标
    if (m_serial != nullptr) // 如果串口不为空
    {
        p_scontrol->COMMark(m_serial); // 发送标记数据
    }
}


// 切换到评分页
void VideoMainPage::toRating() {
    stack->setCurrentWidget(rating);  // 设置当前页面为评分页
    //添加开始评分的marker
    p_scontrol->SetMarkData(hexStr_To_Hexchar("33"));
    // 打标
    if (m_serial != nullptr) // 如果串口不为空
    {
        p_scontrol->COMMark(m_serial); // 发送标记数据
    }

    rating->start();  // 开始评分
}

void VideoMainPage::toRest(){
    stack->setCurrentWidget(rest);
    //添加休息的marker
    p_scontrol->SetMarkData(hexStr_To_Hexchar("77"));
    // 打标
    if (m_serial != nullptr) // 如果串口不为空
    {
        p_scontrol->COMMark(m_serial); // 发送标记数据
    }

    rest->start();//开始休息
}

// 保存评分
void VideoMainPage::saveRating(double valence, double arousal, double dominance, double liking) {
    if (logStream) {  // 如果文本流存在
        *logStream << currentTrial + 1 << "---" << valence << "---" << arousal << "---" << dominance << "---" << liking << "\n";  // 写入评分数据
    }
    toRest();
    //toNextTrial();  // 切换到下一个试次
}

// 切换到下一个试次
void VideoMainPage::toNextTrial() {
    currentTrial++;  // 试次数加1
    if (currentTrial < totalTrials) {  // 如果还有试次
        toFixation();  // 切换到凝视页
    } else {
        if (logFile.isOpen()) logFile.close();  // 关闭日志文件
        // 实验结束
        QLabel *endLabel = new QLabel("实验结束，谢谢参与", this);  // 创建结束标签
        endLabel->setAlignment(Qt::AlignCenter);  // 设置标签居中
        endLabel->setStyleSheet("font-size: 32px;");  // 设置标签字体大小
        QWidget *endWidget = new QWidget(this);  // 创建结束页面
        QVBoxLayout *layout = new QVBoxLayout(endWidget);  // 创建垂直布局
        layout->addWidget(endLabel);  // 添加结束标签
        endWidget->setLayout(layout);  // 设置布局
        stack->addWidget(endWidget);  // 添加到堆栈窗口部件
        stack->setCurrentWidget(endWidget);  // 设置当前页面为结束页面
        //添加实验结束的marker
        p_scontrol->SetMarkData(hexStr_To_Hexchar("22"));
        // 打标
        if (m_serial != nullptr) // 如果串口不为空
        {
            p_scontrol->COMMark(m_serial); // 发送标记数据
        }

        // 设置定时器，5秒后关闭程序
        QTimer::singleShot(5000, this, &QWidget::close);  // 5秒后关闭窗口
    }
}

// 键盘事件处理
void VideoMainPage::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {  // 如果按下Esc键
        if (isFullScreen) {  // 如果是全屏模式
            showNormal();  // 切换到正常模式
            isFullScreen = false;  // 设置全屏标志为false
        } else {  // 如果是正常模式
            showFullScreen();  // 切换到全屏模式
            isFullScreen = true;  // 设置全屏标志为true
        }
    } else {
        QMainWindow::keyPressEvent(event);  // 调用基类的键盘事件处理函数
    }
}

void VideoMainPage::serialConnet(){

    if(comType == "COM"){
        m_serial = new SSerial(this); // 创建串口对象
        m_serial->SetPortName(portName); // 设置串口名称
        m_serial->SetBaudRate(BaudRate); // 设置波特率
        m_serial->SetDataBits(DataBits); // 设置数据位
        m_serial->SetParity(Parity); // 设置校验位
        m_serial->SetStopBits(StopBits); // 设置停止位
        m_serial->SetFlowControl(FlowControl); // 设置流控
        m_serial->SetPreFix(hexStr_To_Hexchar(PreFix)); // 设置前缀

    }

    if (!m_serial->OpenSerial()) // 如果打开串口失败
    {
        QMessageBox::critical(this, tr("Error"), "打开串口出错"); // 弹出错误对话框
    }

    else{
        std::cout << "successful~"<< std::endl;
    }


}




