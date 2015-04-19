#include "journalfinder.h"

#include <QDir>

QString JournalFinder::path(AgentApplication::Journal type)
{
    if (found())
        return QString(QDir::rootPath() + "Windows/Sysnative/winevt/Logs/%1.evtx")
                .arg( AgentApplication::journalToString(type) );
    else
        return QString();
}

bool JournalFinder::found()
{
    QDir dir = QDir(QDir::rootPath());
    if (!dir.cd("Windows"))
        return false;
    if (!dir.cd("Sysnative"))
        return false;
    if (!dir.cd("winevt"))
        return false;
    if (!dir.cd("Logs"))
        return false;

    return true;
}

JournalFinder::JournalFinder()
{}

JournalFinder::~JournalFinder()
{}

