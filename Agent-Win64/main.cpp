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
    AgentApplication app(argc, argv);
    return app.exec();
}
