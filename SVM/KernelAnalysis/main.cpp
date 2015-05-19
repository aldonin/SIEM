#include <QFile>
#include <QTimer>
#include <QDebug>
#include <QtWidgets/QApplication>
#include <QTextCodec>
#include "shellasker.h"
#include <QDebug>
#include <QThread>
#include <QObject>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QThread *thread  = new QThread;

    ShellAsker *asker = new ShellAsker;
    QObject::connect(thread, SIGNAL(started()),  asker,  SLOT(startAsking()));
    QObject::connect(asker,  SIGNAL(finished()), thread, SLOT(quit()));
    QObject::connect(asker,  SIGNAL(finished()), asker,  SLOT(deleteLater()));
    QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    QObject::connect(asker, SIGNAL(finished()), &app, SLOT(quit()));


    thread->start();

    return app.exec();
}
