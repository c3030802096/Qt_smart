#-------------------------------------------------
#
# Project created by QtCreator 2023-05-31T10:11:55
#
#-------------------------------------------------
# 设置源文件编码为 UTF-8
CODECFORSRC = UTF-8
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_smart_home
TEMPLATE = app


SOURCES += main.cpp\
    home.cpp \
    device/device_ac.cpp \
    device/device_curtain.cpp \
    my_custom/digital_scroller.cpp \
    my_custom/global.cpp \
    my_custom/sliderbutton.cpp \
    tcp/tcpserver.cpp \
    tcp/tcpserver_thread.cpp \
    tcp/tcpsocket.cpp \
    device/device_lamp.cpp \
    device/device_fan.cpp

HEADERS  += \
    home.h \
    device/device_ac.h \
    device/device_curtain.h \
    my_custom/digital_scroller.h \
    my_custom/global.h \
    my_custom/sliderbutton.h \
    tcp/tcpserver.h \
    tcp/tcpserver_thread.h \
    tcp/tcpsocket.h \
    device/device_lamp.h \
    device/device_fan.h

FORMS    += \
    home.ui \
    device/device_ac.ui \
    device/device_curtain.ui \
    my_custom/digital_scroller.ui \
    device/device_lamp.ui \
    device/device_fan.ui

RESOURCES += \
    pic.qrc
