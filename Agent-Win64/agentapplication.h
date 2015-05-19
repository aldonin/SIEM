#ifndef AGENTAPPLICATION_H
#define AGENTAPPLICATION_H

#include <QApplication>
#include <QThread>

class TrayIcon;
class Watcher;
class Collector;

/*!
 * \brief Application class of Agent module
 */
class AgentApplication : public QApplication
{
    Q_ENUMS(Journal)
    Q_OBJECT

public:
    /*!
     * \brief AgentApplication.
     * \param argc,argv main() function parameters
     * \sa Collector
     * \sa Watcher
     * \sa TrayIcon
     * \sa SettingsWidget
     *
     * Initializing Collector, Watcher and TrayIcon for own threads.
     * Start event loop for UI settings widget. Create connections.
     */
    AgentApplication(int argc, char *argv[]);

    /*!
     * \brief Free resources, delete TrayIcon.
     */
    ~AgentApplication();

    /*! Types of journals. */
    enum Journal {
        Application,    /*!< Information about Application, driver or service job */
        Security,       /*!< Audit information */
        Setup,          /*!< Extra journals for domen controllers */
        System,         /*!< System and services events information */
        ForwardedEvents /*!< Forwarded Events from another PC */
    };

    /*!
     * \brief Parsing journal type.
     * \param type Journal type.
     * \return Parsed QString from type.
     * \note If journal not found function return empty string.
     * \sa Journal
     */
    static QString journalToString(const Journal type);
    /*!
     * \brief Parsing journal type.
     * \param str Journal type at QString representation.
     * \return Parsed Journal to Journal type.
     * \note If parsing string to Journal failuer function return Application type of Journal.
     * \sa Journal
     */
    static Journal stringToJournal(const QString &str);

public slots:
    /*!
     * \brief Update settings from QSettings.
     * \sa SettingsWidget
     *
     * This slot call when user update settings from settings widget.
     */
    void updateSettings();

private slots:
    /*!
     * \brief Quit application prepare.
     * \sa quitApp()
     *
     * This slot emit signal quitApp() for notifying all generated threads.
     */
    void onQuit();

signals:
    /*!
     * \brief Signal notify generated threads about closing AgentApplication.
     * \sa AgentApplication
     */
    void quitApp();

private:
    /*!
     * \brief Tray icon widget.
     * \sa TrayIcon
     */
    TrayIcon  *m_trayIcon;

    /*!
     * \brief Watcher object.
     * \sa Watcher
     */
    Watcher   *m_watcher;

    /*!
     * \brief Collector object.
     * \sa Collector
     */
    Collector *m_collector;
};

#endif // AGENTAPPLICATION_H
