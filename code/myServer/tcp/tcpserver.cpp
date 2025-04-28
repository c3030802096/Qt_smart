#include "tcpserver.h"

Tcpserver::Tcpserver(QObject *parent) :
    QTcpServer(parent)
{

}

Tcpserver::~Tcpserver()
{

}

///*实时监控客户端连接*/
//void Tcpserver::incomingConnection(qintptr sockID)
//{
//    qDebug()<<"1111111111111111";
//    Tcpserver_Thread * my_tcpserver_thread = new Tcpserver_Thread(sockID);
//    connect(this,SIGNAL(sig_sendToClinet(int,QString)),my_tcpserver_thread,SLOT(slot_sendToClientData(int,QString)));

//    my_tcpserver_thread->start();

//}

void Tcpserver::slot_client_disconnected(int sockID)
{
    Q_UNUSED(sockID);
}

void Tcpserver::slot_deviceSendData(int sockID,QString sendData)
{
    //将数据发送给对应的客户端
    emit sig_sendToClinet(sockID,sendData);
}

void Tcpserver::sendDataToClient(const QString &data)
{
    // 遍历所有连接的客户端并发送数据
    for (QTcpSocket *client : clients) { // 假设你有一个存储所有客户端连接的列表 `clients`
        if (client->state() == QTcpSocket::ConnectedState) {
            client->write(data.toUtf8());
            client->flush();
        }
    }
}

//void Tcpserver::incomingConnection(qintptr socketDescriptor)
//{
//    QTcpSocket *clientSocket = new QTcpSocket(this);
//    clientSocket->setSocketDescriptor(socketDescriptor);
//    clients.append(clientSocket);

//    connect(clientSocket, &QTcpSocket::disconnected, this, [this, clientSocket]() {
//        clients.removeAll(clientSocket);
//        clientSocket->deleteLater();
//    });

//    qDebug() << "新客户端连接：" << socketDescriptor;
//}

void Tcpserver::incomingConnection(qintptr sockID)
{
    qDebug() << "新客户端连接：" << sockID;

    // 创建一个新的线程处理客户端连接
    Tcpserver_Thread *my_tcpserver_thread = new Tcpserver_Thread(sockID);

    // 创建一个 QTcpSocket 对象并设置 socket 描述符
    QTcpSocket *clientSocket = new QTcpSocket(this);
    clientSocket->setSocketDescriptor(sockID);
    clients.append(clientSocket); // 将客户端 socket 添加到列表中

    // 处理客户端断开连接
    connect(clientSocket, &QTcpSocket::disconnected, this, [this, clientSocket]() {
        clients.removeAll(clientSocket);
        clientSocket->deleteLater();
        qDebug() << "客户端断开连接：" << clientSocket;
    });

    // 将信号连接到线程的槽函数
    connect(this, SIGNAL(sig_sendToClinet(int, QString)), my_tcpserver_thread, SLOT(slot_sendToClientData(int, QString)));

    // 启动线程
    my_tcpserver_thread->start();
}
