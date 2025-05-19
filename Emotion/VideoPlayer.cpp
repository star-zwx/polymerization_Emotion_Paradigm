#include "VideoPlayer.h"
#include <QVBoxLayout>

Videoplayer::Videoplayer(QWidget *parent) : QWidget(parent) {
    player = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);

    player->setVideoOutput(videoWidget);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(videoWidget);
    setLayout(layout);

    connect(player, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status){
        if (status == QMediaPlayer::EndOfMedia) {
            emit videoFinished();
        }
    });
}

void Videoplayer::setVideo(const QString &path) {
    player->setMedia(QUrl::fromLocalFile(path));
}

void Videoplayer::play() {
    player->play();
}

void Videoplayer::handleMediaFinished() {
    if (player->mediaStatus() == QMediaPlayer::EndOfMedia) {
        emit videoFinished();
    }
}
