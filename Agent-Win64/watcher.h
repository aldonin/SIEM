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
    void changeInterval(const uint mins);
    void updateSettings();

private slots:
    void journalChange(const QString &path);

signals:
    void journalChange(AgentApplication::Journal);

private slots:
    void debugInfo();


private:
    QFileSystemWatcher *m_watcher;
    QTimer *m_timer;
    Mode m_mode;
    QMap<QString, bool> m_monitoredJournals;

};

#endif // WATCHER_H
