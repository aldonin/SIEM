#ifndef JOURNALEVENT_H
#define JOURNALEVENT_H

#include <QString>
#include <QObject>
#include <QHostAddress>


class JournalEvent
{
public:
    JournalEvent();
    ~JournalEvent();

    bool insert(const QString &value, const QString &key);

    QString getEventID() const;
    QString getMachineName() const;
    QString getData() const;
    QString getIndex() const;
    QString getCategory() const;
    QString getCategoryNumber() const;
    QString getEntryType() const;
    QString getMessage() const;
    QString getSource() const;
    QString getInstanceId() const;
    QString getTimeGenerated() const;
    QString getTimeWritten() const;

    quint16 getPort() const;
    void setPort(const quint16 &port);

    QHostAddress host() const;
    void setHost(const QHostAddress &host);

private:
    QString EventID;
    QString MachineName;
    QString Data;
    QString Index;
    QString Category;
    QString CategoryNumber;
    QString EntryType;
    QString Message;
    QString Source;
    QString InstanceId;
    QString TimeGenerated;
    QString TimeWritten;

    QHostAddress m_host;
    quint16      m_port;

private:
    JournalEvent(const JournalEvent&);
    JournalEvent& operator=(const JournalEvent&);
};




#endif // JOURNALEVENT_H
