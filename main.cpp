#include "Gerarchia/device.h"
#include "Gerarchia/mobile.h"
#include "Gerarchia/smartphone.h"
#include "Gerarchia/tablet.h"
#include "Gerarchia/computer.h"
#include "Gerarchia/fisso.h"
#include "Gerarchia/portatile.h"
#include "Gerarchia/convertibile.h"
#include "Qonteiner/qonteiner.h"
#include "GUI/controller.h"
#include "modello.h"
#include <QApplication>
#include <QDesktopWidget>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDesktopWidget dw;
    Controller w( new Modello() );
    w.setFixedSize(1000,650);
    w.show();
    return a.exec();
}
