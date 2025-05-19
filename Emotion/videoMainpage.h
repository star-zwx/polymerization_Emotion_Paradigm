#ifndef VIDEOMAINPAGE_H
#define VIDEOMAINPAGE_H
#include <QMainWindow>
#include <QStackedWidget>
#include <QFile>
#include <QTextStream>
#include <QKeyEvent>
#include <QMessageBox>
#include "vodeoIntrPage.h"
#include "videoFixationPage.h"
#include "VideoPlayer.h"
#include "VideoRatingPage.h"
#include "RestPage.h"
#include "sserial.h"
#include "utils.h"
#include "scontro.h"


/*
 * 视频播放的运行逻辑
 * 通过类的构造函数运行主页面
 * 每个页面由子页面构成，介绍页面-凝视页面-视频播放页面-评价页面（有无可以通过参数控制）-结束页面

*/

class VideoMainPage:public QMainWindow{
    Q_OBJECT

public:
    VideoMainPage(const QString &filenameJson ,QWidget *parent = nullptr);
    SSerial *m_serial = nullptr;
    //串口发送控制类
    SControl *p_scontrol = nullptr; // 创建控制块对象
private slots:
    void toFixation();
    void toVideo();
    void toRest();
    void toRating();
    void toNextTrial();
    void saveRating(double valence, double arousal, double dominance, double liking);
    void serialConnet();


protected:
    void keyPressEvent(QKeyEvent *event) override;  // 声明 keyPressEvent 方法

private:
    QStackedWidget *stack;
    VideoIntrtionPage *instruction;
    VideoFixationPage *fixation;
    Videoplayer *video;
    RestPage *rest;
    VideoRatingPage *rating;

    int currentTrial;
    int totalTrials;

    QFile logFile;
    QTextStream *logStream;

    QStringList videoPaths;
    QStringList videoLabels;
    QString comType;
    QString portName;
    int BaudRate;
    int DataBits;
    QString Parity;
    int StopBits;
    QString FlowControl;
    QString PreFix;

    bool isFullScreen;  // 添加 isFullScreen 标志
};


#endif // VIDEOMAINPAGE_H
