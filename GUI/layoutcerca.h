#ifndef LAYOUTCERCA_H
#define LAYOUTCERCA_H

#include "comboboxes/combotipodevice.h"
#include "comboboxes/combomemoriaram.h"
#include "comboboxes/combomemoriainterna.h"
#include "listdevice/devicewidgetlista.h"
#include "layoutcatalogo.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>


class LayoutCerca : public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    /*** layout principale (verticale) ***/
    QVBoxLayout* vBox;

    QGridLayout* grid; // layout a griglia per campi di ricerca
    ComboTipoDevice* tipoDevice; // Device
    QFormLayout* formModello;
    QLineEdit* lineModello; // Device
    QFormLayout* formProduttore;
    QLineEdit* lineProduttore; // Device
    QCheckBox* checkSchedaSD; // Mobile
    QCheckBox* checkDualSim; // Smartphone
    QCheckBox* checkSim; // Tablet
    QCheckBox* checkTouchscreen; // Computer
    QCheckBox* checkLuceTastiera; // Portatile

    /*** widget risultato e prezzi ***/
    DeviceWidgetLista* risultato;
    QGridLayout* layoutPrezzi; // layout a griglia per i prezzi
    QLabel* baseTitolo;
    QLabel* baseNumero; // getPrezzo()
    QLabel* totaleTitolo;
    QLabel* totaleNumero; // calcolaPrezzo()

    QPushButton* btCerca;
public:
    LayoutCerca(QWidget* =nullptr);

    ComboTipoDevice* getTipoDevice() const;
    // Device
    QLineEdit *getLineModello() const;
    QLineEdit *getLineProduttore() const;
    // Mobile
    QCheckBox* getCheckSchedaSD() const;
        // Tablet
    QCheckBox* getCheckSim() const;
        // Smartphone
    QCheckBox* getCheckDualSim() const;
    // Computer
        // Fisso
    QCheckBox* getCheckTouchscreen() const;
        // Portatile
    QCheckBox* getCheckLuceTastiera() const;
    // Convertibile

    /********** gestione risultato *******/
    void svuotaRisultato();
    DeviceWidgetLista* getRisultato();
    void setPrezzoBase(const QString);
    void setPrezzoTotale(const QString);

public slots:
    void attivaCerca(int) const;
};

#endif // LAYOUTCERCA_H
