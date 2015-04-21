#ifndef AGENTAPPLICATION_H
#define AGENTAPPLICATION_H

#include <QApplication>

class TrayIcon;

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

    TrayIcon *m_trayIcon;
};

// TODO добавить трансляторы
// TODO автозапуск

#endif // AGENTAPPLICATION_H
