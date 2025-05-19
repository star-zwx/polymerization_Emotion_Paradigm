#ifndef VODEOINTRPAGE_H
#define VODEOINTRPAGE_H

#include <QWidget>
#include <QKeyEvent>

class VideoIntrtionPage : public QWidget {
    Q_OBJECT
public:
    explicit VideoIntrtionPage(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void instructionDone();
};




#endif // VODEOINTRPAGE_H
