#ifndef XMLREADER_H
#define XMLREADER_H

#include <QString>
#include <QDomElement>
#include <QObject>

class JournalEvent;


class XmlReader : public QObject
{
    Q_OBJECT

public:
    explicit XmlReader(const QString &fileName);

    void setPortAddres(const quint16 &portAddres);
    void setHostAddres(const QString &hostAddres);

public slots:
    void processXml();

signals:
    finished(QList<JournalEvent*> list);

private:    
    void getElements(QDomElement root, QString tag, QString att);

    QList<JournalEvent*> list;
    QString m_fileName;
    QString m_hostAddres;
    quint16 m_portAddres;
};

#endif // XMLREADER_H
