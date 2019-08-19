#include "layoutmodificatablet.h"

LayoutModificaTablet::LayoutModificaTablet(QWidget* p) :
    parent(p),
    hBox(new QHBoxLayout(this)),
    checkSim(new QCheckBox("SIM",this))
{
    hBox->addWidget(checkSim);
}

QCheckBox* LayoutModificaTablet::getCheckSim() const{ return checkSim;}
