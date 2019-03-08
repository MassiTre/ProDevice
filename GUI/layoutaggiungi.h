#ifndef LAYOUTAGGIUNGI_H
#define LAYOUTAGGIUNGI_H

#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QFormLayout>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QPushButton>

#include "combotipodevice.h"
#include "combomemoriaram.h"
#include "combomemoriainterna.h"

#include "../Gerarchia/gerarchia.h"

class LayoutAggiungiConvertibile : public QWidget {
    Q_OBJECT
private:
    QCheckBox* checkPenna;
    QCheckBox* checkStaccaTastiera;
public:
    LayoutAggiungiConvertibile (QWidget* = nullptr);
};

class LayoutAggiungiFisso : public QWidget {
    Q_OBJECT
private:
    QCheckBox* checkBluetooth;
    QCheckBox* checkWifi;
public:
    LayoutAggiungiFisso (QWidget* = nullptr);
};

class LayoutAggiungiPortatile : public QWidget {
    Q_OBJECT
private:
    QGridLayout* grid;

    QCheckBox* checkEthernet;
    QCheckBox* checkWebcam;
    QCheckBox* checkLuceTastiera;
    QLineEdit* linePxWebcam;
public:
    LayoutAggiungiPortatile (QWidget* = nullptr);
};

class LayoutAggiungiComputer : public QWidget {
    Q_OBJECT
private:
    QCheckBox* checkTouchscreen;
    QCheckBox* checkLettoreCD;
    QLineEdit* linePorteUsb;
public:
    LayoutAggiungiComputer (QWidget* = nullptr);
};

class LayoutAggiungiTablet : public QWidget {
    Q_OBJECT
private:
    QCheckBox* checkSim;
public:
    LayoutAggiungiTablet (QWidget* = nullptr);
};

class LayoutAggiungiSmartphone : public QWidget {
    Q_OBJECT
private:
    QCheckBox* checkDualSim;
public:
    LayoutAggiungiSmartphone (QWidget* = nullptr);
};


class LayoutAggiungiMobile : public QWidget {
    Q_OBJECT
private:
    QCheckBox* checkSchedaSD;
    QCheckBox* checkJack;
    QCheckBox* checkFaceID;
    QLineEdit* linePxFront;
    QLineEdit* linePxBack;
public:
    LayoutAggiungiMobile (QWidget* = nullptr);
};

class LayoutAggiungi : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* vBox;

    ComboTipoDevice* tipoDevice;
    /* form sx */
    QLineEdit* lineModello;
    QLineEdit* lineSchermo;
    QLineEdit* linePrezzo;
    /*form dx*/
    QLineEdit* lineProduttore;
    QLineEdit* lineProcessore;

    // QLineEdit *lineSo; // RIMUOVI DALLA GERARCHIA DIOCAN
    ComboMemoriaRam* memoriaRam; // RAM:  2 4 8 16 32 64
    ComboMemoriaInterna* memoriaInterna;

    QCheckBox* checkTouchID;

    LayoutAggiungiMobile* aggiungiMobile;
    LayoutAggiungiSmartphone* aggiungiSmartphone;
    LayoutAggiungiTablet* aggiungiTablet;
    LayoutAggiungiComputer* aggiungiComputer;
    LayoutAggiungiPortatile* aggiungiPortatile;
    LayoutAggiungiFisso* aggiungiFisso;
    LayoutAggiungiConvertibile* aggiungiConvertibile;

    QPushButton* btAggiungi;
public:
    LayoutAggiungi(QWidget* = nullptr);

    // ComboTipoDevice* getTipoDevice() const;
    QLineEdit *getLineModello() const;
    QLineEdit *getLineSchermo() const;
    QLineEdit *getLinePrezzo() const;
    QLineEdit *getLineProduttore() const;
    QLineEdit *getLineProcessore() const;
    QComboBox* getMemoriaRam() const;
    QComboBox* getMemoriaInterna() const;
    QCheckBox* getCheckTouchID() const;
    QPushButton* getBtAggiungi() const;

public slots:
    void cambiaAggiungiLayout(int) const;
    void aggiungiDevice() const;
};

#endif // LAYOUTAGGIUNGI_H
