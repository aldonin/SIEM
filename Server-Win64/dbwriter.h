#ifndef DBWRITER_H
#define DBWRITER_H

#include <QObject>

class JournalEvent;

/*!
 * \brief Database Writer class
 *
 * Use for commit journal events to BD.
 * \sa JournalEvent
 */
class DbWriter : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief Default constructor.
     * \param list List journal events
     * \param parent QObject parent pointer
     *
     * At source initialize database connection name.
     * \sa m_connectionName
     * \sa JournalEvent
     */
    explicit DbWriter(QList<JournalEvent*> list, QObject *parent = 0);

    /*!
     * \brief Destructor of class
     *
     * Removes the database connection connectionName from the list of database connections.
     * \sa m_connectionName
     */
    ~DbWriter();

signals:
    /*!
     * \brief Finish commit signal.
     *
     * This signal is emited when commit to database is end.
     * \sa push()
     */
    void finished();

public slots:
    /*!
     * \brief Push init list of events to database.
     *
     * At source of current slot call SVMPredictor to predict danger of events.
     * After finished of commit finished() signal emited.
     * \sa finished()
     * \sa SVMPredictor
     * \sa JournalEvent
     */
    void push();

private:
    /*!
     * \brief List of initialized at constructor set of JournalEvents.
     * \sa JournalEvent
     */
    QList<JournalEvent*> m_list;

    /*!
     * \brief Unique name for db connection.
     *
     * Generated at constructor of class by using current DateTime and QUuid class.
     * \sa DbWriter
     */
    QString m_connectionName;
};

#endif // DBWRITER_H
