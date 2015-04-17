#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include "ui_settingswidget.h"

class SettingsWidget : public QWidget, private Ui::SettingsWidget
{
    Q_OBJECT

public:
    explicit SettingsWidget(QWidget *parent = 0);

    bool isCanClose() const;
    void setIsCanClose(const bool value);

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    bool m_isCanClose;

signals:
    void settingsChanged();

private slots:
    void notifyAllAboutChanges();
    void saveSettings();
};

#endif // SETTINGSWIDGET_H
