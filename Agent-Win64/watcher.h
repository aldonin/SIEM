#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>

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

public slots:
    void changeMode(const Watcher::Mode mode);
    void changeTimer(const unsigned int mins);

private slots:
    void debugInfo();


private:
    QFileSystemWatcher *m_watcher;
    QTimer *m_timer;
    Mode m_mode;
};

#endif // WATCHER_H
