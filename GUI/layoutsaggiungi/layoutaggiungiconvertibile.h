#ifndef LAYOUTAGGIUNGICONVERTIBILE_H
#define LAYOUTAGGIUNGICONVERTIBILE_H

#include <QWidget>
#include <QCheckBox>
#include <QHBoxLayout>

class LayoutAggiungiConvertibile : public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    /*** layout principale (orizzontale) ***/
    QHBoxLayout* hBox;
    /*** widget ***/
    QCheckBox* checkPenna;
    QCheckBox* checkStaccaTastiera;
public:
    LayoutAggiungiConvertibile(QWidget* = nullptr);

    QCheckBox* getCheckPenna() const;
    QCheckBox* getCheckStaccaTastiera() const;

    void ripristina() const;
};


#endif // LAYOUTAGGIUNGICONVERTIBILE_H
