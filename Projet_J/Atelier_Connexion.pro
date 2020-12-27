QT       += core gui sql
QT       += printsupport
QT       += multimedia
QT       += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    arduino.cpp \
    dechet.cpp \
    dialog.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    permis.cpp

HEADERS += \
    arduino.h \
    dechet.h \
    dialog.h \
        mainwindow.h \
    connection.h \
    permis.h

FORMS += \
        dialog.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Ressources.qrc
