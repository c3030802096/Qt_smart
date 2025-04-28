#ifndef DEVICE_FAN_H
#define DEVICE_FAN_H

#include <QWidget>
#include "my_custom/global.h"
#include "my_custom/sliderbutton.h"

namespace Ui {
class DeviceFan;
}

class DeviceFan : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceFan(int room,QWidget *parent = 0);
    ~DeviceFan();

    SliderButton* my_Slider_btn;

    int room_name;
    void openfan();//定时的风扇
    void closefan();//关闭风扇
    bool isFanOn()const;//检查风扇是否打开
private:
    Ui::DeviceFan *ui;
    bool fanStatus=false;//风扇抓捕柜台


public slots:
    void slot_slider_OFF(void);
    void slot_slider_ON(void);

signals:
    void sig_sendData(int sockID,QString sendData);
};

#endif // DEVICE_FAN_H
