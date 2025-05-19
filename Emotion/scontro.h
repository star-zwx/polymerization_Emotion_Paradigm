#ifndef SCONTRO_H
#define SCONTRO_H
#include <QObject>
#include "sserial.h"
#include <QMap>
#include <QString>
#include <QWidget>
class SControl : public QObject
{
    Q_OBJECT
public:
    explicit SControl(QWidget *parent = nullptr);
    ~SControl();
public:
    //打标
    void COMMark(SSerial *serial);
    void SetMarkData(QByteArray mark_data);
    //获取事件
    QString GetEvent(int key_code);
private:
    //打标信息
    QByteArray m_mark_data;
signals:

};

#endif // SCONTRO_H
