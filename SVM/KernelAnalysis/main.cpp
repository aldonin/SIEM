#include <QtWidgets/QApplication>

#include "shellasker.h"
#include <QDebug>
#include <QThread>
#include <QObject>
#include <QProcess>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QThread *thread  = new QThread;

    ShellAsker *asker = new ShellAsker;
    asker->moveToThread(thread);
    QObject::connect(thread, SIGNAL(started()),  asker,  SLOT(startAsking()));
    QObject::connect(asker,  SIGNAL(finished()), thread, SLOT(quit()));
    QObject::connect(asker,  SIGNAL(finished()), asker,  SLOT(deleteLater()));
    QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    QObject::connect(asker, SIGNAL(finished()), &app, SLOT(quit()));


    thread->start();


    return app.exec();
}
