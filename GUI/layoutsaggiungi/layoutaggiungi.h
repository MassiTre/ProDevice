#ifndef LAYOUTAGGIUNGI_H
#define LAYOUTAGGIUNGI_H

#include "../comboboxes/combotipodevice.h"
#include "../comboboxes/combomemoriaram.h"
#include "../comboboxes/combomemoriainterna.h"
#include "Gerarchia/device.h"
#include "Gerarchia/mobile.h"
#include "Gerarchia/smartphone.h"
#include "Gerarchia/tablet.h"
#include "Gerarchia/computer.h"
#include "Gerarchia/fisso.h"
#include "Gerarchia/portatile.h"
#include "Gerarchia/convertibile.h"
#include "Qonteiner/qonteiner.h"
#include "layoutaggiungimobile.h"
#include "layoutaggiungismartphone.h"
#include "layoutaggiungitablet.h"
#include "layoutaggiungicomputer.h"
#include "layoutaggiungiportatile.h"
#include "layoutaggiungifisso.h"
#include "layoutaggiungiconvertibile.h"
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QFileDialog>

class LayoutAggiungi : public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    /*** layout principale schermata (verticale) ***/
    QVBoxLayout* vBox; // per inserire layout in base al tipo di dispositivo

    /*** layout principale Device (griglia) ***/
    QGridLayout* grid; // per tipo e dati comuni a tutti i dispositivi (Device base virtuale)
    /*** grid riga 0 ***/
    ComboTipoDevice* tipoDevice;
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
    LayoutAggiungiMobile* aggiungiMobile;
    LayoutAggiungiSmartphone* aggiungiSmartphone;
    LayoutAggiungiTablet* aggiungiTablet;
    LayoutAggiungiComputer* aggiungiComputer;
    LayoutAggiungiPortatile* aggiungiPortatile;
    LayoutAggiungiFisso* aggiungiFisso;
    LayoutAggiungiConvertibile* aggiungiConvertibile;
    /*** in fondo - pulsanti ***/
    QHBoxLayout* lowHBox;
    QString pathImm;
    QPushButton* btImmagine;
    QPushButton* btAggiungi;
public:
    LayoutAggiungi(QWidget* = nullptr);

    ComboTipoDevice* getTipoDevice() const;
    QLineEdit *getLineModello() const;
    QLineEdit *getLineSchermo() const;
    QLineEdit *getLinePrezzo() const;
    QLineEdit *getLineProduttore() const;
    QLineEdit *getLineProcessore() const;
    QComboBox* getMemoriaRam() const;
    QComboBox* getMemoriaInterna() const;
    QCheckBox* getCheckTouchID() const;

    int getIntMemoriaRam() const;
    int getIntMemoriaInterna() const;

    QString getPathImm() const;

    LayoutAggiungiMobile* getAggiungiMobile() const;
    LayoutAggiungiSmartphone* getAggiungiSmartphone() const;
    LayoutAggiungiTablet* getAggiungiTablet() const;
    LayoutAggiungiComputer* getAggiungiComputer() const;
    LayoutAggiungiPortatile* getAggiungiPortatile() const;
    LayoutAggiungiFisso* getAggiungiFisso() const;
    LayoutAggiungiConvertibile* getAggiungiConvertibile() const;

    void ripristinaTutto() const;
public slots:
    void cambiaAggiungiLayout(int) const; // gestione layout aggiuntivi
    void selezioneImmagine();
};

#endif // LAYOUTAGGIUNGI_H
