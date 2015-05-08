QT += network widgets xml sql

CONFIG += c++11

SOURCES += \
    main.cpp \
    server.cpp \
    socketthread.cpp \
    xmlreader.cpp \
    journalevent.cpp \
    serverapplication.cpp \
    settingswidget.cpp \
    simplecrypt.cpp \
    dbwriter.cpp

HEADERS += \
    server.h \
    constants.h \
    socketthread.h \
    xmlreader.h \
    journalevent.h \
    serverapplication.h \
    settingswidget.h \
    simplecrypt.h \
    dbwriter.h

FORMS += \
    settingswidget.ui

RESOURCES += \
    icons/icons.qrc


