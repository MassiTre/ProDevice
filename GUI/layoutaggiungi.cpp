#include "LayoutAggiungi.h"

#include <QGridLayout>
#include <QHBoxLayout>
#include <QFormLayout>

/************************* LAYOUT AGGIUNGI PRINCIPALE *************************/
LayoutAggiungi::LayoutAggiungi(QWidget* p):
    parent(p),
    vBox(new QVBoxLayout(this)),
    tipoDevice(new ComboTipoDevice(this)),
    lineModello(new QLineEdit(this)),
    lineSchermo(new QLineEdit(this)),
    linePrezzo(new QLineEdit(this)),
    lineProduttore(new QLineEdit(this)),
    lineProcessore(new QLineEdit(this)),
    memoriaRam(new ComboMemoriaRam(this)),
    memoriaInterna(new ComboMemoriaInterna(this)),
    aggiungiMobile(new LayoutAggiungiMobile(this)),
    aggiungiSmartphone(new LayoutAggiungiSmartphone(this)),
    aggiungiTablet(new LayoutAggiungiTablet(this)),
    aggiungiComputer(new LayoutAggiungiComputer(this)),
    aggiungiPortatile(new LayoutAggiungiPortatile(this)),
    aggiungiFisso(new LayoutAggiungiFisso(this)),
    aggiungiConvertibile(new LayoutAggiungiConvertibile(this)),
    btAggiungi(new QPushButton("AGGIUNGI",this))
{

    QGridLayout* grid = new QGridLayout();
    /***************** riga 0: tipo device, prezzo *************/
    /*
    QStringList devices = {"Scegli Dispositivo","Smartphone (Mobile)",
                            "Tablet (Mobile)","Portatile (Computer)",
                           "Fisso (Computer)","Convertibile (Mobile Coputer)"};
    tipoDevice->addItems(devices);
    // tipoDevice->setEnabled(false);
    */
    grid->addWidget(tipoDevice,0,0);

    linePrezzo->setPlaceholderText("Inserisci prezzo base");
    QFormLayout* formPrezzo = new QFormLayout();
    formPrezzo->addRow("Prezzo:", linePrezzo);
    grid->addLayout(formPrezzo,0,1);

    /***************** riga 1,2: formSx modello, schermo *************/
    lineModello->setPlaceholderText("Inserisci il modello");
    lineSchermo->setPlaceholderText("Inserisci dimensione schermo");

    QFormLayout* formSx = new QFormLayout();
    formSx->addRow("Modello:", lineModello);
    formSx->addRow("Schermo:", lineSchermo);
    formSx->addRow("Ram:",memoriaRam);
    grid->addLayout(formSx,1,0);

    /***************** riga 1,2: formDx produttore, processore *************/

    lineProduttore->setPlaceholderText("Inserisci il produttore");
    lineProcessore->setPlaceholderText("Inserisci processore");

    QFormLayout* formDx = new QFormLayout();
    formDx->addRow("Produttore:", lineProduttore);
    formDx->addRow("Processore:", lineProcessore);
    formDx->addRow("Mem:",memoriaInterna);
    grid->addLayout(formDx,1,1);

    // vBox->addStretch(100);
    vBox->addLayout(grid);

    vBox->addWidget(aggiungiMobile);
    vBox->addWidget(aggiungiComputer);
    vBox->addWidget(aggiungiPortatile);
    vBox->addWidget(aggiungiFisso);
    vBox->addWidget(aggiungiSmartphone);
    vBox->addWidget(aggiungiTablet);
    vBox->addWidget(aggiungiConvertibile);

    aggiungiMobile->hide();
    aggiungiComputer->hide();
    aggiungiPortatile->hide();
    aggiungiFisso->hide();
    aggiungiSmartphone->hide();
    aggiungiTablet->hide();
    aggiungiConvertibile->hide();

    vBox->addWidget(btAggiungi);

    vBox->insertStretch(8,1);

    connect(tipoDevice, SIGNAL(activated(int)), this, SLOT( cambiaAggiungiLayout(int) ) );

    connect(btAggiungi, SIGNAL(clicked()), p, SLOT( aggiungiDevice() ));

   /*
        tipoDevice->setStyleSheet("height: 100%");
        lineModello->setStyleSheet("height: 100%");
        lineProduttore->setStyleSheet("height: 100%");
    */

    // grid->setRowMinimumHeight(0,500);
}

ComboTipoDevice* LayoutAggiungi::getTipoDevice() const { return tipoDevice; }
QLineEdit *LayoutAggiungi::getLineModello() const { return lineModello; }
QLineEdit *LayoutAggiungi::getLineSchermo() const { return lineSchermo; }
QLineEdit *LayoutAggiungi::getLinePrezzo() const { return linePrezzo; }
QLineEdit *LayoutAggiungi::getLineProduttore() const { return lineProduttore; }
QLineEdit *LayoutAggiungi::getLineProcessore() const { return lineProcessore; }
QComboBox* LayoutAggiungi::getMemoriaRam() const { return memoriaRam; }
QComboBox* LayoutAggiungi::getMemoriaInterna() const { return memoriaInterna; }
QCheckBox* LayoutAggiungi::getCheckTouchID() const { return checkTouchID; }
QPushButton* LayoutAggiungi::getBtAggiungi() const { return btAggiungi; }
int LayoutAggiungi::getIntMemoriaRam() const {
    switch (memoriaRam->currentIndex()) {
        case 0: return 2;
        case 1: return 4;
        case 2: return 8;
        case 3: return 16;
        case 4: return 32;
        case 5: return 64;
    default: return -1;
    }
}
int LayoutAggiungi::getIntMemoriaInterna() const {
    switch (memoriaRam->currentIndex()) {
        case 0: return 8;
        case 1: return 16;
        case 2: return 32;
        case 3: return 64;
        case 4: return 128;
        case 5: return 256;
        case 6: return 512;
        case 7: return 1024;
        case 8: return 2048;
        case 9: return 3072;
    default: return -1;
    }
}

void LayoutAggiungi::cambiaAggiungiLayout(int index) const {
    switch(index){
    case 0:
        aggiungiMobile->hide();
        aggiungiSmartphone->hide();
        aggiungiTablet->hide();
        aggiungiComputer->hide();
        aggiungiPortatile->hide();
        aggiungiFisso->hide();
        aggiungiConvertibile->hide();
        break;
    case 1: // smartphone + mobile
        aggiungiMobile->show();
        aggiungiSmartphone->show();
        aggiungiTablet->hide();
        aggiungiComputer->hide();
        aggiungiPortatile->hide();
        aggiungiFisso->hide();
        aggiungiConvertibile->hide();
        break;
    case 2: // tablet + mobile
        aggiungiMobile->show();
        aggiungiSmartphone->hide();
        aggiungiTablet->show();
        aggiungiComputer->hide();
        aggiungiPortatile->hide();
        aggiungiFisso->hide();
        aggiungiConvertibile->hide();
        break;
    case 3: // portatile + computer
        aggiungiMobile->hide();
        aggiungiSmartphone->hide();
        aggiungiTablet->hide();
        aggiungiComputer->show();
        aggiungiPortatile->show();
        aggiungiFisso->hide();
        aggiungiConvertibile->hide();
        aggiungiPortatile->getCheckWebcam()->setEnabled(true);
        aggiungiPortatile->getLinePxWebcam()->setEnabled(false);
        break;
    case 4: // fisso + computer
        aggiungiMobile->hide();
        aggiungiSmartphone->hide();
        aggiungiTablet->hide();
        aggiungiComputer->show();
        aggiungiPortatile->hide();
        aggiungiFisso->show();
        aggiungiConvertibile->hide();
        break;
    case 5: // convertibile + tablet + mobile + portatile + computer
        aggiungiMobile->show();
        aggiungiSmartphone->hide();
        aggiungiTablet->show();
        aggiungiComputer->show();
        aggiungiPortatile->show();
        aggiungiFisso->hide();
        aggiungiConvertibile->show();
        aggiungiPortatile->getCheckWebcam()->setEnabled(false);
        aggiungiPortatile->getLinePxWebcam()->setEnabled(false);
        break;
    }
}

/************************* LAYOUT AGGIUNGI CONVERTIBILE *************************/
LayoutAggiungiConvertibile::LayoutAggiungiConvertibile(QWidget* p) :
    QWidget(p),
    checkPenna(new QCheckBox("Bluetooth",this)),
    checkStaccaTastiera(new QCheckBox("Wifi",this))
{
    QHBoxLayout* hBox = new QHBoxLayout(this);
    hBox->addWidget(checkPenna);
    hBox->addWidget(checkStaccaTastiera);
}

QCheckBox* LayoutAggiungiConvertibile::getCheckPenna() const{ return checkPenna;}
QCheckBox* LayoutAggiungiConvertibile::getCheckStaccaTastiera() const{ return checkStaccaTastiera;}

/************************* LAYOUT AGGIUNGI FISSO *************************/
LayoutAggiungiFisso::LayoutAggiungiFisso(QWidget* p) :
    QWidget(p),
    checkBluetooth(new QCheckBox("Bluetooth",this)),
    checkWifi(new QCheckBox("Wifi",this))
{
    QHBoxLayout* hBox = new QHBoxLayout(this);
    hBox->addWidget(checkBluetooth);
    hBox->addWidget(checkWifi);
}

QCheckBox* LayoutAggiungiFisso::getCheckBluetooth() const{ return checkBluetooth;}
QCheckBox* LayoutAggiungiFisso::getCheckWifi() const{ return checkWifi;}

/************************* LAYOUT AGGIUNGI PORTATILE *************************/
LayoutAggiungiPortatile::LayoutAggiungiPortatile(QWidget* p) :
    QWidget(p),
    grid(new QGridLayout(this)),
    checkEthernet(new QCheckBox("Porta ethernet",this)),
    checkWebcam(new QCheckBox("Webcam",this)),
    checkLuceTastiera(new QCheckBox("Tastiera retroillumata",this)),
    linePxWebcam(new QLineEdit(this))
{
    /********************** riga 0 **********************/
    grid->addWidget(checkEthernet,0,0,1,3);
    grid->addWidget(checkLuceTastiera,0,3,1,3);
    /********************** riga 1 **********************/
    grid->addWidget(checkWebcam,1,0,1,2);
    QFormLayout* formPxWebcam = new QFormLayout();
    linePxWebcam->setPlaceholderText("Inserisci pixel webcam");
    formPxWebcam->addRow("Pixel Webcam:",linePxWebcam);
    grid->addLayout(formPxWebcam,1,3,1,4);

    linePxWebcam->setEnabled(false);
    connect(checkWebcam, SIGNAL(clicked(bool)), this, SLOT(attivaLineWebcam()));
}

void LayoutAggiungiPortatile::attivaLineWebcam() const{
    checkWebcam->isChecked() ? linePxWebcam->setEnabled(true) : linePxWebcam->setEnabled(false);
}

QCheckBox* LayoutAggiungiPortatile::getCheckEthernet() const{ return checkEthernet;}
QCheckBox* LayoutAggiungiPortatile::getCheckWebcam() const{ return checkWebcam;}
QCheckBox* LayoutAggiungiPortatile::getCheckLuceTastiera() const{ return checkLuceTastiera;}
QLineEdit* LayoutAggiungiPortatile::getLinePxWebcam() const { return linePxWebcam; }

/************************* LAYOUT AGGIUNGI SMARTPHONE *************************/
LayoutAggiungiComputer::LayoutAggiungiComputer(QWidget* p) :
    QWidget(p),
    checkTouchscreen(new QCheckBox("TouchScreen",this)),
    checkLettoreCD(new QCheckBox("Lettore CD",this)),
    linePorteUsb(new QLineEdit(this))
{
    QGridLayout* grid = new QGridLayout(this);
    grid->addWidget(checkTouchscreen,0,0,1,1);
    grid->addWidget(checkLettoreCD,0,1,1,1);
    QFormLayout* formPorteUsb = new QFormLayout();
    linePorteUsb->setPlaceholderText("Inserisci numero porte usb");
    formPorteUsb->addRow("Porte USB:",linePorteUsb);
    grid->addLayout(formPorteUsb,0,2,1,2);
}

QCheckBox* LayoutAggiungiComputer::getCheckTouchscreen() const{ return checkTouchscreen;}
QCheckBox* LayoutAggiungiComputer::getCheckLettoreCD() const{ return checkLettoreCD;}
QLineEdit* LayoutAggiungiComputer::getLinePorteUsb() const{ return linePorteUsb;}

/************************* LAYOUT AGGIUNGI SMARTPHONE *************************/
LayoutAggiungiTablet::LayoutAggiungiTablet(QWidget* p) :
    QWidget(p),
    checkSim(new QCheckBox("SIM",this))
{
    QHBoxLayout* hBox = new QHBoxLayout(this);
    hBox->addWidget(checkSim);
}

QCheckBox* LayoutAggiungiTablet::getCheckSim() const{ return checkSim;}

/************************* LAYOUT AGGIUNGI SMARTPHONE *************************/
LayoutAggiungiSmartphone::LayoutAggiungiSmartphone(QWidget* p) :
    QWidget(p),
    checkDualSim(new QCheckBox("Dual SIM",this))
{
    QHBoxLayout* hBox = new QHBoxLayout(this);
    hBox->addWidget(checkDualSim);
}

QCheckBox* LayoutAggiungiSmartphone::getCheckDualSim() const{ return checkDualSim;}

/************************* LAYOUT AGGIUNGI MOBILE *************************/

LayoutAggiungiMobile::LayoutAggiungiMobile (QWidget* p) :
    QWidget(p),
    checkSchedaSD(new QCheckBox("Scheda SD",this)),
    checkJack(new QCheckBox("Jack",this)),
    checkFaceID(new QCheckBox("Face ID", this)),
    linePxFront(new QLineEdit(this)),
    linePxBack(new QLineEdit(this))
{
    QGridLayout* grid = new QGridLayout(this);

    linePxFront->setPlaceholderText("Inserisci px fotocamera frontale");
    QFormLayout* form1 = new QFormLayout();
    form1->addRow("Fotocamera frontale:", linePxFront);
    grid->addLayout(form1,0,0,1,3);

    linePxBack->setPlaceholderText("Inserisci px fotocamera posteriore");
    QFormLayout* form2 = new QFormLayout();
    form2->addRow("Fotocamera posteriore:", linePxBack);
    grid->addLayout(form2,0,3,1,3);

    grid->addWidget(checkSchedaSD,1,0,1,2);
    grid->addWidget(checkJack,1,2,1,2);
    grid->addWidget(checkFaceID,1,4,1,2);

}

QCheckBox* LayoutAggiungiMobile::getCheckSchedaSD() const{ return checkSchedaSD;}
QCheckBox* LayoutAggiungiMobile::getCheckJack() const{ return checkJack;}
QCheckBox* LayoutAggiungiMobile::getCheckFaceID() const{ return checkFaceID;}
QLineEdit* LayoutAggiungiMobile::getLinePxFront() const{ return linePxFront;}
QLineEdit* LayoutAggiungiMobile::getLinePxBack() const{ return linePxBack;}

LayoutAggiungiMobile* LayoutAggiungi::getAggiungiMobile() const { return aggiungiMobile; }
LayoutAggiungiSmartphone* LayoutAggiungi::getAggiungiSmartphone() const { return aggiungiSmartphone; }
LayoutAggiungiTablet* LayoutAggiungi::getAggiungiTablet() const { return aggiungiTablet; }
LayoutAggiungiComputer* LayoutAggiungi::getAggiungiComputer() const { return aggiungiComputer; }
LayoutAggiungiPortatile* LayoutAggiungi::getAggiungiPortatile() const { return aggiungiPortatile; }
LayoutAggiungiFisso* LayoutAggiungi::getAggiungiFisso() const { return aggiungiFisso; }
LayoutAggiungiConvertibile* LayoutAggiungi::getAggiungiConvertibile() const { return aggiungiConvertibile; }
