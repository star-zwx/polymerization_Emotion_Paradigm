#ifndef INTRODUCTION_H
#define INTRODUCTION_H
#include<QWidget>
#include<QKeyEvent>
class Introduction : public QWidget{
    Q_OBJECT
public:
    explicit Introduction(QWidget *parent = nullptr);
    QString contentText;

protected:
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void instructionDone();
};

#endif // INTRODUCTION_H
