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
        const char DEFAULT_DB_NAME[]         = "database";
        const char DEFAULT_DB_USERNAME[]     = "admin";
        const char DEFAULT_DB_PASSWORD[]     = "administrator";
        const char DEFAULT_DB_LOCATION[]     = "localhost";
        const char TEST_DB_CONNECTION_NAME[] = "testDbConnection";
    }

    namespace Crypto {
        const quint64 KEY = Q_UINT64_C(0x0a9dc2a6cab3f78a);
    }

    namespace SVM {
        const char DEFAULT_SVM_PATH[]             = "";
        const char DEFAULT_SVM_MODEL_FILE_PATH[]  = "";
        const char DEFAULT_SVM_FOLDER_TEMPORARY[] = "SVM_temporary";

        const QString SVM_PREDICT          = "svm-predict.exe";
        const QString SVM_OUTPUT_FILE_NAME = "result.t";
        const QString SVM_TEST_FILE_NAME   = "test.t";

        // Список взят отсюда http://habrahabr.ru/company/netwrix/blog/148501/
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

        const QStringList DANGER_MESSAGE_KEYWORDS = {"Error",  "Failure", "AppCrash", "Warning",
                                                     "Ошибка", "Отказ",   "Крах",     "Крахом"
                                                    };
    }

}

#endif // CONSTANTS

