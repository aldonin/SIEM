#include <QtWidgets/QApplication>
#include "agentapplication.h"
#include "settingswidget.h"
#include "collector.h"
#include "watcher.h"
#include "journalfinder.h"

#include <QFile>


#include <QDebug>

int main(int argc, char* argv[])
{
   //QApplication app(argc, argv);
    AgentApplication app(argc, argv);

   //QFile file("Application-29.04.2015_17-49-28.xml");
   //qDebug() << file.exists();

   return app.exec();
}
// FIXME Если журнал пуст - то ps ничего не возвращает и не создает файла

