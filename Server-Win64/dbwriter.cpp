#include "dbwriter.h"
#include <QDateTime>
#include <QThread>
#include <QDebug>


#include "journalevent.h"

DbWriter::DbWriter(QList<JournalEvent*> list, QObject *parent) :
    QObject(parent),
    m_list(list)
{
    m_connectionName = QString("%1-%2")
            .arg(QDateTime::currentDateTime().toString("dd.MM.yyyy-hh.mm.ss.z-"))
            .arg(QThread::currentThreadId());
}

DbWriter::~DbWriter()
{
    qDebug() << "~DbWriter";
    delete m_list;
}

void DbWriter::push()
{

}

