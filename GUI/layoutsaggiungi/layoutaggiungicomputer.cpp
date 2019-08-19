#include "layoutaggiungicomputer.h"
/************************* LAYOUT AGGIUNGI SMARTPHONE *************************/
LayoutAggiungiComputer::LayoutAggiungiComputer(QWidget* p) :
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

QCheckBox* LayoutAggiungiComputer::getCheckTouchscreen() const{ return checkTouchscreen;}
QCheckBox* LayoutAggiungiComputer::getCheckLettoreCD() const{ return checkLettoreCD;}
QLineEdit* LayoutAggiungiComputer::getLinePorteUsb() const{ return linePorteUsb;}

void LayoutAggiungiComputer::ripristina() const {
    checkTouchscreen->setChecked(false);
    checkLettoreCD->setChecked(false);
    linePorteUsb->clear();
}
