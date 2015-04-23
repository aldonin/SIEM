#ifndef AGENTAPPLICATION_H
#define AGENTAPPLICATION_H

#include <QApplication>
#include <QThread>

class TrayIcon;
class Watcher;
class Collector;

class AgentApplication : public QApplication
{
    Q_ENUMS(Journal)
    Q_OBJECT

public:
    AgentApplication(int argc, char *argv[]);
    ~AgentApplication();

    enum Journal {
        Application,
        Security,
        Setup,
        System,
        ForwardedEvents
    };

    static QString journalToString(const Journal type);
    static Journal stringToJournal(const QString &str);

public slots:
    void updateSettings();

private:
    void saveSettings();
    void readSettings();

    TrayIcon  *m_trayIcon;
    Watcher   *m_watcher;
    Collector *m_collector;
};

// TODO добавить трансляторы

#endif // AGENTAPPLICATION_H
