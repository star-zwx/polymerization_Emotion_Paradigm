#ifndef RESTPAGE_H
#define RESTPAGE_H
#include <QWidget>
#include <QDoubleSpinBox>

#include <QWidget>
#include <QTimer>

class RestPage : public QWidget {
    Q_OBJECT
public:
    explicit RestPage(QWidget *parent = nullptr);
    void start();  // ← 添加这个声明
    //int duringTime ;

signals:
    void restFinished();

private:
    void restDone();
};

#endif // RESTPAGE_H
