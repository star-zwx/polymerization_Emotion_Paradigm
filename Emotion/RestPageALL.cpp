#include<RestPageAll.h>
#include<QLabel>
#include<QVBoxLayout>
RestPageAll :: RestPageAll(QWidget * parent) : QWidget(parent){
    //设置全屏
    setWindowState(Qt::WindowFullScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);

    //创建标签
    QLabel *label = new QLabel("本轮结束，请休息一会~");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size:100px;color:white;background-color:black;");

    //设置布局
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    setLayout(layout);

}



void RestPageAll::start(){
    //每次进入页面时发送信号并启动定时器
    QTimer::singleShot(duringTime,this,&RestPageAll::restDone);

}


void RestPageAll::restDone(){
    //发送结束信号并发射信号通知主窗口切换页面
    emit restFinished();
}
