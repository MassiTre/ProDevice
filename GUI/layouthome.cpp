#include "layouthome.h"

LayoutHome::LayoutHome(QWidget* p) :
    parent(p),
    vBox(new QVBoxLayout(this)),
    hBox(new QHBoxLayout()),
    btAggiungi(new QPushButton(this)),
    btCerca(new QPushButton(this)),
    btCatalogo(new QPushButton(this)),
    btCarica(new QPushButton("CARICA (file xml)",this))
{
    hBox->addWidget(btAggiungi);
    hBox->addWidget(btCerca);
    hBox->addWidget(btCatalogo);

    btAggiungi->setIcon(QIcon( QString(":/imm/Immagini/aggiungi-icon.png") ));
    btCerca->setIcon(QIcon( QString(":/imm/Immagini/cerca-icon.png") ));
    btCatalogo->setIcon(QIcon( QString(":/imm/Immagini/catalogo-icon.png") ));
    btCarica->setIcon(QIcon( QString(":/imm/Immagini/carica-icon.png") ));
    btAggiungi->setIconSize(QSize(400,400));
    btCerca->setIconSize(QSize(400,400));
    btCatalogo->setIconSize(QSize(400,400));
    btCarica->setIconSize(QSize(50,50));

    btAggiungi->setStyleSheet("height: 500px; width: 333px;");
    btCerca->setStyleSheet("height: 500px; width: 333px;");
    btCatalogo->setStyleSheet("height: 500px; width: 333px;");

    vBox->addLayout(hBox);

    btCarica->setStyleSheet("height: 50px;");

    vBox->addWidget(btCarica);

    connect(btAggiungi, SIGNAL(clicked()), parent, SLOT( esciLayoutAggiungi() ));
    connect(btCerca, SIGNAL(clicked()), parent, SLOT( esciLayoutCerca() ));
    connect(btCatalogo, SIGNAL(clicked()), parent, SLOT( esciLayoutCatalogo() ));

    connect(btCarica, SIGNAL(clicked()), parent, SLOT(caricaXML()) );
}
