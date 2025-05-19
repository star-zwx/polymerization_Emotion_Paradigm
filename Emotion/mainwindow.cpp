#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font = ui->textEdit_fileInforPrint->font();
    font.setPointSize(10); // 设置字体大小为14点
    ui->textEdit_fileInforPrint->setFont(font);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_chanceFile_clicked()
{
    //点击选择文件的按钮的槽函数
    QString folderPath = QFileDialog::getExistingDirectory(this,"选择文件夹");
    //如果选择了文件夹，将该路径设置到QLineEdit
    if(!folderPath.isEmpty()){
        ui->lineEdit_filename->setText(folderPath);
    }
    //获取这个路径下的文件信息，并在信息打印处打印信息
    QDir dir(folderPath);
    QStringList files = dir.entryList(QDir::Files);

    //将文件信息显示在信息打印框中
    ui->textEdit_fileInforPrint->clear();
    foreach (QString file,files){
        ui->textEdit_fileInforPrint->append(file);
    }
}

void MainWindow::on_pushButton_start_clicked()
{
    //点击开始实验的按钮槽函数
    /*
        step1：判断是否选择了刺激类型和文件路径，并且文件中有文件
        step2：如果没有以上判断的内容，弹窗提示让用户选择
        step3：如果选择了以上的全部内容进入实验
    */

    //判断是否填写相关内容
    if( (ui->radioButton_music->isChecked() || ui->radioButton_video->isChecked() || ui->radioButton_staticPhoto->isChecked())){
        filename = ui->lineEdit_filename->text() + "/config.json";
        if(ui->radioButton_music->isChecked()){
            flageRadio = "music";
        }
        else if(ui->radioButton_video->isChecked()){
            flageRadio = "video";

        }

        else{
            flageRadio = "photo";
        }

        //进入实验
        ExperimentPage *experiment = new ExperimentPage(filename,flageRadio);
        //experiment->showFullScreen();


    }
    else{
        //弹窗提醒
        QMessageBox::warning(this, "提示", "请选择信息");
    }




}
