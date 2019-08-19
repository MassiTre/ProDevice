#include "devicewidgetlista.h"

DeviceWidgetLista::DeviceWidgetLista(QWidget* p): parent(p) {

    setIconSize(QSize(150,150));
    addScrollBarWidget(new QScrollBar(Qt::Orientation::Vertical,parent), Qt::AlignRight);

}

void DeviceWidgetLista::aggiungiDevice(Device* d) {

    DeviceElementoLista* nuovoDevice = new DeviceElementoLista(parent, d);

    addItem(nuovoDevice);
}

DeviceElementoLista* DeviceWidgetLista::elementoCorrente() const {
    return static_cast<DeviceElementoLista*>(QListWidget::currentItem());
}
