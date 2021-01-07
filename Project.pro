QT       += core gui sql
QT       += multimedia
QT       += printsupport
QT       += serialport
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DuMessengerServer.cpp \
    DuMessengerSocket.cpp \
    arduino.cpp \
    bon.cpp \
    connection.cpp \
    dechets.cpp \
    employee.cpp \
    exportexcelobject.cpp \
    extrait.cpp \
    gestiondechet.cpp \
    gestionemployee.cpp \
    gestionextrait.cpp \
    gestioninstallation.cpp \
    gestionparking.cpp \
    gestionpermis.cpp \
    gestionpoteaux.cpp \
    gestiontaxe.cpp \
    gestionvehicule.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    menuadmin.cpp \
    messenger.cpp \
    parking.cpp \
    permis.cpp \
    poteaux.cpp \
    recherchebon.cpp \
    rechercher.cpp \
    taxe.cpp \
    vehicule.cpp

HEADERS += \
    DuMessengerServer.h \
    DuMessengerSocket.h \
    arduino.h \
    bon.h \
    connection.h \
    dechets.h \
    employee.h \
    exportexcelobject.h \
    extrait.h \
    gestiondechet.h \
    gestionemployee.h \
    gestionextrait.h \
    gestioninstallation.h \
    gestionparking.h \
    gestionpermis.h \
    gestionpoteaux.h \
    gestiontaxe.h \
    gestionvehicule.h \
    mainwindow.h \
    menu.h \
    menuadmin.h \
    messenger.h \
    parking.h \
    permis.h \
    poteaux.h \
    recherchebon.h \
    rechercher.h \
    taxe.h \
    vehicule.h

FORMS += \
    gestiondechet.ui \
    gestionemployee.ui \
    gestionextrait.ui \
    gestioninstallation.ui \
    gestionparking.ui \
    gestionpermis.ui \
    gestiontaxe.ui \
    gestionvehicule.ui \
    mainwindow.ui \
    menu.ui \
    menuadmin.ui \
    messenger.ui \
    poteaux.ui \
    recherchebon.ui \
    rechercher.ui

TARGET = Sound

RC_ICONS = myappico.ico

QMAKE_CXXFLAGS += -std=gnu++11


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Sound.qrc \
    res.qrc
