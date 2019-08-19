#include "combotipodevice.h"

ComboTipoDevice::ComboTipoDevice(QWidget* parent) :
    QComboBox(parent)
{
    addItem("Tipo Device");
    addItem("Smartphone (Mobile)");
    addItem("Tablet (Mobile)");
    addItem("Portatile (Computer)");
    addItem("Fisso (Computer)");
    addItem("Convertibile (Mobile Computer)");
}
