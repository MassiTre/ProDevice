#include "modello.h"
#include "Avvisi/gestioneeccezione.h"

void Modello::setPathXML(std::string p){
    pathXML = p;
    delete list;
    salvataggio = false;
    list = new Container<Device*>();
}

void Modello::setSalvataggio(bool b){ salvataggio = b; }

bool Modello::getSalvataggio() const{ return salvataggio; }

Container<Device*>::iterator Modello::it_begin(){
    return list->it_begin();
}

Container<Device*>::iterator Modello::it_end(){
    return list->it_end();
}

Container<Device*>::constiterator Modello::cit_begin() const{
    return list->cit_begin();
}

Container<Device*>::constiterator Modello::cit_end() const{
    return list->cit_end();
}

void Modello::salva() {
    QSaveFile file(QString::fromStdString(pathXML));

    if(!file.open(QIODevice::WriteOnly)) {
        throw GestioneEccezione("impossibile scrivere il file, ci scusiamo per il disagio");
    }

    QXmlStreamWriter stream(&file);

    stream.setAutoFormatting(true); // Leggibilità del file XML
    stream.writeStartDocument();  // Scrittura intestazioni XML

    stream.writeStartElement("root");

    auto it = cit_begin();
    while(it != cit_end()) {
        const Device* daSalvare = *it;
        const QString tipoDevice = QString::fromStdString(daSalvare->getTipo());

        stream.writeEmptyElement(tipoDevice); // che tipo sto inserendo

        stream.writeAttribute("PathImmagine", QString::fromStdString(daSalvare->getPathImmagine()));
        stream.writeAttribute("Prezzo", QString::number(daSalvare->getPrezzo()));
        stream.writeAttribute("Modello", QString::fromStdString(daSalvare->getModello()));
        stream.writeAttribute("Produttore", QString::fromStdString(daSalvare->getProduttore()));
        stream.writeAttribute("Schermo", QString::fromStdString(daSalvare->getDimensioneSchermo()));
        stream.writeAttribute("Processore", QString::fromStdString(daSalvare->getProcessore()));
        stream.writeAttribute("Ram", QString("%1").arg(daSalvare->getMemoriaRam()));
        stream.writeAttribute("Memoria", QString("%1").arg(daSalvare->getMemoria()));

        if(daSalvare->getTipo() == "smartphone" || tipoDevice == "tablet") { // mobile
            const Mobile* oMobile = dynamic_cast<const Mobile*>(daSalvare);
            stream.writeAttribute("PxFrontali", QString("%1").arg(oMobile->getPxFrontali()));
            stream.writeAttribute("PxPosteriori", QString("%1").arg(oMobile->getPxPosteriori()));
            stream.writeAttribute("SchedaSD", oMobile->getSchedaSD() ? "true" : "false");
            stream.writeAttribute("Jack", oMobile->getJack() ? "true" : "false");
            stream.writeAttribute("FaceID", oMobile->getFaceID() ? "true" : "false");

            if(tipoDevice == "smartphone") {
                const Smartphone* oSmartphone = dynamic_cast<const Smartphone*>(oMobile);
                stream.writeAttribute("DualSIM", oSmartphone->getDualSIM() ? "true" : "false");
            }

            if(tipoDevice == "tablet") {
                const Tablet* oTablet = dynamic_cast<const Tablet*>(oMobile);
                stream.writeAttribute("SIM", oTablet->getSIM() ? "true" : "false");
            }

        } else if(tipoDevice == "portatile" || tipoDevice == "fisso") { // computer
                const Computer* oComputer = dynamic_cast<const Computer*>(daSalvare);
                stream.writeAttribute("Touchscreen", oComputer->getTouchscreen() ? "true" : "false");
                stream.writeAttribute("LettoreCD", oComputer->getLettoreCD() ? "true" : "false");
                stream.writeAttribute("PorteUSB", QString("%1").arg(oComputer->getPorteUSB()));

            if(tipoDevice == "portatile") {
                const Portatile* oPortatile = dynamic_cast<const Portatile*>(oComputer);
                stream.writeAttribute("Ethernet", oPortatile->getEthernet() ? "true" : "false");
                stream.writeAttribute("Webcam", oPortatile->getWebcam() ? "true" : "false");
                stream.writeAttribute("LuceTastiera", oPortatile->getLuceTastiera() ? "true" : "false");
                stream.writeAttribute("PxWebcam", QString("%1").arg(oPortatile->getPxWebcam()));
            }

            if(tipoDevice == "fisso") {
                const Fisso* oFisso = dynamic_cast<const Fisso*>(oComputer);
                stream.writeAttribute("Bluetooth", oFisso->getBluetooth() ? "true" : "false");
                stream.writeAttribute("WiFi", oFisso->getWifi() ? "true" : "false");
            }

        } else if(tipoDevice == "convertibile") {
            const Convertibile* oConvertibile = dynamic_cast<const Convertibile*>(daSalvare);
                // mobile //
                stream.writeAttribute("PxFrontali", QString("%1").arg(oConvertibile->getPxFrontali()));
                stream.writeAttribute("PxPosteriori", QString("%1").arg(oConvertibile->getPxPosteriori()));
                stream.writeAttribute("FaceID", oConvertibile->getFaceID() ? "true" : "false");
                stream.writeAttribute("SchedaSD", oConvertibile->getSchedaSD() ? "true" : "false");
                stream.writeAttribute("Jack", oConvertibile->getJack() ? "true" : "false");
                // tablet//
                stream.writeAttribute("SIM", oConvertibile->getSIM() ? "true" : "false");
                // computer //
                stream.writeAttribute("Touchscreen", oConvertibile->getTouchscreen() ? "true" : "false");
                stream.writeAttribute("LettoreCD", oConvertibile->getLettoreCD() ? "true" : "false");
                stream.writeAttribute("PorteUSB", QString("%1").arg(oConvertibile->getPorteUSB()));
                // portatile //
                stream.writeAttribute("Ethernet", oConvertibile->getEthernet() ? "true" : "false");
                stream.writeAttribute("Webcam", oConvertibile->getWebcam() ? "true" : "false");
                stream.writeAttribute("LuceTastiera", oConvertibile->getLuceTastiera() ? "true" : "false");
                stream.writeAttribute("PxWebcam", QString("%1").arg(oConvertibile->getPxWebcam()));
                // propri //
                stream.writeAttribute("Penna", oConvertibile->getPenna() ? "true" : "false");
                stream.writeAttribute("StaccaTastiera", oConvertibile->getStaccaTastiera() ? "true" : "false");
        }

        ++it;
    }

        stream.writeEndElement();
        stream.writeEndDocument();
        salvataggio = true;
        file.commit();
}

void Modello::carica(){
    QFile fileSalvataggio(QString::fromStdString(pathXML));

    if(!fileSalvataggio.open(QIODevice::ReadOnly)) {
        GestioneEccezione e = GestioneEccezione("impossibile leggere il file, ci scusiamo per il disagio");
        e.stampaEccezione();
        throw e;
    }

    QXmlStreamReader stream(&fileSalvataggio);
    if(stream.readNextStartElement()){
        if(stream.name() == "root"){
            while(stream.readNextStartElement()){
                const QXmlStreamAttributes attributo = stream.attributes();

                std::string PathImmagine = attributo.hasAttribute("PathImmagine")? attributo.value("PathImmagine").toString().toStdString(): "";
                std::string Modello = attributo.hasAttribute("Modello") ? attributo.value("Modello").toString().toStdString() : "";
                std::string Produttore = attributo.hasAttribute("Produttore") ? attributo.value("Produttore").toString().toStdString() : "";
                std::string Schermo = attributo.hasAttribute("Schermo") ? attributo.value("Schermo").toString().toStdString() : "";
                std::string Processore = attributo.hasAttribute("Processore") ? attributo.value("Processore").toString().toStdString() : "";
                int Ram = attributo.hasAttribute("Ram") ? attributo.value("Ram").toInt() : 0;
                double Prezzo = attributo.hasAttribute("Prezzo") ? attributo.value("Prezzo").toDouble() : 0;
                int Memoria = attributo.hasAttribute("Memoria") ? attributo.value("Memoria").toInt() : 0;

                Device* daInserire = nullptr;

                if(stream.name() == "smartphone" || stream.name() == "tablet"){
                    int PxFrontali = attributo.hasAttribute("PxFrontali") ? attributo.value("PxFrontali").toInt() : 0;
                    int PxPosteriori = attributo.hasAttribute("PxPosteriori") ? attributo.value("PxPosteriori").toInt() : 0;
                    bool SchedaSD = attributo.hasAttribute("SchedaSD") ? attributo.value("SchedaSD").toString()=="true"? true: false : false;
                    bool Jack = attributo.hasAttribute("Jack") ? attributo.value("Jack").toString()=="true"? true: false : false;
                    bool FaceID = attributo.hasAttribute("FaceID") ? attributo.value("FaceID").toString()=="true"? true: false : false;

                    if(stream.name() == "smartphone") {
                        bool DualSIM = attributo.hasAttribute("DualSIM") ? attributo.value("DualSIM").toString()=="true"? true: false : false;

                        daInserire = new Smartphone(PathImmagine, Modello, Produttore, Schermo, Processore, Ram, Memoria, Prezzo, SchedaSD, Jack, FaceID, PxFrontali, PxPosteriori, DualSIM);
                    }

                    if(stream.name() == "tablet") {
                        bool SIM = attributo.hasAttribute("SIM") ? attributo.value("SIM").toString()=="true"? true: false : false;

                        daInserire = new Tablet(PathImmagine, Modello, Produttore, Schermo, Processore, Ram, Memoria, Prezzo, SchedaSD, Jack, FaceID, PxFrontali, PxPosteriori, SIM);
                    }
                } else if(stream.name() == "portatile" || stream.name() == "fisso"){
                    bool Touchscreen = attributo.hasAttribute("Touchscreen") ? attributo.value("Touchscreen").toString()=="true"? true: false : false;
                    bool LettoreCD = attributo.hasAttribute("LettoreCD") ? attributo.value("LettoreCD").toString()=="true"? true: false : false;
                    int PorteUSB = attributo.hasAttribute("PorteUSB") ? attributo.value("PorteUSB").toInt() : 0;

                    if(stream.name() == "portatile") {
                        bool Ethernet = attributo.hasAttribute("Ethernet") ? attributo.value("Ethernet").toString()=="true"? true: false : false;
                        bool Webcam = attributo.hasAttribute("Webcam") ? attributo.value("Webcam").toString()=="true"? true: false : false;
                        bool LuceTastiera = attributo.hasAttribute("LuceTastiera") ? attributo.value("LuceTastiera").toString()=="true"? true: false : false;
                        int PxWebcam = attributo.hasAttribute("PxWebcam") ? attributo.value("PxWebcam").toInt() : 0;

                        daInserire = new Portatile(PathImmagine, Modello, Produttore, Schermo, Processore, Ram, Memoria, Prezzo, Touchscreen, LettoreCD, PorteUSB, Ethernet, Webcam, LuceTastiera, PxWebcam);
                    }

                    if(stream.name() == "fisso") {
                        bool Bluetooth = attributo.hasAttribute("Bluetooth") ? attributo.value("Bluetooth").toString()=="true"? true: false : false;
                        bool WiFi = attributo.hasAttribute("WiFi") ? attributo.value("WiFi").toString()=="true"? true: false : false;


                        daInserire = new Fisso(PathImmagine, Modello, Produttore, Schermo, Processore, Ram, Memoria, Prezzo, Touchscreen, LettoreCD, PorteUSB, Bluetooth, WiFi);
                    }
                } else if(stream.name() == "convertibile") {
                    /* mobile */
                    int PxFrontali = attributo.hasAttribute("PxFrontali") ? attributo.value("PxFrontali").toInt() : 0;
                    int PxPosteriori = attributo.hasAttribute("PxPosteriori") ? attributo.value("PxPosteriori").toInt() : 0;
                    bool SchedaSD = attributo.hasAttribute("SchedaSD") ? attributo.value("SchedaSD").toString()=="true"? true: false : false;
                    bool Jack = attributo.hasAttribute("Jack") ? attributo.value("Jack").toString()=="true"? true: false : false;
                    bool FaceID = attributo.hasAttribute("FaceID") ? attributo.value("FaceID").toString()=="true"? true: false : false;
                    /*tablet*/
                    bool SIM = attributo.hasAttribute("SIM") ? attributo.value("SIM").toString()=="true"? true: false : false;
                    /* computer */
                    bool Touchscreen = attributo.hasAttribute("Touchscreen") ? attributo.value("Touchscreen").toString()=="true"? true: false : false;
                    bool LettoreCD = attributo.hasAttribute("LettoreCD") ? attributo.value("LettoreCD").toString()=="true"? true: false : false;
                    int PorteUSB = attributo.hasAttribute("PorteUSB") ? attributo.value("PorteUSB").toInt() : 0;
                    /* portatile */
                    bool Ethernet = attributo.hasAttribute("Ethernet") ? attributo.value("Ethernet").toString()=="true"? true: false : false;
                    bool Webcam = attributo.hasAttribute("Webcam") ? attributo.value("Webcam").toString()=="true"? true: false : false;
                    bool LuceTastiera = attributo.hasAttribute("LuceTastiera") ? attributo.value("LuceTastiera").toString()=="true"? true: false : false;
                    /* propri */
                    bool Penna = attributo.hasAttribute("Penna") ? attributo.value("Penna").toString()=="true"? true: false : false;
                    bool StaccaTastiera = attributo.hasAttribute("StaccaTastiera") ? attributo.value("StaccaTastiera").toString()=="true"? true: false : false;

                    daInserire = new Convertibile(PathImmagine, Modello, Produttore, Schermo, Processore, Ram, Memoria, Prezzo, SchedaSD, Jack, FaceID, PxFrontali, PxPosteriori, SIM, Touchscreen, LettoreCD, PorteUSB, Ethernet, Webcam, LuceTastiera, Penna, StaccaTastiera);
                }


                if(daInserire!=nullptr)
                    list->insertBack(daInserire);

                if(!stream.isEndDocument())
                    stream.skipCurrentElement();
            }
        }
    } else {
        QMessageBox::warning(nullptr,"Attenzione:",QString::fromStdString("File vuoto! \nInserisci il primo dispositivo"));
    }
}

Modello::Modello(std::string p):
    list(new Container<Device*>),
    pathXML(p),
    salvataggio(true) {}

Container<Device*>* Modello::getList() const{ return list; }

