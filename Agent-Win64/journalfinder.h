#ifndef JOURNALFINDER_H
#define JOURNALFINDER_H

#include <QString>
#include "agentapplication.h"

/*!
 * \brief Class for finding journals at OS.
 *
 * Only static methods and private constructors.
 */
class JournalFinder
{
public:
    /*!
     * \brief Find path to specified journal type.
     * \param type Journal type.
     * \return Full path file to found journal, in case journal not found return empty string.
     */
    static QString path(AgentApplication::Journal type);

    /*!
     * \brief Find journals dir at current OS.
     * \param ok Reference bool &ok variable, indicates result of finding.
     * \return true if dir is found, otherwise false.
     */
    static QString found(bool &ok);

private:
    JournalFinder();
    ~JournalFinder();
};

#endif // JOURNALFINDER_H
