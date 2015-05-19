#include "shellasker.h"

#include <QTimer>
#include <QThread>
#include <QProcess>
#include <QDebug>

const double gammaStep = 0.1;

ShellAsker::ShellAsker(QObject *parent) : QObject(parent)
{
    /*	0 -- C-SVC		(multi-class classification)
     *  1 -- nu-SVC		(multi-class classification)
     * 	2 -- one-class SVM
     *  3 -- epsilon-SVR	(regression)
     *  4 -- nu-SVR		(regression)
     * Нам нужны только первые 2 */
    svmTypes << 0 << 1;

    /*  -t kernel_type : set type of kernel function (default 2)
     *  0 -- linear: u'*v
     *	1 -- polynomial: (gamma*u'*v + coef0)^degree
     *	2 -- radial basis function: exp(-gamma*|u-v|^2)
     *	3 -- sigmoid: tanh(gamma*u'*v + coef0)
     *	4 -- precomputed kernel (kernel values in training_set_file) */
    for (int i = 0; i < 4; ++i)
        kernels << i;


    proc = new QProcess;
}

ShellAsker::~ShellAsker()
{
    delete proc;
}

void ShellAsker::startAsking()
{
    foreach (int type, svmTypes) {

        foreach (int kernel, kernels) {

            for (double step = 0.0; step <= 1.0; step += gammaStep) {
                proc->start(QString("cmd /C svm-train.exe -s %1 -t %2 -g %3 -n 0.2 traininSet.t model.model")
                            .arg(type)
                            .arg(kernel)
                            .arg(step)
                            );

                proc->waitForFinished();

                proc->start("cmd /C powershell -File predict.ps1");
                proc->waitForFinished();
            }

            proc->start("cmd /C powershell -File endl.ps1");
            proc->waitForFinished();
        }
    }

    qDebug() << "ENDIT";
    emit finished();
}

