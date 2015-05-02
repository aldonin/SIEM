QT += widgets network
CONFIG   += c++11

SOURCES += \
    main.cpp \
    agentapplication.cpp \
    trayicon.cpp \
    settingswidget.cpp \
    collector.cpp \
    watcher.cpp \
    journalfinder.cpp \
    filesender.cpp

HEADERS += \
    agentapplication.h \
    trayicon.h \
    settingswidget.h \
    collector.h \
    watcher.h \
    journalfinder.h \
    filesender.h \
    constants.h

RESOURCES += \
    icons/icons.qrc

FORMS += \
    settingswidget.ui
