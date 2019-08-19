#ifndef LAYOUTMODIFICATABLET_H
#define LAYOUTMODIFICATABLET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QCheckBox>

class LayoutModificaTablet : public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    /*** layout principale (orizzontale) ***/
    QHBoxLayout* hBox;
    /*** widget ***/
    QCheckBox* checkSim;
public:
    LayoutModificaTablet(QWidget* = nullptr);

    QCheckBox* getCheckSim() const;
};

#endif // LAYOUTMODIFICATABLET_H
