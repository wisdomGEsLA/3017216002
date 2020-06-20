#-------------------------------------------------
#
# Project created by QtCreator 2020-06-06T23:09:05
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hotel
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        hotelroommanagementsystem.cpp \
    statistics.cpp \
    checkout.cpp \
    register.cpp \
    register1.cpp \
    register2.cpp \
    register3.cpp \
    register4.cpp \
    register5.cpp \
    appoinment1.cpp \
    appointment2.cpp \
    widget.cpp \
    browse.cpp \
    browse1.cpp \
    browse2.cpp \
    browse3.cpp \
    browse4.cpp \
    room_manage.cpp \
    edit_room.cpp \
    new_room.cpp \
    warning.cpp \
    new_type.cpp


HEADERS += \
        hotelroommanagementsystem.h \
    statistics.h \
    checkout.h \
    register.h \
    register1.h \
    register2.h \
    register3.h \
    register4.h \
    register5.h \
    appoinment1.h \
    appointment2.h \
    widget.h \
    browse.h \
    browse1.h \
    browse2.h \
    browse3.h \
    browse4.h \
    room_manage.h \
    edit_room.h \
    new_room.h \
    warning.h \
    new_type.h


FORMS += \
        hotelroommanagementsystem.ui \
    statistics.ui \
    checkout.ui \
    register.ui \
    register1.ui \
    register2.ui \
    register3.ui \
    register4.ui \
    register5.ui \
    appoinment1.ui \
    appointment2.ui \
    widget.ui \
    browse.ui \
    browse1.ui \
    browse2.ui \
    browse3.ui \
    browse4.ui \
    room_manage.ui \
    edit_room.ui \
    new_room.ui \
    warning.ui \
    new_type.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
