#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QTime>
#include <QDateTime>
#include <QTimer>
#include<QPushButton>
#include<QComboBox>
#include<QVBoxLayout>
#include<QLineEdit>
#include "tcp/tcpserver.h"
#include "device/device_ac.h"
#include "device/device_curtain.h"
#include "device/device_lamp.h"
#include "device/device_fan.h"
#include "my_custom/global.h"

namespace Ui {
class home;
}

class Home : public QWidget
{
    Q_OBJECT
    
public:
    explicit Home(QWidget *parent = 0);
    ~Home();
    

public:
    Tcpserver* my_tcpServer;

    DeviceAC* wid_DeviceAC;
    DeviceCurtain *wid_DeviceCurtain;
    DeviceLamp * wid_DeviceLamp;
    DeviceFan * wid_DeviceFan;

    QTimer* my_timer;
    void activateMode(const QString &mode);//激活模式


    void saveCustomMode(const QString &modeName);//保存自定义模式
    void activateCustomMode(const QString &modeNAme);//激活自定义模式
    QString getDeviceStatus() const;





public slots:
    void slot_timeout(void);

private:
    Ui::home *ui;
    QMap<QString,QVariantMap>customModes;//保存自定义模式
    QLabel *statusLabel; // 状态显示标签
    void updateStatusDisplay(); // 更新状态显示
     void handleRemoteCommand(const QString &command); // 处理远程命令
};

#endif // HOME_H
