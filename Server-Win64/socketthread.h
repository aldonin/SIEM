#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H

#include <QThread>


class QTcpSocket;

class SocketThread : public QThread
{
    Q_OBJECT
public:
    SocketThread(qintptr descriptor, QObject *parent = 0);
    ~SocketThread();

protected:
    void run() Q_DECL_OVERRIDE;

private slots:
    void onReadyRead();
    void onDisconnected();

private:
    qintptr     m_socketDescriptor;
    QTcpSocket *m_socket;
    qint32      m_blockSize;

};

#endif // SOCKETTHREAD_H
