#include "server.h"
#include "socketthread.h"
#include "xmlreader.h"
#include "dbwriter.h"

#include <QDebug>
#include <QSettings>


using namespace Constants::Time;

Server::Server(QHostAddress host, quint16 port, QObject *parent)
    : QTcpServer(parent),
      m_host(host),
      m_port(port)
{
    qRegisterMetaType<QList<JournalEvent*> >();
    qRegisterMetaType<QHostAddress>();
}

Server::~Server()
{
    qDebug() << "~Server";
}

void Server::start()
{
    if ( this->listen(m_host, m_port) )
        qDebug() << "Server started at " << m_host.toString() << ":" << m_port;
    else
        qDebug() << "Can't start server";
}

void Server::updateSettings()
{
    QSettings settings;
    settings.beginGroup("Server");
    QString host = settings.value("Host", QVariant(Constants::Server::DEFAULT_HOST.toString())).toString();
    quint16 port = settings.value("Port", QVariant(Constants::Server::DEFAULT_PORT)).toUInt();
    settings.endGroup();

    /* Достаточно интересно, почему мы сравниваем QString'и хостов, а не сами экземляры классов.
        Почему-то, а возможно и понятно почему, QHostAddress::Any при конвертации в QString дает "0.0.0.0",
        но при конвертации из "0.0.0.0" он не понимает, что это Any.
        Поэтому приходится из настроек принимать не QHostAddress, а QString и при проверке
        сравнивать не m_host, а m_host.toString().
    */
    if (port != m_port || host != m_host.toString()) {

        // Stop server listening
        this->close();
        // Update values
        m_port = port;
        m_host = host;
        // Start server for listening
        this->start();
    }
}

void Server::incomingConnection(qintptr handle)
{
    qDebug() << "incomingConnection = " << handle;
    SocketThread *thread = new SocketThread(handle);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    connect(thread, SIGNAL(onFinishRecieved(QString, QHostAddress, quint16)),
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
    DbWriter *writer = new DbWriter(lst);
    QThread  *thread = new QThread;

    writer->moveToThread(thread);

    connect(thread, SIGNAL(started()),  writer, SLOT(push()));
    connect(writer, SIGNAL(finished()), thread, SLOT(quit()));
    connect(writer, SIGNAL(finished()), writer, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}

