#ifndef Controller_H
#define Controller_H

#include "menubar.h"
#include "../modello.h"
#include "listdevice/deviceelementolista.h"
#include "layoutsaggiungi/layoutaggiungi.h"
#include "layoutsmodifica/layoutmodifica.h"
#include "Gerarchia/device.h"
#include "Gerarchia/mobile.h"
#include "Gerarchia/smartphone.h"
#include "Gerarchia/tablet.h"
#include "Gerarchia/computer.h"
#include "Gerarchia/fisso.h"
#include "Gerarchia/portatile.h"
#include "Gerarchia/convertibile.h"
#include "layouthome.h"
#include "layoutcerca.h"
#include "layoutcatalogo.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>

class Controller : public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    MenuBar* menu;
    Modello* modello;
    QVBoxLayout* mainLayout;
    LayoutHome* homeLayout;
    LayoutAggiungi* aggiungiLayout;
    LayoutCerca* cercaLayout;
    LayoutCatalogo* catalogoLayout;
    LayoutModifica* modificaLayout;

    QString pathXML;

public:
    Controller(Modello*, QWidget* = nullptr);
    Modello *getModello();

    void carica() const;

    void visualizzaModificaDevice(Device*);
    void confermaModificaDevice(Device*);
public slots:
    void esciLayoutHome() const;
    void esciLayoutAggiungi() const;
    void esciLayoutCerca() const;
    void esciLayoutCatalogo() const;

    void caricaXML();
    void salvaXML() const;
    void arrestaProdevice();

    void aggiungiDevice();
    void ricercaDevice() const;
    void eliminaDevice();

    void visualizzaModificaDevice();
    void confermaModificaDevice();

};

#endif // Controller_H
