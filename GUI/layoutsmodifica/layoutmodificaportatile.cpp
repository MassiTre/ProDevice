#include "layoutmodificaportatile.h"

LayoutModificaPortatile::LayoutModificaPortatile(QWidget* p) :
    parent(p),
    grid(new QGridLayout(this)),
    checkEthernet(new QCheckBox("Porta ethernet",this)),
    checkWebcam(new QCheckBox("Webcam",this)),
    checkLuceTastiera(new QCheckBox("Tastiera retroillumata",this)),
    formPxWebcam(new QFormLayout()),
    linePxWebcam(new QLineEdit(this))
{
    /********************** riga 0 **********************/
    grid->addWidget(checkEthernet,0,0,1,3);
    grid->addWidget(checkLuceTastiera,0,3,1,3);
    /********************** riga 1 **********************/
    grid->addWidget(checkWebcam,1,0,1,2);

    linePxWebcam->setPlaceholderText("Inserisci pixel webcam");
    formPxWebcam->addRow("Pixel Webcam:",linePxWebcam);
    grid->addLayout(formPxWebcam,1,3,1,4);

    connect(checkWebcam, SIGNAL(clicked(bool)), this, SLOT(attivaLineWebcam()));
}

void LayoutModificaPortatile::attivaLineWebcam() const{
    checkWebcam->isChecked() ? linePxWebcam->setEnabled(true) : linePxWebcam->setEnabled(false);
}

QCheckBox* LayoutModificaPortatile::getCheckEthernet() const{ return checkEthernet;}
QCheckBox* LayoutModificaPortatile::getCheckWebcam() const{ return checkWebcam;}
QCheckBox* LayoutModificaPortatile::getCheckLuceTastiera() const{ return checkLuceTastiera;}
QLineEdit* LayoutModificaPortatile::getLinePxWebcam() const { return linePxWebcam; }
