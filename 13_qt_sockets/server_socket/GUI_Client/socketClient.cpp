#include "socketClient.h"
SocketClient::SocketClient(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket();
    socket->connectToHost("localhost",8000);
    connect(socket,SIGNAL(readyRead()),this,SLOT(onReceivedData()));
}
void SocketClient::send(QString str)
{
    QTextStream stream(socket);
    stream<<str;
}
QString SocketClient::get()
{
    QTextStream stream(socket);
    QString text;
    stream>>text;
    return text;
}
void SocketClient::onReceivedData()
{
    emit changed();
}
