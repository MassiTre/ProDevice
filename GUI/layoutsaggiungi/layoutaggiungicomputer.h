#ifndef LAYOUTAGGIUNGICOMPUTER_H
#define LAYOUTAGGIUNGICOMPUTER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QCheckBox>
#include <QLineEdit>

class LayoutAggiungiComputer : public QWidget {
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
    LayoutAggiungiComputer(QWidget* = nullptr);

    QCheckBox* getCheckTouchscreen() const;
    QCheckBox* getCheckLettoreCD() const;
    QLineEdit* getLinePorteUsb() const;

    void ripristina() const;
};

#endif // LAYOUTAGGIUNGICOMPUTER_H
