#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H

#include <QThread>
#include <QHostAddress>

class QTcpSocket;

class SocketThread : public QThread
{
    Q_OBJECT
public:
    SocketThread(qintptr descriptor, QObject *parent = 0);
    ~SocketThread();

protected:
    void run() Q_DECL_OVERRIDE;

signals:
    void onFinishRecieved( const QString &fileName, const QHostAddress &host, const quint16 port );

private slots:
    void onReadyRead();
    void onDisconnected();

private:
    qintptr     m_socketDescriptor;
    QTcpSocket *m_socket;
    qint32      m_blockSize;

};

#endif // SOCKETTHREAD_H
