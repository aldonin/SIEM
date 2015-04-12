QT += widgets
CONFIG   += c++11

SOURCES += \
    main.cpp \
    agentapplication.cpp \
    trayicon.cpp \
    settingswidget.cpp \
    collector.cpp \
    watcher.cpp

HEADERS += \
    agentapplication.h \
    trayicon.h \
    settingswidget.h \
    collector.h \
    watcher.h

RESOURCES += \
    icons/icons.qrc

FORMS += \
    settingswidget.ui
