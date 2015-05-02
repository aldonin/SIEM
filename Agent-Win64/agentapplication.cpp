#include "agentapplication.h"
#include "trayicon.h"
#include "watcher.h"
#include "collector.h"

#include <QDebug>
#include <QSettings>

AgentApplication::AgentApplication(int argc, char *argv[]) :
    QApplication(argc, argv)
{
    QCoreApplication::setApplicationName("Agent-Win64");
    QCoreApplication::setOrganizationName("LETI");
    QCoreApplication::setOrganizationDomain("eltech.ru");
    QCoreApplication::setApplicationVersion("0.1");

    m_trayIcon = new TrayIcon;
    m_watcher = new Watcher;
    m_collector = new Collector;


    QThread *wthread = new QThread;
    m_watcher->moveToThread(wthread);
    connect(wthread, SIGNAL(started()),  m_watcher, SLOT(initTimerAtCurrentThread()));
    connect(wthread, SIGNAL(finished()), m_watcher, SLOT(deleteLater()));
    connect(this,    SIGNAL(quitApp()),  wthread,   SLOT(quit()));
    connect(wthread, SIGNAL(finished()), wthread,   SLOT(deleteLater()));
    wthread->start();


    QThread *cThread = new QThread;
    m_collector->moveToThread(cThread);
    connect(cThread, SIGNAL(finished()), m_collector, SLOT(deleteLater()));
    connect(this,    SIGNAL(quitApp()),  cThread,     SLOT(quit()));
    connect(cThread, SIGNAL(finished()), cThread,     SLOT(deleteLater()));
    cThread->start();



    setQuitOnLastWindowClosed(false);
    connect(m_trayIcon, SIGNAL(updateSettingNeeded()), this, SLOT(updateSettings()));
    connect(m_trayIcon, SIGNAL(updateSettingNeeded()), m_watcher, SLOT(updateSettings()));
    connect(m_trayIcon, SIGNAL(updateSettingNeeded()), m_collector, SLOT(updateSettings()));

    connect(m_watcher, SIGNAL(timedOut()), m_collector, SLOT(collectAll()));

    connect(m_trayIcon, SIGNAL(quitApplication()), this, SLOT(onQuit()));
    connect(this, SIGNAL(quitApp()), qApp, SLOT(quit()));
}

AgentApplication::~AgentApplication()
{
    qDebug() << "~AgentApp";
    delete m_trayIcon;
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

    if ( isStartup )
        setStartup.setValue("Siem", value);
     else
        setStartup.remove("Siem");
}

void AgentApplication::onQuit()
{
    emit quitApp();
}

