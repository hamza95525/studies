#include "socket.h"
#include <QDebug>
#include <QTextStream>

Socket::Socket(QTcpSocket *sock) : tcpSocket(sock)
{
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(onReceivedData()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(onDisconnect()));
    qDebug()<<"Hello!";
}

Socket::~Socket(){
    qDebug()<<"Bye!";
}

void Socket::onReceivedData()
{
    QTextStream stream(tcpSocket);
    QString text;
    stream>>text;
    stream<<text.toUpper()<<"\n";
}

void Socket::onDisconnect()
{
    tcpSocket->deleteLater();
    delete this;
}
