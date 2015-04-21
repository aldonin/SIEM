#ifndef JOURNALFINDER_H
#define JOURNALFINDER_H

#include <QString>
#include "agentapplication.h"

class JournalFinder
{
public:
    static QString path(AgentApplication::Journal type);
    static QString found(bool &ok);

private:
    JournalFinder();
    ~JournalFinder();
};

#endif // JOURNALFINDER_H
