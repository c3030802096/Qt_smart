#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化TcpSocket
    socket = new QTcpSocket();
    //取消原有连接
    socket->abort();



}

MainWindow::~MainWindow()
{
    delete this->socket;
    delete ui;
}

void MainWindow::on_Btn_Connect_clicked()
{
    if(ui->Btn_Connect->text() == tr("连接") && socket->state() != QTcpSocket::ConnectedState )
    {

//        if (socket->state() == QTcpSocket::ConnectedState) {
//            qDebug() << "客户端连接成功";
//        } else {
//            qDebug() << "客户端连接失败：" << socket->errorString();
//        }
        //获取IP地址
        QString IP = ui->lineEdit_IP->text();
//        qDebug()<<IP;
        //获取端口号
        int port = ui->lineEdit_Port->text().toInt();
//        qDebug()<<port;

        connect(socket, &QTcpSocket::readyRead, this, &MainWindow::Read_Data);
        connect(socket, &QTcpSocket::stateChanged, this, &MainWindow::onStateChanged);
        connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onErrorOccurred()));

        //取消原有连接
        socket->abort();
        //连接服务器
        socket->connectToHost(IP, port);

        //等待连接成功
        if(!socket->waitForConnected(3000))
        {
            return;
        }
        else {
            ui->Btn_Connect->setText("断开\n连接");


            //QMessageBox::information(this, "提示", "连接成功", QMessageBox::Yes);
            QString curr_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:");
            ui->textEdit->append(curr_time + "连接成功！");
        }
    }
    else
    {
        QString curr_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:");
        ui->textEdit->append(curr_time + "断开连接！");
        //断开连接
        socket->disconnectFromHost();
        //修改按键文字
        ui->Btn_Connect->setText("连接");
        return;
    }
}

void MainWindow::onStateChanged(int state)
{
    if (state == QTcpSocket::UnconnectedState) {
        ui->Btn_Connect->setText("连接");
    }
    else if (state == QTcpSocket::ConnectedState) {
        ui->Btn_Connect->setText("断开连接");
    }
}

void MainWindow::onErrorOccurred()
{
//    QMessageBox::information(this, "错误", socket->errorString(), QMessageBox::Yes);
    QString curr_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:");
    ui->textEdit->append(curr_time + "错误信息" + socket->errorString());
}

void MainWindow::Read_Data()
{
    QByteArray buffer;
    //读取缓冲区数据
    buffer = socket->readAll();
//    qDebug() << buffer;

    if(!buffer.isEmpty())
    {
//        QMessageBox::information(this, "收到消息", buffer, QMessageBox::Yes);
        qDebug() << "收到服务器数据：" <<buffer;
    }


    QString valid_data;//有效数据
    QStringList lst_valid_data;
    int func;           //功能码，设置/读取
    int reg;            //寄存器位置
    int data;       //设置或读取的数据
    /*通信协议解析，格式<*03,00,00*>*/
    if(buffer.left(2) == "<*" && buffer.right(2) == "*>"&& buffer.count(",") == 2)
    {
        valid_data = buffer.replace("<*","");
        valid_data = buffer.replace("*>","");
        lst_valid_data = valid_data.split(",");
        qDebug() << lst_valid_data;
        func = lst_valid_data.at(0).toInt();
        reg = lst_valid_data.at(1).toInt();
        data = lst_valid_data.at(2).toInt();

        QString curr_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:");
        if(func == 03)//查询数据
        {
            if((reg == 0) && (data == 1))//查看00寄存器的数据
            {
                QString data = "<*03,00,00*>";//0表示当前为客厅，1为卧室
                qDebug() << "发送数据：" << data;
                socket->write(data.toLatin1());
            }
        }else if(func == 06)//设置数据
        {

            //吊灯的功能
            if((reg == 100) && (data == 0))
            {
                ui->textEdit->append(curr_time + "关闭吊灯");
            }else if((reg == 100) && (data == 1) )
            {
                ui->textEdit->append(curr_time + "开启吊灯");
            }

            //风扇的功能
            if((reg == 101) && (data == 0))
            {
                ui->textEdit->append(curr_time + "关闭风扇");
            }else if((reg == 101) && (data == 1) )
            {
                ui->textEdit->append(curr_time + "开启风扇");
            }

            //空调的功能
            if((reg == 102) && (data == 0))
            {
                ui->textEdit->append(curr_time + "关闭空调");
            }else if((reg == 102) && (data == 1) )
            {
                ui->textEdit->append(curr_time + "开启空调");
            }
            if(reg == 103)
            {
                ui->textEdit->append(curr_time + "设置空调温度为：" + QString::number(data));
            }else if(reg == 104)
            {
                QString mode;
                switch (data) {
                case 0:
                    mode = "自动";
                    break;
                case 1:
                    mode = "除湿";
                    break;
                case 2:
                    mode = "制冷";
                    break;
                case 3:
                    mode = "送风";
                    break;
                default:
                    break;
                }
                ui->textEdit->append(curr_time + "设置空调模式为：" + mode);
            }else if(reg == 105)
            {
                QString wind;
                switch (data) {
                case 0:
                    wind = "小风";
                    break;
                case 1:
                    wind = "低风";
                    break;
                case 2:
                    wind = "大风";
                    break;
                case 3:
                    wind = "猛风";
                    break;
                default:
                    break;
                }
                ui->textEdit->append(curr_time + "设置空调风速为：" + wind);
            }

            //百叶窗的功能
            if((reg == 106) && (data == 0))
            {
                ui->textEdit->append(curr_time + "关闭百叶窗");
            }else if((reg == 106) && (data == 1))
            {
                ui->textEdit->append(curr_time + "开启百叶窗");
            }
            if(reg == 107)
            {
                ui->textEdit->append(curr_time + "设置百叶窗打开范围为：" + QString::number(data) + "%");
            }

        }
    }

}


