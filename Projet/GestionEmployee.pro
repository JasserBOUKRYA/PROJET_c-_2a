QT       += core gui sql
QT       += multimedia
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bon.cpp \
    connection.cpp \
    employee.cpp \
    exportexcelobject.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    bon.h \
    connection.h \
    employee.h \
    exportexcelobject.h \
    login.h \
    mainwindow.h

FORMS += \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
