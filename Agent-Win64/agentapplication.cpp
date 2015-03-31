#include "agentapplication.h"
#include <QSettings>
#include "trayicon.h"

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
    delete m_trayIcon;
    saveSettings();
}

void AgentApplication::saveSettings()
{
}

void AgentApplication::readSettings()
{

}

