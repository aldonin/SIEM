#include <QCoreApplication>

#include "server.h"


int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    Server server;
    server.start();

    return app.exec();
}

