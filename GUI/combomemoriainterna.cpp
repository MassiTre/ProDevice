#include "combomemoriainterna.h"

ComboMemoriaInterna::ComboMemoriaInterna(QWidget* parent) :
    QComboBox(parent)
{
    addItem("8 GB");
    addItem("16 GB");
    addItem("32 GB");
    addItem("64 GB");
    addItem("128 GB");
    addItem("256 GB");
    addItem("512 GB");
    addItem("1 TB");
    addItem("2 TB");
    addItem("3 TB");;
}
