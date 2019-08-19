#include "layoutmodificaconvertibile.h"

LayoutModificaConvertibile::LayoutModificaConvertibile(QWidget* p) :
    parent(p),
    hBox(new QHBoxLayout(this)),
    checkPenna(new QCheckBox("Penna",this)),
    checkStaccaTastiera(new QCheckBox("Tastiera rimuovibile",this))
{
    hBox->addWidget(checkPenna);
    hBox->addWidget(checkStaccaTastiera);
}

QCheckBox* LayoutModificaConvertibile::getCheckPenna() const{ return checkPenna;}
QCheckBox* LayoutModificaConvertibile::getCheckStaccaTastiera() const{ return checkStaccaTastiera;}

