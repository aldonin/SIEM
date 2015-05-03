#include "server.h"
#include "constants.h"
#include "socketthread.h"
#include <QThreadPool>
#include <QDebug>

using namespace Constants::Time;

Server::Server(QObject *parent)
    : QTcpServer(parent)
{
}

Server::~Server()
{
    qDebug() << "~Server";
}

void Server::start()
{
    if ( this->listen(QHostAddress::Any, 2323) )
        qDebug() << "Server started!";
    else
        qDebug() << "Can't start server";
}

void Server::incomingConnection(qintptr handle)
{
    qDebug() << "incomingConnection = " << handle;
    SocketThread *thread = new SocketThread(handle);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}

