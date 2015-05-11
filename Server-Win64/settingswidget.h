#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include "ui_settingswidget.h"

class SettingsWidget : public QWidget, private Ui::SettingsWidget
{
    Q_OBJECT

public:
    explicit SettingsWidget(QWidget *parent = 0);
    ~SettingsWidget();

    bool isCanClose() const;
    void setIsCanClose(const bool value);

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
    bool m_isCanClose;

signals:
    void settingsChanged();
    void settingsSaved();

private slots:
    // Оповещение о изменении настроек
    void notifyAllAboutChanges();

    // Запись настроек в реестр
    void saveSettings();

     // Чтение настроек из реестра
    void readSettings();

    // Задание дефолтных настроек локации сервера
    void defaultServerBtnClicked();

    // Выбор папок для хранения временных файлов
    void choseFolderClicked();

    // Сбросить папки для хранения файлов на дефолтные
    void resetFolderClicked();

    // Выбор пути к БД
    void choseDbLocationClicked();

    // Выбрать папку для SVM библиотек
    void choseSVMFolderClicked();

    // Смена режима хоста сервера Any-Custom
    void hostModeChanged(bool);

    // Дефолтные настройки подключения к базе
    void defaultDatabaseBtnClicked();

    // Протестировать соединение с выбранной БД
    void testDbConnection();

    // Выбрать файл модели SVM
    void choseModelFilePath();

    // Выбрать папку для времнных файлов SVM
    void choseTemporarySVMFolderClicked();

    // Сбросить папку для временных файлов SVM на дефолтную
    void resetSVMTempFolder();

};

#endif // SETTINGSWIDGET_H
