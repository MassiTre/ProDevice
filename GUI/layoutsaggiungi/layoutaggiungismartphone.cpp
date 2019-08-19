#include "layoutaggiungismartphone.h"

LayoutAggiungiSmartphone::LayoutAggiungiSmartphone(QWidget* p) :
    parent(p),
    hBox(new QHBoxLayout(this)),
    checkDualSim(new QCheckBox("Dual SIM",this))
{
    hBox->addWidget(checkDualSim);
}

QCheckBox* LayoutAggiungiSmartphone::getCheckDualSim() const{ return checkDualSim;}

void LayoutAggiungiSmartphone::ripristina() const{
    checkDualSim->setChecked(false);
}
