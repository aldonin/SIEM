#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>
#include "agentapplication.h"

class QFileSystemWatcher;
class QTimer;

/*!
 * \brief The Watcher class
 *
 * The main goals are watch journals changes and notify
 * Collector when journal change or timer timeout.
 *
 * \sa Collector
 */
class Watcher : public QObject
{
    Q_OBJECT
    Q_ENUMS(Mode)

public:
    /*!
     * \brief Default constructor.
     * \param parent Pointer to QObject parent.
     *
     * Initialize QFileSystemWatcher and init opening settings.
     */
    explicit Watcher(QObject *parent = 0);

    /*!
     * \brief Destructor
     *
     * Stop timer, delete QFileSystemWatcher, clear monitored journals.
     */
    ~Watcher();

    /*! Watcher's jobs mode. */
    enum Mode {
        Timed,      /*!< Triggered on timer timeout signal */
        FileChanged /*!< Triggered on monitored journal chaged */
    };

    /*!
     * \brief Timer interval.
     * \return Timer timeout interval in miliseconds.
     *
     * Default value of interval is 0.
     */
    uint interval() const;

public slots:
    /*!
     * \brief Initialization timer at current thread.
     *
     * This is slot is needed because of timers can be start and stop only at
     * thread where it was been init. So we have no constructor initialization timer,
     * but have this slot.
     */
    void initTimerAtCurrentThread();

    /*!
     * \brief Update settings from QSettings.
     *
     * This slot call when user update settings from settings widget.
     * \sa SettingsWidget
     */
    void updateSettings();

private slots:
    /*!
     * \brief Slot on journal change.
     * \param path Full path to changed journal.
     *
     * This slot calls when journal changed. Inside emited signal journalChange().
     *
     * \sa journalChange()
     */
    void journalChange(const QString &path);

    /*!
     * \brief This slot is reaction on signal changing watcher mode.
     * \param mode New setted mode.
     *
     * This slot reset timer in case previous mode != new one.
     * \sa Mode
     */
    void changeMode(const Watcher::Mode mode);

    /*!
     * \brief This slot is reaction on signal changing interval.
     * \param mins New timer interval.
     *
     * Set new value of intervals to watcher's timer.
     * \note If current Watcher mode is Timed, then timer will be reset and start with new value.
     * \sa Mode
     */
    void changeInterval(const int mins);

    /*!
     * \brief Collecting slot.
     *
     * This slot emit timedOut() signal and notify about timer timeout.
     * \sa timedOut()
     */
    void timeToCollect();

signals:
    /*!
     * \brief Journal change signal.
     *
     * Notify about journal with specified type was changed.
     */
    void journalChange(AgentApplication::Journal);

    /*!
     * \brief Watcher timeout signal.
     *
     * Emited when timer timeout.
     * \sa timeToCollect()
     */
    void timedOut();

private:
    QFileSystemWatcher *m_watcher;              ///< QFileSystemWatcher directory and files.
    QTimer *m_timer;                            ///< Object timer.
    Mode m_mode;                                ///< Current watcher mode.
    QMap<QString, bool> m_monitoredJournals;    ///< Map of journals and monitored state.
    int m_timerInterval;                        ///< Current timer interval.

};

#endif // WATCHER_H
