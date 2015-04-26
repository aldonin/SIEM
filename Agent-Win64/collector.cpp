#include "collector.h"
#include <QDebug>
#include <QThread>
#include <QSettings>
#include <QFile>
#include <QDateTime>

Collector::Collector(QObject *parent) : QObject(parent)
{
    m_prc = new QProcess;
    executeStr = "cmd /C powershell -NoProfile –ExecutionPolicy Unrestricted –File D:/1.ps1";

    //connect(m_prc, SIGNAL(finished(int)), m_prc, SLOT(deleteLater()));

   // prc->start(executeStr);

   // prc->waitForFinished();
}

Collector::~Collector()
{
    qDebug() << "~Collector";
    delete m_prc;
}

void Collector::collect(const AgentApplication::Journal type)
{
    QDateTime time = QDateTime::currentDateTime();
    QFile executePS(QString("%1-%2.ps1")
                    .arg( AgentApplication::journalToString(type) )
                    .arg( time.toString("dd.MM.yyyy_hh-mm-ss") ));

    qDebug() << QString("%1-%2.ps1")
                .arg( AgentApplication::journalToString(type) )
                .arg( time.toString("dd.MM.yyyy_hh:mm:ss") );

    if (!executePS.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Can't open file";
    } else {

        QTextStream out(&executePS);

        // TODO исправить на After
        out <<  QString("(Get-EventLog -LogName '%1' -Newest %2 |ConvertTo-Xml -noTypeInformation).save(\"%3\") \nGet-Process Powershell | Stop-Process")
                .arg( AgentApplication::journalToString(type) )
                .arg( "10" )
                .arg( "D:\\1.xml" );
        executePS.close();

        executeStr = QString("cmd /C powershell -NoProfile –ExecutionPolicy Unrestricted –File %1").arg(executePS.fileName());

        m_prc->start(executeStr);
        m_prc->waitForFinished();
        qDebug() << executePS.remove();
    }
}

void Collector::collectAll()
{
    QSettings settings;
    settings.beginGroup("monitoredJournals");
    QStringList keys = settings.childKeys();
    foreach (QString journalName, keys) {
        if (settings.value(journalName).toBool())
            collect( AgentApplication::stringToJournal(journalName) );
    }

    settings.endGroup();

}

void Collector::currentThread()
{
    qDebug() << "QThread collector: " << QThread::currentThreadId();
}

void Collector::updateSettings()
{
    // TODO брать настройки из QSettings
}

