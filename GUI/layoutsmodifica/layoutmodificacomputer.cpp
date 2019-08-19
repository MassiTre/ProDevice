#include "layoutmodificacomputer.h"

LayoutModificaComputer::LayoutModificaComputer(QWidget* p) :
    parent(p),
    grid(new QGridLayout(this)),
    checkTouchscreen(new QCheckBox("TouchScreen",this)),
    checkLettoreCD(new QCheckBox("Lettore CD",this)),
    formPorteUsb(new QFormLayout()),
    linePorteUsb(new QLineEdit(this))
{
    grid->addWidget(checkTouchscreen,0,0,1,1);
    grid->addWidget(checkLettoreCD,0,1,1,1);

    linePorteUsb->setPlaceholderText("Inserisci numero porte usb");
    formPorteUsb->addRow("Porte USB:",linePorteUsb);
    grid->addLayout(formPorteUsb,0,2,1,2);
}

QCheckBox* LayoutModificaComputer::getCheckTouchscreen() const{ return checkTouchscreen;}
QCheckBox* LayoutModificaComputer::getCheckLettoreCD() const{ return checkLettoreCD;}
QLineEdit* LayoutModificaComputer::getLinePorteUsb() const{ return linePorteUsb;}

