#include "collector.h"
#include <QDebug>
#include <QThread>

Collector::Collector(QObject *parent) : QObject(parent)
{
    m_prc = new QProcess(this);
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
    // FIXME в зависимости от типа
    Q_UNUSED(type)
    m_prc->start(executeStr);
    m_prc->waitForFinished();
}

void Collector::currentThread()
{
    qDebug() << "QThread collector: " << QThread::currentThreadId();
}

void Collector::updateSettings()
{
    // TODO брать настройки из QSettings
}

