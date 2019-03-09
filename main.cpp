#include "Gerarchia/gerarchia.h"
#include "Qonteiner/qonteiner.h"
#include "GUI/controller.h"
#include "GUI/modello.h"

#include <QApplication>
#include <QDesktopWidget>

#include <iostream>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);


    QDesktopWidget dw;
    // int x = static_cast<int>( dw.width()*.5 );
    // int y = static_cast<int>( dw.height()*.5 );

    Controller w( new Modello() );
    // w.showMaximized();
    w.setFixedSize(1000,550);
    // w.setFixedWidth(1000);
    // w.setMaximumHeight(1000);
    w.show();

    Convertibile d;
    d.setPrezzo(1000);
    std::cout << "prezzo base: " << d.getPrezzo() << std::endl;
    d.setLuceTastiera(true);
    std::cout << "prezzo totale: " << d.calcolaPrezzo() << std::endl << std::endl;

    // std::cout << "px forntali: " << d.getPxFrontali() << std::endl;
    std::cout << "px Webcam: " << d.getPxWebcam() << std::endl << std::endl;
    d.setPxWebcam(3);
    d.setTouchscreen(true);
    // std::cout << "px forntali: " << d.getPxFrontali() << std::endl;
    std::cout << "px Webcam: " << d.getPxWebcam() << std::endl << std::endl;

    std::cout << "Info: \n" << d.stampaSpecifiche() << std::endl << std::endl;
    return a.exec();
}
