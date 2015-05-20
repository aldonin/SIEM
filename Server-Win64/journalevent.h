#ifndef JOURNALEVENT_H
#define JOURNALEVENT_H

#include <QString>
#include <QObject>
#include <QHostAddress>
#include <QDateTime>


/*!
 * \brief Journal event class.
 *
 * Represent class for storage information about events fields like:
 * - Type of Journal
 * - Source host
 * - Source port
 * - Event ID
 * - Machine Name
 * - Data
 * - Index
 * - Category
 * - Category Number
 * - Entry Type
 * - Message
 * - Source
 * - InstanceId
 * - Time Generated
 * - Time Written
 */
class JournalEvent
{
    Q_ENUMS(EventLogEntryType)
    Q_ENUMS(JournalType)

public:
    /*!
     * \brief Default constructor
     */
    JournalEvent();
    /*!
     * \brief Destructor
     */
    ~JournalEvent();

    /*! Entry types. */
    enum EventLogEntryType {
        Information,        /*!< Information message */
        Error,              /*!< Error state */
        FailureAudit,       /*!< Failure access audit */
        SuccessAudit,       /*!< Success access audit */
        Warning             /*!< Warning message */
    };

     /*! Types of journals. */
    enum JournalType {
        Application,        /*!< Information about Application, driver or service job */
        Security,           /*!< Audit information */
        Setup,              /*!< Extra journals for domen controllers */
        System,             /*!< System and services events information */
        ForwardedEvents     /*!< Forwarded Events from another PC */
    };

    /*!
     * \brief Insert value to specified key.
     * \param key Field of Journal
     * \param value Inserted value
     * \return True if value inserted, otherwise false.
     *
     * Key and value param not specified by their type, method parse them from QString.
     */
    bool insert(const QString &key, const QString &value);


    int     getEventID() const;         //! \return Event ID as integer.
    QString getMachineName() const;     //! \return Machine name as QString.
    QString getData() const;            //! \return Data as QString.
    int     getIndex() const;           //! \return Index as integer
    QString getCategory() const;        //! \return Category as QString
    int     getCategoryNumber() const;  //! \return Category Number as integer
    int     getEntryType() const;       //! \return Entry type as integer, parse if from EventLogEntryType
    QString getMessage() const;         //! \return Message as QString
    QString getSource() const;          //! \return Source as QString
    int     getInstanceId() const;      //! \return Instance Id as integer
    QString getTimeGenerated() const;   //! \return Generated time as QString at format dd.MM.yyyy hh:mm:ss
    QString getTimeWritten() const;     //! \return Written time as QString at format dd.MM.yyyy hh:mm:ss


    QString getJournalType() const;             //! \return Journal type as QString, parsed from JournalType.
    JournalType getgetJournalTypeAsType() const;//! \return Journal type as JournalType without parsing.
    /*!
     * \brief Set new journal type to current object.
     * \param type New type.
     *
     * Call parsing from QString to JournalType and set value.
     */
    void setJournalType(const QString &type);

    /*!
     * \brief Get source port.
     * \return port
     */
    quint16 getPort() const;
    /*!
     * \brief Set source port.
     * \param port New port value.
     */
    void setPort(const quint16 &port);

    /*!
     * \brief Get source host.
     * \return host
     */
    QHostAddress host() const;
    /*!
     * \brief Set source host.
     * \param host New host value.
     */
    void setHost(const QHostAddress &host);

private:
    JournalType       type;             ///< Type of Journal.
    int               EventID;          ///< Event ID.
    QString           MachineName;      ///< Machine Name.
    QString           Data;             ///< Data.
    int               Index;            ///< Index.
    QString           Category;         ///< Category.
    int               CategoryNumber;   ///< Number of Category.
    EventLogEntryType EntryType;        ///< Type of Entry.
    QString           Message;          ///< Message.
    QString           Source;           ///< Source.
    int               InstanceId;       ///< Instance ID.
    QDateTime         TimeGenerated;    ///< Generated time.
    QDateTime         TimeWritten;      ///< Writtend time.

    QHostAddress m_host;                ///< Source host.
    quint16      m_port;                ///< Source port.

private:
    JournalEvent(const JournalEvent&);
    JournalEvent& operator=(const JournalEvent&);

private:
    /*!
     * \brief Conver QString to Entry Type
     * \param strType String for parsing.
     * \return Parsed EventLogEntryType value.
     * \note If parsing failure method return EventLogEntryType::Information type.
     * \sa EventLogEntryType
     */
    EventLogEntryType EntryTypefromString(const QString strType) const;
    /*!
     * \brief Conver QString to Journal Type
     * \param strType String for parsing.
     * \return Parsed JournalType value.
     * \note If parsing failure method return JournalType::Application type.
     * \sa JournalType
     */
    JournalType       JournalTypeFromString(const QString strType) const;
};




#endif // JOURNALEVENT_H
