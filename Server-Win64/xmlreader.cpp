#include "xmlreader.h"

#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include "journalevent.h"
#include "constants.h"

using namespace Constants::Server;

XmlReader::XmlReader(const QString &fileName) :
    m_fileName(fileName)
{
    m_hostAddres = DEFAULT_HOST;
    m_portAddres = DEFAULT_PORT;
}

void XmlReader::processXml()
{
    qDebug() << "processXml";
    QDomDocument doc;
    QFile file(m_fileName);
    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file)) {
        qDebug() << "Can't open xml file for reading";
        emit finished( list );
        return;
    }

    // Получаем список всех событий
    QDomNodeList objects = doc.elementsByTagName("Object");

    // Резервируем место в список для исключения случаев реалокации контейнера
    list.reserve( objects.size() );


    for (int i = 0; i < objects.size(); i++) {

        // Получаем очередное событие
        QDomNode node = objects.item(i);

        // Пытаемся разобрать его
        if (node.isElement()) {
            QDomElement event = node.toElement();
            getElements(event, "Property", "Name");
        }
    }

    emit finished( list );
}

void XmlReader::getElements(QDomElement root, QString tag, QString att)
{
    QDomNodeList nodes = root.elementsByTagName(tag);

    JournalEvent *ev = new JournalEvent;
    ev->setHost( m_hostAddres );
    ev->setPort( m_portAddres );

    for (int i = 0; i < nodes.count(); ++i) {
        QDomNode elm = nodes.at(i);

        if ( elm.isElement() ) {
            QDomElement e = elm.toElement();

            // Если не пусты имя, значение и данных элемент не содержит подэлементов - добавляем соответствующее поле в событие
            if (!e.attribute(att).isEmpty() && !e.text().isEmpty() && e.elementsByTagName("Property").size() == 0)
                ev->insert( e.attribute(att), e.text() );            
        }
    }

    list.append( ev );
}

void XmlReader::setHostAddres(const QHostAddress &hostAddres)
{
    m_hostAddres = hostAddres;
}

void XmlReader::setPortAddres(const quint16 &portAddres)
{
    m_portAddres = portAddres;
}
