#ifndef DEVICEWIDGETLISTA_H
#define DEVICEWIDGETLISTA_H

#include "../../Gerarchia/device.h"
#include "deviceelementolista.h"
#include <QListWidget>
#include <QScrollBar>

class DeviceWidgetLista : public QListWidget{
    Q_OBJECT
private:
    QWidget* parent;
public:
    DeviceWidgetLista(QWidget* =nullptr);
    void aggiungiDevice(Device*);
    DeviceElementoLista* elementoCorrente() const;
};

#endif // DEVICEWIDGETLISTA_H
