#include "agentapplication.h"
#include <QSettings>
#include "trayicon.h"
#include <QDebug>

AgentApplication::AgentApplication(int argc, char *argv[]) :
    QApplication(argc, argv)
{
    QCoreApplication::setApplicationName("SIEM Agent-Win64");
    QCoreApplication::setApplicationVersion("0.1");

    m_trayIcon = new TrayIcon;

    setQuitOnLastWindowClosed(false);
}

AgentApplication::~AgentApplication()
{
    //qDebug() << "~AgentApp";
    delete m_trayIcon;
    //saveSettings();
}

QString AgentApplication::journalToString(const AgentApplication::Journal type)
{
    QString result = QString();
    switch (type) {
    case Application:
        result = "Application";
        break;
    case Security:
        result = "Security";
        break;
    case Setup:
        result = "Setup";
        break;
    case System:
        result = "System";
        break;
    case ForwardedEvents:
        result = "ForwardedEvents";
        break;
    default:
        Q_UNREACHABLE();
        break;
    }

    return result;
}

AgentApplication::Journal AgentApplication::stringToJournal(const QString &str)
{
    Journal type = Journal::Application;

    if (QString::compare(str, "Application", Qt::CaseInsensitive) == 0)
        type = Journal::Application;

    if (QString::compare(str, "Security", Qt::CaseInsensitive) == 0)
        type = Journal::Security;

    if (QString::compare(str, "Setup", Qt::CaseInsensitive) == 0)
        type = Journal::Setup;

    if (QString::compare(str, "System", Qt::CaseInsensitive) == 0)
        type = Journal::System;

    if (QString::compare(str, "ForwardedEvents", Qt::CaseInsensitive) == 0)
        type = Journal::ForwardedEvents;


    return type;
}

void AgentApplication::saveSettings()
{
}

void AgentApplication::readSettings()
{

}

