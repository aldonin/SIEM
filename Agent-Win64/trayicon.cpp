#include "trayicon.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QApplication>
#include "settingswidget.h"
#include <QDebug>

TrayIcon::TrayIcon()
{
    QIcon icon(":agent.png");
    m_trayIcon = new QSystemTrayIcon(icon, this);
    m_settings = new SettingsWidget;

    QMenu *menu = new QMenu;

    menu->addAction(tr("Settings"), this, SLOT(openSettings()));
    menu->addSeparator();
    menu->addAction(tr("Exit"), qApp, SLOT(quit()));

    m_trayIcon->setContextMenu(menu);
    m_trayIcon->show();
}

TrayIcon::~TrayIcon()
{
    delete m_trayIcon;

    m_settings->setIsCanClose(true);
    delete m_settings;
}

void TrayIcon::openSettings()
{
    m_settings->show();
}

