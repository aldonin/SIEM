#include <QCoreApplication>

#include "serverapplication.h"
#include "simplecrypt.h"
#include "journalevent.h"

#include <QDebug>


int main(int argc, char* argv[])
{
    ServerApplication app(argc, argv);

    return app.exec();
}

