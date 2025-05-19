#ifndef VIDEORATINGPAGE_H
#define VIDEORATINGPAGE_H
#include <QWidget>
#include <QDoubleSpinBox>

namespace Ui {
class VideoRatingPage;   // 如果 Qt Designer 生成的是 Form
}

class VideoRatingPage : public QWidget {
    Q_OBJECT

public:
    explicit VideoRatingPage(QWidget *parent = nullptr);
    void start();

signals:
    void ratingFinished(double valence, double arousal, double dominance, double liking);

private slots:
    void onSubmitButtonClicked();
    void updateSliderValue(double value);
    void updateSpinBoxValue(double value);

private:
    Ui::VideoRatingPage *ui;
    QDoubleSpinBox *valenceSpinBox;
    QDoubleSpinBox *arousalSpinBox;
    QDoubleSpinBox *dominanceSpinBox;
    QDoubleSpinBox *likingSpinBox;
};

#endif // VIDEORATINGPAGE_H
