#include "videoFixationPage.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>


VideoFixationPage::VideoFixationPage(QWidget *parent) : QWidget(parent){
    // 设置窗口为全屏
    setWindowState(Qt::WindowFullScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);  // 可以设置为无背景透明，确保全屏效果

    // 创建标签
    QLabel *label = new QLabel("+", this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 200px; color: white; background-color: black;");

    // 设置布局
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    setLayout(layout);

    // 初始化串口
//    serialPort->setPortName("COM1");  // 设置串口名称，根据实际情况修改
//    if (serialPort->open(QIODevice::WriteOnly)) {
//        serialPort->setBaudRate(QSerialPort::Baud9600);
//        serialPort->setDataBits(QSerialPort::Data8);
//        serialPort->setParity(QSerialPort::NoParity);
//        serialPort->setStopBits(QSerialPort::OneStop);
//        serialPort->setFlowControl(QSerialPort::NoFlowControl);
//    }
}

void VideoFixationPage::start() {
    // 每次进入该页面时发送开始信号并启动 2 秒定时器
    //sendStartSignal();  // 发送开始信号
    QTimer::singleShot(5000, this, &VideoFixationPage::fixationDone);
}

//void FixationPage::sendStartSignal() {
//    if (serialPort->isOpen()) {
//        QByteArray data = "1";  // 向串口发送数字 1 表示开始
//        serialPort->write(data);
//    }
//}

void VideoFixationPage::fixationDone() {
    // 发送结束信号并发射信号通知主窗口切换页面
    //sendEndSignal();  // 发送结束信号
    emit fixationFinished();  // 发射信号，通知主窗口切换页面
}

//void FixationPage::sendEndSignal() {
//    if (serialPort->isOpen()) {
//        QByteArray data = "2";  // 向串口发送数字 2 表示结束
//        serialPort->write(data);
//    }
//}
