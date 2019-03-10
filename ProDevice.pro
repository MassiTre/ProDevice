#-------------------------------------------------
#
# Project created by QtCreator 2019-02-18T16:19:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProDevice
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
        mainwindow.cpp \
    Gerarchia/gerarchia.cpp \
    GUI/controller.cpp \
    GUI/menubar.cpp \
    GUI/layoutaggiungi.cpp \
    GUI/layouthome.cpp \
    GUI/layoutcerca.cpp \
    GUI/layoutcatalogo.cpp \
    GUI/combotipodevice.cpp \
    GUI/combomemoriaram.cpp \
    GUI/combomemoriainterna.cpp \
    GUI/itemwidget.cpp \
    GUI/listdevice.cpp \
    GUI/modello.cpp \
    Gerarchia/Gerarchia.cpp \
    GUI/combomemoriainterna.cpp \
    GUI/combomemoriaram.cpp \
    GUI/combotipodevice.cpp \
    GUI/Controller.cpp \
    GUI/itemwidget.cpp \
    GUI/layoutaggiungi.cpp \
    GUI/layoutcatalogo.cpp \
    GUI/layoutcerca.cpp \
    GUI/layouthome.cpp \
    GUI/listdevice.cpp \
    GUI/menubar.cpp \
    GUI/modello.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
        mainwindow.h \
    GUI/menubar.h \
    GUI/controller.h \
    GUI/modello.h \
    Gerarchia/gerarchia.h \
    Qonteiner/qonteiner.h \
    GUI/layoutaggiungi.h \
    GUI/layouthome.h \
    GUI/layoutcerca.h \
    GUI/layoutcatalogo.h \
    GUI/combotipodevice.h \
    GUI/combomemoriaram.h \
    GUI/combomemoriainterna.h \
    GUI/itemwidget.h \
    GUI/listdevice.h \
    Qonteiner/qonteiner.h \
    Gerarchia/gerarchia.h \
    GUI/combomemoriainterna.h \
    GUI/combomemoriaram.h \
    GUI/combotipodevice.h \
    GUI/Controller.h \
    GUI/itemwidget.h \
    GUI/layoutaggiungi.h \
    GUI/layoutcatalogo.h \
    GUI/layoutcerca.h \
    GUI/layouthome.h \
    GUI/layouthome_copy.h \
    GUI/listdevice.h \
    GUI/menubar.h \
    GUI/modello.h \
    Qonteiner/qonteiner.h \
    mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    imm_src.qrc
