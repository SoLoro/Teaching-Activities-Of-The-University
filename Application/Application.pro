QT       += core gui
QT       += network
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    application.cpp \
    editions.cpp \
    main.cpp \
    mainwindow.cpp \
    pulpits.cpp \
    teachers.cpp \
    workplans.cpp

HEADERS += \
    application.h \
    editions.h \
    mainwindow.h \
    pulpits.h \
    teachers.h \
    workplans.h

FORMS += \
    application.ui \
    editions.ui \
    mainwindow.ui \
    pulpits.ui \
    teachers.ui \
    workplans.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
