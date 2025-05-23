#include <QApplication>
#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QStringList>
#include <QDebug>
#include"PicturePlayer.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FullScreenImagePlayer player;
    QStringList imageList;
    imageList << "C:\\Users\\Administrator\\Desktop\\qt\\polymerizationEmotion\\resources\\photos\\25.png" << "C:\\Users\\Administrator\\Desktop\\qt\\polymerizationEmotion\\resources\\photos\\2.png"; // 替换为实际的图片路径
    player.setImageList(imageList);
    player.show();

    return app.exec();
}
