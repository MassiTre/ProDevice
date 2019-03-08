#include "layoutcerca.h"

#include <QGridLayout>
#include <QFormLayout>

LayoutCerca::LayoutCerca(QWidget* p) :
    QWidget (p),
    vBox(new QVBoxLayout(this)),
    /***** Device **************/
    tipoDevice(new ComboTipoDevice(this)),
    lineModello(new QLineEdit(this)),
    lineProduttore(new QLineEdit(this)),
    /***** Mobile **************/
    checkSchedaSD(new QCheckBox("Scheda SD",this)),
    /***** Smartphone **********/
    checkDualSim(new QCheckBox("Dual SIM",this)),
    /***** Tablet **************/
    checkSim(new QCheckBox("SIM",this)),
    /***** Computer ************/
    checkTouchscreen(new QCheckBox("TouchScreen",this)),
    /***** Portatile ***********/
    checkLuceTastiera(new QCheckBox("Tastiera retroillumata",this)),
    btCerca(new QPushButton("CERCA",this))
{
    QGridLayout* grid = new QGridLayout();

    lineModello->setPlaceholderText("Inserisci il modello");
    QFormLayout* formModello = new QFormLayout();
    formModello->addRow("Modello:", lineModello);

    lineProduttore->setPlaceholderText("Inserisci il produttore");
    QFormLayout* formProduttore = new QFormLayout();
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
    vBox->addWidget(btCerca);

    // btCerca->setEnabled(false);

    vBox->insertStretch(1,1);

    connect(tipoDevice, SIGNAL(activated(int)), this, SLOT( attivaCerca(int) ) );

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
