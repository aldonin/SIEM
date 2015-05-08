#ifndef DBWRITER_H
#define DBWRITER_H

#include <QObject>

class JournalEvent;

class DbWriter : public QObject
{
    Q_OBJECT
public:
    explicit DbWriter(QList<JournalEvent*> list, QObject *parent = 0);
    ~DbWriter();

signals:
    void finished();

public slots:
    void push();

private:
    QList<JournalEvent*> *m_list;
    QString m_connectionName;
};

#endif // DBWRITER_H
