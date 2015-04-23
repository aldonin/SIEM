#include <QtWidgets/QApplication>
#include "agentapplication.h"
#include "settingswidget.h"
#include "collector.h"
#include "watcher.h"
#include "journalfinder.h"


#include <QDebug>

int main(int argc, char* argv[])
{
   AgentApplication app(argc, argv);
   return app.exec();
}


/**

  Содержимое скрипта
 *  (Get-EventLog -LogName 'Application' -Newest 13 |ConvertTo-Xml -noTypeInformation).save("D:\testNoType.xml")
     Get-Process Powershell | Stop-Process

 *
 *
*/
