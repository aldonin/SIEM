#include "server.h"
#include "constants.h"
#include "socketthread.h"
#include "xmlreader.h"

#include <QDebug>


using namespace Constants::Time;

Server::Server(QObject *parent)
    : QTcpServer(parent)
{
    qRegisterMetaType<QList<JournalEvent*> >();
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

    connect(thread, SIGNAL(onFinishRecieved(QString,QString,quint16)),
            this,   SLOT(handleXml(QString,QString,quint16)));

    thread->start();
}

void Server::handleXml(const QString &fileName, const QString &host, const quint16 port)
{
    qDebug() << "HandleXMl";
    XmlReader *reader = new XmlReader(fileName);
    reader->setHostAddres(host);
    reader->setPortAddres(port);

    QThread *thread = new QThread;
    reader->moveToThread(thread);

    connect(thread, SIGNAL(started()),                       reader, SLOT(processXml()));
    connect(reader, SIGNAL(finished(QList<JournalEvent*>)), thread, SLOT(quit()));
    connect(reader, SIGNAL(finished(QList<JournalEvent*>)), reader, SLOT(deleteLater()));
    connect(reader, SIGNAL(finished(QList<JournalEvent*>)), this,   SLOT(writeToDataBase(QList<JournalEvent*>)));
    connect(thread, SIGNAL(finished()),                      thread, SLOT(deleteLater()));

    // TODO добавить слот на обработку finished(QList) для пушера в базу данных

    thread->start();
}

void Server::writeToDataBase( QList<JournalEvent *> lst )
{
    qDebug() << lst.size();
}

