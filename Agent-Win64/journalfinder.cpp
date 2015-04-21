#include "journalfinder.h"

#include <QDir>
#include <QDebug>

QString JournalFinder::path(AgentApplication::Journal type)
{
    bool ok = false;
    QString path = found(ok);
    if (ok) {
        if (QSysInfo::windowsVersion() > QSysInfo::WV_XP)
            return QString(path + "/%1.%2")
                    .arg( AgentApplication::journalToString(type) ).arg("evtx");
        else
            return QString(path + "/%1.%2")
                    .arg( AgentApplication::journalToString(type) ).arg("evt");
    } else {
        return QString();
    }
}

QString JournalFinder::found(bool &ok)
{
    QDir dir = QDir(QDir::rootPath());

    if (!dir.cd("Windows"))
        ok = false;

    if (QSysInfo::windowsVersion() <= QSysInfo::WV_XP){
        if (!dir.cd("System32"))
            ok = false;
        if (!dir.cd("config"))
            ok = false;
    } else {
        if (!dir.cd("Sysnative"))
            ok = false;
        if (!dir.cd("winevt"))
            ok = false;
        if (!dir.cd("Logs"))
            ok = false;
    }

    ok = true;
    return dir.path();
}

JournalFinder::JournalFinder()
{}

JournalFinder::~JournalFinder()
{}

