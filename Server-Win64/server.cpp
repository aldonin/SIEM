#include "server.h"
#include "socketthread.h"
#include "xmlreader.h"

#include <QDebug>


using namespace Constants::Time;

Server::Server(QHostAddress host, quint16 port, QObject *parent)
    : QTcpServer(parent),
      m_host(host),
      m_port(port)
{
    qRegisterMetaType<QList<JournalEvent*> >();
}

Server::~Server()
{
    qDebug() << "~Server";
}

void Server::start()
{
    if ( this->listen(m_host, m_port) )
        qDebug() << "Server started!";
    else
        qDebug() << "Can't start server";
}

void Server::updateSettings()
{
    //TODO проверять изменились ли host and port и если надо перезапускать сервак
}

void Server::incomingConnection(qintptr handle)
{
    qDebug() << "incomingConnection = " << handle;
    SocketThread *thread = new SocketThread(handle);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    connect(thread, SIGNAL(onFinishRecieved(QString, QString, quint16)),
            this,   SLOT(handleXml(QString, QHostAddress, quint16)));

    thread->start();
}

void Server::handleXml(const QString &fileName, const QHostAddress &host, const quint16 port)
{
    XmlReader *reader = new XmlReader(fileName);
    reader->setHostAddres(host);
    reader->setPortAddres(port);

    QThread *thread = new QThread;
    reader->moveToThread(thread);

    connect(thread, SIGNAL(started()),                      reader, SLOT(processXml()));
    connect(reader, SIGNAL(finished(QList<JournalEvent*>)), thread, SLOT(quit()));
    connect(reader, SIGNAL(finished(QList<JournalEvent*>)), reader, SLOT(deleteLater()));
    connect(reader, SIGNAL(finished(QList<JournalEvent*>)), this,   SLOT(writeToDataBase(QList<JournalEvent*>)));
    connect(thread, SIGNAL(finished()),                     thread, SLOT(deleteLater()));

    thread->start();
}

void Server::writeToDataBase( QList<JournalEvent *> lst )
{
    qDebug() << lst.size();
}

