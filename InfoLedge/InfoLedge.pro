TEMPLATE = app
TARGET = infoledge

QT = core gui

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    menuwindow.cpp \
    searchwindow.cpp

DISTFILES += \
    resources/emoji/avatar.jpg \
    resources/emoji/door.jpg \
    resources/emoji/emoji.png \
    resources/emoji/happy.png \
    resources/emoji/in-love.png \
    resources/emoji/laugh.png \
    resources/emoji/love.png \
    resources/emoji/party.png \
    resources/emoji/sad.png \
    resources/emoji/smile.png \
    resources/emoji/smiling-face.png \
    resources/emoji/star.png \
    resources/emoji/tear.png \
    resources/emoji/thinking.png \
    resources/emoji/thinking_1.png \
    resources/emoji/thinking_2.png \
    resources/emoji/winking-face.png \
    resources/emoji/wow.png

HEADERS += \
    mainwindow.h \
    menuwindow.h \
    searchwindow.h
