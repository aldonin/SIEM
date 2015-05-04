#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>

#include "journalevent.h"


class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    ~Server();

    void start();

protected:
    void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;

private slots:
    void handleXml( const QString &fileName, const QString &host, const quint16 port );
    void writeToDataBase( QList<JournalEvent *> );
};

Q_DECLARE_METATYPE(QList<JournalEvent*>)

#endif // SERVER_H
