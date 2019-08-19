#include "layoutmodificafisso.h"

LayoutModificaFisso::LayoutModificaFisso(QWidget* p) :
    parent(p),
    hBox(new QHBoxLayout(this)),
    checkBluetooth(new QCheckBox("Bluetooth",this)),
    checkWifi(new QCheckBox("Wifi",this))
{
    hBox->addWidget(checkBluetooth);
    hBox->addWidget(checkWifi);
}

QCheckBox* LayoutModificaFisso::getCheckBluetooth() const{ return checkBluetooth;}
QCheckBox* LayoutModificaFisso::getCheckWifi() const{ return checkWifi;}
