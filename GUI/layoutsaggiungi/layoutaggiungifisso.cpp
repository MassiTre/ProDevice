#include "layoutaggiungifisso.h"

LayoutAggiungiFisso::LayoutAggiungiFisso(QWidget* p) :
    parent(p),
    hBox(new QHBoxLayout(this)),
    checkBluetooth(new QCheckBox("Bluetooth",this)),
    checkWifi(new QCheckBox("Wifi",this))
{
    hBox->addWidget(checkBluetooth);
    hBox->addWidget(checkWifi);
}

QCheckBox* LayoutAggiungiFisso::getCheckBluetooth() const{ return checkBluetooth;}
QCheckBox* LayoutAggiungiFisso::getCheckWifi() const{ return checkWifi;}

void LayoutAggiungiFisso::ripristina() const {
    checkBluetooth->setChecked(false);
    checkWifi->setChecked(false);
}
