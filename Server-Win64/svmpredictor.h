#ifndef SVMPREDICTOR_H
#define SVMPREDICTOR_H

#include <QString>
#include <QMap>

class JournalEvent;

/*!
 * \brief SVM predictor class.
 *
 * Realize funtion for data preditction using libSVM.
 * LibSVM library files, the latest version you can find
 * <a href="http://www.csie.ntu.edu.tw/~cjlin/libsvm/">here</a>
 * or on <a href="https://github.com/cjlin1/libsvm">GitHub</a>
 */
class SVMPredictor
{
public:
    /*!
     * \brief Constructor of class.
     * \param ev Journal event for prediction.
     * \sa JournalEvent
     */
    explicit SVMPredictor(JournalEvent *ev = 0);
    /*!
     * \brief Free resources.
     */
    ~SVMPredictor();

    /*!
     * \brief Set event for prediction.
     * \param ev Journal event for prediction.
     * \sa JournalEvent
     */
    void setEvent(JournalEvent *ev);

    /*!
     * \brief Predict specified journal.
     * \return True if result of SVM-predict = 1, otherwise 0.
     *
     * For getting result call answer() function.
     * \sa answer()
     */
    bool predict();

private:
    /*!
     * \brief Get predition value.
     * \return Value of prediction
     *
     * Open result file and check integer value of current prediction.
     * \sa Constants::SVM
     */
    int answer() const;
    /*!
     * \brief Save map container.
     * \param map container with values for prediction.
     *
     * Save map container to test file.
     * \sa Constants::SVM
     */
    void saveMap(QMap<int, int>&);

private:
    JournalEvent *m_event;      ///< Prediction journal event.
    QString m_outputFilePath;   ///< Full path to output file.
    QString m_predictPath;      ///< Full path to prediction file.
    QString m_modelFilePath;    ///< Full path to model file.
    QString m_testFileName;     ///< Full path to test file.
};

#endif // SVMPREDICTOR_H
