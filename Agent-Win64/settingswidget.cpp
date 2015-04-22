#include "settingswidget.h"
#include <QCloseEvent>
#include <QSettings>


#include <QDebug>


SettingsWidget::SettingsWidget(QWidget *parent) :
    QWidget(parent), m_isCanClose(false)
{
    setupUi(this);

    readSettings();

    connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));   
    connect(listWidget, SIGNAL(currentTextChanged(QString)), categoryName, SLOT(setText(QString)));

    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(readSettings()));
    connect(cancelBtn,  SIGNAL(clicked()), this, SLOT(close()));
    connect(okBtn, SIGNAL(clicked()), this, SLOT(saveSettings()));
    connect(okBtn, SIGNAL(clicked()), this, SLOT(close()));
    connect(applyBtn, SIGNAL(clicked()), this, SLOT(saveSettings()));

    connect(this, SIGNAL(settingsSaved()), this, SLOT(notifyAllAboutChanges()));


}

bool SettingsWidget::isCanClose() const
{
    return m_isCanClose;
}

void SettingsWidget::setIsCanClose(const bool value)
{
    m_isCanClose = value;
}

void SettingsWidget::closeEvent(QCloseEvent *ev)
{
   if (m_isCanClose) {
       ev->accept();
   } else {
       this->hide();
       ev->ignore();
   }
}


void SettingsWidget::saveSettings()
{
    QSettings settings;
    settings.beginGroup("monitoredJournals");
    settings.setValue("Application",     appBox->isChecked());
    settings.setValue("Security",        secBox->isChecked());
    settings.setValue("Setup",           setupBox->isChecked());
    settings.setValue("System",          systemBox->isChecked());
    settings.setValue("ForwardedEvents", feBox->isChecked());
    settings.endGroup();

    // 0 - timedMode, 1 - fileChangedMode
    int mode = timedMode->isChecked() ? 0 : 1;
    settings.setValue("watcherMode/mode", mode);

    settings.setValue("general/Startup", startUp->isChecked());

    emit settingsSaved();
}

void SettingsWidget::readSettings()
{
    QSettings settings;
    settings.beginGroup("monitoredJournals");
    appBox->setChecked(settings.value("Application").toBool());
    secBox->setChecked(settings.value("Security").toBool());
    setupBox->setChecked(settings.value("Setup").toBool());
    systemBox->setChecked(settings.value("System").toBool());
    feBox->setChecked(settings.value("ForwardedEvents").toBool());
    settings.endGroup();

    int mode = settings.value("watchedMode/mode").toInt();
    timedMode->setChecked( mode == 0 ? true : false);

    startUp->setChecked(settings.value("general/Startup").toBool());
}

void SettingsWidget::notifyAllAboutChanges()
{
    emit settingsChanged();
}
