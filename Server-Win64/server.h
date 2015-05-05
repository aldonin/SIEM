#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>

#include "journalevent.h"
#include "constants.h"


class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QHostAddress host = QHostAddress::Any,
                    quint16 port      = Constants::Server::DEFAULT_PORT,
                    QObject *parent   = 0);
    ~Server();

public slots:
    void start();
    void updateSettings();

protected:
    void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;

private slots:
    void handleXml( const QString &fileName, const QString &host, const quint16 port );
    void writeToDataBase( QList<JournalEvent *> );

private:
    QHostAddress m_host;
    quint16      m_port;

};

Q_DECLARE_METATYPE(QList<JournalEvent*>)

#endif // SERVER_H
