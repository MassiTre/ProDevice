#ifndef LAYOUTMODIFICAFISSO_H
#define LAYOUTMODIFICAFISSO_H

#include <QCheckBox>
#include <QHBoxLayout>

class LayoutModificaFisso: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    /*** layout principale (orizzontale) ***/
    QHBoxLayout* hBox;
    /*** widget ***/
    QCheckBox* checkBluetooth;
    QCheckBox* checkWifi;
public:
    LayoutModificaFisso(QWidget* = nullptr);

    QCheckBox* getCheckBluetooth() const;
    QCheckBox* getCheckWifi() const;

};

#endif // LAYOUTMODIFICAFISSO_H
