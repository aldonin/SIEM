#include "collector.h"
#include <QDebug>

Collector::Collector(QObject *parent) : QObject(parent)
{
    prc = new QProcess(this);

    //QString path = "C:/Windows/system32/WindowsPowerShell/v1.0/powershell.exe";
    QString path = "cmd /C powershell";

    QStringList comm;
    comm.append("-NoProfile");
    comm.append("–ExecutionPolicy Unrestricted");
    comm.append("–File D:/1.ps1");

    connect(prc,SIGNAL(readyReadStandardOutput()), this, SLOT(readyRead()));
    connect(prc, SIGNAL(readyReadStandardError()), this, SLOT(readError()));

    connect(prc, SIGNAL(error(QProcess::ProcessError)), this, SLOT(emitError(QProcess::ProcessError)));
    connect(prc, SIGNAL(finished(int)), prc, SLOT(deleteLater()));

    prc->start("cmd /C powershell -NoProfile –ExecutionPolicy Unrestricted –File D:/1.ps1");

    prc->waitForFinished();
}

Collector::~Collector()
{
    qDebug() << "~Collector";
    delete prc;
}

void Collector::readyRead()
{
    qDebug() << "ready!";
    qDebug() << QString(prc->readAllStandardOutput());
}

void Collector::readError()
{
    qDebug() << QString(prc->readAllStandardError());
}

void Collector::emitError(QProcess::ProcessError err)
{
    qDebug() << prc->error();
}

