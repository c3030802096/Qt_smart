#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);

    my_tcpServer = new Tcpserver(this);
    //启动服务器线程
    if (!my_tcpServer->listen(QHostAddress::Any, 6666)) {
        qDebug() << "服务器监听失败：" << my_tcpServer->errorString();
    } else {
        qDebug() << "服务器正在监听端口 6666";
    }


    /*启动定时器*/
    my_timer =  new QTimer(this);
    connect(my_timer,SIGNAL(timeout()),this,SLOT(slot_timeout()));
    my_timer->start(1000);

    QTimer *checkTimer = new QTimer(this);
    connect(checkTimer, &QTimer::timeout, this, [this]() {
        QTime currentTime = QTime::currentTime();
        if (currentTime.hour() == 19 && currentTime.minute() ==56) {
            //滑动按钮
            wid_DeviceCurtain->my_Slider_btn = new SliderButton(this);
            wid_DeviceCurtain->my_Slider_btn->set_button_color(QColor(36,110,202),QColor(188,188,188),QColor(255,255,255));
            wid_DeviceCurtain->my_Slider_btn->set_button_size(30,40);
            wid_DeviceCurtain->my_Slider_btn->move(230,15);
            wid_DeviceCurtain->my_Slider_btn->setButtonStatus(true);
            qDebug() << "时间匹配，打开百叶窗";
            wid_DeviceCurtain->openCurtain(); // 打开百叶窗
            wid_DeviceCurtain->setCurtainPercentage(60);
            qDebug()<<"百叶窗打开到：60%";

            //打开风扇
            wid_DeviceFan->openfan();

            //打开灯
            wid_DeviceLamp->openlamp();

            //打开空调
            wid_DeviceAC->openslider();
            wid_DeviceAC->my_digitalScroller->setCurValue(25);
            wid_DeviceAC->setModeAndSpeed("自动","小风");
        }
    });
    checkTimer->start(60 * 1000); // 每分钟检查一次
    qDebug() << "定时器已启动，每分钟检查一次时间";



    /*空调窗口*/
    wid_DeviceAC = new DeviceAC(LIVINGROOM,this);
    connect(wid_DeviceAC,SIGNAL(sig_sendData(int,QString)),my_tcpServer,SLOT(slot_deviceSendData(int,QString)));
    wid_DeviceAC->move(660,220);

    /*百叶窗窗口*/
    wid_DeviceCurtain = new DeviceCurtain(LIVINGROOM,this);
    connect(wid_DeviceCurtain,SIGNAL(sig_sendData(int,QString)),my_tcpServer,SLOT(slot_deviceSendData(int,QString)));
    wid_DeviceCurtain->move(1050,220);

    /*吊灯窗口*/
    wid_DeviceLamp = new DeviceLamp(LIVINGROOM,this);
    connect(wid_DeviceLamp,SIGNAL(sig_sendData(int,QString)),my_tcpServer,SLOT(slot_deviceSendData(int,QString)));
    wid_DeviceLamp->move(330,220);

    /*风扇窗口*/
    wid_DeviceFan = new DeviceFan(LIVINGROOM,this);
    connect(wid_DeviceFan,SIGNAL(sig_sendData(int,QString)),my_tcpServer,SLOT(slot_deviceSendData(int,QString)));
    wid_DeviceFan->move(330,530);



    /* 设置样式*/
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background,QBrush(QPixmap("://png/background.png")));
    setPalette(pal);

    ui->label_headpic->setStyleSheet("border-image:url(:/png/head.png)");
    ui->label_headpic->setText("");

    ui->frame_left->setStyleSheet("#frame_left{background-color:rgba(0,0,0,70%);}");

    ui->label_keting->setStyleSheet("color:#FFFFFF");
    ui->label_time_1->setStyleSheet("color:#FFFFFF");
    ui->label_time_2->setStyleSheet("color:#FFFFFF");
    ui->label_status->setStyleSheet("color:#FFFFFF");

     ui->label_fenge->setFixedWidth(3);
     ui->label_fenge->setText("");
    ui->label_fenge->setStyleSheet("background-color:#FFFFFF");

    ui->label_info->setStyleSheet("color:rgba(255,255,255,200)");


    /*获取时间*/
    ui->label_time_1->setText(QTime::currentTime().toString("hh:mm"));
    ui->label_time_2->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd ddd"));





//    //为模式添加按钮
//    QPushButton *btnHomeMode = new QPushButton("回家模式", this);
//    btnHomeMode->setGeometry(50, 50, 120, 40);
//    connect(btnHomeMode, &QPushButton::clicked, this, [this]() {
//        activateMode("回家模式");
//    });

//    QPushButton *btnAwayMode = new QPushButton("离家模式", this);
//    btnAwayMode->setGeometry(50, 100, 120, 40);
//    connect(btnAwayMode, &QPushButton::clicked, this, [this]() {
//        activateMode("离家模式");
//    });
//    QPushButton *btnsleepMode=new QPushButton("睡眠模式",this);
//    btnsleepMode->setGeometry(50,150,120,40);
//    connect(btnsleepMode,&QPushButton::clicked,this,[this](){
//        activateMode("睡眠模式");
//    });


    //模式选择下拉框设置
    QComboBox * comboMode=new QComboBox(this);
    comboMode->setGeometry(20,220,100,30);//(50,220,150,30);
    comboMode->addItems({"回家模式","离家模式","睡眠模式"});
    QPushButton *btnActivateMode=new QPushButton("激活模式",this);
    btnActivateMode->setGeometry(150,220,100,30);
    connect(btnActivateMode,&QPushButton::clicked,this,[this,comboMode](){
        QString selectedMode = comboMode->currentText();
        activateMode(selectedMode);
    });

    //定时选择模式
    QTimer *modeTimer = new QTimer(this);
    connect(modeTimer, &QTimer::timeout, this, [this]() {
        QTime currentTime = QTime::currentTime();
        if (currentTime.hour() == 19 && currentTime.minute() == 0) {
            activateMode("回家模式");
        } else if (currentTime.hour() == 8 && currentTime.minute() == 0) {
            activateMode("离家模式");
        }else if(currentTime.hour() == 23 && currentTime.minute() == 0) {
            activateMode("睡眠模式");
        }
    });
    modeTimer->start(60 * 1000); // 每分钟检查一次

    /***********************************
     *名称：slot_temp_value_channged
     *功能：添加自定义模式界面
     *说明：无
    ***********************************/



    QVBoxLayout *layout = new QVBoxLayout();

    QLabel *labelModeName = new QLabel("自定义模式名称：", this);
    labelModeName->setStyleSheet("QLabel { color: white; }");

    layout->addWidget(labelModeName);

    QLineEdit *lineEditModeName = new QLineEdit(this);
    lineEditModeName->setPlaceholderText("输入模式名称");
    layout->addWidget(lineEditModeName);

    QPushButton *btnSaveMode = new QPushButton("保存模式", this);
    layout->addWidget(btnSaveMode);

    QLabel *labelCustomModes = new QLabel("已保存的自定义模式：", this);
    labelCustomModes->setStyleSheet("QLabel { color: white; }");
    layout->addWidget(labelCustomModes);

    QComboBox *comboCustomModes = new QComboBox(this);
    layout->addWidget(comboCustomModes);

    QPushButton *btnActivateCustomMode = new QPushButton("激活模式", this);
    layout->addWidget(btnActivateCustomMode);

    QWidget *modeWidget = new QWidget(this);
    modeWidget->setLayout(layout);
    modeWidget->setGeometry(40, 250, 180, 200);

    // 连接信号槽（与上面相同）
    connect(btnSaveMode, &QPushButton::clicked, this, [this, lineEditModeName, comboCustomModes]() {
        QString modeName = lineEditModeName->text();
        if (modeName.isEmpty()) {
            qDebug() << "模式名称不能为空";
            return;
        }
        saveCustomMode(modeName);
        comboCustomModes->addItem(modeName);
        qDebug() << "模式已保存并添加到下拉框：" << modeName;
    });

    connect(btnActivateCustomMode, &QPushButton::clicked, this, [this, comboCustomModes]() {
        QString selectedMode = comboCustomModes->currentText();
        if (selectedMode.isEmpty()) {
            qDebug() << "未选择任何模式";
            return;
        }
        activateCustomMode(selectedMode);
        qDebug() << "模式已激活：" << selectedMode;
    });

    // 初始化状态显示区域
    statusLabel = new QLabel("当前状态：", this);
    statusLabel->setGeometry(270, -20, 400, 200);
    statusLabel->setStyleSheet("color: white; font-size: 16px;");

    // 定时更新状态
    QTimer *statusTimer = new QTimer(this);
    connect(statusTimer, &QTimer::timeout, this, [this]() {
        updateStatusDisplay();
    });
    statusTimer->start(1000); // 每秒更新一次



}
// 保存自定义模式
void Home::saveCustomMode(const QString &modeName)
{
    QVariantMap modeSettings;
    modeSettings["CurStatus"]=wid_DeviceCurtain->isCurOn();//百叶窗
    modeSettings["CurtainPercentage"] = wid_DeviceCurtain->getCurtainPercentage();

    modeSettings["FanStatus"] = wid_DeviceFan->isFanOn();//风扇
    modeSettings["LampStatus"] = wid_DeviceLamp->isLampOn();//灯

    modeSettings["AcStatus"]=wid_DeviceAC->isAcOn();
    modeSettings["ACTemperature"] = wid_DeviceAC->getCurValue();//空调
    modeSettings["ACMode"] =wid_DeviceAC-> getCurrentMode();
    modeSettings["ACSpeed"] = wid_DeviceAC->getCurrentSpeed();

    customModes[modeName] = modeSettings;
    qDebug() << "自定义模式已保存：" << modeName;
}

// 激活自定义模式
void Home::activateCustomMode(const QString &modeName)
{
    if (customModes.contains(modeName)) {
        QVariantMap modeSettings = customModes[modeName];

        wid_DeviceCurtain->setCurtainPercentage(modeSettings["CurtainPercentage"].toInt());
        if (modeSettings["FanStatus"].toBool())
        {
            wid_DeviceFan->openfan();
        } else {
            wid_DeviceFan->closefan();
        }
        if (modeSettings["LampStatus"].toBool()) {
            wid_DeviceLamp->openlamp();
        } else {
            wid_DeviceLamp->closelamp();
        }
        if(modeSettings["CurStatus"].toBool()){
            wid_DeviceCurtain->openCurtain();
        }else{
            wid_DeviceCurtain->closeCurtain();
        }
        if(modeSettings["AcStatus"].toBool()){
            wid_DeviceAC->openslider();
        }else{
            wid_DeviceAC->closeslider();
        }

        wid_DeviceAC->openslider();
        wid_DeviceAC->my_digitalScroller->setCurValue(modeSettings["ACTemperature"].toInt());
        wid_DeviceAC->setModeAndSpeed(modeSettings["ACMode"].toString(), modeSettings["ACSpeed"].toString());
        qDebug() << "自定义模式已激活：" << modeName;
    } else {
        qDebug() << "模式不存在：" << modeName;
    }
}
void Home::slot_timeout(void)
{
    /*获取时间*/
    ui->label_time_1->setText(QTime::currentTime().toString("hh:mm"));
    ui->label_time_2->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd ddd"));



    if(livingroom_status == CONNECT)
    {
        ui->label_status->setText("状态：在线");
    }else
    {
        ui->label_status->setText("状态：离线");
    }
}

//模式配置
void Home::activateMode(const QString &mode)
{
    if (mode.isEmpty()) {
            qDebug() << "无效的模式：" << mode;
            return;
        }
    if(mode=="回家模式"){
        //打开百叶窗到60%
        wid_DeviceCurtain->openCurtain();
        wid_DeviceCurtain->setCurtainPercentage(60);
        qDebug()<<"回家模式：百叶窗打开到60%";

        //打开风扇
        wid_DeviceFan->openfan();
        qDebug()<<"回家模式:风扇已打开";

        //打开灯
        wid_DeviceLamp->openlamp();
        qDebug()<<"回家模式： 灯已打开";

        //打开空调，温度设置为25°，模式为自动，小风
        wid_DeviceAC->openslider();
        wid_DeviceAC->my_digitalScroller->setVisible(25);
        wid_DeviceAC->setModeAndSpeed("自动","小风");
        qDebug()<<"回家模式：空调已开，温度设置为25°，模式为自动：小风";

    }else if(mode=="离家模式")
    {
        // 关闭百叶窗
        wid_DeviceCurtain->closeCurtain();
        qDebug() << "离家模式：百叶窗已关闭";

        // 关闭风扇
        wid_DeviceFan->closefan();
        qDebug() << "离家模式：风扇已关闭";

        // 关闭灯
        wid_DeviceLamp->closelamp();
        qDebug() << "离家模式：灯已关闭";

        // 关闭空调
        wid_DeviceAC->closeslider();
        qDebug() << "离家模式：空调已关闭";
    } else if(mode=="睡眠模式"){
        // 关闭百叶窗
        wid_DeviceCurtain->setCurtainPercentage(1);
        wid_DeviceCurtain->closeCurtain();
        qDebug() << "睡眠模式：百叶窗已关闭";

        // 关闭风扇
        wid_DeviceFan->closefan();
        qDebug() << "睡眠：风扇已关闭";

        // 关闭灯
        wid_DeviceLamp->closelamp();
        qDebug() << "睡眠：灯已关闭";

        // 打开i空调，小风，28°
        wid_DeviceAC->openslider();
        wid_DeviceAC->my_digitalScroller->setVisible(28);
        wid_DeviceAC->setModeAndSpeed("自动","小风");
         qDebug()<<"睡眠模式：空调已开，温度设置为28°，模式为自动：小风";

    }else {
        qDebug() << "未知模式：" << mode;
    }

}
//自定义模式：允许用户通过界面选择设备的状态，并保存为自定义模式。
//状态显示：增加一个状态显示区域，实时显示当前模式和设备状态。
//远程控制：结合网络通信模块，实现通过手机或其他设备远程切换模式。
Home::~Home()
{
    delete ui;
}
// 更新状态显示
void Home::updateStatusDisplay()
{
    QString status = "当前状态：\n";
    status += QString("百叶窗：%1%\n").arg(wid_DeviceCurtain->getCurtainPercentage());
    status += QString("风扇：%1\n").arg(wid_DeviceFan->isFanOn() ? "打开" : "关闭");
    status += QString("灯：%1\n").arg(wid_DeviceLamp->isLampOn() ? "打开" : "关闭");
    status += QString("空调：%1°，模式：%2，风速：%3\n")
                  .arg(wid_DeviceAC->getCurValue())
                  .arg(wid_DeviceAC->getCurrentMode())
                  .arg(wid_DeviceAC->getCurrentSpeed());
    statusLabel->setText(status);
}

//远程连接功能
void Home::handleRemoteCommand(const QString &command)
{
    QString decodedCommand = QString::fromUtf8(command.toUtf8()); // 确保解码为 UTF-8 字符串
    if (command.startsWith("MODE:")) {
        QString modeName = command.mid(5).trimmed();
        if (customModes.contains(modeName)) {
            activateCustomMode(modeName);
            my_tcpServer->sendDataToClient("激活自定义模式：" + modeName);
            qDebug() << "远程激活自定义模式：" << modeName;
        } else {
            activateMode(modeName);
            my_tcpServer->sendDataToClient("激活预定义模式：" + modeName);
            qDebug() << "远程激活预定义模式：" << modeName;
        }
    } else if (command == "GET_STATUS") {
        QString status = getDeviceStatus();
        my_tcpServer->sendDataToClient(status);
        qDebug() << "远程获取状态：" << status;
    } else {
        my_tcpServer->sendDataToClient("未知命令：" + command);
        qDebug() << "未知命令：" << command;
    }
}

//提取设备状态的逻辑为单独的函数，便于复用。
QString Home::getDeviceStatus() const
{
    QString status = "STATUS:\n";
    status += QString("Curtain:%1%\n").arg(wid_DeviceCurtain->getCurtainPercentage());
    status += QString("Fan:%1\n").arg(wid_DeviceFan->isFanOn() ? "ON" : "OFF");
    status += QString("Lamp:%1\n").arg(wid_DeviceLamp->isLampOn() ? "ON" : "OFF");
    status += QString("AC:%1°,%2,%3\n")
                  .arg(wid_DeviceAC->getCurValue())
                  .arg(wid_DeviceAC->getCurrentMode())
                  .arg(wid_DeviceAC->getCurrentSpeed());
    return status;
}
