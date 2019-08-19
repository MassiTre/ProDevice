#ifndef LAYOUTAGGIUNGISMARTPHONE_H
#define LAYOUTAGGIUNGISMARTPHONE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QCheckBox>

class LayoutAggiungiSmartphone : public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    /*** layout principale (orizzontale) ***/
    QHBoxLayout* hBox;
    /*** widget ***/
    QCheckBox* checkDualSim;
public:
    LayoutAggiungiSmartphone(QWidget* = nullptr);

    QCheckBox* getCheckDualSim() const;

    void ripristina() const;
};

#endif // LAYOUTAGGIUNGISMARTPHONE_H
