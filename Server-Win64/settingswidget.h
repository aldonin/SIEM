#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include "ui_settingswidget.h"

/*!
 * \brief Settings Widget class.
 *
 * Represent form for customize Server Application settings.
 * UI form developed in QtCreator.
 */
class SettingsWidget : public QWidget, private Ui::SettingsWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Default constructor.
     * \param parent QWidget parent object.
     *
     * Create connection form element and their slots. Initialize opening settings by QSettings storage.
     * As default storage for QSettings class chosen OS registry.
     */
    explicit SettingsWidget(QWidget *parent = 0);
    //! Free resources.
    ~SettingsWidget();

    /*!
     * \brief Check state of form for closing.
     * \return true if form is ready for closing, otherwise false.
     * \sa m_isCanClose
     */
    bool isCanClose() const;
    /*!
     * \brief Set state for form closing.
     * \param value true if form is ready for closing.
     * \sa m_isCanClose
     */
    void setIsCanClose(const bool value);

protected:
    /*!
     * \brief Override method for hook close event of form.
     * \param event Close event parameter type.
     *
     * Needed for ignore close form if flag isCanClose not ready.
     * The main purpose this hack is reject updating settings every time form shown.
     */
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
    bool m_isCanClose;      ///< State of form for closing.

signals:
    /*!
     * \brief Settings was changed.
     *
     * Signal send when settings at form was changed and accepted.
     * This signal notify all another modules about changes at settings widget.
     * \sa notifyAllAboutChanges()
     */
    void settingsChanged();
    /*!
     * \brief Settings was saved.
     * \sa saveSettings()
     *
     * This signal emited when user clicked on Ok or Apply button at settings widget form.
     */
    void settingsSaved();

private slots:
    /*!
     * \brief Broadcast notifier.
     *
     * This slot emit settingsChanged() signal and notify another modules about changes.
     */
    void notifyAllAboutChanges();

    /*!
     * \brief Save settings.
     *
     * This slot call when user clicked on Ok or Apply button at settings widget form.
     * The settings specified at form save at QSettings storage.
     * \sa settingsChanged()
     */
    void saveSettings();

    /*!
     * \brief Update settings.
     *
     * This slot update settings from QSettings storage when form load or Cancel button clicked.
     */
    void readSettings();

    /*!
     * \brief Reset values server params.
     *
     * Reset values server params to default.
     * \sa Constants::Server
     */
    void defaultServerBtnClicked();

    /*!
     * \brief Chose folder for temporaty files.
     *
     * This method open user dialogs with chosing folder for storage temporary files.
     */
    void choseFolderClicked();

    /*!
     * \brief Reset chosen temporaty folder to default.
     * \sa Constants::TemporaryFolders
     */
    void resetFolderClicked();

    /*!
     * \brief Chose location of database file.
     * \sa Constants::Database
     * \sa DbWriter
     *
     * This method open user dialogs with chosing db file location.
     */
    void choseDbLocationClicked();

    /*!
     * \brief Chose folde of SVM lib files.
     * \sa Constants::SVM
     * \sa SVMPredictor
     *
     * This method open user dialogs with chosing folder where SVM libs stored.
     */
    void choseSVMFolderClicked();

    /*!
     * \brief This slot call when user change host mode.
     * \param state Represent Any mode or Custom.
     *
     * Enable or disable input mode controls.
     * \sa Server
     */
    void hostModeChanged(bool);

    /*!
     * \brief Reset values to database connection.
     *
     * Reset values server params to default.
     * \sa Constants::Database
     */
    void defaultDatabaseBtnClicked();

    /*!
     * \brief Test database connection.
     *
     * Test connection with specified db location and parameters.
     * Show dialog message about result of connection.
     * \sa Constants::Database
     */
    void testDbConnection();

    /*!
     * \brief Chose location of model SVM file.
     * \sa Constants::SVM
     * \sa SVMPredictor
     *
     * This method open user dialogs with chosing model file location.
     */
    void choseModelFilePath();

    /*!
     * \brief Chose folde of SVM temporary files.
     * \sa Constants::SVM
     * \sa SVMPredictor
     *
     * This method open user dialogs with chosing folder where SVM temporary files will be stored.
     */
    void choseTemporarySVMFolderClicked();

    /*!
     * \brief Reset chosen temporaty SVM folder to default.
     * \sa Constants::SVM
     */
    void resetSVMTempFolder();

};

#endif // SETTINGSWIDGET_H
