#include<Introduction.h>
#include<QLabel>
#include<QVBoxLayout>
#include<QKeyEvent>


Introduction:: Introduction(QWidget *parent) : QWidget(parent){
    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    QLabel * label = new QLabel("contentText");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size:24px");

    QVBoxLayout * layout = new QVBoxLayout(this);
    layout->addWidget(label);
    setLayout(layout);

}


void Introduction  ::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Space){
        emit instructionDone();
    }
}
