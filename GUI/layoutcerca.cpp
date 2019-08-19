#include "layoutcerca.h"

LayoutCerca::LayoutCerca(QWidget* p) :
    parent(p),
    vBox(new QVBoxLayout(this)),
    grid(new QGridLayout()),
    tipoDevice(new ComboTipoDevice(this)),
    formModello(new QFormLayout()),
    lineModello(new QLineEdit(this)),
    formProduttore(new QFormLayout()),
    lineProduttore(new QLineEdit(this)),
    checkSchedaSD(new QCheckBox("Scheda SD",this)),
    checkDualSim(new QCheckBox("Dual SIM",this)),
    checkSim(new QCheckBox("SIM",this)),
    checkTouchscreen(new QCheckBox("TouchScreen",this)),
    checkLuceTastiera(new QCheckBox("Tastiera retroillumata",this)),
    risultato(new DeviceWidgetLista(this)),
    layoutPrezzi(new QGridLayout()),
    baseTitolo(new QLabel("Prezzo base:")),
    baseNumero(new QLabel("0.0 €")),
    totaleTitolo(new QLabel("Prezzo totale:")),
    totaleNumero(new QLabel("0.0 €")),
    btCerca(new QPushButton("CERCA",this))
{
    lineModello->setPlaceholderText("Inserisci il modello");
    formModello->addRow("Modello:", lineModello);

    lineProduttore->setPlaceholderText("Inserisci il produttore");
    formProduttore->addRow("Produttore:", lineProduttore);

    grid->addWidget(tipoDevice,0,0,1,6);
    grid->addLayout(formModello,1,0,1,3);
    grid->addLayout(formProduttore,1,3,1,3);
    grid->addWidget(checkSchedaSD,2,0,1,2);
    grid->addWidget(checkDualSim,2,2,1,2);
    grid->addWidget(checkSim,2,4,1,2);
    grid->addWidget(checkTouchscreen,3,0,1,2);
    grid->addWidget(checkLuceTastiera,3,2,1,2);

    checkSchedaSD->setEnabled(false);
    checkDualSim->setEnabled(false);
    checkSim->setEnabled(false);
    checkTouchscreen->setEnabled(false);
    checkLuceTastiera->setEnabled(false);

    vBox->addLayout(grid);

    risultato->setStyleSheet("height: 150px");
    vBox->addWidget(risultato);

    baseTitolo->setStyleSheet("font-size: 15px");
    baseNumero->setStyleSheet("font-size: 15px");
    totaleTitolo->setStyleSheet("font-size: 15px");
    totaleNumero->setStyleSheet("font-size: 15px");
    layoutPrezzi->addWidget(baseTitolo,0,0);
    layoutPrezzi->addWidget(totaleTitolo,0,1);
    layoutPrezzi->addWidget(baseNumero,1,0);
    layoutPrezzi->addWidget(totaleNumero,1,1);
    vBox->addLayout(layoutPrezzi);

    vBox->insertStretch(-1,1);

    vBox->addWidget(btCerca);

    connect(tipoDevice, SIGNAL(activated(int)), this, SLOT( attivaCerca(int) ) );
    connect(btCerca, SIGNAL(clicked()), p, SLOT( ricercaDevice() ));
}

void LayoutCerca::attivaCerca(int index) const {
    switch(index){
    case 0:
        checkSchedaSD->setEnabled(false);
        checkDualSim->setEnabled(false);
        checkSim->setEnabled(false);
        checkTouchscreen->setEnabled(false);
        checkLuceTastiera->setEnabled(false);
        break;
    case 1: // smartphone + mobile
        checkSchedaSD->setEnabled(true);
        checkDualSim->setEnabled(true);
        checkSim->setEnabled(false);
        checkTouchscreen->setEnabled(false);
        checkLuceTastiera->setEnabled(false);
        break;
    case 2: // tablet + mobile
        checkSchedaSD->setEnabled(true);
        checkDualSim->setEnabled(false);
        checkSim->setEnabled(true);
        checkTouchscreen->setEnabled(false);
        checkLuceTastiera->setEnabled(false);
        break;
    case 3: // portatile + computer
        checkSchedaSD->setEnabled(false);
        checkDualSim->setEnabled(false);
        checkSim->setEnabled(false);
        checkTouchscreen->setEnabled(true);
        checkLuceTastiera->setEnabled(true);
        break;
    case 4: // fisso + computer
        checkSchedaSD->setEnabled(false);
        checkDualSim->setEnabled(false);
        checkSim->setEnabled(false);
        checkTouchscreen->setEnabled(true);
        checkLuceTastiera->setEnabled(false);
        break;
    case 5: // convertibile + tablet + mobile + portatile + computer
        checkSchedaSD->setEnabled(true);
        checkDualSim->setEnabled(false);
        checkSim->setEnabled(true);
        checkTouchscreen->setEnabled(true);
        checkLuceTastiera->setEnabled(true);
        break;
    }
}

DeviceWidgetLista* LayoutCerca::getRisultato() {
    return risultato;
}

void LayoutCerca::svuotaRisultato() {
    risultato->clear();
}

void LayoutCerca::setPrezzoBase(const QString pb){
    baseNumero->setText(pb);
}

void LayoutCerca::setPrezzoTotale(const QString pt){
    totaleNumero->setText(pt);
}

ComboTipoDevice* LayoutCerca::getTipoDevice() const { return tipoDevice; }
QLineEdit *LayoutCerca::getLineModello() const { return lineModello; }
QLineEdit *LayoutCerca::getLineProduttore() const { return lineProduttore; }
QCheckBox* LayoutCerca::getCheckSchedaSD() const{ return checkSchedaSD;}
QCheckBox* LayoutCerca::getCheckSim() const { return checkSim; }
QCheckBox* LayoutCerca::getCheckDualSim() const{ return checkDualSim;}
QCheckBox* LayoutCerca::getCheckTouchscreen() const{ return checkTouchscreen;}
QCheckBox* LayoutCerca::getCheckLuceTastiera() const{ return checkLuceTastiera;}
