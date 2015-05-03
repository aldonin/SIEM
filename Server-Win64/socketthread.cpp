#include "socketthread.h"

#include <QTcpSocket>
#include <QFile>
#include <QDebug>

SocketThread::SocketThread(qintptr descriptor, QObject *parent)
    : QThread(parent), m_socketDescriptor(descriptor)
{
    qDebug() << "SocketThread(), thread = " << QThread::currentThreadId();
}

SocketThread::~SocketThread()
{
    qDebug() << "~SocketThread()";
    delete m_socket;
}

void SocketThread::run()
{
    m_socket = new QTcpSocket;
    m_socket->setSocketDescriptor(m_socketDescriptor);

    connect(m_socket, SIGNAL(readyRead()),    this, SLOT(onReadyRead()),    Qt::DirectConnection);
    connect(m_socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()), Qt::DirectConnection);

    exec();
}

void SocketThread::onReadyRead()
{
    qDebug() << "onReadyRead";


    QDataStream in(m_socket);
    in.setVersion(QDataStream::Qt_5_4);

    if (m_blockSize == 0) {
        if (m_socket->bytesAvailable() < sizeof(quint32))
        return;
        in >> m_blockSize;
    }
    if (m_socket->bytesAvailable() < m_blockSize)
        return;

    QString fileName;
    in >> fileName;
    qDebug() << fileName;
    QByteArray line = m_socket->readAll();
    QFile target("D:\\RECV___Application-29.04.2015_17-59-06.xml");
    if (!target.open(QIODevice::WriteOnly)) {
        qDebug() << "Can't open file for written";
        return;
    }
    target.write(line);

    target.close();

    qDebug() << "Finished!";

    m_socket->disconnectFromHost();

    qDebug() << "Disconnect!";
}

void SocketThread::onDisconnected()
{
    m_socket->close();

    // Выход из цикла обработки событий
    quit();
}

