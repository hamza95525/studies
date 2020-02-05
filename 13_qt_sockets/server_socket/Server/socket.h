#ifndef SOCKET_H
#define SOCKET_H
#include <QObject>
#include <QTcpSocket>
class Socket : public QObject
{
    Q_OBJECT
private:
    QTcpSocket *tcpSocket;
    ~Socket();
public:
    Socket(QTcpSocket *sock);
signals:
public slots:
    void onReceivedData();
    void onDisconnect();
};
#endif // SOCKET_H
