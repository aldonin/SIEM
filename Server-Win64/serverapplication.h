#ifndef SERVERAPPLICATION_H
#define SERVERAPPLICATION_H

#include <QApplication>

class Server;
class QSystemTrayIcon;
class SettingsWidget;

/*!
 * \brief The Application class of server module
 */
class ServerApplication : public QApplication
{
    Q_OBJECT

public:
    /*!
     * \brief ServerApplication
     * \param argc, argv argc,argv main() function parameters
     *
     * Initialize Server for individual thread.
     * Start event loop for UI settings widget. Create connections.
     * \sa Server
     * \sa SettingsWidget
     */
    ServerApplication(int argc, char *argv[]);
    /*!
     * \brief Destructor of class.
     *
     * Free resources, delete TrayIcon and SettingsWidget.
     */
    ~ServerApplication();

signals:
    /*!
     * \brief Stop server signal.
     *
     * Emiteds in case of server was stoped.
     */
    void stopServer();
    /*!
     * \brief Exit application signal.
     *
     * Emiteds in case of user chose 'Exit' from context menu.
     */
    void quitApp();

private slots:
    /*!
     * \brief Open settings slot.
     *
     * Call when user chose at context menu 'Show settings'.
     * \sa SettingsWidget
     */
    void openSettings();
    /*!
     * \brief Action of quit app.
     *
     * Call in case of user chose 'Exit' from context menu.
     */
    void onQuitAction();

public slots:
    /*!
     * \brief Update settings from QSettings.
     *
     * This slot call when user update settings from settings widget.
     * \sa SettingsWidget
     */
    void updateSettings();

private:
    Server          *m_server;          ///< Reomplemented Tcp Server.
    QSystemTrayIcon *m_trayIcon;        ///< Tray icon with context menu.
    SettingsWidget  *m_settingsWidget;  ///< Settings widget.
};

#endif // SERVERAPPLICATION_H
