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

    namespace Database {
        const char DEFAULT_DB_NAME[]     = "database";
        const char DEFAULT_DB_USERNAME[] = "admin";
        const char DEFAULT_DB_PASSWORD[] = "administrator";
        const char DEFAULT_DB_LOCATION[] = "localhost";
    }

    namespace Crypto {
        const quint64 KEY = Q_UINT64_C(0x0a9dc2a6cab3f78a);
    }

}

#endif // CONSTANTS

