#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>

#include "journalevent.h"
#include "constants.h"

/*!
 * \brief Tcp server class.
 *
 * Represent multithreading Tcp server for handling incoming connections.
 * Start for listening on specified host and port.
 * Provide function for connecting recieving files, handling xmls and write them to database.
 * \sa DbWriter
 * \sa SocketThread
 * \sa XmlReader
 */
class Server : public QTcpServer
{
    Q_OBJECT
public:
    /*!
     * \brief Default constructor.
     * \param host Host for listening, as default value Any
     * \param port Listening port, as default DEFAULT_PORT
     * \param parent QObject parent pointer.
     * \sa Constants::Server
     *
     * Init server settings: host and port.
     */
    explicit Server(QHostAddress host = QHostAddress::Any,
                    quint16 port      = Constants::Server::DEFAULT_PORT,
                    QObject *parent   = 0);
    /*!
     * Free resources.
     */
    ~Server();

public slots:
    /*!
     * \brief Start server.
     *
     * Start server on specified host and port.
     * \sa Server
     */
    void start();
    /*!
     * \brief Update settings from QSettings.
     *
     * This slot call when user update settings from settings widget.
     * \sa SettingsWidget
     */
    void updateSettings();

protected:
    /*!
     * \brief Handle incoming server connection.
     * \param handle Incoming connection descriptor
     *
     * For each incoming connection created new SocketThread at individual thread and it event loop.
     * After received file handle by XmlReader.
     * \note This is overriding function.
     * \sa SocketThread
     * \sa handleXml()
     */
    void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;

private slots:
    /*!
     * \brief Parsing incoming from SocketThread xml.
     * \param fileName Incoming file name
     * \param host Incoming host
     * \param port Incoming port
     *
     * Start XmlRead at individual thread for parsing xml.
     * After handling parsed list of Journal Events handle by DbWriter.
     * \sa writeToDataBase()
     * \sa XmlReader
     */
    void handleXml( const QString &fileName, const QHostAddress &host, const quint16 port );
    /*!
     * \brief Commit handling list of journal events to database.
     *
     * Start DbWriter at individual thread for commit list of journals.
     * \sa DbWriter
     * \sa JournalEvent
     */
    void writeToDataBase( QList<JournalEvent *> );

private:
    QHostAddress m_host;    ///< Server listening host.
    quint16      m_port;    ///< Server listening port.

};

Q_DECLARE_METATYPE(QList<JournalEvent*>)
Q_DECLARE_METATYPE(QHostAddress)

#endif // SERVER_H
