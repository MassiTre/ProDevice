#include "layoutmodifica.h"

LayoutModifica::LayoutModifica(QWidget* p):
  parent(p),
  vBox(new QVBoxLayout(this)),
  grid(new QGridLayout()),
  labelDevice(new QLabel(QString(""),this,Qt::Widget)),
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
  modificaMobile(new LayoutModificaMobile(this)),
  modificaSmartphone(new LayoutModificaSmartphone(this)),
  modificaTablet(new LayoutModificaTablet(this)),
  modificaComputer(new LayoutModificaComputer(this)),
  modificaPortatile(new LayoutModificaPortatile(this)),
  modificaFisso(new LayoutModificaFisso(this)),
  modificaConvertibile(new LayoutModificaConvertibile(this)),
  lowHBox(new QHBoxLayout()),
  pathImm(""),
  btImmagine(new QPushButton("Cambia immagine",this)),
  btModificaAvanzata(new QPushButton("MODIFICA AVANZATA",this)),
  btConferma(new QPushButton("CONFERMA MODIFICHE",this))
{

    /***************** riga 0: tipo device, prezzo *************/
    grid->addWidget(labelDevice,0,0);

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
    vBox->addWidget(modificaMobile);
    vBox->addWidget(modificaComputer);
    vBox->addWidget(modificaPortatile);
    vBox->addWidget(modificaFisso);
    vBox->addWidget(modificaSmartphone);
    vBox->addWidget(modificaTablet);
    vBox->addWidget(modificaConvertibile);
    /***************** preimposto tutti nascosti *************/
    modificaMobile->hide();
    modificaComputer->hide();
    modificaPortatile->hide();
    modificaFisso->hide();
    modificaSmartphone->hide();
    modificaTablet->hide();
    modificaConvertibile->hide();

    /***************** pulsanti in fondo alla pagina *************/
    btImmagine->setStyleSheet("height:70px;");
    btModificaAvanzata->setStyleSheet("height:30px;");
    btConferma->setStyleSheet("height:30px;");
    vBox->addWidget(btImmagine);
    lowHBox->addWidget(btModificaAvanzata);
    lowHBox->addWidget(btConferma);
    vBox->addLayout(lowHBox);
    vBox->insertStretch(9,1);
    /*** azioni pulsanti ***/
    connect(btImmagine, SIGNAL(clicked()), this, SLOT(selezionaNuovaImm()));
    connect(btModificaAvanzata, SIGNAL(clicked()), this, SLOT( cambiaModificaLayout() ));
    connect(btConferma, SIGNAL(clicked()), p, SLOT( confermaModificaDevice() ));
}

void LayoutModifica::cambiaModificaLayout() const {
    std::string tipo = labelDevice->text().toStdString();

    if(tipo == "SMARTPHONE" || tipo == "TABLET" || tipo == "CONVERTIBILE") { // mobile
        modificaMobile->show();
        if(tipo == "SMARTPHONE") {
            modificaSmartphone->show();
        }
        if(tipo == "TABLET") {
            modificaTablet->show();
        }
    }
    if(tipo == "PORTATILE" || tipo == "FISSO" || tipo == "CONVERTIBILE") { // computer
        modificaComputer->show();
        if(tipo == "PORTATILE") {
            modificaPortatile->show();
        }
        if(tipo == "FISSO") {
            modificaFisso->show();
        }
    }
    if(tipo == "CONVERTIBILE") {// mobile + computer
        modificaConvertibile->show();
    }
}

std::string LayoutModifica::getPathImm() const {
    return pathImm.toStdString();
}

void LayoutModifica::setPathImm(std::string p){
    pathImm = QString::fromStdString(p);
    btImmagine->setIcon(QIcon(pathImm));
}

void LayoutModifica::selezionaNuovaImm(){
    QString nuovaPath = QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/SalvataggioDati" , "File immagini(*.JPG;*.PNG)");
    if(nuovaPath != "") {
        pathImm = nuovaPath;
        btImmagine->setIcon(QIcon(nuovaPath));
    } else {
        btImmagine->setIcon(QIcon(pathImm));
    }
}

QLabel* LayoutModifica::getLabelDevice() const{ return labelDevice; }
QLineEdit* LayoutModifica::getLineModello() const { return lineModello; }
QLineEdit* LayoutModifica::getLineSchermo() const { return lineSchermo; }
QLineEdit* LayoutModifica::getLinePrezzo() const { return linePrezzo; }
QLineEdit* LayoutModifica::getLineProduttore() const { return lineProduttore; }
QLineEdit* LayoutModifica::getLineProcessore() const { return lineProcessore; }
QComboBox* LayoutModifica::getMemoriaRam() const { return memoriaRam; }
QComboBox* LayoutModifica::getMemoriaInterna() const { return memoriaInterna; }

int LayoutModifica::getIntMemoriaRam() const {
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

int LayoutModifica::getIntMemoriaInterna() const {
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

void LayoutModifica::setIndexMemoriaRam(int mr) const {
    if(mr==2){ memoriaRam->setCurrentIndex(0); }
    else if(mr==4){ memoriaRam->setCurrentIndex(1); }
    else if(mr==8){ memoriaRam->setCurrentIndex(2); }
    else if(mr==16){ memoriaRam->setCurrentIndex(3); }
    else if(mr==32){ memoriaRam->setCurrentIndex(4); }
    else if(mr==64){ memoriaRam->setCurrentIndex(5); }
    else { memoriaRam->setCurrentIndex(-1); }
}

void LayoutModifica::setIndexMemoriaInterna(int mi) const {
    if(mi==8){ memoriaRam->setCurrentIndex(0); }
    else if(mi==16){ memoriaRam->setCurrentIndex(1); }
    else if(mi==32){ memoriaRam->setCurrentIndex(2); }
    else if(mi==64){ memoriaRam->setCurrentIndex(3); }
    else if(mi==128){ memoriaRam->setCurrentIndex(4); }
    else if(mi==256){ memoriaRam->setCurrentIndex(5); }
    else if(mi==512){ memoriaRam->setCurrentIndex(6); }
    else if(mi==1024){ memoriaRam->setCurrentIndex(7); }
    else if(mi==2048){ memoriaRam->setCurrentIndex(8); }
    else if(mi==3072){ memoriaRam->setCurrentIndex(9); }
    else { memoriaRam->setCurrentIndex(-1); }
}


LayoutModificaMobile* LayoutModifica::getModificaMobile() const { return modificaMobile; }
LayoutModificaSmartphone* LayoutModifica::getModificaSmartphone() const { return modificaSmartphone; }
LayoutModificaTablet* LayoutModifica::getModificaTablet() const { return modificaTablet; }
LayoutModificaComputer* LayoutModifica::getModificaComputer() const { return modificaComputer; }
LayoutModificaPortatile* LayoutModifica::getModificaPortatile() const { return modificaPortatile; }
LayoutModificaFisso* LayoutModifica::getModificaFisso() const { return modificaFisso; }
LayoutModificaConvertibile* LayoutModifica::getModificaConvertibile() const { return modificaConvertibile; }
