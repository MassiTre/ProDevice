#include "layoutaggiungiportatile.h"

LayoutAggiungiPortatile::LayoutAggiungiPortatile(QWidget* p) :
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

void LayoutAggiungiPortatile::ripristina() const {
    checkEthernet->setChecked(false);
    checkWebcam->setChecked(false);
    checkLuceTastiera->setChecked(false);
    linePxWebcam->setEnabled(false);
}
