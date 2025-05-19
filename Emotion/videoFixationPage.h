#ifndef VIDEOFIXATIONPAGE_H
#define VIDEOFIXATIONPAGE_H
#include <QWidget>
#include <QTimer>

class VideoFixationPage : public QWidget {
    Q_OBJECT
public:
    explicit VideoFixationPage(QWidget *parent = nullptr);
    void start();  // ← 添加这个声明

signals:
    void fixationFinished();

private:
    void fixationDone();
};
#endif // VIDEOFIXATIONPAGE_H
