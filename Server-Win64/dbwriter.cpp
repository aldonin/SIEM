#include "dbwriter.h"
#include <QDateTime>
#include <QThread>
#include <QDebug>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSettings>
#include <QUuid>

#include "journalevent.h"
#include "constants.h"
#include "simplecrypt.h"

using namespace Constants::Database;

DbWriter::DbWriter(QList<JournalEvent*> list, QObject *parent) :
    QObject(parent),
    m_list(list)
{
    m_connectionName = QString("%1-%2")
            .arg(QDateTime::currentDateTime().toString("dd.MM.yyyy-hh.mm.ss.zzz"))
            .arg(QUuid::createUuid().toString());
}

DbWriter::~DbWriter()
{
    qDebug() << "~DbWriter";
    QSqlDatabase::removeDatabase(m_connectionName);
}

void DbWriter::push()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", m_connectionName);

    QSettings settings;
    settings.beginGroup("Database");

    db.setDatabaseName( settings.value("Location", QVariant(DEFAULT_DB_LOCATION)).toString() );
    db.setHostName( settings.value("Name", QVariant(DEFAULT_DB_NAME)).toString() );
    db.setUserName( settings.value("User", QVariant(DEFAULT_DB_USERNAME)).toString() );
    QString enctyptedPassword = settings.value("Password", QVariant(DEFAULT_DB_PASSWORD)).toString();
    if (enctyptedPassword != DEFAULT_DB_PASSWORD) {
        SimpleCrypt crypt;
        crypt.setKey(Constants::Crypto::KEY);
        enctyptedPassword = crypt.decryptToString( enctyptedPassword );
    }
    db.setPassword(enctyptedPassword);

    settings.endGroup();

    if (!db.open() || db.tables().isEmpty()) {
        qDebug() << "Can't connect to database from DbWriter";
        emit finished();
        return;
    }

    QSqlQuery query(db);
    for (auto it = m_list.begin(); it != m_list.end(); ++it) {

        query.prepare("INSERT INTO Events VALUES(:SourceHost, :SourcePort, :EventID, :MachineName,"
                      " :Data, :Index, :Category, :CategoryNumber,"
                      " :EntryType, :Message, :Source, :InstanceId,"
                      " :TimeGenerated, :TimeWritten)");

        query.bindValue(":SourceHost",    (*it)->host().toString());
        query.bindValue(":SourcePort",    (*it)->getPort());
        query.bindValue(":EventID",       (*it)->getEventID());
        query.bindValue(":MachineName",   (*it)->getMachineName());
        query.bindValue(":Data",          (*it)->getData());
        query.bindValue(":Index",         (*it)->getIndex());
        query.bindValue(":Category",      (*it)->getCategory());
        query.bindValue(":CategoryNumber",(*it)->getCategoryNumber());
        query.bindValue(":EntryType",     (*it)->getEntryType());
        query.bindValue(":Message",       (*it)->getMessage());
        query.bindValue(":Source",        (*it)->getSource());
        query.bindValue(":InstanceId",    (*it)->getInstanceId());
        query.bindValue(":TimeGenerated", (*it)->getTimeGenerated());
        query.bindValue(":TimeWritten",   (*it)->getTimeWritten());

        if (!query.exec())
            qDebug() << "Can't execute query. Last error: " << query.lastError();

        query.clear();
    }

    emit finished();
}

