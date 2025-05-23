#ifndef PICTUREMAINPAGE_H
#define PICTUREMAINPAGE_H
#include <QMainWindow>
#include <QStackedWidget>
#include <QFile>
#include <QTextStream>
#include <QKeyEvent>
#include <QMessageBox>
#include "Introduction.h"
#include "FixationPage.h"
#include "PicturePlayer.h"
#include "RestPageAll.h"
#include "sserial.h"
#include "utils.h"
#include "scontro.h"


/*
 * picture播放的运行逻辑
 * 通过类的构造函数运行主页面
 * 每个页面由子页面构成，介绍页面-凝视页面-视频播放页面-评价页面（有无可以通过参数控制）-结束页面

*/

class PictureMainPage:public QMainWindow{
    Q_OBJECT

public:
    PictureMainPage(const QString &filenameJson ,QWidget *parent = nullptr);
    SSerial *m_serial = nullptr;
    //串口发送控制类
    SControl *p_scontrol = nullptr; // 创建控制块对象
private slots:
    void toFixation(); //转移到凝视页面
    void toPicture();
    void toRest();
    void toNextTrial();
    //void saveRating(double valence, double arousal, double dominance, double liking);
    void serialConnet();


protected:
    void keyPressEvent(QKeyEvent *event) override;  // 声明 keyPressEvent 方法

private:
    QStackedWidget *stack;  //窗口堆栈
    Introduction *introduction;  //介绍页面
    FixationPage *fixation;  //凝视页面
    PicturePlayer *picture;   //照片播放页面
    RestPageAll *rest;    //休息页面


    int currentTrial;  //当前的试次
    int totalTrials;  //总的试次

    QStringList picturePaths;  //图片路径
    QStringList pictureLabels;  //图片标签
    QString comType; //串口类型
    QString portName; //串口名称
    int BaudRate;  //波特率
    int DataBits;  //数据位长度
    QString Parity;  //校验位
    int StopBits;//停止位
    QString FlowControl;//流控设置
    QString PreFix; //打标头部信息

    bool isFullScreen;  // 添加 isFullScreen 标志

    QString  RepeatOrNot;
    int RepeatTime;
    QString RandomPlay;
    int oneplayNum;
    int pictNum;
    int imageDuring;
    QVector<QVector<int>> indexArray;
    QStringList stringList;
};

#endif // PICTUREMAINPAGE_H
