#ifndef LAYOUTAGGIUNGIFISSO_H
#define LAYOUTAGGIUNGIFISSO_H

#include <QCheckBox>
#include <QHBoxLayout>

class LayoutAggiungiFisso : public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    /*** layout principale (orizzontale) ***/
    QHBoxLayout* hBox;
    /*** widget ***/
    QCheckBox* checkBluetooth;
    QCheckBox* checkWifi;
public:
    LayoutAggiungiFisso(QWidget* = nullptr);

    QCheckBox* getCheckBluetooth() const;
    QCheckBox* getCheckWifi() const;

    void ripristina() const;
};


#endif // LAYOUTAGGIUNGIFISSO_H
