#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>

class Server : public QObject
{
    Q_OBJECT
private:
    QTcpServer *server;
public:
    explicit Server(QObject *parent = nullptr);

signals:

public slots:
    void makeNewConnection();
};

#endif // SERVER_H
