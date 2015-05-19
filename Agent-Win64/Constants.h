#ifndef GLOBALNAMESPACE
#define GLOBALNAMESPACE

//! Agent application constants
namespace Constants {

    //! Time namespace
    namespace Time {
        //! Seconds per one minute
        const int SECOND_PER_MINUTE     = 60;
        //! Miliseconds per one second
        const int MSEC_PER_SECOND       = 1000;
        //! Default value for timer timeout while watcher use timer mode
        const int DEFAULT_TIMER_TIMEOUT = 1;
    }

    //! Temporary folders namespace
    namespace TemporaryFolders {
        //! Temporary folders for PoweShell scripts
        const char DEFAULT_FOLDER_PSSCRIPT_TEMPORARY[] = "PSScript_temporary";
        //! Temporary folders for Xml files
        const char DEFAULT_FOLDER_XML_TEMPORARY[]      = "Xml_temporary";
    }

    //! Server parameters namespace
    namespace Server {
        //! Default host
        const char DEFAULT_HOST_NAME[] = "localhost";
        //! Default port
        const int  DEFAULT_PORT        = 2323;
    }

    //! PowerShell parameters namespace
    namespace PowerShell {
        //! Default PowerShell execute parameters
        const char DEFAULT_SHELL_PARAM[] = "-NoProfile –ExecutionPolicy Unrestricted";
    }
}

#endif // GLOBALNAMESPACE

