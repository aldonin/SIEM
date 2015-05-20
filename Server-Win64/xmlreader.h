#ifndef XMLREADER_H
#define XMLREADER_H

#include <QString>
#include <QDomElement>
#include <QObject>
#include <QHostAddress>

class JournalEvent;

/*!
 * \brief Xml reader class
 *
 * Provide function for parsing xml files.
 *
 * Based on QDomDocument way for parsing.
 */
class XmlReader : public QObject
{
    Q_OBJECT

public:
    /*!
     * \brief Default contructor.
     * \param fileName Full path to file for parsing.
     */
    explicit XmlReader(const QString &fileName);
    /*!
     * Free resources.
     */
    ~XmlReader();

    /*!
     * \brief Set port addres to new forming Journal Event.
     * \param portAddres Incoming connection port addres.
     */
    void setPortAddres(const quint16 &portAddres);
    /*!
     * \brief Set host addres to new forming Journal Event.
     * \param hostAddres Incoming connection host addres.
     */
    void setHostAddres(const QHostAddress &hostAddres);

public slots:
    /*!
     * \brief Parsing specified xml file.
     *
     * Emit finished(QList<JournalEvent*> list) signal after finishing parsing.
     * \note If specified file not open or parsing failure finished(QList<JournalEvent*> list) signal will be emited anyway.
     * \sa finished(QList<JournalEvent*> list)
     */
    void processXml();

signals:
    /*!
     * \brief Finished parsing signal.
     * \param list Forwarding list of events to another slot.
     * \sa processXml()
     */
    finished(QList<JournalEvent*> list);

private:    
    /*!
     * \brief Get xml elements by root element, tag and attribute name.
     * \param root Relative root element.
     * \param tag Tag for search.
     * \param att Attribute for search.
     */
    void getElements(QDomElement root, QString tag, QString att);

    QList<JournalEvent*> list;  ///< Formed from xml list of events.
    QString      m_fileName;    ///< File name for parsing.
    QHostAddress m_hostAddres;  ///< Incoming connection host addres.
    quint16      m_portAddres;  ///< Incoming connection port addres.
};

#endif // XMLREADER_H
