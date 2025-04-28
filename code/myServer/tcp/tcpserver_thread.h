#ifndef TCPSERVER_THREAD_H
#define TCPSERVER_THREAD_H

#include <QThread>
#include <QDebug>
#include "tcp/tcpsocket.h"

#include "my_custom/global.h"


class Tcpserver_Thread : public QThread
{
    Q_OBJECT
public:
    explicit Tcpserver_Thread(int sockID, QObject *parent = 0);
    
    ~Tcpserver_Thread();


private:
    int my_sockID;//属于每个客户端（socket）自己唯一的端口号，用于身份识别

    Tcpsocket* my_tcpscoket;

signals:
    void sig_disconnetTCP(int sockID);

    void sig_sendToClientData(int,QByteArray);


private slots:
    void slot_disconnetToHost(void);

    void slot_sendToClientData(int sockID,QString sendData);


protected:
    void run();
    
};

#endif // TCPSERVER_THREAD_H

