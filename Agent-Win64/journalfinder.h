#ifndef JOURNALFINDER_H
#define JOURNALFINDER_H

#include <QString>
#include "agentapplication.h"

class JournalFinder
{
public:
    static QString path(AgentApplication::Journal type);
    static bool found();

private:
    JournalFinder();
    ~JournalFinder();
};

#endif // JOURNALFINDER_H
