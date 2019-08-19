#ifndef LAYOUTMODIFICACOMPUTER_H
#define LAYOUTMODIFICACOMPUTER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QCheckBox>
#include <QLineEdit>

class LayoutModificaComputer : public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    /*** layout principale (griglia) ***/
    QGridLayout* grid;
    /*** widget ***/
    QCheckBox* checkTouchscreen;
    QCheckBox* checkLettoreCD;
    QFormLayout* formPorteUsb; // layout n° porte usb
    QLineEdit* linePorteUsb; // widget n° porte usb
public:
    LayoutModificaComputer(QWidget* = nullptr);

    QCheckBox* getCheckTouchscreen() const;
    QCheckBox* getCheckLettoreCD() const;
    QLineEdit* getLinePorteUsb() const;
};

#endif // LAYOUTMODIFICACOMPUTER_H
