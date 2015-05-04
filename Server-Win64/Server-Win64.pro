QT += network widgets xml

CONFIG += c++11

SOURCES += \
    main.cpp \
    server.cpp \
    socketthread.cpp \
    xmlreader.cpp \
    journalevent.cpp

HEADERS += \
    server.h \
    constants.h \
    socketthread.h \
    xmlreader.h \
    journalevent.h
