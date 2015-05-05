#include <QCoreApplication>

#include "server.h"
#include "xmlreader.h"
#include "journalevent.h"
#include "serverapplication.h"

#include <QDebug>
#include <QList>


int main(int argc, char* argv[])
{
    //QCoreApplication app(argc, argv);
    ServerApplication app(argc, argv);

//    Server server;
//    server.start();

    return app.exec();

}

