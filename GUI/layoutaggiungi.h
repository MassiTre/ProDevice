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

    QCheckBox* getCheckPenna() const;
    QCheckBox* getCheckStaccaTastiera() const;
};

class LayoutAggiungiFisso : public QWidget {
    Q_OBJECT
private:
    QCheckBox* checkBluetooth;
    QCheckBox* checkWifi;
public:
    LayoutAggiungiFisso (QWidget* = nullptr);

    QCheckBox* getCheckBluetooth() const;
    QCheckBox* getCheckWifi() const;
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

    QCheckBox* getCheckEthernet() const;
    QCheckBox* getCheckWebcam() const;
    QCheckBox* getCheckLuceTastiera() const;
    QLineEdit* getLinePxWebcam() const;
public slots:
    void attivaLineWebcam() const;
};

class LayoutAggiungiComputer : public QWidget {
    Q_OBJECT
private:
    QCheckBox* checkTouchscreen;
    QCheckBox* checkLettoreCD;
    QLineEdit* linePorteUsb;
public:
    LayoutAggiungiComputer (QWidget* = nullptr);

    QCheckBox* getCheckTouchscreen() const;
    QCheckBox* getCheckLettoreCD() const;
    QLineEdit* getLinePorteUsb() const;
};

class LayoutAggiungiTablet : public QWidget {
    Q_OBJECT
private:
    QCheckBox* checkSim;
public:
    LayoutAggiungiTablet (QWidget* = nullptr);

    QCheckBox* getCheckSim() const;
};

class LayoutAggiungiSmartphone : public QWidget {
    Q_OBJECT
private:
    QCheckBox* checkDualSim;
public:
    LayoutAggiungiSmartphone (QWidget* = nullptr);

    QCheckBox* getCheckDualSim() const;
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

    QCheckBox* getCheckSchedaSD() const;
    QCheckBox* getCheckJack() const;
    QCheckBox* getCheckFaceID() const;
    QLineEdit* getLinePxFront() const;
    QLineEdit* getLinePxBack() const;
};

class LayoutAggiungi : public QWidget {
    Q_OBJECT
private:
    QWidget* parent;

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

    ComboTipoDevice* getTipoDevice() const;
    QLineEdit *getLineModello() const;
    QLineEdit *getLineSchermo() const;
    QLineEdit *getLinePrezzo() const;
    QLineEdit *getLineProduttore() const;
    QLineEdit *getLineProcessore() const;
    QComboBox* getMemoriaRam() const;
    QComboBox* getMemoriaInterna() const;
    QCheckBox* getCheckTouchID() const;
    QPushButton* getBtAggiungi() const;
    int getIntMemoriaRam() const;
    int getIntMemoriaInterna() const;

    LayoutAggiungiMobile* getAggiungiMobile() const;
    LayoutAggiungiSmartphone* getAggiungiSmartphone() const;
    LayoutAggiungiTablet* getAggiungiTablet() const;
    LayoutAggiungiComputer* getAggiungiComputer() const;
    LayoutAggiungiPortatile* getAggiungiPortatile() const;
    LayoutAggiungiFisso* getAggiungiFisso() const;
    LayoutAggiungiConvertibile* getAggiungiConvertibile() const;

public slots:
    void cambiaAggiungiLayout(int) const;
    // void aggiungiDevice() const;
};

#endif // LAYOUTAGGIUNGI_H
