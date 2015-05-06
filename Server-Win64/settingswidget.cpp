#include "settingswidget.h"
#include <QCloseEvent>
#include <QSettings>
#include <QDebug>
#include <QDir>
#include <QFileDialog>

#include "constants.h"


using namespace Constants::Server;
using namespace Constants::Time;
using namespace Constants::TemporaryFolders;

SettingsWidget::SettingsWidget(QWidget *parent) :
    QWidget(parent), m_isCanClose(false)
{
    setupUi(this);

    readSettings();

    // Переключение между элементами меню настройки
    connect(listWidget, SIGNAL(currentRowChanged(int)),     stackedWidget, SLOT(setCurrentIndex(int)));
    connect(listWidget, SIGNAL(currentTextChanged(QString)), categoryName, SLOT(setText(QString)));

    // Глобальные кнопки Сохранить, Отменить, Применить
    connect(cancelBtn,  SIGNAL(clicked()), this, SLOT(readSettings()));
    connect(cancelBtn,  SIGNAL(clicked()), this, SLOT(close()));
    connect(okBtn,      SIGNAL(clicked()), this, SLOT(saveSettings()));
    connect(okBtn,      SIGNAL(clicked()), this, SLOT(close()));
    connect(applyBtn,   SIGNAL(clicked()), this, SLOT(saveSettings()));

    // Оповещение о изменении настроек
    connect(this, SIGNAL(settingsSaved()), this, SLOT(notifyAllAboutChanges()));

    // Смена режима хоста сервера Any-Custom
    connect(customRB, SIGNAL(toggled(bool)), this, SLOT(hostModeChanged(bool)));


    // Задание дефолтных настроек локации сервера
    connect(defaultServerBtn, SIGNAL(clicked()), this, SLOT(defaultServerBtnClicked()));

    // Выбор папок для хранения временных файлов
    connect(xmlBrowseFolderBtn, SIGNAL(clicked()), this, SLOT(choseFolderClicked()));

    // Сбросить папки для хранения файлов на дефолтные
    connect(xmlResetFolderBtn, SIGNAL(clicked()), this, SLOT(resetFolderClicked()));
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

    // General
    settings.setValue("General/Startup", startUp->isChecked());


    // Sever
    settings.beginGroup("Server");
    settings.setValue("Host", AnyRB->isChecked() ? "0" : hostEdit->text() );
    settings.setValue("Port", portEdit->text().toUInt());
    settings.endGroup();


    // Temporary folders
    settings.beginGroup("Path");

    // Удалим папки, которые были созданы до этого
    QString oldDir = settings.value("XmlTemporary", QVariant("")).toString();
    if (!oldDir.isEmpty())
        QDir().rmdir(oldDir);

    settings.setValue("XmlTemporary", xmlFolderEdit->text());
    settings.endGroup();

    // Создадим новые папки
    if ( !QDir(xmlFolderEdit->text()).exists() )
        QDir().mkdir(xmlFolderEdit->text());


    // TODO Database

    emit settingsSaved();
}

void SettingsWidget::readSettings()
{
    QSettings settings;

    // General
    startUp->setChecked( settings.value("General/Startup", QVariant(false)).toBool() );


    // Server
    settings.beginGroup("Server");
    portEdit->setText( QString::number(settings.value("Port", QVariant(DEFAULT_PORT)).toUInt()) );
    QString host = settings.value("Host", QVariant(DEFAULT_HOST.toString())).toString();
    if ( host == "0" || host == DEFAULT_HOST.toString() ) {
        AnyRB->setChecked(true);
        hostEdit->setEnabled(false);
        hostLbl->setEnabled(false);
    } else {
        customRB->setChecked(true);
        hostEdit->setText(host);
    }

    settings.endGroup();


    // Temporary folders
    settings.beginGroup("Path");
    xmlFolderEdit->setText( settings.value("XmlTemporary", QVariant(QCoreApplication::applicationDirPath() + "/" + DEFAULT_FOLDER_XML_TEMPORARY)).toString() );

    if (!QDir(xmlFolderEdit->text()).exists())
        QDir().mkdir(xmlFolderEdit->text());
    settings.endGroup();


    // TODO Database

}



void SettingsWidget::defaultServerBtnClicked()
{
    AnyRB->setChecked(true);
    portEdit->setText(QString::number(DEFAULT_PORT));
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

    xmlFolderEdit->setText(dir);
}

void SettingsWidget::resetFolderClicked()
{
    xmlFolderEdit->setText( QCoreApplication::applicationDirPath() + "/" + DEFAULT_FOLDER_XML_TEMPORARY );
}

void SettingsWidget::hostModeChanged(bool state)
{
    hostLbl->setEnabled(state);
    hostEdit->setEnabled(state);
}

void SettingsWidget::notifyAllAboutChanges()
{
    emit settingsChanged();
}
