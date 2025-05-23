#include<PicturePlayer.h>
#include<QDebug>

PicturePlayer::PicturePlayer(QWidget *parent ) : QWidget(parent){
    setWindowState(Qt::WindowFullScreen);//设置全屏
    timer = new QTimer;
    connect(timer,&QTimer::timeout,this,&PicturePlayer::showNextImage);
    //timer->start(duringTime);



}


void PicturePlayer::setImageList(const QStringList &imageLists,const QStringList &imageLabels,int duringTimes){
    imageList = imageLists;
    duringTime = duringTimes;
    imageLabel = imageLabels;
    currentIndex = 0;
    if (!imageList.isEmpty()) {
        update(); // 先画第一张图
        timer->start(duringTime); // 再开始定时器
    }

}

void PicturePlayer::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    if (currentIndex < imageList.size()) {
        QPixmap pixmap(imageList[currentIndex]);
        if (!pixmap.isNull()) {
            QPainter painter(this);
            // 缩放图片以适应窗口大小
            pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            painter.drawPixmap(0, 0, pixmap);
            //这里预留打标的代码，每一张图片打一个标，根据labels
        } else {
            qDebug() << "Failed to load image:" << imageList[currentIndex];
        }
    }
}


void PicturePlayer::keyPressEvent(QKeyEvent *event)  {
    if (event->key() == Qt::Key_Escape) {
        close(); // 关闭窗口
    } else {
        QWidget::keyPressEvent(event); // 传递其他键事件
    }
}

void PicturePlayer:: showNextImage() {
    qDebug()<<"currentIndex" << currentIndex;
    currentIndex++;
    if (currentIndex < imageList.size()) {
        update(); // 触发绘制事件
    } else {
        timer->stop(); // 停止计时器

        emit PictureFinished(); // 发射播放完成信号

        this->close();
    }
}

PicturePlayer::~PicturePlayer(){


}


