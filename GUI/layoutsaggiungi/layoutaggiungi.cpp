#include "layoutaggiungi.h"

/************************* LAYOUT AGGIUNGI PRINCIPALE *************************/
LayoutAggiungi::LayoutAggiungi(QWidget* p):
    parent(p),
    vBox(new QVBoxLayout(this)),
    grid(new QGridLayout()),
    tipoDevice(new ComboTipoDevice(this)),
    formPrezzo(new QFormLayout()),
    linePrezzo(new QLineEdit(this)),
    formSx(new QFormLayout()),
    lineModello(new QLineEdit(this)),
    lineSchermo(new QLineEdit(this)),
    memoriaRam(new ComboMemoriaRam(this)),
    formDx(new QFormLayout()),
    lineProduttore(new QLineEdit(this)),
    lineProcessore(new QLineEdit(this)),
    memoriaInterna(new ComboMemoriaInterna(this)),
    aggiungiMobile(new LayoutAggiungiMobile(this)),
    aggiungiSmartphone(new LayoutAggiungiSmartphone(this)),
    aggiungiTablet(new LayoutAggiungiTablet(this)),
    aggiungiComputer(new LayoutAggiungiComputer(this)),
    aggiungiPortatile(new LayoutAggiungiPortatile(this)),
    aggiungiFisso(new LayoutAggiungiFisso(this)),
    aggiungiConvertibile(new LayoutAggiungiConvertibile(this)),
    lowHBox(new QHBoxLayout()),
    pathImm(""),
    btImmagine(new QPushButton("Inserisci immagine")),
    btAggiungi(new QPushButton("AGGIUNGI",this))
{

    /***************** riga 0: tipo device, prezzo *************/
    grid->addWidget(tipoDevice,0,0);

    linePrezzo->setPlaceholderText("Inserisci prezzo base");
    formPrezzo->addRow("Prezzo:", linePrezzo);
    grid->addLayout(formPrezzo,0,1);

    /***************** riga 1,2: formSx modello, schermo *************/
    lineModello->setPlaceholderText("Inserisci il modello");
    lineSchermo->setPlaceholderText("Inserisci dimensione schermo");

    formSx->addRow("Modello:", lineModello);
    formSx->addRow("Schermo:", lineSchermo);
    formSx->addRow("Ram:",memoriaRam);
    grid->addLayout(formSx,1,0);

    /***************** riga 1,2: formDx produttore, processore *************/

    lineProduttore->setPlaceholderText("Inserisci il produttore");
    lineProcessore->setPlaceholderText("Inserisci processore");

    formDx->addRow("Produttore:", lineProduttore);
    formDx->addRow("Processore:", lineProcessore);
    formDx->addRow("Mem:",memoriaInterna);
    grid->addLayout(formDx,1,1);

    // vBox->addStretch(100);
    vBox->addLayout(grid);

    /***************** riga 3+: altri layout *************/
    vBox->addWidget(aggiungiMobile);
    vBox->addWidget(aggiungiComputer);
    vBox->addWidget(aggiungiPortatile);
    vBox->addWidget(aggiungiFisso);
    vBox->addWidget(aggiungiSmartphone);
    vBox->addWidget(aggiungiTablet);
    vBox->addWidget(aggiungiConvertibile);
    /***************** preimposto tutti nascosti *************/
    aggiungiMobile->hide();
    aggiungiComputer->hide();
    aggiungiPortatile->hide();
    aggiungiFisso->hide();
    aggiungiSmartphone->hide();
    aggiungiTablet->hide();
    aggiungiConvertibile->hide();

    /***************** pulsanti in fondo alla pagina *************/
    btImmagine->setStyleSheet("height:70px;");
    btAggiungi->setStyleSheet("height:70px;");
    lowHBox->addWidget(btImmagine);
    lowHBox->addWidget(btAggiungi);
    vBox->addLayout(lowHBox);
    vBox->insertStretch(8,1);

    /*** azioni pulsanti ***/
    connect(tipoDevice, SIGNAL(activated(int)), this, SLOT( cambiaAggiungiLayout(int) ) );
    connect(btImmagine, SIGNAL(clicked()), this, SLOT(selezioneImmagine()));
    connect(btAggiungi, SIGNAL(clicked()), p, SLOT( aggiungiDevice() ));
}

ComboTipoDevice* LayoutAggiungi::getTipoDevice() const { return tipoDevice; }
QLineEdit* LayoutAggiungi::getLineModello() const { return lineModello; }
QLineEdit* LayoutAggiungi::getLineSchermo() const { return lineSchermo; }
QLineEdit* LayoutAggiungi::getLinePrezzo() const { return linePrezzo; }
QLineEdit* LayoutAggiungi::getLineProduttore() const { return lineProduttore; }
QLineEdit* LayoutAggiungi::getLineProcessore() const { return lineProcessore; }
QComboBox* LayoutAggiungi::getMemoriaRam() const { return memoriaRam; }
QComboBox* LayoutAggiungi::getMemoriaInterna() const { return memoriaInterna; }

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

void LayoutAggiungi::selezioneImmagine() {
    pathImm = QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/Dati Dispositivi" , "File JPG/PNG (*.JPG, *PNG)");
    if(pathImm!=""){
        btImmagine->setText("Cambia");
        btImmagine->setIcon(QIcon(pathImm));
        btImmagine->setIconSize(QSize(60,60));
    } else {
        btImmagine->setText("Inserisci immagine");
        btImmagine->setIcon(QIcon());
    }
}

QString LayoutAggiungi::getPathImm() const {
    return pathImm;
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

void LayoutAggiungi::ripristinaTutto() const {
    linePrezzo->clear();
    lineModello->clear();
    lineSchermo->clear();
    memoriaRam->setCurrentIndex(0);
    lineProduttore->clear();
    lineProcessore->clear();
    memoriaInterna->setCurrentIndex(0);

    aggiungiMobile->ripristina();
    aggiungiSmartphone->ripristina();
    aggiungiTablet->ripristina();
    aggiungiComputer->ripristina();
    aggiungiPortatile->ripristina();
    aggiungiFisso->ripristina();
    aggiungiConvertibile->ripristina();

    btImmagine->setIcon(QIcon());;
}

LayoutAggiungiMobile* LayoutAggiungi::getAggiungiMobile() const { return aggiungiMobile; }
LayoutAggiungiSmartphone* LayoutAggiungi::getAggiungiSmartphone() const { return aggiungiSmartphone; }
LayoutAggiungiTablet* LayoutAggiungi::getAggiungiTablet() const { return aggiungiTablet; }
LayoutAggiungiComputer* LayoutAggiungi::getAggiungiComputer() const { return aggiungiComputer; }
LayoutAggiungiPortatile* LayoutAggiungi::getAggiungiPortatile() const { return aggiungiPortatile; }
LayoutAggiungiFisso* LayoutAggiungi::getAggiungiFisso() const { return aggiungiFisso; }
LayoutAggiungiConvertibile* LayoutAggiungi::getAggiungiConvertibile() const { return aggiungiConvertibile; }
