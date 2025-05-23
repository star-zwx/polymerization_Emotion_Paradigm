#include "PictureMainPage.h"
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
#include <QVector>
#include <QDebug>
#include <algorithm>
#include <random>
#include <ctime>
#include <qmath.h>
PictureMainPage::PictureMainPage(const QString &filenamejson,QWidget *parent)
    : QMainWindow(parent),currentTrial(0),totalTrials(0),isFullScreen(false)

{   stack = new QStackedWidget(this);

    //创建各个页面
    introduction = new Introduction(this);
    fixation = new FixationPage(this);
    picture = new PicturePlayer(this);
    rest = new RestPageAll(this);

    setCentralWidget(stack);

    stack->addWidget(introduction);
    stack->addWidget(fixation);
    stack->addWidget(picture);
    stack->addWidget(rest);



    resize(800,600);


    //信号与槽连接

    connect(introduction,&Introduction::instructionDone,this,&PictureMainPage::toFixation);
    connect(fixation, &FixationPage::fixationFinished, this, &PictureMainPage::toPicture);  // 凝视页完成后切换到视频页
    connect(picture, &PicturePlayer::PictureFinished, this, &PictureMainPage::toRest);  // 视频页完成后切换到评分页
    connect(rest, &RestPageAll::restFinished, this, &PictureMainPage::toNextTrial);  // 休息页完成后切换到下一个试次


    //打开json文件读取配置信息
    QFileInfo fileInfo(filenamejson);
    //获取文件路径
    QString pathWithoutFile = fileInfo.path();

    QFile jsonFile(filenamejson);

    if(jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QByteArray jsonData = jsonFile.readAll();  // 读取文件内容
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);  // 解析JSON数据
        if(jsonDoc.isObject()){
            QJsonObject jsonObj = jsonDoc.object();  // 获取JSON对象
            if(jsonObj.contains("pictures") && jsonObj["pictures"].isArray()){
                QJsonArray picturesArray = jsonObj["pictures"].toArray();  // 获取图片数组
                //遍历图片数组

                pictNum = picturesArray.size();
                for(const QJsonValue &pictureValue :picturesArray){
                    if(pictureValue.isObject()){
                        QJsonObject pictObj = pictureValue.toObject();  // 获取图片对象
                        QString pictPath = pathWithoutFile+'/'+pictObj["path"].toString();  // 获取视图片路径
                        qDebug() << "file"<<pictPath;
                        QString videoLabel = pictObj["label"].toString();  // 获取图片标签
                        picturePaths.append(pictPath);  // 添加到图片路径列表
                        pictureLabels.append(videoLabel);  // 添加到图片标签列表
                    }
                }
            }//picture键值结束

            //解析下面的其他键值
            //解析串口配置
            if(jsonObj.contains("MarkerInfo") && jsonObj["MarkerInfo"].isArray()){
                //获取事件串口的配置信息
                QJsonArray markerCom = jsonObj["MarkerInfo"].toArray();
                for (const QJsonValue &makerValue : markerCom) {  // 遍历数组
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

            }//串口配置信息读取完成

            //读取页面信息配置信息
            if(jsonObj.contains("PageConfig") && jsonObj["PageConfig"].isArray()){
                QJsonArray pageInfor = jsonObj["PageConfig"].toArray();
                for(const QJsonValue &pagevalue:pageInfor){
                    if(pagevalue.isObject()){
                        QJsonObject pageObj = pagevalue.toObject();
                        //下面配置其他页面显示的一些信息，介绍页文字，休息时长，凝视时长
                        introduction->contentText = pageObj["IntroPageText"].toString(); //介绍页文字
                        rest->duringTime = pageObj["RestTime"].toInt(); //休息时长
                        fixation->duringTime = pageObj["FixationTime"].toInt(); //凝视时长


                    }
                }
            }//页面显示信息配置完成


            //读取图片播放的一些配置信息
            if(jsonObj.contains("DisplayConfig") && jsonObj["DisplayConfig"].isArray()){
                QJsonArray displayInfor = jsonObj["DisplayConfig"].toArray();
                for(const QJsonValue &displayValue:displayInfor){
                    if(displayValue.isObject()){
                        QJsonObject disObj = displayValue.toObject();
                        //下面配置图片的持续时长，是否重复，重复次数
                        imageDuring = disObj["ContinueTime"].toInt();
                        RepeatTime = disObj["RepeatTime"].toInt();
                        RepeatOrNot = disObj["RepeatOrNot"].toString();
                        RandomPlay = disObj["RandomPlay"].toString();
                        oneplayNum = disObj["oneplayNum"].toInt();
                    }
                }
            }//图片播放的配置设置完成



        }

        jsonFile.close();
    }
    else{
        qDebug() << "Failed to open JSON file.";  // 打开文件失败
    }
    //这里加入对重复信息的重构
    //先判断是否对图片进行重复播放，重复次数是多少
    if(RepeatOrNot == "yes" && RepeatTime != 0 ){
        //如果需要重复，就把重复次数设置成trail数
        //totalTrials = int(pictNum*RepeatTime/oneplayNum);
        totalTrials = qCeil(static_cast<qreal>(pictNum*RepeatTime) / oneplayNum);
        qDebug()<< "total"<<totalTrials;
        //然后将图片地址列表按照重复次数扩充(降低空间复杂度，生成索引来模拟重复)
        // 生成索引数组

        // 创建一个包含所有图片索引的列表，并重复每个索引playsPerImage次
        QVector<int> imageIndices;
        for (int i = 0; i < pictNum; ++i) {
            for (int j = 0; j < oneplayNum; ++j) {
                imageIndices.append(i);
            }
        }

        // 随机打乱索引列表
        std::srand(std::time(0));
        std::shuffle(imageIndices.begin(), imageIndices.end(), std::default_random_engine(static_cast<unsigned>(std::time(0))));


        // 填充索引数组
        for (int i = 0; i < totalTrials; ++i) {
            int startIdx = i * oneplayNum;
            QVector<int> trailIndices = imageIndices.mid(startIdx, oneplayNum);

            // 如果trail的索引数量不足trailSize，则用-1填充
            while (trailIndices.size() < oneplayNum) {
                trailIndices.append(-1);
            }

            indexArray.append(trailIndices);
        }


        qDebug()<< indexArray;






    }

    //开始连接串口
    serialConnet(); //开始连接串口

    p_scontrol = new SControl(this); // 创建控制块对象
    stack->setCurrentWidget(introduction);  // 设置当前页面为说明页
    //发送介绍页打标
    p_scontrol->SetMarkData(hexStr_To_Hexchar("55"));
    // 打标
    if (m_serial != nullptr) // 如果串口不为空
    {
        p_scontrol->COMMark(m_serial); // 发送标记数据
    }
}

// 切换到凝视页
void PictureMainPage::toFixation() {
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
void PictureMainPage::toPicture() {
    // 获取当前试次的image路径
    QVector<int> picPathIndex = indexArray[currentTrial];  // 获取当前试次的视频路径，先获取当前的索引
    //根据索引在获取qstring
    QStringList indexToName ;
    QStringList indexToLabel;
    for(int idx : picPathIndex) {
        if (idx >= 0 && idx < picturePaths.size()) {
            indexToName.append(picturePaths[idx]);
            indexToLabel.append(pictureLabels[idx]);
        }
    }

    qDebug()<< picPathIndex;

    picture->setImageList(indexToName,indexToLabel,imageDuring);  // 设置视频路径
    stack->setCurrentWidget(picture);  // 设置当前页面为视频页
    picture->show();  // 播放image

}



void PictureMainPage::toRest(){
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



// 切换到下一个试次
void PictureMainPage::toNextTrial() {
    currentTrial++;  // 试次数加1
    if (currentTrial < totalTrials) {  // 如果还有试次
        toFixation();  // 切换到凝视页
    } else {

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
void PictureMainPage::keyPressEvent(QKeyEvent *event) {
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

void PictureMainPage::serialConnet(){

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

