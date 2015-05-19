#ifndef FILESENDER_H
#define FILESENDER_H

#include <QObject>

class QFile;

/*!
 * \brief Designed for transfering files.
 *
 * This class send file through Tcp protocol at specified host.
 */
class FileSender : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief FileSender class constructor.
     * \param fileName full path name to transfering file.
     * \param parent QObject parent.
     *
     * At constructor initialize receiver's host and port stored at QSettings.
     * Create file for sending based on file name param.
     */
    explicit FileSender(QString fileName, QObject *parent = 0);


    /*!
     * \brief Class destructor.
     *
     * Free sending file resources.
     */
    ~FileSender();

signals:
    /*!
     * \brief Finished signal.
     * \param fileName full path name to transfering file.
     *
     * This signal emited when file stransfering was finished.
     */
    void finished(const QString &fileName);

public slots:
    /*!
     * \brief Send file on specified host and port.
     *
     * At this slots open file for reading transfering information, open Tcp socket and try to
     * connect at specified host and port. After we initialize block and while transfer data more
     * than block part of file size of block will send.
     *
     * \warning Sending may be failed if transfering file not open or socket can't connect to host. Whatever
     * in this case finished() signal will be emited.
     *
     * \sa finished();
     */
    void send();

    /*!
     * \brief Disconnected slot from host.
     *
     * This slot emit finished() signal.
     *
     * \sa finished();
     */
    void disconnected();

private:
    /*!
     * \brief Sending file.
     */
    QFile *m_file;

    /*!
     * \brief Receiver's port.
     */
    quint16 m_port;

    /*!
     * \brief Receiver's host.
     */
    QString m_host;
};

#endif // FILESENDER_H
