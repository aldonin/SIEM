#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>

class QThreadPool;

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    ~Server();

    void start();

protected:
    void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;

private:
};

#endif // SERVER_H
