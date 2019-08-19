#ifndef DEVICEELEMENTOLISTA_H
#define DEVICEELEMENTOLISTA_H

#include "../../Gerarchia/device.h"

#include <QListWidgetItem>

class DeviceElementoLista : public QListWidgetItem {
private:
    QWidget* parent;
    Device* oggetto;
public:
    DeviceElementoLista(QWidget* = nullptr, Device* = nullptr);
    Device* oggettoCorrente() const;
    void aggiornaOggetto();
};

#endif // DEVICEELEMENTOLISTA_H
