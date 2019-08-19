#include "layoutaggiungiconvertibile.h"

LayoutAggiungiConvertibile::LayoutAggiungiConvertibile(QWidget* p) :
    parent(p),
    hBox(new QHBoxLayout(this)),
    checkPenna(new QCheckBox("Penna",this)),
    checkStaccaTastiera(new QCheckBox("Tastiera rimuovibile",this))
{
    hBox->addWidget(checkPenna);
    hBox->addWidget(checkStaccaTastiera);
}

QCheckBox* LayoutAggiungiConvertibile::getCheckPenna() const{ return checkPenna;}
QCheckBox* LayoutAggiungiConvertibile::getCheckStaccaTastiera() const{ return checkStaccaTastiera;}

void LayoutAggiungiConvertibile::ripristina() const {
    checkPenna->setChecked(false);
    checkStaccaTastiera->setChecked(false);
}
