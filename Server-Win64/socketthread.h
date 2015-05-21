#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H

#include <QThread>
#include <QHostAddress>

class QTcpSocket;

/*!
 * \brief Socket Thread class.
 *
 * Inherit QThread class. Implement funtion for recieving
 * file from Agent.
 *
 * Recieving file is occur by block specified blockSize.
 */
class SocketThread : public QThread
{
    Q_OBJECT
public:
    /*!
     * \brief Socket Thread constructor.
     * \param descriptor Incoming socket desctiptor.
     * \param parent QObject parent.
     */
    SocketThread(qintptr descriptor, QObject *parent = 0);
    /*!
     *  \brief Free resources. Delete socket.
     */
    ~SocketThread();

protected:
    /*!
     * \brief Run method of QThread. Start thread.
     *
     * Create new QTcpSocket with specified socket descriptor.
     * \note Overriding funtion of QThread class.
     * \note Start own event loop.
     * \sa onDisconnected()
     */
    void run() Q_DECL_OVERRIDE;

signals:
    /*!
     * \brief Finished recieve signal.
     * \param fileName Recieved file name.
     * \param host  Source host.
     * \param port  Source port.
     *
     * Emited after transfer file was recieved.
     */
    void onFinishRecieved( const QString &fileName, const QHostAddress &host, const quint16 port );

private slots:
    /*!
     * \brief Ready read socket slot.
     *
     * Implement function for recieving data when it is ready for transfer.
     */
    void onReadyRead();
    /*!
     * \brief Disconect socket from host slot.
     *
     * Close socket.
     * Finish event loop of SocketThread.
     */
    void onDisconnected();

private:
    qintptr     m_socketDescriptor;      ///< Incoming from server socket descriptor.
    QTcpSocket *m_socket;                ///< Tcp socket for recieving file.
    qint32      m_blockSize;             ///< Max size of block socket able to recieved.

};

#endif // SOCKETTHREAD_H
