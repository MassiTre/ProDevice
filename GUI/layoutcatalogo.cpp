#include "layoutcatalogo.h"

LayoutCatalogo::LayoutCatalogo(QWidget* p) :
    QWidget(p),
    vBox(new QVBoxLayout(this)),
    lista(new DeviceWidgetLista(this)),
    hBts(new QHBoxLayout()),
    btModifica(new QPushButton("MODIFICA",this)),
    btElimina(new QPushButton("ELIMINA",this))
{
    vBox->addWidget(lista);
    lista->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    lista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    hBts->addWidget(btModifica);
    hBts->addWidget(btElimina);
    vBox->addLayout(hBts);

    connect(btModifica, SIGNAL(clicked()), p, SLOT( visualizzaModificaDevice() ));
    connect(btElimina, SIGNAL(clicked()), p, SLOT( eliminaDevice() ));

}

DeviceWidgetLista* LayoutCatalogo::getLista() const{ return lista; }
