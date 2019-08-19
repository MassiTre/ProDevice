#include "layoutaggiungitablet.h"

LayoutAggiungiTablet::LayoutAggiungiTablet(QWidget* p) :
    parent(p),
    hBox(new QHBoxLayout(this)),
    checkSim(new QCheckBox("SIM",this))
{
    hBox->addWidget(checkSim);
}

QCheckBox* LayoutAggiungiTablet::getCheckSim() const{ return checkSim;}

void LayoutAggiungiTablet::ripristina() const{
    checkSim->setChecked(false);
}
