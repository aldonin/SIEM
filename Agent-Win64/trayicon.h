#ifndef TRAYICON_H
#define TRAYICON_H

#include <QObject>

class QSystemTrayIcon;
class SettingsWidget;

class TrayIcon : QObject
{
    Q_OBJECT

public:
    TrayIcon();
    ~TrayIcon();

signals:
    // TODO пробросить эту функцию в agentapplication и добавлять в автозапуск
    void sayBaseApplitionUpdateSetting();
    // NOTE для XP regedit : HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run

private:
    QSystemTrayIcon *m_trayIcon;
    SettingsWidget *m_settings;

private slots:
    void openSettings();
};

#endif // TRAYICON_H
