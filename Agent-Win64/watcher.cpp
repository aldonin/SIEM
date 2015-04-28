#include "watcher.h"
#include <QFileSystemWatcher>
#include <QDebug>
#include <QTimer>
#include <QSettings>

#define SECOND_PER_MINUTE 60
#define MSEC_PER_SECOND 1000

Watcher::Watcher(QObject *parent) : QObject(parent)
{
    m_watcher = new QFileSystemWatcher;
    m_timerInterval = 0;
    m_mode = Mode::FileChanged;
    connect(m_watcher, SIGNAL(fileChanged(QString)), this, SLOT(journalChange(QString)));
}

Watcher::~Watcher()
{
    qDebug() << "~Watcher";
    delete m_watcher;

    if (m_timer->isActive())
        m_timer->stop();
    delete m_timer;
    qDebug() << "~wathcher" <<QThread::currentThread();
    m_monitoredJournals.clear();
}

uint Watcher::interval() const
{
    return m_timer->interval();
}

void Watcher::initTimerAtCurrentThread()
{
    qDebug() << "Init" <<QThread::currentThread();
    m_timer = new QTimer;
    updateSettings();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(timeToCollect()));
}

void Watcher::changeMode(const Watcher::Mode mode)
{
   if (mode != m_mode) {
       m_mode = mode;
       m_mode == Mode::Timed ? m_timer->start(m_timerInterval * SECOND_PER_MINUTE * MSEC_PER_SECOND) : m_timer->stop();
   }
}

void Watcher::timeToCollect()
{
    emit timedOut();
}

void Watcher::changeInterval(const int mins)
{
    if (m_mode == Mode::Timed)
        if (m_timer->interval() != mins)
            m_timer->start(mins * SECOND_PER_MINUTE * MSEC_PER_SECOND);

    m_timerInterval = mins;
}

void Watcher::updateSettings()
{
    QSettings settings;
    settings.beginGroup("monitoredJournals");
    QStringList journals = settings.childKeys();


    foreach (QString key, journals) {
        m_monitoredJournals.insert(key, settings.value(key).toBool());
    }

    settings.endGroup();

    int mode = settings.value("watchedMode/mode").toInt();\

    /*
     * При инициализации таймера всегда сначала задаем ему таймаут, а только потом проверяем мод.
     * Ибо если сначала проверять мод, то при значение не совпадаюшем с текущим таймером каждый раз
     * будет происходить его лишний перезапуск.
     */
    changeInterval( settings.value("watchedMode/timedMode/timeout", QVariant(1)).toInt() );

    changeMode( mode == 0 ? Mode::Timed : Mode::FileChanged );
}

void Watcher::journalChange(const QString &path)
{
    // get name journal, remove all subdirs
    QString str = path.section("/", -1);

    emit journalChange( AgentApplication::stringToJournal(str) );
}

void Watcher::currentThread()
{
    qDebug() << "QThread wather: " << QThread::currentThreadId();
}

