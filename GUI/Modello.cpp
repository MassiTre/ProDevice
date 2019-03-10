#include "modello.h"

#include <QSaveFile>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>

void Modello::setNuovaPath(std::string p){
    path = p;
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
    return list->const_begin();
}

Container<Device*>::constiterator Modello::cit_end() const{
    return list->const_end();
}
/*
void Modello::salva(){
    QSaveFile file(QString::fromStdString(path));
    QXmlStreamWriter lettore(&file);

    lettore.setAutoFormatting(true); // Leggibilità del file XML
    lettore.writeStartDocument();  // Scrittura intestazioni XML

    lettore.writeStartElement("Dispositivi nuovi salvati");

    auto it = cit_begin();
    while(it != cit_end()){
        const Device* daSalvare = *it;
        const QString tipoDevice = QString::fromStdString(daSalvare->getTipo());
        lettore.writeEmptyElement(tipoDevice); // che tipo sto inserendo

        lettore.writeAttribute("Nome", QString::fromStdString(daSalvare->getNome()));
        lettore.writeAttribute("CasaProduttrice", QString::fromStdString(daSalvare->getCasaProduttrice()));
        lettore.writeAttribute("Eta", QString("%1").arg(daSalvare->getEta()));
        lettore.writeAttribute("AnnoPubblicazione", QString("%1").arg(daSalvare->getAnnoPubblicazione()));
        lettore.writeAttribute("Prezzo", QString().arg(daSalvare->getPrezzo()));
        lettore.writeAttribute("PezziInMagazzino", QString("%1").arg(daSalvare->getPezziInMagazzino()));
        lettore.writeAttribute("usato", daSalvare->getUsato() ? "True" : "False");
        lettore.writeAttribute("pathImm", QString::fromStdString(daSalvare->getPath()));

        if(tipologiaOgg == "Videogioco"){
            const Videogioco* oggVideogioco = static_cast<const Videogioco*>(daSalvare);
            lettore.writeAttribute("Ps4", oggVideogioco->getPs4() ? "True" : "False");
            lettore.writeAttribute("XboxOne", oggVideogioco->getXboxOne() ? "True" : "False");
            lettore.writeAttribute("Genere", QString::fromStdString(oggVideogioco->getGenere()));
            lettore.writeAttribute("Sconto", QString("%1").arg(oggVideogioco->getSconto()));
            lettore.writeAttribute("Contenuto", QString::fromStdString(oggVideogioco->getContenuto()));
        } else if(tipologiaOgg == "GiocoDaTavolo"){
            const GiocoDaTavolo* oggGiocoDaTavolo = static_cast<const GiocoDaTavolo*>(daSalvare);
            lettore.writeAttribute("NumGiocatori", QString("%1").arg(oggGiocoDaTavolo->getNumGiocatori()));
            lettore.writeAttribute("Tipologia", QString::fromStdString(oggGiocoDaTavolo->getTipologia()));
            lettore.writeAttribute("Regolamento", QString::fromStdString(oggGiocoDaTavolo->getRegolamento()));
            lettore.writeAttribute("Contenuto", QString::fromStdString(oggGiocoDaTavolo->getContenuto()));
            lettore.writeAttribute("Sconto", QString("%1").arg(oggGiocoDaTavolo->getSconto()));
        } else if(tipologiaOgg == "GiocoDaTavoloConCarte"){
            const GiocoDaTavoloConCarte* oggGiocoDaTavoloConCarte = static_cast<const GiocoDaTavoloConCarte*>(daSalvare);
            lettore.writeAttribute("edizioneLimitata", oggGiocoDaTavoloConCarte->getEdizioneLimitata() ? "True" : "False");
            lettore.writeAttribute("Regolamento", QString::fromStdString(oggGiocoDaTavoloConCarte->getRegolamento()));
            lettore.writeAttribute("NumGiocatori", QString("%1").arg(oggGiocoDaTavoloConCarte->getNumGiocatori()));
            lettore.writeAttribute("Contenuto", QString::fromStdString(oggGiocoDaTavoloConCarte->getContenuto()));
            lettore.writeAttribute("Sconto", QString("%1").arg(oggGiocoDaTavoloConCarte->getSconto()));
        } else if(tipologiaOgg == "CarteCollezionabili"){
            const CarteCollezionabili* oggCarteCollezionabili = static_cast<const CarteCollezionabili*>(daSalvare);
            lettore.writeAttribute("edizioneLimitata", oggCarteCollezionabili->getEdizioneLimitata() ? "True" : "False");
            lettore.writeAttribute("NumCarte", QString("%1").arg(oggCarteCollezionabili->getNumCarte()));
            lettore.writeAttribute("Edizione", QString::fromStdString(oggCarteCollezionabili->getEdizione()));
            lettore.writeAttribute("Sconto", QString("%1").arg(oggCarteCollezionabili->getSconto()));
        }

        ++it;
    }

    lettore.writeEndElement();
    lettore.writeEndDocument();
    datiSalvati = true;
    file.commit();
}
*/
void Modello::carica(){
    QFile fileSalvataggio(QString::fromStdString(path));

    if(!fileSalvataggio.open(QIODevice::ReadOnly)) {
        qWarning() << "Impossibile caricare il file" << fileSalvataggio.errorString();
        return ;
    }

    QXmlStreamReader lettore(&fileSalvataggio);
    if(lettore.readNextStartElement()){
        if(lettore.name() == "root"){
            while(lettore.readNextStartElement()){
                const QXmlStreamAttributes attributo = lettore.attributes();

                std::string PathImmagine = attributo.hasAttribute("pathImmagine")? attributo.value("pathImmagine").toString().toStdString(): "";
                std::string Modello = attributo.hasAttribute("Modello") ? attributo.value("Modello").toString().toStdString() : "";
                std::string Produttore = attributo.hasAttribute("Produttore") ? attributo.value("Produttore").toString().toStdString() : "";
                std::string Schermo = attributo.hasAttribute("Schermo") ? attributo.value("Schermo").toString().toStdString() : "";
                std::string Processore = attributo.hasAttribute("Processore") ? attributo.value("Processore").toString().toStdString() : "";
                int Ram = attributo.hasAttribute("Ram") ? attributo.value("Ram").toInt() : 0;
                double Prezzo = attributo.hasAttribute("Prezzo") ? attributo.value("Prezzo").toDouble() : 0;
                int Memoria = attributo.hasAttribute("Memoria") ? attributo.value("Memoria").toInt() : 0;

                Device* daInserire = nullptr;

                if(lettore.name() == "Smartphone" || lettore.name() == "Tablet"){
                    int PxFrontali = attributo.hasAttribute("PxFrontali") ? attributo.value("PxFrontali").toInt() : 0;
                    int PxPosteriori = attributo.hasAttribute("PxPosteriori") ? attributo.value("PxPosteriori").toInt() : 0;
                    bool SchedaSD = attributo.hasAttribute("SchedaSD") ? attributo.value("SchedaSD").toString()=="true"? true: false : false;
                    bool Jack = attributo.hasAttribute("Jack") ? attributo.value("Jack").toString()=="true"? true: false : false;
                    bool FaceID = attributo.hasAttribute("FaceID") ? attributo.value("FaceID").toString()=="true"? true: false : false;

                    if(lettore.name() == "Smartphone") {
                        bool DualSIM = attributo.hasAttribute("DualSIM") ? attributo.value("DualSIM").toString()=="true"? true: false : false;

                        daInserire = new Smartphone(PathImmagine, Modello, Produttore, Schermo, Processore, Ram, Memoria, Prezzo, SchedaSD, Jack, FaceID, PxFrontali, PxPosteriori, DualSIM);
                    }

                    if(lettore.name() == "Tablet") {
                        bool SIM = attributo.hasAttribute("SIM") ? attributo.value("SIM").toString()=="true"? true: false : false;

                        daInserire = new Tablet(PathImmagine, Modello, Produttore, Schermo, Processore, Ram, Memoria, Prezzo, SchedaSD, Jack, FaceID, PxFrontali, PxPosteriori, SIM);
                    }
                } else if(lettore.name() == "Portatile" || lettore.name() == "Fisso"){
                    bool Touchscreen = attributo.hasAttribute("Touchscreen") ? attributo.value("Touchscreen").toString()=="true"? true: false : false;
                    bool LettoreCD = attributo.hasAttribute("LettoreCD") ? attributo.value("LettoreCD").toString()=="true"? true: false : false;
                    int PorteUSB = attributo.hasAttribute("PorteUSB") ? attributo.value("PorteUSB").toInt() : 0;

                    if(lettore.name() == "Portatile") {
                        bool Ethernet = attributo.hasAttribute("Ethernet") ? attributo.value("Ethernet").toString()=="true"? true: false : false;
                        bool Webcam = attributo.hasAttribute("Webcam") ? attributo.value("Webcam").toString()=="true"? true: false : false;
                        bool LuceTastiera = attributo.hasAttribute("LuceTastiera") ? attributo.value("LuceTastiera").toString()=="true"? true: false : false;
                        int PxWebcam = attributo.hasAttribute("PxWebcam") ? attributo.value("PxWebcam").toInt() : 0;

                        daInserire = new Portatile(PathImmagine, Modello, Produttore, Schermo, Processore, Ram, Memoria, Prezzo, Touchscreen, LettoreCD, PorteUSB, Ethernet, Webcam, LuceTastiera, PxWebcam);
                    }

                    if(lettore.name() == "Fisso") {
                        bool Bluetooth = attributo.hasAttribute("Bluetooth") ? attributo.value("Bluetooth").toString()=="true"? true: false : false;
                        bool WiFi = attributo.hasAttribute("WiFi") ? attributo.value("WiFi").toString()=="true"? true: false : false;


                        daInserire = new Fisso(PathImmagine, Modello, Produttore, Schermo, Processore, Ram, Memoria, Prezzo, Touchscreen, LettoreCD, PorteUSB, Bluetooth, WiFi);
                    }
                } else if(lettore.name() == "Convertibile") {
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

                if(!lettore.isEndDocument())
                    lettore.skipCurrentElement();
            }
        }
    }
}

Modello::Modello(std::string p):
    list(new Container<Device*>),
    path(p),
    salvataggio(true) {}

Container<Device*>* Modello::getList() const{ return list; }
