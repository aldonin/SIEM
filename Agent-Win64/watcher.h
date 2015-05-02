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
    explicit Watcher(QObject *parent = 0);
    ~Watcher();

    enum Mode {
        Timed,
        FileChanged
    };

    uint interval() const;

public slots:
    // Необходимо инициализация таймера в потоке, в котором он будет работать, иначе ловлю ошибку Timers cannot be stopped from another thread
    void initTimerAtCurrentThread();
    void updateSettings();

private slots:
    void journalChange(const QString &path);
    void changeMode(const Watcher::Mode mode);
    void changeInterval(const int mins);

signals:
    void journalChange(AgentApplication::Journal);
    void timedOut();

private slots:
    void timeToCollect();


private:
    QFileSystemWatcher *m_watcher;
    QTimer *m_timer;
    Mode m_mode;
    QMap<QString, bool> m_monitoredJournals;
    int m_timerInterval;

};

#endif // WATCHER_H
