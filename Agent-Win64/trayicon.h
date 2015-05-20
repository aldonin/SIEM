#ifndef TRAYICON_H
#define TRAYICON_H

#include <QObject>

class QSystemTrayIcon;
class SettingsWidget;

/*!
 * \brief Tray Icon class for displying settings widget.
 * \sa SettingsWidget
 *
 * Display icon at tray, show context menu by click and open settings widget.
 */
class TrayIcon : public QObject
{
    Q_OBJECT

public:
    /*!
     * \brief Default class constructor.
     *
     * Init context menu for tray, connect it with actions.
     */
    TrayIcon();
    ~TrayIcon();

signals:
    /*!
     * \brief Settings was changed.
     * \sa AgentApplication
     *
     * Purposely forwarding to AgentApplication class.
     */
    void updateSettingNeeded();

    /*!
     * \brief Quit application signal.
     *
     * Notify AgentApplication about user exit chose.
     */
    void quitApplication();

private:
    QSystemTrayIcon *m_trayIcon;    ///< Tray icon widget.
    SettingsWidget *m_settings;     ///< Settings widget.

private slots:
    /*!
     * \brief Open settings slot.
     * \sa SettingsWidget
     *
     * Call when user chose at context menu 'Show settings'.
     */
    void openSettings();

    /*!
     * \brief Update settings from QSettings.
     * \sa SettingsWidget
     *
     * This slot call when user update settings from settings widget.
     */
    void undateSettings();

    /*!
     * \brief Quit application.
     * \sa quitApplication()
     *
     * This slot call when user chose at context menu 'Exit'.
     * This slot emit quitApplication() signal.
     */
    void onQuitAction();
};

#endif // TRAYICON_H
