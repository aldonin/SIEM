#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <QObject>
#include "agentapplication.h"

class Collector : public QObject
{
    Q_OBJECT

public:
    explicit Collector(QObject *parent = 0);
    ~Collector();

private:
    void saveSettings();

private:
    QString executeStr;
    QMap<AgentApplication::Journal, QDateTime> m_lastTimeCollect;
    QString m_psScriptTempFolder;
    QString m_xmlTempFolder;

public slots:
    // Для определенного типа журнала
    void collect(const AgentApplication::Journal type = AgentApplication::Journal::Application);
    // Для всех журнала по событию таймера
    void collectAll();

    void updateSettings();

private slots:
    void removeXmlFile(const QString &fileName);
};

#endif // COLLECTOR_H
