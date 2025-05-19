/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QTextEdit *textEdit_chanceInfor;
    QToolButton *toolButton;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton_staticPhoto;
    QRadioButton *radioButton_video;
    QRadioButton *radioButton_music;
    QGroupBox *groupBox_2;
    QTextEdit *textEdit_fileInforPrint;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_chanceFile;
    QLineEdit *lineEdit_filename;
    QPushButton *pushButton_start;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(581, 395);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(41, 180, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 565, 332));
        gridLayout_4 = new QGridLayout(layoutWidget1);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        textEdit_chanceInfor = new QTextEdit(groupBox);
        textEdit_chanceInfor->setObjectName(QString::fromUtf8("textEdit_chanceInfor"));
        textEdit_chanceInfor->setGeometry(QRect(10, 139, 256, 181));
        toolButton = new QToolButton(groupBox);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(11, 23, 218, 26));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        toolButton->setFont(font);
        toolButton->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 255, 247);"));
        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(11, 53, 201, 74));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton_staticPhoto = new QRadioButton(layoutWidget2);
        radioButton_staticPhoto->setObjectName(QString::fromUtf8("radioButton_staticPhoto"));
        QFont font1;
        font1.setPointSize(10);
        radioButton_staticPhoto->setFont(font1);

        gridLayout_2->addWidget(radioButton_staticPhoto, 0, 0, 1, 1);

        radioButton_video = new QRadioButton(layoutWidget2);
        radioButton_video->setObjectName(QString::fromUtf8("radioButton_video"));
        radioButton_video->setFont(font1);

        gridLayout_2->addWidget(radioButton_video, 1, 0, 1, 1);

        radioButton_music = new QRadioButton(layoutWidget2);
        radioButton_music->setObjectName(QString::fromUtf8("radioButton_music"));
        radioButton_music->setFont(font1);

        gridLayout_2->addWidget(radioButton_music, 2, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(layoutWidget1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        textEdit_fileInforPrint = new QTextEdit(groupBox_2);
        textEdit_fileInforPrint->setObjectName(QString::fromUtf8("textEdit_fileInforPrint"));
        textEdit_fileInforPrint->setGeometry(QRect(10, 53, 256, 192));
        textEdit_fileInforPrint->setFont(font1);
        textEdit_fileInforPrint->setStyleSheet(QString::fromUtf8("border-color: rgb(160, 198, 255);"));
        layoutWidget3 = new QWidget(groupBox_2);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 22, 240, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_chanceFile = new QPushButton(layoutWidget3);
        pushButton_chanceFile->setObjectName(QString::fromUtf8("pushButton_chanceFile"));
        pushButton_chanceFile->setFont(font1);

        horizontalLayout->addWidget(pushButton_chanceFile);

        lineEdit_filename = new QLineEdit(layoutWidget3);
        lineEdit_filename->setObjectName(QString::fromUtf8("lineEdit_filename"));

        horizontalLayout->addWidget(lineEdit_filename);

        pushButton_start = new QPushButton(groupBox_2);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(10, 260, 251, 51));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_start->setFont(font2);
        pushButton_start->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 255, 130);"));

        gridLayout_4->addWidget(groupBox_2, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 581, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\203\205\347\273\252\350\257\261\345\217\221\350\204\221\347\224\265\351\207\207\351\233\206\350\214\203\345\274\217app", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\350\257\261\345\217\221\347\261\273\345\236\213", nullptr));
        textEdit_chanceInfor->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\257\267\345\205\210\351\200\211\346\213\251\350\257\261\345\217\221\346\235\220\346\226\231\347\261\273\345\236\213\357\274\233</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\204\266\345\220\216\345\234\250\345\217\263\344\276\247\351\200\211\346\213\251\345\214\205\345\220\253config.json\346\226\207\344\273\266\345\222\214\347\264\240\346\235\220\346\272\220\346\226\207\344\273\266\347\232\204\350\267\257\345\276\204</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; ma"
                        "rgin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\351\200\211\346\213\251\345\220\216 \344\274\232\346\211\223\345\215\260\346\226\207\344\273\266\344\277\241\346\201\257\357\274\214\347\241\256\350\256\244\346\262\241\351\227\256\351\242\230\345\220\216\357\274\214\347\202\271\345\207\273\347\253\213\345\215\263\345\274\200\345\247\213\345\256\236\351\252\214\345\215\263\345\217\257\345\274\200\345\247\213</p></body></html>", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\350\257\261\345\217\221\346\235\220\346\226\231\347\261\273\345\236\213", nullptr));
        radioButton_staticPhoto->setText(QCoreApplication::translate("MainWindow", "\351\235\231\346\200\201\345\233\276\347\211\207", nullptr));
        radioButton_video->setText(QCoreApplication::translate("MainWindow", "\344\270\215\345\256\232\346\227\266\351\225\277\347\232\204\350\247\206\351\242\221\347\211\207\346\256\265", nullptr));
        radioButton_music->setText(QCoreApplication::translate("MainWindow", "\344\270\215\345\256\232\346\227\266\351\225\277\347\232\204\351\237\263\344\271\220\347\211\207\346\256\265", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266\350\267\257\345\276\204", nullptr));
        textEdit_fileInforPrint->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\226\207\344\273\266\344\277\241\346\201\257</p></body></html>", nullptr));
        pushButton_chanceFile->setText(QCoreApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\346\226\207\344\273\266\350\267\257\345\276\204", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "\347\253\213\345\215\263\345\274\200\345\247\213\345\256\236\351\252\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
