#include <QCoreApplication>

#include "server.h"

#include "xmlreader.h"
#include "journalevent.h"
#include "serverapplication.h"

#include <QDebug>
#include <QList>



int main(int argc, char* argv[])
{

    ServerApplication app(argc, argv);

    return app.exec();

}

