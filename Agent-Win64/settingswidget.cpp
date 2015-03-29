#include "settingswidget.h"

SettingsWidget::SettingsWidget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
    connect(listWidget, SIGNAL(currentTextChanged(QString)), categoryName, SLOT(setText(QString)));
}
