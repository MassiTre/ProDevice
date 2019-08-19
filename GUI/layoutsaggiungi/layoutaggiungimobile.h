#ifndef LAYOUTAGGIUNGIMOBILE_H
#define LAYOUTAGGIUNGIMOBILE_H

#include <QWidget>
#include <QGridLayout>
#include <QFormLayout>
#include <QCheckBox>
#include <QLineEdit>

class LayoutAggiungiMobile : public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    /*** layout principale (griglia) ***/
    QGridLayout* grid;
    /*** riga 0 ***/
    QFormLayout* formPxFront; // form pixel fotocamera frontale
    QLineEdit* linePxFront; // widegt pixel fotocamera frontale
    QFormLayout* formPxBack; // form pixel fotocamera posteriore
    QLineEdit* linePxBack; // widget pixel fotocamera posteriore
    /*** riga 1 - widget ***/
    QCheckBox* checkSchedaSD;
    QCheckBox* checkJack;
    QCheckBox* checkFaceID;
public:
    LayoutAggiungiMobile(QWidget* = nullptr);

    QCheckBox* getCheckSchedaSD() const;
    QCheckBox* getCheckJack() const;
    QCheckBox* getCheckFaceID() const;
    QLineEdit* getLinePxFront() const;
    QLineEdit* getLinePxBack() const;

    void ripristina() const;
};

#endif // LAYOUTAGGIUNGIMOBILE_H
