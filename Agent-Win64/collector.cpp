#include "collector.h"
#include <QDebug>

Collector::Collector(QObject *parent) : QObject(parent)
{
    m_prc = new QProcess(this);
    executeStr = "cmd /C powershell -NoProfile –ExecutionPolicy Unrestricted –File D:/1.ps1";

    connect(m_prc,SIGNAL(readyReadStandardOutput()), this, SLOT(readyRead()));
    connect(m_prc, SIGNAL(readyReadStandardError()), this, SLOT(readError()));

    connect(m_prc, SIGNAL(error(QProcess::ProcessError)), this, SLOT(emitError(QProcess::ProcessError)));
    connect(m_prc, SIGNAL(finished(int)), m_prc, SLOT(deleteLater()));

   // prc->start(executeStr);

   // prc->waitForFinished();
}

Collector::~Collector()
{
    qDebug() << "~Collector";
    delete m_prc;
}

void Collector::readyRead()
{
    qDebug() << "ready!";
    qDebug() << QString(m_prc->readAllStandardOutput());
}

void Collector::readError()
{
    qDebug() << QString(m_prc->readAllStandardError());
}

void Collector::emitError(QProcess::ProcessError err)
{
    qDebug() << m_prc->error();
}

void Collector::collect(const AgentApplication::Journal type)
{
    // FIXME в зависимости от типа
    Q_UNUSED(type)
    m_prc->start(executeStr);
    m_prc->waitForFinished();
}

