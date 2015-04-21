#include <QtWidgets/QApplication>
#include "agentapplication.h"
#include "settingswidget.h"
#include "collector.h"
#include "watcher.h"
#include "journalfinder.h"


#include <QDebug>
#include <QThread>

int main(int argc, char* argv[])
{
   //QApplication app(argc, argv);
   AgentApplication app(argc, argv);
   qDebug() <<JournalFinder::path(AgentApplication::Application);

  //SettingsWidget w;
   //w.show();
   //Collector c;
   //c.collect();

    //Watcher w;




    return app.exec();
  // return 0;
}
