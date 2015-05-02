#include "settingswidget.h"
#include <QCloseEvent>
#include <QSettings>
#include <QDebug>
#include <QDir>
#include <QFileDialog>

#include "constants.h"

using namespace Constants::PowerShell;
using namespace Constants::Server;
using namespace Constants::TemporaryFolders;
using namespace Constants::Time;

SettingsWidget::SettingsWidget(QWidget *parent) :
    QWidget(parent), m_isCanClose(false)
{
    setupUi(this);

    readSettings();

    // Переключение между элементами меню настройки
    connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));   
    connect(listWidget, SIGNAL(currentTextChanged(QString)), categoryName, SLOT(setText(QString)));

    // Глобальные кнопки Сохранить, Отменить, Применить
    connect(cancelBtn,  SIGNAL(clicked()), this, SLOT(readSettings()));
    connect(cancelBtn,  SIGNAL(clicked()), this, SLOT(close()));
    connect(okBtn,      SIGNAL(clicked()), this, SLOT(saveSettings()));
    connect(okBtn,      SIGNAL(clicked()), this, SLOT(close()));
    connect(applyBtn,   SIGNAL(clicked()), this, SLOT(saveSettings()));

    // Оповещение о изменении настроек
    connect(this,       SIGNAL(settingsSaved()), this, SLOT(notifyAllAboutChanges()));

    // Изменение режима работы, активация ввода времени
    connect(timedMode,  SIGNAL(toggled(bool)),   this, SLOT(modeChanged(bool)));

    // Задание дефолтных настроек локации сервера и параметров запроса PS
    connect(defaultServerBtn, SIGNAL(clicked()), this, SLOT(defaultServerBtnClicked()));
    connect(defaultShellBtn, SIGNAL(clicked()), this, SLOT(defaultShellBtnClicked()));

    // Выбор папок для хранения временных файлов
    connect(psScriptBrowseFolderBtn, SIGNAL(clicked()), this, SLOT(choseFolderClicked()));
    connect(xmlBrowseFolderBtn,      SIGNAL(clicked()), this, SLOT(choseFolderClicked()));

    // Сбросить папки для хранения файлов на дефолтные
    connect(psScriptResetFolderBtn, SIGNAL(clicked()), this, SLOT(resetFolderClicked()));
    connect(xmlResetFolderBtn,      SIGNAL(clicked()), this, SLOT(resetFolderClicked()));
}

SettingsWidget::~SettingsWidget()
{
    qDebug() << "~SettingsWidget()";
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
    settings.setValue("watchedMode/mode", mode);
    settings.setValue("watchedMode/timedMode/timeout", minDelay->value());

    settings.setValue("general/Startup", startUp->isChecked());

    settings.beginGroup("server");
    settings.setValue("host", hostEdit->text());
    settings.setValue("port", portEdit->text().toUInt());
    settings.endGroup();

    settings.setValue("PowerShell/executeParams", shellEdit->text().simplified());


    settings.beginGroup("Path");
    // Удалим папки, которые были созданы до этого
    QString currentDir = settings.value("PSScriptTemporary", QVariant("")).toString();
    if (!currentDir.isEmpty())
        QDir().rmdir(currentDir);

    currentDir = settings.value("XmlTemporary", QVariant("")).toString();

    if (!currentDir.isEmpty())
        QDir().rmdir(currentDir);

    settings.setValue("PSScriptTemporary", psScriptFolderEdit->text());
    settings.setValue("XmlTemporary", xmlFolderEdit->text());
    settings.endGroup();

    // Создадим новые папки
    if (!QDir(psScriptFolderEdit->text()).exists())
        QDir().mkdir(psScriptFolderEdit->text());

    if (!QDir(xmlFolderEdit->text()).exists())
        QDir().mkdir(xmlFolderEdit->text());

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
    mode == 0 ? timedMode->setChecked(true) : fileChangeMode->setChecked(true);
    minDelay->setValue(settings.value("watchedMode/timedMode/timeout", QVariant(DEFAULT_TIMER_TIMEOUT)).toInt());

    startUp->setChecked(settings.value("general/Startup").toBool());

    settings.beginGroup("server");
    hostEdit->setText( settings.value("host", QVariant(DEFAULT_HOST_NAME)).toString() );
    portEdit->setText( QString::number( settings.value("port", QVariant(DEFAULT_PORT)).toUInt() ) );
    settings.endGroup();

    shellEdit->setText( settings.value("PowerShell/executeParams", QVariant(DEFAULT_SHELL_PARAM)).toString() );

    settings.beginGroup("Path");
    psScriptFolderEdit->setText( settings.value("PSScriptTemporary", QVariant(QCoreApplication::applicationDirPath() + "/" + DEFAULT_FOLDER_PSSCRIPT_TEMPORARY)).toString() );
    xmlFolderEdit->setText(      settings.value("XmlTemporary",      QVariant(QCoreApplication::applicationDirPath() + "/" + DEFAULT_FOLDER_XML_TEMPORARY)).toString() );
    settings.endGroup();

    qDebug() << psScriptFolderEdit->text() << " " << xmlFolderEdit->text();
    if (!QDir(psScriptFolderEdit->text()).exists())
        QDir().mkdir(psScriptFolderEdit->text());

    if (!QDir(xmlFolderEdit->text()).exists())
        QDir().mkdir(xmlFolderEdit->text());
}

void SettingsWidget::modeChanged(bool state)
{
    label->setEnabled(state);
    minDelay->setEnabled(state);
}

void SettingsWidget::defaultServerBtnClicked()
{
    hostEdit->setText(DEFAULT_HOST_NAME);
    portEdit->setText(QString::number(DEFAULT_PORT));
}

void SettingsWidget::defaultShellBtnClicked()
{
    shellEdit->setText(DEFAULT_SHELL_PARAM);
}

void SettingsWidget::choseFolderClicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,
                                                    tr("Chose Directory"),
                                                    QCoreApplication::applicationDirPath(),
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (dir.isEmpty())
        return;

    if (!QDir(dir).exists())
        QDir().mkdir(dir);

    QPushButton *btn = dynamic_cast<QPushButton*>(sender());

    if ( btn->objectName() == "xmlBrowseFolderBtn" )
        xmlFolderEdit->setText(dir);
    else
        psScriptFolderEdit->setText(dir);
}

void SettingsWidget::resetFolderClicked()
{
    QPushButton *btn = dynamic_cast<QPushButton*>(sender());

    if  ( btn->objectName() == "xmlResetFolderBtn" ) {
        if (!QDir(DEFAULT_FOLDER_XML_TEMPORARY).exists())
            QDir().mkdir(DEFAULT_FOLDER_XML_TEMPORARY);

        xmlFolderEdit->setText( QCoreApplication::applicationDirPath() + "/" + DEFAULT_FOLDER_XML_TEMPORARY );
    } else {
        if (!QDir(DEFAULT_FOLDER_PSSCRIPT_TEMPORARY).exists())
            QDir().mkdir(DEFAULT_FOLDER_PSSCRIPT_TEMPORARY);

        psScriptFolderEdit->setText( QCoreApplication::applicationDirPath() + "/" + DEFAULT_FOLDER_PSSCRIPT_TEMPORARY );
    }
}

void SettingsWidget::notifyAllAboutChanges()
{
    emit settingsChanged();
}
