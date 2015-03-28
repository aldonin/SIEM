#ifndef AGENTAPPLICATION_H
#define AGENTAPPLICATION_H

#include <QApplication>

class TrayIcon;

class AgentApplication : public QApplication
{
public:
    AgentApplication(int argc, char *argv[]);
    ~AgentApplication();


private:
    void saveSettings();
    void readSettings();

    TrayIcon *m_trayIcon;
};

// TODO добавить трансляторы
// TODO автозапуск

#endif // AGENTAPPLICATION_H
