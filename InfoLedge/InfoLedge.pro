TEMPLATE = app
TARGET = infoledge

QT = core gui

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

SOURCES += \
    main.cpp \
    window.cpp

DISTFILES += \
    resources/avatar.jpg

HEADERS += \
    window.h
