QT += network widgets xml

CONFIG += c++11

SOURCES += \
    main.cpp \
    server.cpp \
    socketthread.cpp \
    xmlreader.cpp \
    journalevent.cpp \
    serverapplication.cpp \
    settingswidget.cpp

HEADERS += \
    server.h \
    constants.h \
    socketthread.h \
    xmlreader.h \
    journalevent.h \
    serverapplication.h \
    settingswidget.h

FORMS += \
    settingswidget.ui

RESOURCES += \
    icons/icons.qrc


