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

HEADERS += \
    Avvisi/gestioneeccezione.h \
    Gerarchia/computer.h \
    Gerarchia/convertibile.h \
    Gerarchia/device.h \
    Gerarchia/fisso.h \
    Gerarchia/mobile.h \
    Gerarchia/portatile.h \
    Gerarchia/smartphone.h \
    Gerarchia/tablet.h \
    GUI/comboboxes/combomemoriainterna.h \
    GUI/comboboxes/combomemoriaram.h \
    GUI/comboboxes/combotipodevice.h \
    GUI/layoutsaggiungi/layoutaggiungi.h \
    GUI/layoutsaggiungi/layoutaggiungicomputer.h \
    GUI/layoutsaggiungi/layoutaggiungiconvertibile.h \
    GUI/layoutsaggiungi/layoutaggiungifisso.h \
    GUI/layoutsaggiungi/layoutaggiungimobile.h \
    GUI/layoutsaggiungi/layoutaggiungiportatile.h \
    GUI/layoutsaggiungi/layoutaggiungismartphone.h \
    GUI/layoutsaggiungi/layoutaggiungitablet.h \
    GUI/layoutsmodifica/layoutmodifica.h \
    GUI/layoutsmodifica/layoutmodificacomputer.h \
    GUI/layoutsmodifica/layoutmodificaconvertibile.h \
    GUI/layoutsmodifica/layoutmodificafisso.h \
    GUI/layoutsmodifica/layoutmodificamobile.h \
    GUI/layoutsmodifica/layoutmodificaportatile.h \
    GUI/layoutsmodifica/layoutmodificasmartphone.h \
    GUI/layoutsmodifica/layoutmodificatablet.h \
    GUI/listdevice/deviceelementolista.h \
    GUI/listdevice/devicewidgetlista.h \
    GUI/controller.h \
    GUI/layoutcatalogo.h \
    GUI/layoutcerca.h \
    GUI/layouthome.h \
    GUI/menubar.h \
    Qonteiner/qonteiner.h \
    modello.h

SOURCES += \
    Avvisi/gestioneeccezione.cpp \
    Gerarchia/computer.cpp \
    Gerarchia/convertibile.cpp \
    Gerarchia/device.cpp \
    Gerarchia/fisso.cpp \
    Gerarchia/mobile.cpp \
    Gerarchia/portatile.cpp \
    Gerarchia/smartphone.cpp \
    Gerarchia/tablet.cpp \
    GUI/comboboxes/combomemoriainterna.cpp \
    GUI/comboboxes/combomemoriaram.cpp \
    GUI/comboboxes/combotipodevice.cpp \
    GUI/layoutsaggiungi/layoutaggiungi.cpp \
    GUI/layoutsaggiungi/layoutaggiungicomputer.cpp \
    GUI/layoutsaggiungi/layoutaggiungiconvertibile.cpp \
    GUI/layoutsaggiungi/layoutaggiungifisso.cpp \
    GUI/layoutsaggiungi/layoutaggiungimobile.cpp \
    GUI/layoutsaggiungi/layoutaggiungiportatile.cpp \
    GUI/layoutsaggiungi/layoutaggiungismartphone.cpp \
    GUI/layoutsaggiungi/layoutaggiungitablet.cpp \
    GUI/layoutsmodifica/layoutmodifica.cpp \
    GUI/layoutsmodifica/layoutmodificacomputer.cpp \
    GUI/layoutsmodifica/layoutmodificaconvertibile.cpp \
    GUI/layoutsmodifica/layoutmodificafisso.cpp \
    GUI/layoutsmodifica/layoutmodificamobile.cpp \
    GUI/layoutsmodifica/layoutmodificaportatile.cpp \
    GUI/layoutsmodifica/layoutmodificasmartphone.cpp \
    GUI/layoutsmodifica/layoutmodificatablet.cpp \
    GUI/listdevice/deviceelementolista.cpp \
    GUI/listdevice/devicewidgetlista.cpp \
    GUI/controller.cpp \
    GUI/layoutcatalogo.cpp \
    GUI/layoutcerca.cpp \
    GUI/layouthome.cpp \
    GUI/menubar.cpp \
    main.cpp \
    modello.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imm_src.qrc

RC_FILE = ProDevice.rc
