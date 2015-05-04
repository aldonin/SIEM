#include <QCoreApplication>

#include "server.h"
#include "xmlreader.h"
#include "journalevent.h"

#include <QDebug>
#include <QList>


int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    //typedef QList<JournalEvent*> ListOfEvents;
    //qRegisterMetaType<ListOfEvents>("ListOfEvents");
    //qRegisterMetaType<QList<JournalEvent*>& >("QList<JournalEvent*>&");
    Server server;
    server.start();
    return app.exec();

}

