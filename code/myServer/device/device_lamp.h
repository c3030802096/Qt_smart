#ifndef DEVICE_LAMP_H
#define DEVICE_LAMP_H

#include <QWidget>
#include "my_custom/global.h"
#include "my_custom/sliderbutton.h"

namespace Ui {
class DeviceLamp;
}

class DeviceLamp : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceLamp(int room,QWidget *parent = 0);
    ~DeviceLamp();

    SliderButton* my_Slider_btn;
    int room_name;

    void openlamp();//打开定时的灯；
    void closelamp();
    bool isLampOn()const;

private:
    Ui::DeviceLamp *ui;
    bool lampStatus;


public slots:
    void slot_slider_OFF(void);
    void slot_slider_ON(void);


signals:
    void sig_sendData(int sockID,QString sendData);
};

#endif // DEVICE_LAMP_H
