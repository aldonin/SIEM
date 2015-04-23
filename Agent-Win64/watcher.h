#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>
#include "agentapplication.h"

class QFileSystemWatcher;
class QTimer;

class Watcher : public QObject
{
    Q_OBJECT
    Q_ENUMS(Mode)

public:
    Watcher(QObject *parent = 0);
    ~Watcher();

    enum Mode {
        Timed,
        FileChanged
    };

    uint interval() const;

public slots:
    void changeMode(const Watcher::Mode mode);
    void changeInterval(const int mins);
    void updateSettings();

private slots:
    void journalChange(const QString &path);
    void currentThread();

signals:
    void journalChange(AgentApplication::Journal);
    void timedOut();

private slots:
    void debugInfo();
    void timeToCollect();


private:
    QFileSystemWatcher *m_watcher;
    QTimer *m_timer;
    Mode m_mode;
    QMap<QString, bool> m_monitoredJournals;
    int m_timerInterval;

};

#endif // WATCHER_H
