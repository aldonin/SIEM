#ifndef CONSTANTS
#define CONSTANTS

#include <QHostAddress>

//! Server application constants
namespace Constants {

    //! Server parameters namespace
    namespace Server {
        //! Default host
        const QHostAddress DEFAULT_HOST = QHostAddress::Any;

        //! Default port
        const int          DEFAULT_PORT = 2323;
    }

    //! Time namespace
    namespace Time {
          //! Seconds per one minute
        const int SECOND_PER_MINUTE = 60;

        //! Miliseconds per one second
        const int MSEC_PER_SECOND   = 1000;
    }

    //! Temporary folders namespace
    namespace TemporaryFolders {
        //! Temporary folders for Xml files
        const char DEFAULT_FOLDER_XML_TEMPORARY[] = "Xml_temporary";
    }

    //! Database namespace
    namespace Database {
        //! Default name
        const char DEFAULT_DB_NAME[]         = "database";

        //! Default username
        const char DEFAULT_DB_USERNAME[]     = "admin";

        //! Default password
        const char DEFAULT_DB_PASSWORD[]     = "administrator";

        //! Default location
        const char DEFAULT_DB_LOCATION[]     = "localhost";

        //! Connection name for testing connection
        const char TEST_DB_CONNECTION_NAME[] = "testDbConnection";
    }


    //! Cryptographic namespace
    namespace Crypto {
        //! Crypto key
        const quint64 KEY = Q_UINT64_C(0x0a9dc2a6cab3f78a);
    }

    //! Support Vector Machine namespace
    namespace SVM {
        //! Default path to SVM libs
        const char DEFAULT_SVM_PATH[]             = "";

        //! Default path to model file
        const char DEFAULT_SVM_MODEL_FILE_PATH[]  = "";

        //! Default path to temporaty folder for SVM
        const char DEFAULT_SVM_FOLDER_TEMPORARY[] = "SVM_temporary";

        //! SVM-predict name
        const QString SVM_PREDICT          = "svm-predict.exe";

        //! Output result SVM file
        const QString SVM_OUTPUT_FILE_NAME = "result.t";

        //! File with test set for SVM
        const QString SVM_TEST_FILE_NAME   = "test.t";


        //! List of danger event IDs, <a href="http://habrahabr.ru/company/netwrix/blog/148501/">source</a>
        const QList<int> DANGER_EVENT_ID  = {675, 4771,
                                             676, 672, 4768,
                                             681, 680, 4776,
                                             642, 4738,
                                             632, 4728, 636, 4732, 660, 4756,
                                             624, 4720,
                                             644, 4740,
                                             517, 1102,

                                             529, 4625, 531, 532, 533, 534,  5461, 535, 539
                                            };

        //! List of danger keyword at message field
        const QStringList DANGER_MESSAGE_KEYWORDS = {"Error",  "Failure", "AppCrash", "Warning",
                                                     "Ошибка", "Отказ",   "Крах",     "Крахом"
                                                    };
    }

}

#endif // CONSTANTS

