#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <QObject>
#include <QProcess>
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
    QProcess *m_prc;
    QMap<AgentApplication::Journal, QDateTime> m_lastTimeCollect;

public slots:
    // Для определенного типа журнала
    void collect(const AgentApplication::Journal type = AgentApplication::Journal::Application);
    // Для всех журнала по событию таймера
    void collectAll();
    void currentThread();

    void updateSettings();
};

#endif // COLLECTOR_H
