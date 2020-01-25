#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include <QTcpSocket>

class SocketClient : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text WRITE send READ get NOTIFY changed)
private:
    QTcpSocket *socket;
public:
    explicit SocketClient(QObject *parent = nullptr);
    void send(QString str);
    QString get();

signals:
    void changed();
public slots:
    void onReceivedData();
};

#endif // SOCKET_H
