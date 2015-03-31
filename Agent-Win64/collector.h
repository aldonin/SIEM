#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <QObject>
#include <QProcess>

class Collector : public QObject
{
    Q_OBJECT
public:
    explicit Collector(QObject *parent = 0);
    ~Collector();

private:
    QProcess *prc;

signals:

public slots:

    void readyRead();
    void readError();
    void emitError(QProcess::ProcessError err);
};

#endif // COLLECTOR_H
