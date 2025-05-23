#ifndef FIXTATIONPAGE_H
#define FIXTATIONPAGE_H
#include <QWidget>
#include <QTimer>

class FixationPage : public QWidget {
    Q_OBJECT
public:
    explicit FixationPage(QWidget *parent = nullptr);
    void start();  // ← 添加这个声明
    int duringTime ;

signals:
    void fixationFinished();

private:
    void fixationDone();

};
#endif // FIXTATIONPAGE_H
