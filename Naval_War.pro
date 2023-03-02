QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
MOC_DIR = tmp
OBJECTS_DIR = tmp
SOURCES += \
    main.cpp \
    src/gamewidget.cpp \
    src/mainwindow.cpp \
    src/hoverpushbutton.cpp \
    src/dockwidget.cpp \
    src/gamegrid.cpp \
    src/startmenuwidget.cpp

HEADERS += \
    include/gamewidget.h \
    include/mainwindow.h \
    include/hoverpushbutton.h \
    include/dockwidget.h \
    include/gamegrid.h \
    include/startmenuwidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
