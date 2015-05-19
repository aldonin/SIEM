#ifndef SHELLASKER_H
#define SHELLASKER_H

class QProcess;

#include <QList>
#include <QObject>

class ShellAsker : public QObject
{
    Q_OBJECT
public:
    explicit ShellAsker(QObject *parent = 0);
    ~ShellAsker();

public slots:
    void startAsking();

signals:
    void finished();

private:
    QProcess *proc;

    QList<int> svmTypes;
    QList<int> kernels;
};

#endif // SHELLASKER_H
