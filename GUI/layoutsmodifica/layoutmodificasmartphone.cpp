#include "layoutmodificasmartphone.h"

LayoutModificaSmartphone::LayoutModificaSmartphone(QWidget* p) :
    parent(p),
    hBox(new QHBoxLayout(this)),
    checkDualSim(new QCheckBox("Dual SIM",this))
{
    hBox->addWidget(checkDualSim);
}

QCheckBox* LayoutModificaSmartphone::getCheckDualSim() const{ return checkDualSim;}
