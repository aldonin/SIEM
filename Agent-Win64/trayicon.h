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

private:
    QSystemTrayIcon *m_trayIcon;
    SettingsWidget *m_settings;

private slots:
    void openSettings();
};

#endif // TRAYICON_H
