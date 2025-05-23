#include <QApplication>
#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QStringList>
#include <QKeyEvent>
#include <QDebug>
class FullScreenImagePlayer : public QWidget {
    Q_OBJECT

public:
    FullScreenImagePlayer(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowState(Qt::WindowFullScreen);
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &FullScreenImagePlayer::showNextImage);
        timer->start(5000); // 5秒切换一次图片
    }

    void setImageList(const QStringList &imageList) {
        this->imageList = imageList;
        currentIndex = 0;
        if (!imageList.isEmpty()) {
            update(); // 触发绘制事件
        }
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);
        if (currentIndex < imageList.size()) {
            QPixmap pixmap(imageList[currentIndex]);
            if (!pixmap.isNull()) {
                QPainter painter(this);
                // 缩放图片以适应窗口大小
                pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                painter.drawPixmap(0, 0, pixmap);
            } else {
                qDebug() << "Failed to load image:" << imageList[currentIndex];
            }
        }
    }

    void keyPressEvent(QKeyEvent *event) override {
        if (event->key() == Qt::Key_Escape) {
            close(); // 关闭窗口
        } else {
            QWidget::keyPressEvent(event); // 传递其他键事件
        }
    }

private slots:
    void showNextImage() {
        currentIndex = (currentIndex + 1) % imageList.size();
        update(); // 触发绘制事件
    }

private:
    QTimer *timer;
    QStringList imageList;
    int currentIndex;
};
