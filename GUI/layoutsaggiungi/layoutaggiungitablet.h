#ifndef LAYOUTAGGIUNGITABLET_H
#define LAYOUTAGGIUNGITABLET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QCheckBox>

class LayoutAggiungiTablet : public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    /*** layout principale (orizzontale) ***/
    QHBoxLayout* hBox;
    /*** widget ***/
    QCheckBox* checkSim;
public:
    LayoutAggiungiTablet(QWidget* = nullptr);

    QCheckBox* getCheckSim() const;

    void ripristina() const;
};

#endif // LAYOUTAGGIUNGITABLET_H
