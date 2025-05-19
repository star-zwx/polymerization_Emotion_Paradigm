#include "VideoRatingPage.h"
#include "ui_formrating.h"  // 确保正确包含生成的 UI 头文件

VideoRatingPage::VideoRatingPage(QWidget *parent) : QWidget(parent), ui(new Ui::VideoRatingPage) {
    ui->setupUi(this);  // 初始化 UI

//    this->setLayout(ui->horizontalLayout_2);
//    this->setLayout(ui->horizontalLayout_3);

    setStyleSheet("background-color: white;");

    // 设置 QSlider 的范围为 100 到 900，以模拟浮动数值
    ui->horizontalSlider->setRange(100, 900);
    ui->horizontalSlider_2->setRange(100, 900);
    ui->horizontalSlider_3->setRange(100, 900);
    ui->horizontalSlider_4->setRange(100, 900);

    // 创建 QDoubleSpinBox 并设置范围和步长，但不添加到布局中
    valenceSpinBox = new QDoubleSpinBox(this);
    valenceSpinBox->setRange(1.0, 9.0);
    valenceSpinBox->setSingleStep(0.1);
    valenceSpinBox->setVisible(false);  // 隐藏 QDoubleSpinBox

    arousalSpinBox = new QDoubleSpinBox(this);
    arousalSpinBox->setRange(1.0, 9.0);
    arousalSpinBox->setSingleStep(0.1);
    arousalSpinBox->setVisible(false);  // 隐藏 QDoubleSpinBox

    dominanceSpinBox = new QDoubleSpinBox(this);
    dominanceSpinBox->setRange(1.0, 9.0);
    dominanceSpinBox->setSingleStep(0.1);
    dominanceSpinBox->setVisible(false);  // 隐藏 QDoubleSpinBox

    likingSpinBox = new QDoubleSpinBox(this);
    likingSpinBox->setRange(1.0, 9.0);
    likingSpinBox->setSingleStep(0.1);
    likingSpinBox->setVisible(false);  // 隐藏 QDoubleSpinBox

    // 连接信号和槽
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &VideoRatingPage::updateSpinBoxValue);
    connect(valenceSpinBox, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &VideoRatingPage::updateSliderValue);

    connect(ui->horizontalSlider_2, &QSlider::valueChanged, this, &VideoRatingPage::updateSpinBoxValue);
    connect(arousalSpinBox, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &VideoRatingPage::updateSliderValue);

    connect(ui->horizontalSlider_3, &QSlider::valueChanged, this, &VideoRatingPage::updateSpinBoxValue);
    connect(dominanceSpinBox, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &VideoRatingPage::updateSliderValue);

    connect(ui->horizontalSlider_4, &QSlider::valueChanged, this, &VideoRatingPage::updateSpinBoxValue);
    connect(likingSpinBox, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &VideoRatingPage::updateSliderValue);

    connect(ui->pushButton, &QPushButton::clicked, this, &VideoRatingPage::onSubmitButtonClicked);
}

void VideoRatingPage::start() {
    ui->horizontalSlider->setValue(500);  // 初始化 Valence 滑块
    ui->horizontalSlider_2->setValue(500);   // 初始化 Arousal 滑块
    ui->horizontalSlider_3->setValue(500); // 初始化 Dominance 滑块
    ui->horizontalSlider_4->setValue(500);    // 初始化 Liking 滑块
}

void VideoRatingPage::onSubmitButtonClicked() {
    double valence = valenceSpinBox->value();
    double arousal = arousalSpinBox->value();
    double dominance = dominanceSpinBox->value();
    double liking = likingSpinBox->value();
    emit ratingFinished(valence, arousal, dominance, liking);
}

void VideoRatingPage::updateSliderValue(double value) {
    QDoubleSpinBox *spinBox = qobject_cast<QDoubleSpinBox *>(sender());
    QSlider *slider = nullptr;
    if (spinBox == valenceSpinBox) {
        slider = ui->horizontalSlider;
    } else if (spinBox == arousalSpinBox) {
        slider = ui->horizontalSlider_2;
    } else if (spinBox == dominanceSpinBox) {
        slider = ui->horizontalSlider_3;
    } else if (spinBox == likingSpinBox) {
        slider = ui->horizontalSlider_4;
    }
    if (slider) {
        slider->setValue(static_cast<int>(value * 100.0));
    }
}

void VideoRatingPage::updateSpinBoxValue(double value) {
    QSlider *slider = qobject_cast<QSlider *>(sender());
    QDoubleSpinBox *spinBox = nullptr;
    if (slider == ui->horizontalSlider) {
        spinBox = valenceSpinBox;
    } else if (slider == ui->horizontalSlider_2) {
        spinBox = arousalSpinBox;
    } else if (slider == ui->horizontalSlider_3) {
        spinBox = dominanceSpinBox;
    } else if (slider == ui->horizontalSlider_4) {
        spinBox = likingSpinBox;
    }
    if (spinBox) {
        spinBox->setValue(static_cast<double>(value) / 100.0);
    }
}
