#include "layoutaggiungimobile.h"

LayoutAggiungiMobile::LayoutAggiungiMobile (QWidget* p) :
    parent(p),
    grid(new QGridLayout(this)),
    formPxFront(new QFormLayout()),
    linePxFront(new QLineEdit(this)),
    formPxBack(new QFormLayout()),
    linePxBack(new QLineEdit(this)),
    checkSchedaSD(new QCheckBox("Scheda SD",this)),
    checkJack(new QCheckBox("Jack",this)),
    checkFaceID(new QCheckBox("Face ID", this))
{
    linePxFront->setPlaceholderText("Inserisci px fotocamera frontale");
    formPxFront->addRow("Fotocamera frontale:", linePxFront);
    grid->addLayout(formPxFront,0,0,1,3);

    linePxBack->setPlaceholderText("Inserisci px fotocamera posteriore");
    formPxBack->addRow("Fotocamera posteriore:", linePxBack);
    grid->addLayout(formPxBack,0,3,1,3);

    grid->addWidget(checkSchedaSD,1,0,1,2);
    grid->addWidget(checkJack,1,2,1,2);
    grid->addWidget(checkFaceID,1,4,1,2);
}

QCheckBox* LayoutAggiungiMobile::getCheckSchedaSD() const{ return checkSchedaSD;}
QCheckBox* LayoutAggiungiMobile::getCheckJack() const{ return checkJack;}
QCheckBox* LayoutAggiungiMobile::getCheckFaceID() const{ return checkFaceID;}
QLineEdit* LayoutAggiungiMobile::getLinePxFront() const{ return linePxFront;}
QLineEdit* LayoutAggiungiMobile::getLinePxBack() const{ return linePxBack;}

void LayoutAggiungiMobile::ripristina() const {
    linePxFront->clear();
    linePxBack->clear();
    checkSchedaSD->setChecked(false);
    checkJack->setChecked(false);
    checkFaceID->setChecked(false);
}
