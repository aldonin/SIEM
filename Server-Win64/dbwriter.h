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
    QList<JournalEvent*> m_list;
    QString m_connectionName;
};


/*
 * NOTE при отправки событий с локальной машины, вместо вписываемого хоста в БД будет писаться ::1
 * Достаточно странное поведение, учитывая, что это значение возвращается при использовании IPv6
 */

#endif // DBWRITER_H
