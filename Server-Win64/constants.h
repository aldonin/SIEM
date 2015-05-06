#ifndef CONSTANTS
#define CONSTANTS

#include <QHostAddress>

namespace Constants {

    namespace Server {
        const QHostAddress DEFAULT_HOST = QHostAddress::Any;
        const int          DEFAULT_PORT = 2323;
    }

    namespace Time {
        const int SECOND_PER_MINUTE = 60;
        const int MSEC_PER_SECOND   = 1000;
    }

    namespace TemporaryFolders {
        const char DEFAULT_FOLDER_XML_TEMPORARY[] = "Xml_temporary";
    }

}

#endif // CONSTANTS

