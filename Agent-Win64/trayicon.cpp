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
    menu->addAction(tr("Exit"), this, SLOT(onQuitAction()));

    m_trayIcon->setContextMenu(menu);
    m_trayIcon->show();

    connect(m_settings, SIGNAL(settingsChanged()), this, SLOT(undateSettings()));
}

TrayIcon::~TrayIcon()
{
    qDebug() << "~TrayIcon";
    delete m_trayIcon;

    m_settings->setIsCanClose(true);
    delete m_settings;
}

void TrayIcon::openSettings()
{
    m_settings->show();
}

void TrayIcon::undateSettings()
{
    emit updateSettingNeeded();
}

void TrayIcon::onQuitAction()
{
    emit quitApplication();
}

