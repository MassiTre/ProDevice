#ifndef LAYOUTMODIFICASMARTPHONE_H
#define LAYOUTMODIFICASMARTPHONE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QCheckBox>

class LayoutModificaSmartphone : public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    /*** layout principale (orizzontale) ***/
    QHBoxLayout* hBox;
    /*** widget ***/
    QCheckBox* checkDualSim;
public:
    LayoutModificaSmartphone(QWidget* = nullptr);

    QCheckBox* getCheckDualSim() const;
};

#endif // LAYOUTMODIFICASMARTPHONE_H
