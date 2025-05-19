/*
 * 主要实现实验素材呈现的逻辑
 * 1. 读取选中素材的json文件
 * 2.根据json文件中的配置信息进行串口连接
 * 3.根据json文件进行刺激素材的解码：
 * 3.1 根据上一级传入的参数判断是哪种刺激类型，不同的刺激类型要使用不同的呈现方式
 * 3.1.1视频和音乐呈现时长以本身素材的呈现时长为准
 * 3.1.2静态图片的呈现时长在json文件中配置
 * 3.1.3重复次数也需要在json文件中配置
 *

*/
#include "experimentpage.h"
#include "videoMainpage.h"
# include <iostream>
#include <QDebug>
// 构造函数
ExperimentPage::ExperimentPage(const QString &fileNameJson ,const QString &flageRadioBtn , QWidget *parent)
      // 接收参数：json文件所在的文件夹，选择的刺激类型
{

    //serialConnet();
    //判断用户选择了哪种类型的刺激
    if(flageRadioBtn == "music"){
        qDebug() << "music";

    }
    else if(flageRadioBtn == "video"){
        qDebug() << "video";
        //选择视频的播放
        VideoMainPage *currentVideo = new VideoMainPage(fileNameJson);
        currentVideo->showFullScreen();
        this->close();


    }

    else{
        qDebug() << "photo";
        //选择图片播放的模式

    }



}



ExperimentPage::~ExperimentPage(){

    this->close();


}
