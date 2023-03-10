QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
MOC_DIR = tmp
OBJECTS_DIR = tmp
SOURCES += \
    src/executable/main.cpp \
    src/GUI/gamedockwidget.cpp \
    src/GUI/gamewidget.cpp \
    src/GUI/mainwindow.cpp \
    src/GUI/hoverpushbutton.cpp \
    src/GUI/setupdockwidget.cpp \
    src/GUI/startmenuwidget.cpp \
    src/game_dynamics/gamegrid.cpp \
    src/game_dynamics/boat.cpp \
    src/game_dynamics/gamewrapper.cpp 
    

HEADERS += \
    include/GUI/gamedockwidget.h \
    include/GUI/gamewidget.h \
    include/GUI/mainwindow.h \
    include/GUI/hoverpushbutton.h \
    include/GUI/setupdockwidget.h \
    include/GUI/startmenuwidget.h \
    include/game_dynamics/gamegrid.h \
    include/game_dynamics/boat.h \
    include/game_dynamics/boatpart.h \
    include/game_dynamics/coordinates.h \
    include/game_dynamics/gamewrapper.h \
    include/game_dynamics/battleship.h \
    include/game_dynamics/sonar.h \
    include/game_dynamics/support.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
