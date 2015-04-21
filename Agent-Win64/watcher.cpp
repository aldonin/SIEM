#include "watcher.h"
#include <QFileSystemWatcher>
#include <QDebug>
#include <QTimer>
#include <QSettings>

#define SECOND_PER_MINUTE 60
#define MSEC_PER_SECOND 1000

Watcher::Watcher(QObject *parent) : QObject(parent)
{
    m_watcher = new QFileSystemWatcher(this);
    m_timer = new QTimer(this);

//    m_monitoredJournals.insert("Application", false);
//    m_monitoredJournals.insert("Security", false);
//    m_monitoredJournals.insert("Setup", false);
//    m_monitoredJournals.insert("System", false);
//    m_monitoredJournals.insert("ForwardedEvents", false);



//    m_mode = Mode::Timed;
    updateSettings();

    connect(m_timer, SIGNAL(timeout()), this, SLOT(debugInfo()));
    connect(m_watcher, SIGNAL(fileChanged(QString)), this, SLOT(journalChange(QString)));

    m_timer->start(10000);


    //qDebug() << m_watcher->addPath("C:/Windows/Sysnative/winevt/Logs/Application.evtx");
   // qDebug() << m_watcher->addPath("C:/Windows/Sysnative/winevt");
   // qDebug() << m_watcher->addPath("C:/Windows/System32/winevt");

}

Watcher::~Watcher()
{
    delete m_watcher;

    if (m_timer->isActive())
        m_timer->stop();
    delete m_timer;

    m_monitoredJournals.clear();
    //delete m_monitoredJournals;
}

uint Watcher::interval() const
{
    return m_timer->interval();
}

void Watcher::changeMode(const Watcher::Mode mode)
{
    m_mode = mode;
}

void Watcher::debugInfo()
{
    qDebug() << "Timedout: " << m_timer->interval();
}

void Watcher::changeInterval(const uint mins)
{
    if (m_mode == Mode::Timed) {
        m_timer->start(mins * SECOND_PER_MINUTE * MSEC_PER_SECOND);
    }
}

void Watcher::updateSettings()
{
    QSettings settings;
    settings.beginGroup("monitoredJournals");
    QMapIterator<QString, bool> it(m_monitoredJournals);

    while (it.hasNext()) {
        it.next();
        m_monitoredJournals.insert(it.key(), it.value());
    }

    settings.endGroup();

    int mode = settings.value("watchedMode/mode").toInt();
    m_mode = ( mode == 0 ? Mode::Timed : Mode::FileChanged);
}

void Watcher::journalChange(const QString &path)
{
    // get name journal, remove all subdirs
    QString str = path.section("/", -1);

    emit journalChange( AgentApplication::stringToJournal(str) );
}

