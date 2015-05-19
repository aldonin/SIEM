#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <QObject>
#include "agentapplication.h"

/*!
 * \brief Class for collection journals.
 *
 * Collection OS journals, include file sending module.
 */
class Collector : public QObject
{
    Q_OBJECT

public:
    /*!
     * \brief Default constructor.
     * \param parent QObject parent.
     *
     * Initialize default settings from QSettings.
     */
    explicit Collector(QObject *parent = 0);

    ~Collector();

private:
    /*!
     * \brief Save settings of collector state.
     *
     * Save last date and time of last grab for each journal.
     */
    void saveSettings();

private:
    QString executeStr;                                             /// \brief PowerShell execution string.
    QMap<AgentApplication::Journal, QDateTime> m_lastTimeCollect;   /// \brief Map of journals and their last datetime grab.
    QString m_psScriptTempFolder;                                   /// \brief Temporary folder for PowerShell script.
    QString m_xmlTempFolder;                                        /// \brief Temporary folder for Xml files.

public slots:
    /*!
     * \brief Grab journal with specified type.
     * \param type Journal type.
     * \sa AgentApplication::Journal
     */
    void collect(const AgentApplication::Journal type = AgentApplication::Journal::Application);

    /*!
     * \brief Grab all watching journals
     *
     * Grab all watching journals specified at settings Agent App.
     */
    void collectAll();

    /*!
     * \brief Update settings from QSettings.
     *
     * This slot call when user update settings from settings widget.
     * \sa SettingsWidget
     */
    void updateSettings();

private slots:
    /*!
     * \brief Remove xml file.
     * \param fileName Full file path.
     *
     * Remove grabbing file after it's transfer.
     *
     * \sa FileSender
     */
    void removeXmlFile(const QString &fileName);
};

#endif // COLLECTOR_H
