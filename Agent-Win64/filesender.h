#ifndef FILESENDER_H
#define FILESENDER_H

#include <QObject>

class QFile;

class FileSender : public QObject
{
    Q_OBJECT
public:
    explicit FileSender(QString fileName, QObject *parent = 0);
    ~FileSender();

signals:
    void finished();

public slots:
    void send();
    void disconnected();

private:
    QFile *m_file;
    quint16 m_port;
    QString m_host;

};

#endif // FILESENDER_H
