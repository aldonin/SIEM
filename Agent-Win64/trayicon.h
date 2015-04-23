#ifndef TRAYICON_H
#define TRAYICON_H

#include <QObject>

class QSystemTrayIcon;
class SettingsWidget;

class TrayIcon : public QObject
{
    Q_OBJECT

public:
    TrayIcon();
    ~TrayIcon();

signals:
    void updateSettingNeeded();
    void quitApplication();

private:
    QSystemTrayIcon *m_trayIcon;
    SettingsWidget *m_settings;

private slots:
    void openSettings();
    void undateSettings();
    void onQuitAction();
};

#endif // TRAYICON_H
