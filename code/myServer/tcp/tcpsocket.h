#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QTcpSocket>
#include <QHostAddress>
#include <QStringList>

#include "my_custom/global.h"

class Tcpsocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit Tcpsocket(int sockID, QObject *parent = 0);
    ~Tcpsocket();

    void set_client_data(int reg,QString data);
    void read_client_data(int reg,QString data);

signals:
    void sig_dataReady(const QString &ip,const QByteArray &data);

public slots:
    void slot_recvData(void);
    void slot_sendData(int id, const QByteArray& data);

private:
    int my_sockID;//属于每个客户端自己唯一的端口号，用于身份识别
};

#endif // TCPSOCKET_H
