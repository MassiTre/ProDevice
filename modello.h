#ifndef MODELLO_H
#define MODELLO_H

#include "Gerarchia/device.h"
#include "Gerarchia/mobile.h"
#include "Gerarchia/smartphone.h"
#include "Gerarchia/tablet.h"
#include "Gerarchia/computer.h"
#include "Gerarchia/fisso.h"
#include "Gerarchia/portatile.h"
#include "Gerarchia/convertibile.h"
#include "Qonteiner/qonteiner.h"
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <QMessageBox>

class Modello {
    private:
        Container<Device*>* list;
        std::string pathXML;
        bool salvataggio;
    public:
        Modello(std::string = ":/Dati Dispositivi/catalogo.xml");
        ~Modello();

        void salva(); //Salvataggio dei dati
        void carica(); //Caricamento dei dati
        void setPathXML(std::string);
        bool getSalvataggio() const;
        void setSalvataggio(bool);
        Container<Device*>::iterator it_begin();
        Container<Device*>::iterator it_end();
        Container<Device*>::constiterator cit_begin() const;
        Container<Device*>::constiterator cit_end() const;

        Container<Device*>* getList() const;
};

#endif // MODELLO_H
