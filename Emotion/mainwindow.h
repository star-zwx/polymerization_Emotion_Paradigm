#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include "experimentpage.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString filename;
    QString flageRadio;

private slots:
    void on_pushButton_chanceFile_clicked();

    void on_pushButton_start_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
