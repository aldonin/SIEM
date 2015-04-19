#include "settingswidget.h"
#include <QCloseEvent>

SettingsWidget::SettingsWidget(QWidget *parent) :
    QWidget(parent), m_isCanClose(false)
{
    setupUi(this);

    connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));   
    connect(listWidget, SIGNAL(currentTextChanged(QString)), categoryName, SLOT(setText(QString)));

    connect(cancelBtn,  SIGNAL(clicked()), this, SLOT(close()));

    connect(okBtn, SIGNAL(clicked()), this, SLOT(saveSettings()));
    connect(okBtn, SIGNAL(clicked()), this, SLOT(close()));

    connect(applyBtn, SIGNAL(clicked()), this, SLOT(saveSettings()));
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
    //TODO save settings to QSettings
}

void SettingsWidget::notifyAllAboutChanges()
{
    emit settingsChanged();
}
