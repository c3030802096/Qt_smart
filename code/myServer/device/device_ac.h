#ifndef DeviceAC_H
#define DeviceAC_H

#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include<QLabel>
#include "my_custom/digital_scroller.h"
#include "my_custom/sliderbutton.h"
#include "tcp/tcpsocket.h"

#include "my_custom/global.h"

namespace Ui {
class device_ac;
}

class DeviceAC : public QWidget
{
    Q_OBJECT
    
public:
    explicit DeviceAC(int room,QWidget *parent = 0);
    ~DeviceAC();

    DigitalScroller* my_digitalScroller;
    SliderButton* my_Slider_btn;

    int room_name;

    void openslider();//打开空调总开关
    void closeslider();//打开空调总开关

    void setModeAndSpeed(const QString& mode,const QString & speed);//设置风速

    int getCurValue()const;//当前温度
    QString getCurrentMode()const;//获取当前模式
    QString getCurrentSpeed()const;//获取当前风速
    bool isAcOn()const;//空调开关状态


private slots:

    void slot_temp_value_channged(int currentValue);

    void on_btn_mode_clicked();

    void on_btn_wind_clicked();

    void on_btn_wind_back_clicked();

    void on_btn_mode_back_clicked();

    void slot_btn_click(void);

    void slot_slider_OFF(void);
    void slot_slider_ON(void);

private:
    int currentTemperature = 25; // 当前温度，默认为 25
    QString currentMode = "自动"; // 当前模式，默认为 "自动"
    QString currentSpeed = "小风"; // 当前风速，默认为 "小风"

signals:
    void sig_sendData(int sockID,QString sendData);

private:
    Ui::device_ac *ui;
    bool AcStatus=false;

    QLabel *statusLabel; // 状态显示标签
    void updateStatusDisplay(); // 更新状态显示
};

#endif // DeviceAC_H
