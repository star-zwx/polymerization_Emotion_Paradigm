#include "RestPage.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>


RestPage::RestPage(QWidget *parent) : QWidget(parent){
    // 设置窗口为全屏
    setWindowState(Qt::WindowFullScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);  // 可以设置为无背景透明，确保全屏效果

    // 创建标签
    QLabel *label = new QLabel("本轮结束，请休息20秒~", this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 100px; color: white; background-color: black;");

    // 设置布局
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    setLayout(layout);

}

void RestPage::start() {
    // 每次进入该页面时发送开始信号并启动 2 秒定时器
    //sendStartSignal();  // 发送开始信号
    QTimer::singleShot(20000, this, &RestPage::restDone);
}



void RestPage::restDone() {
    // 发送结束信号并发射信号通知主窗口切换页面
    //sendEndSignal();  // 发送结束信号
    emit restFinished();  // 发射信号，通知主窗口切换页面
}

