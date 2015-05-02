#ifndef GLOBALNAMESPACE
#define GLOBALNAMESPACE

namespace Constants {
    namespace Time {

        const int SECOND_PER_MINUTE     = 60;
        const int MSEC_PER_SECOND       = 1000;
        const int DEFAULT_TIMER_TIMEOUT = 1;
    }

    namespace TemporaryFolders {
        const char DEFAULT_FOLDER_PSSCRIPT_TEMPORARY[] = "PSScript_temporary";
        const char DEFAULT_FOLDER_XML_TEMPORARY[]      = "Xml_temporary";
    }

    namespace Server {
        const char DEFAULT_HOST_NAME[] = "localhost";
        const int  DEFAULT_PORT        = 2323;
    }

    namespace PowerShell {
        const char DEFAULT_SHELL_PARAM[] = "-NoProfile –ExecutionPolicy Unrestricted";
    }
}

#endif // GLOBALNAMESPACE

