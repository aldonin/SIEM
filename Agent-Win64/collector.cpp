#include "collector.h"
#include <QDebug>
#include <QThread>
#include <QSettings>
#include <QFile>
#include <QDateTime>
#include <QProcess>

#include "filesender.h"

Collector::Collector(QObject *parent) : QObject(parent)
{
    executeStr = "cmd /C powershell -NoProfile –ExecutionPolicy Unrestricted –File D:/1.ps1";

    updateSettings();
}

Collector::~Collector()
{
    qDebug() << "~Collector";
    saveSettings();
}

void Collector::saveSettings()
{
    QSettings settings;
    settings.beginGroup("monitoredJournals/lastTimeCollect");
    QMapIterator<AgentApplication::Journal, QDateTime> it(m_lastTimeCollect);
    while (it.hasNext()) {
        it.next();
        settings.setValue(AgentApplication::journalToString(it.key()), it.value().toString("dd.MM.yyyy hh:mm:ss"));
    }
    settings.endGroup();
}

void Collector::collect(const AgentApplication::Journal type)
{
    QDateTime curTime = QDateTime::currentDateTime();
    QFile executePS(QString("%1-%2.ps1")
                    .arg( AgentApplication::journalToString(type) )
                    .arg( curTime.toString("dd.MM.yyyy_hh-mm-ss") ));

    if (!executePS.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Can't open file";
    } else {

        QTextStream out(&executePS);

        QDateTime lastTimeUpdate = m_lastTimeCollect.value(type, curTime);

        QString xmlFileName = QString("%1-%2.xml")
                .arg( AgentApplication::journalToString(type) )
                .arg( curTime.toString("dd.MM.yyyy_hh-mm-ss") );

        out <<  QString("(Get-EventLog -LogName '%1' -After '%2' |ConvertTo-Xml -noTypeInformation).save(\"%3\") \nGet-Process Powershell | Stop-Process")
                .arg( AgentApplication::journalToString(type) )
                .arg( lastTimeUpdate.toString("dd.MM.yyyy hh:mm:ss") )
                .arg( xmlFileName );

        executePS.close();

        executeStr = QString("cmd /C powershell -NoProfile –ExecutionPolicy Unrestricted –File %1").arg(executePS.fileName());

        QProcess prc;
        prc.start(executeStr);
        prc.waitForFinished();
        // TODO remove this
        // TODO также надо xml файл удалять после отправки
        //qDebug() << executePS.remove();

        FileSender *sender = new FileSender(xmlFileName);
        QThread *thread = new QThread;
        sender->moveToThread(thread);

        connect(thread, SIGNAL(started()), sender, SLOT(send()));
        connect(sender, SIGNAL(finished()), thread, SLOT(quit()));
        connect(sender, SIGNAL(finished()), sender, SLOT(deleteLater()));
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

        thread->start();
    }
}

void Collector::collectAll()
{
    QSettings settings;
    settings.beginGroup("monitoredJournals");
    QStringList keys = settings.childKeys();
    foreach (QString journalName, keys) {
        if (settings.value(journalName).toBool()) {
            collect( AgentApplication::stringToJournal(journalName) );
            m_lastTimeCollect.insert(AgentApplication::stringToJournal(journalName), QDateTime::currentDateTime());
        }
    }

    settings.endGroup();
}

void Collector::currentThread()
{
    qDebug() << "QThread collector: " << QThread::currentThreadId();
}

void Collector::updateSettings()
{
    QSettings settings;

    settings.beginGroup("monitoredJournals/lastTimeCollect");
    QStringList keys = settings.childKeys();
    foreach (QString journalName, keys) {
        QDateTime settingsDate = QDateTime::fromString(settings.value(journalName).toString(), "dd.MM.yyyy hh:mm:ss");
        if ( settingsDate > m_lastTimeCollect.value(AgentApplication::stringToJournal(journalName), QDateTime::fromString("01.01.1990 00:00", "dd.MM.yyyy hh:mm")) ) {
            m_lastTimeCollect.insert( AgentApplication::stringToJournal(journalName), settingsDate );
        }
    }
    settings.endGroup();
}

