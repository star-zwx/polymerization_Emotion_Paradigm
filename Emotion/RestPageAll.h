#ifndef RESTPAGEALL_H
#define RESTPAGEALL_H
#include<QWidget>
#include<QDoubleSpinBox>
#include<QTimer>

class RestPageAll: public QWidget{
    Q_OBJECT
public:
    explicit RestPageAll(QWidget *parent = nullptr);
    void start();
    int duringTime;

signals:
    void restFinished();

private:
    void restDone();

};

#endif // RESTPAGEALL_H
