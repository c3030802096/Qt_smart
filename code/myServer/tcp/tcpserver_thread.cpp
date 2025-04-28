#include "tcpserver_thread.h"

Tcpserver_Thread::Tcpserver_Thread(int sockID, QObject *parent) :
    QThread(parent)
{
    /*获取当前线程对应的客户端编号*/
    my_sockID = sockID;
}

Tcpserver_Thread::~Tcpserver_Thread()
{

}


void Tcpserver_Thread::run()
{

    qDebug() << my_sockID;
    /*新的客户端进来，需要建立一个socket对象来管理*/
    my_tcpscoket = new Tcpsocket(my_sockID);
    Global::curr_socket = my_sockID;


    if(!my_tcpscoket->setSocketDescriptor(my_sockID))
    {
        return;
    }
    //通知对应的线程客户端已经断开连接
    connect(my_tcpscoket,SIGNAL(disconnected()),this,SLOT(slot_disconnetToHost()));
    connect(this,SIGNAL(sig_sendToClientData(int,QByteArray)),my_tcpscoket,SLOT(slot_sendData(int,QByteArray)));

    qDebug() << "客户端：" << my_tcpscoket->peerAddress() << my_sockID << " 连接成功";

    //客户端第一次连接时，需发送一句查看名称的指令，告诉服务器当前客户端是谁。
    emit sig_sendToClientData(my_sockID,"<*03,00,01*>");
    this->exec();
}



void Tcpserver_Thread::slot_disconnetToHost(void)
{
    //通知服务器，本线程对应的socket客户端已经断开
    emit sig_disconnetTCP(my_sockID);

    if(g_socket_map.value(my_sockID) == LIVINGROOM)
    {
        livingroom_status = ERROR;
    }

    //销毁
    my_tcpscoket->disconnectFromHost();
    my_tcpscoket->destroyed();

    //结束该线程
    this->quit();

}

/***********************************
 *名称：slot_sendToClientData
 *功能：发送数据给对应的客户端
 *说明：无
***********************************/
void Tcpserver_Thread::slot_sendToClientData(int sockID,QString sendData)
{
    emit sig_sendToClientData(sockID,sendData.toUtf8());
}

