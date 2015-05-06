#include <QCoreApplication>

#include "serverapplication.h"
#include "simplecrypt.h"

#include <QDebug>
#include <QList>



int main(int argc, char* argv[])
{
    ServerApplication app(argc, argv);

    return app.exec();

}

