#include "vodeoIntrPage.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QKeyEvent>

VideoIntrtionPage::VideoIntrtionPage(QWidget *parent) : QWidget(parent) {
    setFocusPolicy(Qt::StrongFocus);  // 允许接收键盘事件
    setFocus();  // 获取焦点

    QLabel *label = new QLabel("实验须知：\n\n 本次实验你将会观看五个电影片段，请在播放期间尽量代入情节\n \n\n 每次电影开始之前将会有2秒注视屏幕中心+阶段\n\n\n 观看完电影片段后会有调查问卷，请你根据观看感受进行拖动滑动条进行评价\n\n\n 按空格键开始实验", this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px;");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    setLayout(layout);
}

void VideoIntrtionPage::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space) {
        emit instructionDone();  // 发送信号，告诉主窗口切换页面
    }
}
