#ifndef SERVERAPPLICATION_H
#define SERVERAPPLICATION_H

#include <QApplication>

class Server;
class QSystemTrayIcon;
class SettingsWidget;

class ServerApplication : public QApplication
{
    Q_OBJECT

public:
    ServerApplication(int argc, char *argv[]);
    ~ServerApplication();

signals:
    void stopServer();
    void quitApp();

private slots:
    void openSettings();
    void onQuitAction();

private:
    Server          *m_server;
    QSystemTrayIcon *m_trayIcon;
    SettingsWidget  *m_settingsWidget;
};

#endif // SERVERAPPLICATION_H
