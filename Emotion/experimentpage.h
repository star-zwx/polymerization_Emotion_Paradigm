#ifndef EXPERIMENTPAGE_H
#define EXPERIMENTPAGE_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QFile>
#include <QTextStream>
#include <QKeyEvent>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include "sserial.h"
#include "scontro.h"
#include "utils.h"

#endif // EXPERIMENTPAGE_H

//声明实验流程的类
class ExperimentPage : public QMainWindow {
    Q_OBJECT

public:
    //公共函数
     ExperimentPage(const QString &fileNameJson,const QString &flageRadioBtn, QWidget *parent = nullptr);
     ~ExperimentPage();

    SSerial *m_serial = nullptr;
    //串口发送控制类
    SControl *p_scontrol = nullptr; // 创建控制块对象

private:
    QString comType; //com类型
    QString portName; //串口名称
    int BaudRate;    //波特率
    int DataBits;    //数据位长度
    QString Parity;  //校验位
    int StopBits;    //停止位
    QString FlowControl;  //数据流控
    QString PreFix;  //打标头部
    bool isFullScreen;  // 添加 isFullScreen 标志.
    QStringList filePath; //刺激材料
    QStringList fileLable; //材料label

};
