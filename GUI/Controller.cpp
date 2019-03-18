#include "Controller.h"
#include <QFileDialog>

Controller::Controller(Modello* m, QWidget* parent) :
    QWidget(parent),
    menu(new MenuBar(this)),
    modello(m),
    mainLayout(new QVBoxLayout(this)),
    homeLayout(new LayoutHome(this)),
    aggiungiLayout(new LayoutAggiungi(this)),
    cercaLayout(new LayoutCerca(this)),
    catalogoLayout(new LayoutCatalogo(this)),
    pathXML(QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/Dati Dispositivi" , "File XML(*.xml)"))
{
    mainLayout->setMenuBar(menu);
    mainLayout->addWidget(homeLayout);
    mainLayout->addWidget(aggiungiLayout);
    mainLayout->addWidget(cercaLayout);
    mainLayout->addWidget(catalogoLayout);

    aggiungiLayout->hide();
    cercaLayout->hide();
    catalogoLayout->hide();

    setLayout(mainLayout);
}

void Controller::esciLayoutHome() const {
    aggiungiLayout->hide();
    cercaLayout->hide();
    catalogoLayout->hide();

    homeLayout->show();
}

void Controller::esciLayoutAggiungi() const {
    homeLayout->hide();
    cercaLayout->hide();
    catalogoLayout->hide();

    aggiungiLayout->show();
}

void Controller::esciLayoutCerca() const {
    homeLayout->hide();
    aggiungiLayout->hide();
    catalogoLayout->hide();

    cercaLayout->show();
}

void Controller::esciLayoutCatalogo() const {
    homeLayout->hide();
    aggiungiLayout->hide();
    cercaLayout->hide();

    catalogoLayout->show();
}

void Controller::caricaXML(){
    QString xml = QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/Dati Dispositivi" , "File XML(*.xml)");

    if(xml!=""){
        catalogoLayout->getLista()->clear();
        modello->setPathXML(xml.toStdString());
        modello->carica();

        Container<Device*>::iterator b_it = modello->it_begin();
        Container<Device*>::iterator e_it = modello->it_end();

        for(; b_it != e_it; ++b_it){
          catalogoLayout->getLista()->aggiungiDevice(*b_it);
        }

        modello->setSalvataggio(true);
        esciLayoutCatalogo();
    }
}

void Controller::salvaXML() const {
    if(pathXML != "") {
        modello->salva();
        modello->setSalvataggio(true);
        return;
    }
    // se path nulla
}


#include<iostream>

void Controller::aggiungiDevice() const
{
    int currentIndex = aggiungiLayout->getTipoDevice()->currentIndex();
    if( currentIndex == 0 ){
        std::cout << "eccezione: devi scegliere il tipo" << std::endl;
        return;
    }

    std::string PathImmagine = "";
    std::string Modello = aggiungiLayout->getLineModello()->text().toStdString();
    std::string Produttore = aggiungiLayout->getLineProduttore()->text().toStdString();
    std::string Schermo = aggiungiLayout->getLineSchermo()->text().toStdString();
    std::string Processore = aggiungiLayout->getLineProcessore()->text().toStdString();
    int Ram = aggiungiLayout->getIntMemoriaRam();
    int Memoria = aggiungiLayout->getIntMemoriaInterna();
    double Prezzo = aggiungiLayout->getLinePrezzo()->text().toDouble();

    bool SchedaSD, Jack, FaceID, PxFrontali, PxPosteriori, Touchscreen, LettoreCD;
    int PorteUSB;

    Device* nuovoDevice = nullptr;
    if( currentIndex == 1 || currentIndex == 2 || currentIndex == 5 ) { // mobile
        SchedaSD = aggiungiLayout->getAggiungiMobile()->getCheckSchedaSD()->isChecked() ? true : false;
        Jack = aggiungiLayout->getAggiungiMobile()->getCheckJack()->isChecked() ? true : false;
        FaceID = aggiungiLayout->getAggiungiMobile()->getCheckFaceID()->isChecked() ? true : false;
        PxFrontali = aggiungiLayout->getAggiungiMobile()->getLinePxFront()->text().toInt();
        PxPosteriori = aggiungiLayout->getAggiungiMobile()->getLinePxBack()->text().toInt();
        if( currentIndex == 1 ){ // smartphone
            bool DualSIM = aggiungiLayout->getAggiungiSmartphone()->getCheckDualSim()->isChecked() ? true : false;
            nuovoDevice = new Smartphone(PathImmagine, Modello, Produttore, Schermo, Processore, Ram, Memoria, Prezzo, SchedaSD, Jack, FaceID, PxFrontali, PxPosteriori, DualSIM);
        }
        if( currentIndex == 2 ){ // tablet
            bool SIM = aggiungiLayout->getAggiungiTablet()->getCheckSim()->isChecked() ? true : false;
            nuovoDevice = new Tablet(PathImmagine, Modello, Produttore, Schermo, Processore, Ram, Memoria, Prezzo, SchedaSD, Jack, FaceID, PxFrontali, PxPosteriori, SIM);
        }
    }
    if( currentIndex == 3 || currentIndex == 4 || currentIndex == 5 ) { // computer
        Touchscreen = aggiungiLayout->getAggiungiComputer()->getCheckTouchscreen()->isChecked() ? true : false;
        LettoreCD = aggiungiLayout->getAggiungiComputer()->getCheckLettoreCD()->isChecked() ? true : false;
        PorteUSB = aggiungiLayout->getAggiungiComputer()->getLinePorteUsb()->text().toInt();
        if( currentIndex == 3 ) { // portatile
            bool Ethernet = aggiungiLayout->getAggiungiPortatile()->getCheckEthernet()->isChecked() ? true : false;
            bool Webcam = aggiungiLayout->getAggiungiPortatile()->getCheckWebcam()->isChecked() ? true : false;
            bool LuceTastiera = aggiungiLayout->getAggiungiPortatile()->getCheckLuceTastiera()->isChecked() ? true : false;
            int PxWebcam = aggiungiLayout->getAggiungiPortatile()->getLinePxWebcam()->text().toInt();
            nuovoDevice = new Portatile(PathImmagine, Modello, Produttore, Schermo, Processore, Ram, Memoria, Prezzo, Touchscreen, LettoreCD, PorteUSB, Ethernet, Webcam, LuceTastiera, PxWebcam);
        }
        if( currentIndex == 4 ) { // fisso
            bool Bluetooth = aggiungiLayout->getAggiungiFisso()->getCheckBluetooth()->isChecked() ? true : false;
            bool WiFi = aggiungiLayout->getAggiungiFisso()->getCheckWifi()->isChecked() ? true : false;
            nuovoDevice = new Fisso(PathImmagine, Modello, Produttore, Schermo, Processore, Ram, Memoria, Prezzo, Touchscreen, LettoreCD, PorteUSB, Bluetooth, WiFi);
        }
    }
    if( currentIndex == 5 ) { // convertibile
        // ho già device + mobile + computer
        // tablet
        bool SIM = aggiungiLayout->getAggiungiTablet()->getCheckSim()->isChecked() ? true : false;
        // portatile
        bool Ethernet = aggiungiLayout->getAggiungiPortatile()->getCheckEthernet()->isChecked() ? true : false;
        bool Webcam = aggiungiLayout->getAggiungiPortatile()->getCheckWebcam()->isChecked() ? true : false;
        bool LuceTastiera = aggiungiLayout->getAggiungiPortatile()->getCheckLuceTastiera()->isChecked() ? true : false;
        // propri
        bool Penna = aggiungiLayout->getAggiungiConvertibile()->getCheckPenna()->isChecked() ? true : false;
        bool StaccaTastiera = aggiungiLayout->getAggiungiConvertibile()->getCheckStaccaTastiera()->isChecked() ? true : false;
        nuovoDevice = new Convertibile(PathImmagine, Modello, Produttore, Schermo, Processore, Ram, Memoria, Prezzo, SchedaSD, Jack, FaceID, PxFrontali, PxPosteriori, SIM, Touchscreen, LettoreCD, PorteUSB, Ethernet, Webcam, LuceTastiera, Penna, StaccaTastiera);
    }

    modello->getList()->insertBack(nuovoDevice);
    modello->salva();
    modello->carica();
}
