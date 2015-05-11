#ifndef SVMPREDICTOR_H
#define SVMPREDICTOR_H

#include <QString>
#include <QMap>

class JournalEvent;

class SVMPredictor
{
public:
    explicit SVMPredictor(JournalEvent *ev = 0);
    ~SVMPredictor();

    void setEvent(JournalEvent *ev);

    bool predict();

private:
    int answer() const;
    void saveMap(QMap<int, int>&);

private:
    JournalEvent *m_event;
    QString m_outputFilePath;
    QString m_predictPath;
    QString m_modelFilePath;
    QString m_testFileName;
};

#endif // SVMPREDICTOR_H
