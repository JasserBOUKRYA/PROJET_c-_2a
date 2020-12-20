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
    extrait.cpp \
    gestionemployee.cpp \
    gestionextrait.cpp \
    gestioninstallation.cpp \
    gestionpoteaux.cpp \
    gestiontaxe.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    menuadmin.cpp \
    poteaux.cpp \
    recherchebon.cpp \
    rechercher.cpp \
    taxe.cpp

HEADERS += \
    arduino.h \
    bon.h \
    connection.h \
    employee.h \
    exportexcelobject.h \
    extrait.h \
    gestionemployee.h \
    gestionextrait.h \
    gestioninstallation.h \
    gestionpoteaux.h \
    gestiontaxe.h \
    mainwindow.h \
    menu.h \
    menuadmin.h \
    poteaux.h \
    recherchebon.h \
    rechercher.h \
    taxe.h

FORMS += \
    gestionemployee.ui \
    gestionextrait.ui \
    gestioninstallation.ui \
    gestiontaxe.ui \
    mainwindow.ui \
    menu.ui \
    menuadmin.ui \
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
