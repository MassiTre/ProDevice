#ifndef LAYOUTMODIFICACONVERTIBILE_H
#define LAYOUTMODIFICACONVERTIBILE_H

#include <QWidget>
#include <QCheckBox>
#include <QHBoxLayout>

class LayoutModificaConvertibile: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    /*** layout principale (orizzontale) ***/
    QHBoxLayout* hBox;
    /*** widget ***/
    QCheckBox* checkPenna;
    QCheckBox* checkStaccaTastiera;
public:
    LayoutModificaConvertibile(QWidget* = nullptr);

    QCheckBox* getCheckPenna() const;
    QCheckBox* getCheckStaccaTastiera() const;
};

#endif // LAYOUTMODIFICACONVERTIBILE_H
