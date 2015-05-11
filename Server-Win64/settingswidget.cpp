#include "settingswidget.h"
#include <QCloseEvent>
#include <QSettings>
#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>

#include "constants.h"
#include "simplecrypt.h"

using namespace Constants::Server;
using namespace Constants::Time;
using namespace Constants::TemporaryFolders;
using namespace Constants::Database;
using namespace Constants::SVM;

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

    // Дефолтные настройки подключения к базе
    connect(defaultDBBtn, SIGNAL(clicked()), this, SLOT(defaultDatabaseBtnClicked()));

    // Выбор папок для хранения временных файлов
    connect(xmlBrowseFolderBtn, SIGNAL(clicked()), this, SLOT(choseFolderClicked()));

    // Выбор пути к БД
    connect(dbLocationBtn, SIGNAL(clicked()), this, SLOT(choseDbLocationClicked()));

    // Сбросить папки для хранения файлов на дефолтные
    connect(xmlResetFolderBtn, SIGNAL(clicked()), this, SLOT(resetFolderClicked()));

    // Протестировать соединение с выбранной БД
    connect(testDBBtn, SIGNAL(clicked()), this, SLOT(testDbConnection()));

    // Выбрать папку для SVM библиотек
    connect(SVMFolderBtn, SIGNAL(clicked()), this, SLOT(choseSVMFolderClicked()));

    // Выбрать файл модели SVM
    connect(ModelFileBtn, SIGNAL(clicked()), this, SLOT(choseModelFilePath()));

    // Сбросить папку для временных файлов SVM на дефолтную
    connect(resetTempSVMBtn, SIGNAL(clicked()), this, SLOT(resetSVMTempFolder()));

    // Выбрать папку для времнных файлов SVM
    connect(tempSVMBtn, SIGNAL(clicked()), this, SLOT(choseTemporarySVMFolderClicked()));
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
    settings.setValue("Host", AnyRB->isChecked() ? QHostAddress(QHostAddress::Any).toString() : hostEdit->text() );
    settings.setValue("Port", portEdit->text().toUInt());
    settings.endGroup();


    // Temporary folders
    settings.beginGroup("Path");

    // Удалим папки, которые были созданы до этого
    QString oldDir = settings.value("XmlTemporary", QVariant("")).toString();
    if (!oldDir.isEmpty())
        QDir().rmdir(oldDir);

    settings.setValue("XmlTemporary", xmlFolderEdit->text());

    // Создадим новые папки
    if ( !QDir(xmlFolderEdit->text()).exists() )
        QDir().mkdir(xmlFolderEdit->text());

    settings.endGroup();




    // Database
    settings.beginGroup("Database");
    settings.setValue("Location", dbLocation->text());
    settings.setValue("Name", dbName->text());
    settings.setValue("User", dbUser->text());
    SimpleCrypt crypt;
    crypt.setKey(Constants::Crypto::KEY);
    QString encryptedPassword = crypt.encryptToString(dbPass->text());
    settings.setValue("Password", encryptedPassword);
    settings.endGroup();

    // SVM
    settings.beginGroup("SVM");
    settings.setValue("LibraryPath",     SVMEdit->text());
    settings.setValue("ModelFilePath",   ModelFileEdit->text());

    // Удалим папки, которые были созданы до этого
    QString oldDirSVM = settings.value("TemporaryFolder", QVariant("")).toString();
    if (!oldDirSVM.isEmpty())
        QDir().rmdir(oldDirSVM);

    settings.setValue("TemporaryFolder", tempSVMEdit->text());

    // Создадим новые папки
    if ( !QDir(tempSVMEdit->text()).exists() )
        QDir().mkdir(tempSVMEdit->text());
    settings.endGroup();

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


    // Database
    settings.beginGroup("Database");

    dbLocation->setText( settings.value("Location", QVariant(DEFAULT_DB_LOCATION)).toString() );
    dbName->setText( settings.value("Name", QVariant(DEFAULT_DB_NAME)).toString() );
    dbUser->setText( settings.value("User", QVariant(DEFAULT_DB_USERNAME)).toString() );

    QString enctyptedPassword = settings.value("Password", QVariant(DEFAULT_DB_PASSWORD)).toString();
    if (enctyptedPassword != DEFAULT_DB_PASSWORD) {
        SimpleCrypt crypt;
        crypt.setKey(Constants::Crypto::KEY);
        enctyptedPassword = crypt.decryptToString( enctyptedPassword );
    }

    dbPass->setText( enctyptedPassword );


    settings.endGroup();

    // SVM
    settings.beginGroup("SVM");
    SVMEdit->setText( settings.value("LibraryPath", QVariant(DEFAULT_SVM_PATH)).toString() );
    ModelFileEdit->setText( settings.value("ModelFilePath", QVariant(DEFAULT_SVM_MODEL_FILE_PATH)).toString() );
    tempSVMEdit->setText( settings.value("TemporaryFolder", QVariant(QCoreApplication::applicationDirPath() + "/" + DEFAULT_SVM_FOLDER_TEMPORARY)).toString() );

    if (!QDir(tempSVMEdit->text()).exists())
        QDir().mkdir(tempSVMEdit->text());

    settings.endGroup();
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

void SettingsWidget::choseDbLocationClicked()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                tr("Open database file"),
                                                QCoreApplication::applicationDirPath());

    // User presses Cancel
    if ( file.isNull() )
        return;

    dbLocation->setText(file);
}

void SettingsWidget::choseSVMFolderClicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,
                                                    tr("Chose Directory"),
                                                    QCoreApplication::applicationDirPath(),
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!dir.isEmpty() && QDir(dir).exists()) {
        QStringList files;
        files << "libsvm.dll" << "svm-predict.exe" << "svmpredict.mexw64";

        foreach (QString file, files) {
            if (!QFile::exists(dir + "/" + file)) {
                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Warning);
                msgBox.setWindowIcon(QIcon(":serverIcon.png"));
                msgBox.setText(QString("Can't find %1 at current directory").arg(file));
                msgBox.exec();
                return;
            }
        }

        SVMEdit->setText( dir );
    }
}

void SettingsWidget::hostModeChanged(bool state)
{
    hostLbl->setEnabled(state);
    hostEdit->setEnabled(state);
}

void SettingsWidget::defaultDatabaseBtnClicked()
{
    dbLocation->setText( DEFAULT_DB_LOCATION );
    dbName->setText( DEFAULT_DB_NAME );
    dbUser->setText( DEFAULT_DB_USERNAME );
    dbPass->setText( DEFAULT_DB_PASSWORD );
}

void SettingsWidget::testDbConnection()
{
    {
        // Добавим новую БД с именем TEST_DB_CONNECTION_NAME в список зарегистрированных БД
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", TEST_DB_CONNECTION_NAME);

        db.setDatabaseName(dbLocation->text());
        db.setUserName(dbUser->text());
        db.setHostName(dbName->text());
        db.setPassword(dbPass->text());

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowIcon(QIcon(":serverIcon.png"));
        // Попытаемся соединиться с базой и проверить БД ли вообще это
        QString status = db.open() && !db.tables().isEmpty() ? "Success" : "Failed";
        msgBox.setText( QString("Connection database status: %1")
                        .arg(status)
                        );

        msgBox.exec();
    }

    // Удалим созданную базу с именем TEST_DB_CONNECTION_NAME из списка зарегистрированных БД
    QSqlDatabase::removeDatabase(TEST_DB_CONNECTION_NAME);
}

void SettingsWidget::choseModelFilePath()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                tr("Chose model file path"),
                                                QCoreApplication::applicationDirPath());

    // User presses Cancel
    if ( file.isNull() )
        return;

    ModelFileEdit->setText(file);
}

void SettingsWidget::choseTemporarySVMFolderClicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,
                                                    tr("Chose Directory"),
                                                    QCoreApplication::applicationDirPath(),
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (dir.isEmpty())
        return;

    if (!QDir(dir).exists())
        QDir().mkdir(dir);

    tempSVMEdit->setText( dir );
}

void SettingsWidget::resetSVMTempFolder()
{
    tempSVMEdit->setText( QCoreApplication::applicationDirPath() + "/" + DEFAULT_SVM_FOLDER_TEMPORARY );
}

void SettingsWidget::notifyAllAboutChanges()
{
    emit settingsChanged();
}
