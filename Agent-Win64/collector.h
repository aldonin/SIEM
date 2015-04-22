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
    QString executeStr;
    QProcess *m_prc;

public slots:
    void collect(const AgentApplication::Journal type = AgentApplication::Journal::Application);
    void currentThread();

    void updateSettings();
};

#endif // COLLECTOR_H
