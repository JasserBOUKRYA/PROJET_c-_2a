QT       += core gui sql
QT       += multimedia
QT       += printsupport
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    bon.cpp \
    connection.cpp \
    employee.cpp \
    exportexcelobject.cpp \
    gestionemployee.cpp \
    gestioninstallation.cpp \
    gestionpoteaux.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    poteaux.cpp \
    recherchebon.cpp \
    rechercher.cpp

HEADERS += \
    arduino.h \
    bon.h \
    connection.h \
    employee.h \
    exportexcelobject.h \
    gestionemployee.h \
    gestioninstallation.h \
    gestionpoteaux.h \
    mainwindow.h \
    menu.h \
    poteaux.h \
    recherchebon.h \
    rechercher.h

FORMS += \
    gestionemployee.ui \
    gestioninstallation.ui \
    mainwindow.ui \
    menu.ui \
    poteaux.ui \
    recherchebon.ui \
    rechercher.ui

TARGET = Sound

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Sound.qrc
