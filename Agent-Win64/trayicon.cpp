#include "trayicon.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QApplication>

TrayIcon::TrayIcon()
{
    QIcon icon(":agent.png");
    m_trayIcon = new QSystemTrayIcon(icon, this);

    QMenu *menu = new QMenu;

    menu->addAction(tr("Settings"), this, SLOT(slotSettings()));
    menu->addSeparator();
    menu->addAction(tr("Exit"), qApp, SLOT(quit()));

    m_trayIcon->setContextMenu(menu);
    m_trayIcon->show();
}

TrayIcon::~TrayIcon()
{
    delete m_trayIcon;
}

void TrayIcon::slotSettings()
{

}

