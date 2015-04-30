#include "filesender.h"
#include <QTcpSocket>
#include <QFile>
#include <QSettings>
#include "globalnamespace.h"

FileSender::FileSender(QString fileName,QObject *parent) :
    QObject(parent)
{
    m_file = new QFile(fileName);

    QSettings settings;
    settings.beginGroup("server");
    m_host = settings.value("host", QVariant(DEFAULT_HOST_NAME)).toString();
    m_port = settings.value("port", QVariant(DEFAULT_PORT)).toUInt();
    settings.endGroup();
}

FileSender::~FileSender()
{
    qDebug() << "~FileSender";
    delete m_file;
}

void FileSender::send()
{
    QTcpSocket *socket = new QTcpSocket;

    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    socket->connectToHost(m_host, m_port);
    socket->waitForConnected();

    if ( (socket->state() != QAbstractSocket::ConnectedState) || (!m_file->open(QIODevice::ReadOnly)) ) {
        qDebug() << "Socket can't connect or can't open file for transfer";
        delete socket;
        emit finished( m_file->fileName() );
        return;
    }

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_4);
    out << (quint32)0 << m_file->fileName();

    QByteArray q = m_file->readAll();
    block.append(q);
    m_file->close();

    out.device()->seek(0);
    out << (quint32)(block.size() - sizeof(quint32));

    qint64 x = 0;
    while (x < block.size()) {
        qint64 y = socket->write(block);
        x += y;
        qDebug() << x;
    }
}

void FileSender::disconnected()
{
    emit finished( m_file->fileName() );
    qDebug() << "disconnected!";
}

