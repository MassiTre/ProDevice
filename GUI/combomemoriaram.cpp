#include "combomemoriaram.h"

ComboMemoriaRam::ComboMemoriaRam(QWidget* parent) :
    QComboBox(parent)
{
    addItem("2 GB");
    addItem("4 GB");
    addItem("8 GB");
    addItem("16 GB");
    addItem("32 GB");
    addItem("64 GB");
}
