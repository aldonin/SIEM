#include <QtWidgets/QApplication>
#include "agentapplication.h"
#include "settingswidget.h"

int main(int argc, char* argv[])
{
   QApplication app(argc, argv);
    // AgentApplication app(argc, argv);

   SettingsWidget w;
   w.show();

    return app.exec();
}
