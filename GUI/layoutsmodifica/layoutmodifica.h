#ifndef LAYOUTMODIFICA_H
#define LAYOUTMODIFICA_H

#include "../comboboxes/combomemoriainterna.h"
#include "../comboboxes/combomemoriaram.h"
#include "Gerarchia/device.h"
#include "Gerarchia/mobile.h"
#include "Gerarchia/smartphone.h"
#include "Gerarchia/tablet.h"
#include "Gerarchia/computer.h"
#include "Gerarchia/fisso.h"
#include "Gerarchia/portatile.h"
#include "Gerarchia/convertibile.h"
#include "layoutmodificamobile.h"
#include "layoutmodificasmartphone.h"
#include "layoutmodificatablet.h"
#include "layoutmodificacomputer.h"
#include "layoutmodificaportatile.h"
#include "layoutmodificafisso.h"
#include "layoutmodificaconvertibile.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QFileDialog>

class LayoutModifica: public QDialog {
    Q_OBJECT
private:
    QWidget* parent;

    /*** layout principale schermata (verticale) ***/
    QVBoxLayout* vBox; // per inserire layout in base al tipo di dispositivo

    /*** layout principale Device (griglia) ***/
    QGridLayout* grid; // per tipo e dati comuni a tutti i dispositivi (Device base virtuale)
    /*** grid riga 0 ***/
    QLabel* labelDevice;
    QFormLayout* formPrezzo; // layout prezzo
    QLineEdit* linePrezzo;
    /*** grid riga 1,2 - colonna sx */
    QFormLayout* formSx;
    QLineEdit* lineModello;
    QLineEdit* lineSchermo;
    ComboMemoriaRam* memoriaRam;
    /*** grid riga 1,2 - colonna dx */
    QFormLayout* formDx;
    QLineEdit* lineProduttore;
    QLineEdit* lineProcessore;
    ComboMemoriaInterna* memoriaInterna;
    /*** riga 3+ - altri layout ***/
    LayoutModificaMobile* modificaMobile;
    LayoutModificaSmartphone* modificaSmartphone;
    LayoutModificaTablet* modificaTablet;
    LayoutModificaComputer* modificaComputer;
    LayoutModificaPortatile* modificaPortatile;
    LayoutModificaFisso* modificaFisso;
    LayoutModificaConvertibile* modificaConvertibile;
    /*** in fondo - pulsanti ***/
    QHBoxLayout* lowHBox;
    QString pathImm;
    QPushButton* btImmagine;

    QPushButton* btModificaAvanzata;

    QPushButton* btConferma;

public:
    LayoutModifica(QWidget* = nullptr);

    QLabel* getLabelDevice() const;
    QLineEdit* getLineModello() const;
    QLineEdit* getLineSchermo() const;
    QLineEdit* getLinePrezzo() const;
    QLineEdit* getLineProduttore() const;
    QLineEdit* getLineProcessore() const;
    QComboBox* getMemoriaRam() const;
    QComboBox* getMemoriaInterna() const;
    QCheckBox* getCheckTouchID() const;

    int getIntMemoriaRam() const;
    int getIntMemoriaInterna() const;
    void setIndexMemoriaRam(int) const;
    void setIndexMemoriaInterna(int) const;

    std::string getPathImm() const;
    void setPathImm(std::string);

    void setBtImm();

    LayoutModificaMobile* getModificaMobile() const;
    LayoutModificaSmartphone* getModificaSmartphone() const;
    LayoutModificaTablet* getModificaTablet() const;
    LayoutModificaComputer* getModificaComputer() const;
    LayoutModificaPortatile* getModificaPortatile() const;
    LayoutModificaFisso* getModificaFisso() const;
    LayoutModificaConvertibile* getModificaConvertibile() const;


public slots:
    void cambiaModificaLayout() const;
    void selezionaNuovaImm();
};

#endif // LAYOUTMODIFICA_H
