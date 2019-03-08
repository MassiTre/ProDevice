#ifndef LAYOUTCERCA_H
#define LAYOUTCERCA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

#include "combotipodevice.h"
#include "combomemoriaram.h"
#include "combomemoriainterna.h"


class LayoutCerca : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* vBox;

    ComboTipoDevice* tipoDevice;
    /***** Device **************/
    QLineEdit* lineModello;
    QLineEdit* lineProduttore;
    /***** Mobile **************/
    QCheckBox* checkSchedaSD;
    /***** Smartphone **********/
    QCheckBox* checkDualSim;
    /***** Tablet **************/
    QCheckBox* checkSim;
    /***** Computer ************/
    QCheckBox* checkTouchscreen;
    /***** Portatile ***********/
    QCheckBox* checkLuceTastiera;

    QPushButton* btCerca;
public:
    LayoutCerca(QWidget* =nullptr);
public slots:
    void attivaCerca(int) const;
};

#endif // LAYOUTCERCA_H
