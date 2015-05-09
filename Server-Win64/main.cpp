#include <QCoreApplication>

#include "serverapplication.h"
#include "simplecrypt.h"
#include "journalevent.h"

#include <QDebug>


int main(int argc, char* argv[])
{
    ServerApplication app(argc, argv);

    return app.exec();

//    QString entryType = "0";
//    JournalEvent ev;
//    int x = ev.EntryTypefromString(entryType);
//    qDebug() << x;

    return 0;
}

