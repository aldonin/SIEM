#ifndef JOURNALEVENT_H
#define JOURNALEVENT_H

#include <QString>
#include <QObject>
#include <QHostAddress>
#include <QDateTime>


class JournalEvent
{
    Q_ENUMS(EventLogEntryType)

public:
    JournalEvent();
    ~JournalEvent();

    enum EventLogEntryType {
        Information,
        Error,
        FailureAudit,
        SuccessAudit,
        Warning
    };

    bool insert(const QString &value, const QString &key);

    int     getEventID() const;
    QString getMachineName() const;
    QString getData() const;
    int     getIndex() const;
    QString getCategory() const;
    int     getCategoryNumber() const;
    int     getEntryType() const;
    QString getMessage() const;
    QString getSource() const;
    int     getInstanceId() const;
    QString getTimeGenerated() const;
    QString getTimeWritten() const;

    quint16 getPort() const;
    void setPort(const quint16 &port);

    QHostAddress host() const;
    void setHost(const QHostAddress &host);

private:
    int               EventID;
    QString           MachineName;
    QString           Data;
    int               Index;
    QString           Category;
    int               CategoryNumber;
    EventLogEntryType EntryType;
    QString           Message;
    QString           Source;
    int               InstanceId;
    QDateTime         TimeGenerated;
    QDateTime         TimeWritten;

    QHostAddress m_host;
    quint16      m_port;

private:
    JournalEvent(const JournalEvent&);
    JournalEvent& operator=(const JournalEvent&);
public:

    EventLogEntryType EntryTypefromString(const QString strType) const;
};




#endif // JOURNALEVENT_H
