#include "server.h"
#include<QDebug>
#include "socket.h"
Server::Server(QObject *parent) : QObject(parent)
{
    server = new QTcpServer();
    server->listen(QHostAddress::Any,8000);
    connect(server,SIGNAL(newConnection()),this,SLOT(makeNewConnection()));
}
void Server::makeNewConnection()
{
    new Socket(server->nextPendingConnection());
}
