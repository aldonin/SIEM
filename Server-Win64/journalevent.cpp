#include "journalevent.h"

#include <QStringList>

JournalEvent::JournalEvent()
{

}

JournalEvent::~JournalEvent()
{

}

bool JournalEvent::insert(const QString &value, const QString &key)
{
    QStringList lst;
    lst << "EventID" << "MachineName" << "Data" << "Index" << "Category" << "CategoryNumber"
        << "EntryType" << "Message" << "Source" << "InstanceId" << "TimeGenerated" << "TimeWritten";

   int index = lst.indexOf(value);
   switch (index) {
   case 0:
       EventID = key;
       break;
   case 1:
       MachineName = key;
       break;
   case 2:
       Data = key;
       break;
   case 3:
       Index = key;
       break;
   case 4:
       Category = key;
       break;
   case 5:
       CategoryNumber = key;
       break;
   case 6:
       EntryType = key;
       break;
   case 7:
       Message = key;
       break;
   case 8:
       Source = key;
       break;
   case 9:
       InstanceId = key;
       break;
   case 10:
       TimeGenerated = key;
       break;
   case 11:
       TimeWritten = key;
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

QString JournalEvent::getEventID() const
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

QString JournalEvent::getIndex() const
{
    return Index;
}

QString JournalEvent::getCategory() const
{
    return Category;
}

QString JournalEvent::getCategoryNumber() const
{
    return CategoryNumber;
}
QString JournalEvent::getEntryType() const
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

QString JournalEvent::getInstanceId() const
{
    return InstanceId;
}

QString JournalEvent::getTimeGenerated() const
{
    return TimeGenerated;
}

QString JournalEvent::getTimeWritten() const
{
    return TimeWritten;
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
















