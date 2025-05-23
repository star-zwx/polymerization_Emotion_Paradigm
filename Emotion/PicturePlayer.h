#ifndef PICTUREPLAYER_H
#define PICTUREPLAYER_H
#include<QPixmap>
#include<QVBoxLayout>
#include<QTime>
#include<QApplication>
#include<QDesktopWidget>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QTimer>
#include <QApplication>
#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QPixmap>
#include <QDir>
#include<QKeyEvent>
#include<QPainter>
class PicturePlayer : public QWidget{
    Q_OBJECT;

public:
    explicit PicturePlayer(QWidget * parent = nullptr);
    void setImageList(const QStringList &imageLists,const QStringList &imageLabel,int duringTime);
    ~PicturePlayer();


protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
signals:
    void PictureFinished();


private slots:
//    void handlePicturesFinished();
    void showNextImage();

private:
    QTimer *timer;
    QStringList  imageList;
    QStringList imageLabel;
    int duringTime ;
    int currentIndex;





};

#endif // PICTUREPLAYER_H
