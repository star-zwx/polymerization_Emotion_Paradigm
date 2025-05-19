#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H
#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>

class Videoplayer : public QWidget {
    Q_OBJECT
public:
    explicit Videoplayer(QWidget *parent = nullptr);
    void setVideo(const QString &path);  // 设置视频路径
    void play();  // ← 添加这个声明

signals:
    void videoFinished();

private slots:
    void handleMediaFinished();

private:
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
};

#endif // VIDEOPLAYER_H
