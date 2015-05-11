#include "svmpredictor.h"
#include "journalevent.h"
#include "constants.h"

#include <QSettings>
#include <QCoreApplication>
#include <QFile>
#include <QDateTime>
#include <QNetworkInterface>
#include <QProcess>
#include <QDebug>

using namespace Constants::SVM;

SVMPredictor::SVMPredictor(JournalEvent *ev) : m_event(ev)
{
    QSettings settings;
    settings.beginGroup("SVM");
    m_modelFilePath = settings.value("ModelFilePath",   QVariant(DEFAULT_SVM_MODEL_FILE_PATH)).toString();
    QString workDir = settings.value("TemporaryFolder", QVariant(QCoreApplication::applicationDirPath() + "/" + DEFAULT_SVM_FOLDER_TEMPORARY)).toString();
    m_predictPath   = settings.value("LibraryPath",     QVariant(DEFAULT_SVM_PATH)).toString() + "/" +  SVM_PREDICT;
    settings.endGroup();

    m_outputFilePath = workDir + "/" + SVM_OUTPUT_FILE_NAME;
    m_testFileName   = workDir + "/" + SVM_TEST_FILE_NAME;
}

SVMPredictor::~SVMPredictor()
{
    qDebug() << "~SVMPredictor";
}



void SVMPredictor::setEvent(JournalEvent *ev)
{
    m_event = ev;
}

bool SVMPredictor::predict()
{
    QMap<int, int> map;

    // Check JournalType
    map[1] = (m_event->getgetJournalTypeAsType() == JournalEvent::Application
              || m_event->getgetJournalTypeAsType() == JournalEvent::Security
              || m_event->getgetJournalTypeAsType() == JournalEvent::Setup
              || m_event->getgetJournalTypeAsType() == JournalEvent::System
              || m_event->getgetJournalTypeAsType() == JournalEvent::ForwardedEvents) ? 0 : 1;

    // Check EventID
    map[2] = DANGER_EVENT_ID.contains(m_event->getEventID()) ? 1 : 0;

    // Check MachineName
    map[3] = 0;

    // Check Data
    map[4] = m_event->getData() == "System.Byte[]" ? 0 : 1;

    // Check Index
    map[5] = m_event->getIndex() > 0 ? 0 : 1;

    // Check Category - для каждой программы свой
    map[6] = 0;

    // Check CategoryNumber - sa Category
    map[7] = 0;

    // Check EntryType
    map[8] = (m_event->getEntryType() == JournalEvent::EventLogEntryType::Error
              || m_event->getEntryType() == JournalEvent::EventLogEntryType::FailureAudit
              || m_event->getEntryType() == JournalEvent::EventLogEntryType::Warning) ? 1 : 0;

    // Check Message
    map[9] = 0;
    foreach (QString key, DANGER_MESSAGE_KEYWORDS) {
        if ( m_event->getMessage().contains(key, Qt::CaseInsensitive) ) {
            map[9] = 1;
            break;
        }
    }

    // Check Source
    map[10] = 0;

    // Check InstanceId
    map[11] = ( m_event->getInstanceId() == m_event->getEventID()
               || m_event->getInstanceId() >= 1000) ? 0 : 1;

    // Check TimeGenerated
    QDateTime genDT = QDateTime::fromString(m_event->getTimeGenerated(), "dd.MM.yyyy hh:mm:ss");
    map[12] = ( genDT < QDateTime::currentDateTime()) ? 0 : 1;

    // Check TimeWritten
    QDateTime writtenDT = QDateTime::fromString(m_event->getTimeWritten(), "dd.MM.yyyy hh:mm:ss");
    map[13] = ( writtenDT < QDateTime::currentDateTime() && writtenDT >= genDT ) ? 0 : 1;

    // Check Port
    map[14] = m_event->getPort() <= 0 ?  1 : 0;

    // Check Host
    map[15] = 0;
    QStringList local, remote;
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
             local = address.toString().split(".");
    }

    remote = m_event->host().toString().split(".");
    for (int i = 0; i < 2; ++i) {
        if ( remote.at(i) != local.at(i) )
            map[15] = 1;
    }

    saveMap(map);


    QProcess proc;
    proc.start("cmd /C " + m_predictPath + " " + m_testFileName
               + " " + m_modelFilePath + " " + m_outputFilePath
               );

    proc.waitForFinished();

    return answer() == 1 ;

}

int SVMPredictor::answer() const
{
    QFile file(m_outputFilePath);

    if (file.open(QIODevice::ReadOnly |QIODevice::Text)) {
        QTextStream in(&file);
        int result = in.readLine().toInt();
        file.close();

        return result;
    } else {
        qDebug() << "Can't open result file!";
    }

    return -1;
}

void SVMPredictor::saveMap(QMap<int, int> &map)
{
    QFile file(m_testFileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QMapIterator<int, int> i(map);
            in << 0 << " ";
            while (i.hasNext()) {
                i.next();
                in << i.key() << ":" << i.value() << " ";
            }
            file.close();
        } else {
            qDebug() << "SVMPredictor::saveMap: Can't opent file for writting!";
        }
}
