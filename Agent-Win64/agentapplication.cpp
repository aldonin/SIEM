#include "agentapplication.h"
#include <QSettings>
#include "trayicon.h"
#include <QDebug>

AgentApplication::AgentApplication(int argc, char *argv[]) :
    QApplication(argc, argv)
{
    QCoreApplication::setApplicationName("SIEM Agent-Win64");
    QCoreApplication::setOrganizationName("LETI");
    QCoreApplication::setOrganizationDomain("eltech.ru");
    QCoreApplication::setApplicationVersion("0.1");

    m_trayIcon = new TrayIcon;

    setQuitOnLastWindowClosed(false);
    connect(m_trayIcon, SIGNAL(updateSettingNeeded()), this, SLOT(updateSettings()));
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
        result = QSysInfo::windowsVersion() > QSysInfo::WV_XP ? "Application" : "AppEvent";
        break;
    case Security:
        result = QSysInfo::windowsVersion() > QSysInfo::WV_XP ? "Security" : "SecEvent";
        break;
    case Setup:
        result =  "Setup";
        break;
    case System:
        result = QSysInfo::windowsVersion() > QSysInfo::WV_XP ? "System" : "SysEvt";
        break;
    case ForwardedEvents:
        result = QSysInfo::windowsVersion() > QSysInfo::WV_XP ? "ForwardedEvents" : "EventForwarding-Operational";
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

    if (QString::compare(str, "Application", Qt::CaseInsensitive) == 0 ||
            QString::compare(str, "AppEvent", Qt::CaseInsensitive) == 0)
        type = Journal::Application;

    if (QString::compare(str, "Security", Qt::CaseInsensitive) == 0 ||
            QString::compare(str, "SecEvent", Qt::CaseInsensitive) == 0)
        type = Journal::Security;

    if (QString::compare(str, "Setup", Qt::CaseInsensitive) == 0)
        type = Journal::Setup;

    if (QString::compare(str, "System", Qt::CaseInsensitive) == 0 ||
            QString::compare(str, "SysEvt", Qt::CaseInsensitive) == 0)
        type = Journal::System;

    if (QString::compare(str, "ForwardedEvents", Qt::CaseInsensitive) == 0 ||
            QString::compare(str, "EventForwarding-Operational", Qt::CaseInsensitive) == 0)
        type = Journal::ForwardedEvents;


    return type;
}

void AgentApplication::updateSettings()
{
    QSettings settings;
    bool isStartup = settings.value("general/Startup").toBool();
    QSettings setStartup("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);

    QString value = AgentApplication::applicationFilePath();
    value.replace(QRegExp("/"), "\\");

    if (isStartup)
        setStartup.setValue("Siem", value);
     else
        setStartup.remove("Siem");
}

void AgentApplication::saveSettings()
{
}

void AgentApplication::readSettings()
{

}

