#include "controller.h"

Controller::Controller(Modello* m, QWidget* parent) :
    QWidget(parent),
    menu(new MenuBar(this)),
    modello(m),
    mainLayout(new QVBoxLayout(this)),
    homeLayout(new LayoutHome(this)),
    aggiungiLayout(new LayoutAggiungi(this)),
    cercaLayout(new LayoutCerca(this)),
    catalogoLayout(new LayoutCatalogo(this)),
    modificaLayout(new LayoutModifica(this)),
    pathXML()
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

    caricaXML();
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

void Controller::carica() const {
    if(pathXML != ""){
        modello->setPathXML(pathXML.toStdString());

        catalogoLayout->getLista()->clear();

        modello->carica();

        Container<Device*>::constiterator aux = modello->cit_begin();
        Container<Device*>::constiterator auxEnd = modello->cit_end();

        for(; aux != auxEnd; ++aux) {
            catalogoLayout->getLista()->aggiungiDevice(*aux);
        }

        modello->setSalvataggio(true);
    } else {
        // CARICA QUALCOSA
    }
}

void Controller::caricaXML(){
    QString xml = QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/Dati Dispositivi" , "File XML(*.xml)");

    if(xml!=""){
        pathXML = xml;

        modello->setPathXML(xml.toStdString());
        modello->carica();

        Container<Device*>::constiterator b_cit = modello->cit_begin();
        Container<Device*>::constiterator e_cit = modello->cit_end();

        for(; b_cit != e_cit; ++b_cit){
          catalogoLayout->getLista()->aggiungiDevice(*b_cit);
        }

        modello->setSalvataggio(true);
    } else {
        // CARICA XML!
    }

}

void Controller::salvaXML() const {
    if(pathXML != "") {
        modello->salva();
        modello->setSalvataggio(true);
        carica();
    }
    // se path nulla
}

void Controller::arrestaProdevice() {
    this->close();
}

void Controller::aggiungiDevice() {

    int currentIndex = aggiungiLayout->getTipoDevice()->currentIndex();
    if( currentIndex == 0 ){ QMessageBox::warning(aggiungiLayout,"Campo mancante","Seleziona il tipo di device che vuoi inserire"); return; }

    std::string PathImmagine = aggiungiLayout->getPathImm().toStdString();
    if(PathImmagine == "") { QMessageBox::warning(aggiungiLayout,"Campo mancante","Non hai scelto un'immagine per il prodotto"); return; }
    std::string Modello = aggiungiLayout->getLineModello()->text().toStdString();
    if(Modello == "") { QMessageBox::warning(aggiungiLayout,"Campo mancante","Non hai specificato il modello"); return; }
    std::string Produttore = aggiungiLayout->getLineProduttore()->text().toStdString();
    if(Produttore == "") { QMessageBox::warning(aggiungiLayout,"Campo mancante","Non hai specificato il produttore"); return; }
    std::string Schermo = aggiungiLayout->getLineSchermo()->text().toStdString();
    if(Schermo == "") { QMessageBox::warning(aggiungiLayout,"Campo mancante","Non hai indicato le dimensioni dello schermo"); return; }
    std::string Processore = aggiungiLayout->getLineProcessore()->text().toStdString();
    if(Processore == "") { QMessageBox::warning(aggiungiLayout,"Campo mancante","Non hai indicato le specifiche del processore"); return; }
    int Ram = aggiungiLayout->getIntMemoriaRam();
    int Memoria = aggiungiLayout->getIntMemoriaInterna();

    double Prezzo;
    if(aggiungiLayout->getLinePrezzo()->text() == "") { QMessageBox::warning(aggiungiLayout,"E' gratis ?","Non hai inserito il prezzo"); return; }
    else { Prezzo = aggiungiLayout->getLinePrezzo()->text().toDouble(); }

    bool SchedaSD, Jack, FaceID, PxFrontali, PxPosteriori, Touchscreen, LettoreCD;
    int PorteUSB;

    Device* nuovoDevice = nullptr;
    if( currentIndex == 1 || currentIndex == 2 || currentIndex == 5 ) { // mobile
        SchedaSD = aggiungiLayout->getAggiungiMobile()->getCheckSchedaSD()->isChecked() ? true : false;
        Jack = aggiungiLayout->getAggiungiMobile()->getCheckJack()->isChecked() ? true : false;
        FaceID = aggiungiLayout->getAggiungiMobile()->getCheckFaceID()->isChecked() ? true : false;
        if(aggiungiLayout->getAggiungiMobile()->getLinePxFront()->text() == "") { QMessageBox::warning(aggiungiLayout,"Campo mancante","Non hai indicato la fotocamera frontale"); return; }
        else { PxFrontali = aggiungiLayout->getAggiungiMobile()->getLinePxFront()->text().toInt(); }
        if(aggiungiLayout->getAggiungiMobile()->getLinePxBack()->text() == "") { QMessageBox::warning(aggiungiLayout,"Campo mancante","Non hai indicato la fotocamera posteriore"); return; }
        else { PxPosteriori = aggiungiLayout->getAggiungiMobile()->getLinePxBack()->text().toInt(); }

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
        if(aggiungiLayout->getAggiungiComputer()->getLinePorteUsb()->text() == "") { QMessageBox::warning(aggiungiLayout,"Campo mancante","Non hai indicato il numero di porte USB"); return; }
        else { PorteUSB = aggiungiLayout->getAggiungiComputer()->getLinePorteUsb()->text().toInt(); }
        if( currentIndex == 3 ) { // portatile
            bool Ethernet = aggiungiLayout->getAggiungiPortatile()->getCheckEthernet()->isChecked() ? true : false;
            bool Webcam = aggiungiLayout->getAggiungiPortatile()->getCheckWebcam()->isChecked() ? true : false;
            bool LuceTastiera = aggiungiLayout->getAggiungiPortatile()->getCheckLuceTastiera()->isChecked() ? true : false;
            int PxWebcam;
            if( aggiungiLayout->getAggiungiPortatile()->getCheckWebcam()->isChecked() && aggiungiLayout->getAggiungiPortatile()->getLinePxWebcam()->text() != "" ) { PxWebcam = aggiungiLayout->getAggiungiPortatile()->getLinePxWebcam()->text().toInt(); }
            else { QMessageBox::warning(aggiungiLayout,"Campo mancante","Non hai indicato la webcam"); return; }
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

    Device* giaPresente = modello->getList()->cerca(nuovoDevice);
    if(giaPresente){
        QMessageBox::warning(cercaLayout,"Doppione","Il dispositivo è già presente nel catalogo.\nRicontrolla e modifica le informazioni se intendi inserirente una variante.");
        return;
    }

    modello->getList()->insertBack(nuovoDevice);
    aggiungiLayout->ripristinaTutto();

    modello->salva();
    carica();

}

void Controller::ricercaDevice() const {

    int currentIndex = cercaLayout->getTipoDevice()->currentIndex();
    if( currentIndex == 0 ){
        QMessageBox::warning(cercaLayout,"Tipo mancante","Seleziona il tipo di device che vuoi cercare");
        return;
    }

    std::string Modello = cercaLayout->getLineModello()->text().toStdString();
    std::string Produttore = cercaLayout->getLineProduttore()->text().toStdString();

    bool SchedaSD, Touchscreen;

    Device* cercaDevice = nullptr;
    if( currentIndex == 1 || currentIndex == 2 || currentIndex == 5 ) { // mobile
        SchedaSD = cercaLayout->getCheckSchedaSD()->isChecked() ? true : false;
        if( currentIndex == 1 ){ // smartphone
            bool DualSIM = cercaLayout->getCheckDualSim()->isChecked() ? true : false;
            cercaDevice = new Smartphone("", Modello, Produttore, "", "", 0, 0, 0.0, SchedaSD, true, true, 0, 0, DualSIM);
        }
        if( currentIndex == 2 ){ // tablet
            cercaDevice = new Tablet("", Modello, Produttore, "", "", 0, 0, 0.0, SchedaSD, true, true, 0, 0, true);
        }
    }
    if( currentIndex == 3 || currentIndex == 4 || currentIndex == 5 ) { // computer
        Touchscreen = cercaLayout->getCheckTouchscreen()->isChecked() ? true : false;
        if( currentIndex == 3 ) { // portatile
            bool LuceTastiera = cercaLayout->getCheckLuceTastiera()->isChecked() ? true : false;
            cercaDevice = new Portatile("", Modello, Produttore, "", "", 0, 0, 300, Touchscreen, true, 0, true, true, LuceTastiera, 0);
        }
        if( currentIndex == 4 ) { // fisso
            cercaDevice = new Fisso("", Modello, Produttore, "", "", 0, 0, 0.0, Touchscreen, true, 0, true, true);
        }
    }
    if( currentIndex == 5 ) { // convertibile
        // ho già device + mobile + computer
        // tablet
        bool LuceTastiera = cercaLayout->getCheckLuceTastiera()->isChecked() ? true : false;
        bool SIM = cercaLayout->getCheckSim()->isChecked() ? true : false;
        cercaDevice = new Convertibile("", Modello, Produttore, "", "", 0, 0, 0.0, SchedaSD, true, true, 0, 0, SIM, Touchscreen, true, 0, true, true, LuceTastiera, true, true);
    }

    Device* trovato = modello->getList()->cerca(cercaDevice);
    delete cercaDevice;

    if(trovato){
        cercaLayout->svuotaRisultato();
        cercaLayout->getRisultato()->aggiungiDevice(trovato);
        double pb = trovato->getPrezzo();
        cercaLayout->setPrezzoBase(QString::number(pb).append(" €"));
        double pt = trovato->calcolaPrezzo();
        cercaLayout->setPrezzoTotale(QString::number(pt).append(" €"));
    }else{
        QMessageBox::warning(cercaLayout,"Errore 404","Non è stato trovato nessun dispositivo.\nRicontrolla i campi inseriti.");
        return;
    }

}

void Controller::visualizzaModificaDevice() {

    if( !catalogoLayout->getLista()->elementoCorrente() ) { QMessageBox::warning(catalogoLayout,"Nessun elemneto","Devi selezionare il dispositivo da modificare"); return; }

    DeviceElementoLista* dwl = nullptr;
    Device* daModificare = nullptr;

    if(catalogoLayout->getLista()->elementoCorrente() != nullptr) {
        dwl = catalogoLayout->getLista()->elementoCorrente();
        daModificare = dwl->oggettoCorrente();
    } else {
        // WARNING seleziona un dispositivo
    }

    std::string tipo = daModificare->getTipo();

    /*** Device ***/
    modificaLayout->setPathImm(daModificare->getPathImmagine());
    modificaLayout->getLineModello()->setText(QString::fromStdString(daModificare->getModello()));
    modificaLayout->getLineSchermo()->setText(QString::fromStdString(daModificare->getDimensioneSchermo()));
    modificaLayout->getLinePrezzo()->setText(QString::number(daModificare->getPrezzo()));
    modificaLayout->getLineProduttore()->setText(QString::fromStdString(daModificare->getProduttore()));
    modificaLayout->getLineProcessore()->setText(QString::fromStdString(daModificare->getProcessore()));
    modificaLayout->setIndexMemoriaRam(daModificare->getMemoriaRam());
    modificaLayout->setIndexMemoriaInterna(daModificare->getMemoria());

    if(tipo == "smartphone" || tipo == "tablet" || tipo == "convertibile") { // mobile
        Mobile* pm = dynamic_cast<Mobile*>(daModificare);
        modificaLayout->getModificaMobile()->getCheckSchedaSD()->setChecked(pm->getSchedaSD());
        modificaLayout->getModificaMobile()->getCheckJack()->setChecked(pm->getJack());
        modificaLayout->getModificaMobile()->getCheckFaceID()->setChecked(pm->getFaceID());
        modificaLayout->getModificaMobile()->getLinePxFront()->setText(QString::number(pm->getPxFrontali()));
        modificaLayout->getModificaMobile()->getLinePxBack()->setText(QString::number(pm->getPxPosteriori()));
        if(tipo == "smartphone") {
            modificaLayout->getLabelDevice()->setText(QString("SMARTPHONE"));
            Smartphone* ps = dynamic_cast<Smartphone*>(pm);
            modificaLayout->getModificaSmartphone()->getCheckDualSim()->setChecked(ps->getDualSIM());
        }
        if(tipo == "tablet") {
            modificaLayout->getLabelDevice()->setText(QString("TABLET"));
            Tablet* pt = dynamic_cast<Tablet*>(pm);
            modificaLayout->getModificaTablet()->getCheckSim()->setChecked(pt->getSIM());
        }
    }
    if(tipo == "portatile" || tipo == "fisso" || tipo == "convertibile") { // computer
        Computer* pc = dynamic_cast<Computer*>(daModificare);
        modificaLayout->getModificaComputer()->getCheckTouchscreen()->setChecked(pc->getTouchscreen());
        modificaLayout->getModificaComputer()->getCheckLettoreCD()->setChecked(pc->getLettoreCD());
        modificaLayout->getModificaComputer()->getLinePorteUsb()->setText(QString::number(pc->getPorteUSB()));
        if(tipo == "portatile") {
            modificaLayout->getLabelDevice()->setText(QString("PORTATILE"));
            Portatile* pp = dynamic_cast<Portatile*>(pc);
            modificaLayout->getModificaPortatile()->getCheckEthernet()->setChecked(pp->getEthernet());
            modificaLayout->getModificaPortatile()->getCheckWebcam()->setChecked(pp->getWebcam());
            modificaLayout->getModificaPortatile()->getCheckLuceTastiera()->setChecked(pp->getLuceTastiera());
            modificaLayout->getModificaPortatile()->getLinePxWebcam()->setText(QString::number(pp->getPxWebcam()));
        }
        if(tipo == "fisso") {
            modificaLayout->getLabelDevice()->setText(QString("FISSO"));
            Fisso* pf = dynamic_cast<Fisso*>(pc);
            modificaLayout->getModificaFisso()->getCheckBluetooth()->setChecked(pf->getBluetooth());
            modificaLayout->getModificaFisso()->getCheckWifi()->setChecked(pf->getWifi());
        }
    }
    if(tipo == "convertibile") {// mobile + computer
        modificaLayout->getLabelDevice()->setText(QString("CONVERTIBILE"));
        Convertibile* pcv = dynamic_cast<Convertibile*>(daModificare);
        // tablet
        modificaLayout->getModificaTablet()->getCheckSim()->setChecked(pcv->getSIM());
        // portatile
        modificaLayout->getModificaPortatile()->getCheckEthernet()->setChecked(pcv->getEthernet());
        modificaLayout->getModificaPortatile()->getCheckWebcam()->setChecked(pcv->getWebcam());
        modificaLayout->getModificaPortatile()->getCheckLuceTastiera()->setChecked(pcv->getLuceTastiera());
        // propri
        modificaLayout->getModificaConvertibile()->getCheckPenna()->setChecked(pcv->getPenna());
        modificaLayout->getModificaConvertibile()->getCheckStaccaTastiera()->setChecked(pcv->getStaccaTastiera());
    }


    modificaLayout->getModificaMobile()->hide();
    modificaLayout->getModificaComputer()->hide();
    modificaLayout->getModificaPortatile()->hide();
    modificaLayout->getModificaFisso()->hide();
    modificaLayout->getModificaSmartphone()->hide();
    modificaLayout->getModificaTablet()->hide();
    modificaLayout->getModificaConvertibile()->hide();
    modificaLayout->show();
}

void Controller::confermaModificaDevice() {
    std::string tipo = modificaLayout->getLabelDevice()->text().toStdString();
    Device* daModificare = catalogoLayout->getLista()->elementoCorrente()->oggettoCorrente();
    daModificare->setPathImmagine(modificaLayout->getPathImm());
    if( modificaLayout->getLineModello()->text() == "" ) { QMessageBox::warning(modificaLayout,"Campo mancante","Non hai specificato il modello"); return; }
    else { daModificare->setModello(modificaLayout->getLineModello()->text().toStdString()); }
    if( modificaLayout->getLineSchermo()->text() == "" ) { QMessageBox::warning(modificaLayout,"Campo mancante","Non hai indicato le dimensioni dello schermo"); return; }
    else { daModificare->setDimensioneSchermo(modificaLayout->getLineSchermo()->text().toStdString()); };
    if(modificaLayout->getLinePrezzo()->text() == "") { QMessageBox::warning(modificaLayout,"E' gratis ?","Non hai inserito il prezzo"); return; }
    else { daModificare->setPrezzo(modificaLayout->getLinePrezzo()->text().toDouble());}
    if(modificaLayout->getLineProduttore()->text() == "") { QMessageBox::warning(modificaLayout,"Campo mancante","Non hai specificato il produttore"); return; }
    else { daModificare->setProduttore(modificaLayout->getLineProduttore()->text().toStdString()); }
    if(modificaLayout->getLineProcessore()->text() == "") { QMessageBox::warning(modificaLayout,"Campo mancante","Non hai indicato le specifiche del processore"); return; }
    else{ daModificare->setProcessore(modificaLayout->getLineProcessore()->text().toStdString()); }
    daModificare->setMemoriaRam(modificaLayout->getIntMemoriaRam());
    daModificare->setMemoria(modificaLayout->getIntMemoriaInterna());

    if(tipo == "SMARTPHONE" || tipo == "TABLET" || tipo == "CONVERTIBILE") { // mobile
        Mobile* pm = dynamic_cast<Mobile*>(daModificare);
        pm->setSchedaSD(modificaLayout->getModificaMobile()->getCheckSchedaSD()->isChecked());
        pm->setJack(modificaLayout->getModificaMobile()->getCheckJack()->isChecked());
        pm->setFaceID(modificaLayout->getModificaMobile()->getCheckFaceID()->isChecked());
        if(modificaLayout->getModificaMobile()->getLinePxFront()->text() == "") { QMessageBox::warning(modificaLayout,"Campo mancante","Non hai indicato la fotocamera frontale"); return; }
        else{ pm->setPxFrontali(modificaLayout->getModificaMobile()->getLinePxFront()->text().toInt()); }
        if(modificaLayout->getModificaMobile()->getLinePxBack()->text() == "") { QMessageBox::warning(modificaLayout,"Campo mancante","Non hai indicato la fotocamera posteriore"); return; }
        else{ pm->setPxPosteriori(modificaLayout->getModificaMobile()->getLinePxBack()->text().toInt()); }
        if(tipo == "SMARTPHONE") {
            Smartphone* ps = dynamic_cast<Smartphone*>(pm);
            ps->setDualSIM(modificaLayout->getModificaSmartphone()->getCheckDualSim()->isChecked());
        }
        if(tipo == "TABLET") {
            Tablet* pt = dynamic_cast<Tablet*>(pm);
            pt->setSIM(modificaLayout->getModificaTablet()->getCheckSim()->isChecked());
        }
    }
    if(tipo == "PORTATILE" || tipo == "FISSO" || tipo == "CONVERTIBILE") { // computer
        Computer* pc = dynamic_cast<Computer*>(daModificare);
        pc->setTouchscreen(modificaLayout->getModificaComputer()->getCheckTouchscreen()->isChecked());
        pc->setLettoreCD(modificaLayout->getModificaComputer()->getCheckLettoreCD()->isChecked());
        if(modificaLayout->getModificaComputer()->getLinePorteUsb()->text() == "") { QMessageBox::warning(modificaLayout,"Campo mancante","Non hai indicato il numero di porte USB"); return; }
        else{ pc->setPorteUSB(modificaLayout->getModificaComputer()->getLinePorteUsb()->text().toInt()); }
        if(tipo == "PORTATILE") {
            Portatile* pp = dynamic_cast<Portatile*>(pc);
            pp->setEthernet(modificaLayout->getModificaPortatile()->getCheckEthernet()->isChecked());
            pp->setWebcam(modificaLayout->getModificaPortatile()->getCheckWebcam()->isChecked());
            pp->setLuceTastiera(modificaLayout->getModificaPortatile()->getCheckLuceTastiera()->isChecked());
            if( modificaLayout->getModificaPortatile()->getCheckWebcam()->isChecked() && modificaLayout->getModificaPortatile()->getLinePxWebcam()->text() == "" ) { QMessageBox::warning(modificaLayout,"Campo mancante","Non hai indicato la webcam"); return; }
            else{ pp->setPxWebcam(modificaLayout->getModificaPortatile()->getLinePxWebcam()->text().toInt()); }
        }
        if(tipo == "FISSO") {
            Fisso* pf = dynamic_cast<Fisso*>(pc);
            pf->setBluetooth(modificaLayout->getModificaFisso()->getCheckBluetooth()->isChecked());
            pf->setWifi(modificaLayout->getModificaFisso()->getCheckWifi()->isChecked());
        }
    }
    if(tipo == "CONVERTIBILE") {// mobile + computer
        Convertibile* pcv = dynamic_cast<Convertibile*>(daModificare);
        // tablet
        pcv->setSIM(modificaLayout->getModificaTablet()->getCheckSim()->isChecked());
        // portatile
        pcv->setEthernet(modificaLayout->getModificaPortatile()->getCheckEthernet()->isChecked());
        pcv->setWebcam(modificaLayout->getModificaPortatile()->getCheckWebcam()->isChecked());
        pcv->setLuceTastiera(modificaLayout->getModificaPortatile()->getCheckLuceTastiera()->isChecked());
        // propri
        pcv->setPenna(modificaLayout->getModificaConvertibile()->getCheckPenna()->isChecked());
        pcv->setStaccaTastiera(modificaLayout->getModificaConvertibile()->getCheckStaccaTastiera()->isChecked());
    }

    modello->salva();
    carica();

    modificaLayout->close();
}

void Controller::eliminaDevice(){

    if( !catalogoLayout->getLista()->elementoCorrente() ) { QMessageBox::warning(catalogoLayout,"Nessun elemneto","Devi selezionare il dispositivo da eliminare"); return; }

    DeviceElementoLista* daEliminare = catalogoLayout->getLista()->elementoCorrente();

    modello->getList()->elimina(daEliminare->oggettoCorrente());

    modello->salva();
    carica();
}

