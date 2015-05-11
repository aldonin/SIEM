#include "journalevent.h"

#include <QStringList>


JournalEvent::JournalEvent()
{

}

JournalEvent::~JournalEvent()
{

}

bool JournalEvent::insert(const QString &key, const QString &value)
{
    QStringList lst;
    lst << "EventID" << "MachineName" << "Data" << "Index" << "Category" << "CategoryNumber"
        << "EntryType" << "Message" << "Source" << "InstanceId" << "TimeGenerated" << "TimeWritten";

   int index = lst.indexOf(key);
   switch (index) {
   case 0:
       EventID = value.toInt();
       break;
   case 1:
       MachineName = value;
       break;
   case 2:
       Data = value;
       break;
   case 3:
       Index = value.toInt();
       break;
   case 4:
       Category = value;
       break;
   case 5:
       CategoryNumber = value.toInt();
       break;
   case 6:
       EntryType = EntryTypefromString(value);
       break;
   case 7:
       Message = value;
       break;
   case 8:
       Source = value;
       break;
   case 9:
       InstanceId = value.toInt();
       break;
   case 10:
       TimeGenerated = QDateTime::fromString(value, "dd.MM.yyyy h:mm:ss");
       break;
   case 11:
       TimeWritten = QDateTime::fromString(value, "dd.MM.yyyy h:mm:ss");
       break;
   case -1:
       return false;
       break;

   default:
       Q_UNREACHABLE();
       return false;
       break;
   }

   return true;

}

int JournalEvent::getEventID() const
{
    return EventID;
}

QString JournalEvent::getMachineName() const
{
    return MachineName;
}

QString JournalEvent::getData() const
{
    return Data;
}

int JournalEvent::getIndex() const
{
    return Index;
}

QString JournalEvent::getCategory() const
{
    return Category;
}

int JournalEvent::getCategoryNumber() const
{
    return CategoryNumber;
}
int JournalEvent::getEntryType() const
{
    return EntryType;
}

QString JournalEvent::getMessage() const
{
    return Message;
}

QString JournalEvent::getSource() const
{
    return Source;
}

int JournalEvent::getInstanceId() const
{
    return InstanceId;
}

QString JournalEvent::getTimeGenerated() const
{
    return TimeGenerated.toString("dd.MM.yyyy hh:mm:ss");
}

QString JournalEvent::getTimeWritten() const
{
    return TimeWritten.toString("dd.MM.yyyy hh:mm:ss");
}

QString JournalEvent::getJournalType() const
{
    switch (type) {
    case Application:
        return QString("Application");
        break;
    case Security:
        return QString("Security");
        break;
    case Setup:
        return QString("Setup");
        break;
    case System:
        return QString("System");
        break;
    case ForwardedEvents:
        return QString("ForwardedEvents");
        break;
    default:
        Q_UNREACHABLE();
        return QString("Application");
        break;
    }
}

JournalEvent::JournalType JournalEvent::getgetJournalTypeAsType() const
{
    return type;
}

void JournalEvent::setJournalType(const QString &type)
{
    this->type = JournalTypeFromString(type);
}

quint16 JournalEvent::getPort() const
{
    return m_port;
}

void JournalEvent::setPort(const quint16 &port)
{
    m_port = port;
}

QHostAddress JournalEvent::host() const
{
    return m_host;
}

void JournalEvent::setHost(const QHostAddress &host)
{
    m_host = host;
}

JournalEvent::EventLogEntryType JournalEvent::EntryTypefromString(const QString strType) const
{
    /*
     * C Win7 x32 почему то иногда вместо QString имени EntryType приходит int значение.
     * Приходится сначала пытаться распарсить int значение, а только потом пытаться найти соответствие с QString полем
     */
    bool okCast = false;
    int type = strType.toInt(&okCast);
    if (okCast)
        return static_cast<EventLogEntryType>(type);


    if ( strType.compare("Error", Qt::CaseInsensitive) == 0 )
        return EventLogEntryType::Error;

    if ( strType.compare("FailureAudit", Qt::CaseInsensitive) == 0 )
        return EventLogEntryType::FailureAudit;

    if ( strType.compare("Information", Qt::CaseInsensitive) == 0 )
        return EventLogEntryType::Information;

    if ( strType.compare("SuccessAudit", Qt::CaseInsensitive) == 0 )
        return EventLogEntryType::SuccessAudit;

    if ( strType.compare("Warning", Qt::CaseInsensitive) == 0 )
        return EventLogEntryType::Warning;

    Q_UNREACHABLE();
    return EventLogEntryType::Information;
}

JournalEvent::JournalType JournalEvent::JournalTypeFromString(const QString strType) const
{
    if ( strType.compare("Application", Qt::CaseInsensitive) == 0 )
        return JournalType::Application;

    if ( strType.compare("Security", Qt::CaseInsensitive) == 0 )
        return JournalType::Security;

    if ( strType.compare("Setup", Qt::CaseInsensitive) == 0 )
        return JournalType::Setup;

    if ( strType.compare("System", Qt::CaseInsensitive) == 0 )
        return JournalType::System;

    if ( strType.compare("ForwardedEvents", Qt::CaseInsensitive) == 0 )
        return JournalType::ForwardedEvents;

    Q_UNREACHABLE();
    return JournalType::Application;
}
















