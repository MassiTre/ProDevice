#include "layoutmodificamobile.h"

LayoutModificaMobile::LayoutModificaMobile (QWidget* p) :
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

QCheckBox* LayoutModificaMobile::getCheckSchedaSD() const{ return checkSchedaSD;}
QCheckBox* LayoutModificaMobile::getCheckJack() const{ return checkJack;}
QCheckBox* LayoutModificaMobile::getCheckFaceID() const{ return checkFaceID;}
QLineEdit* LayoutModificaMobile::getLinePxFront() const{ return linePxFront;}
QLineEdit* LayoutModificaMobile::getLinePxBack() const{ return linePxBack;}
