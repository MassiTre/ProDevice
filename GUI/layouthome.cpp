#include "layouthome.h"
// QIcon LayoutHome::iconAggiungi = QIcon( QString("../ProDevice/Immagini/add-button.png"));
#include <iostream>
#include <QDir>

LayoutHome::LayoutHome(QWidget* p) :
    parent(p),
    // iconAggiungi(QIcon( QString(":/Immagini/add-button.png") ) ),
    // btAggiungi(new QToolButton(this)),
    btAggiungi(new QPushButton(this)),
    btCerca(new QPushButton(this)),
    btCatalogo(new QPushButton(this)),
    btCarica(new QPushButton("CARICA",this)),
    btSalva(new QPushButton("SALVA",this))
{
    QVBoxLayout* vBox = new QVBoxLayout(this);

    QHBoxLayout* hBox1 = new QHBoxLayout();

    hBox1->addWidget(btAggiungi);
    hBox1->addWidget(btCerca);
    hBox1->addWidget(btCatalogo);

    // btAggiungi->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // btAggiungi->setIcon(QIcon( QString(":/imm/Immagini/add-icon.png") ));
    // QString s = QDir::currentPath();
    // std::cout << "PORCO DIO" << std::endl;
    // std::cout << s.toStdString() << std::endl;
    // btAggiungi->setIconSize(QSize(200,200));
    // btAggiungi->setText("AGGIUNGI");
    /****** PUSH BUTTON *******/
    // btAggiungi->setStyleSheet( "background-image: url(':/imm/Immagini/add-button.png'); width: 200px; height: 200px;" );
    // btAggiungi->setIconSize(QSize(200,200));
    // btAggiungi->setFlat(true);
    // btAggiungi->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    btAggiungi->setIcon(QIcon( QString(":/imm/Immagini/aggiungi-icon.png") ));
    btCerca->setIcon(QIcon( QString(":/imm/Immagini/cerca-icon.png") ));
    btCatalogo->setIcon(QIcon( QString(":/imm/Immagini/catalogo-icon.png") ));
    btCarica->setIcon(QIcon( QString(":/imm/Immagini/carica-icon.png") ));
    btSalva->setIcon(QIcon( QString(":/imm/Immagini/salva-icon.png") ));
    btAggiungi->setIconSize(QSize(200,200));
    btCerca->setIconSize(QSize(200,200));
    btCatalogo->setIconSize(QSize(200,200));
    btCarica->setIconSize(QSize(50,50));
    btSalva->setIconSize(QSize(50,50));

    btAggiungi->setStyleSheet("height: 500px; width: 333px;");
    btCerca->setStyleSheet("height: 500px; width: 333px;");
    btCatalogo->setStyleSheet("height: 500px; width: 333px;");

    vBox->addLayout(hBox1);

    QHBoxLayout* hBox2 = new QHBoxLayout();

    hBox2->addWidget(btCarica);
    hBox2->addWidget(btSalva);

    btCarica->setStyleSheet("height: 50px;");
    btSalva->setStyleSheet("height: 50px;");

    vBox->addLayout(hBox2);

    connect(btAggiungi, SIGNAL(clicked()), parent, SLOT( esciLayoutAggiungi() ));
    connect(btCerca, SIGNAL(clicked()), parent, SLOT( esciLayoutCerca() ));
    connect(btCatalogo, SIGNAL(clicked()), parent, SLOT( esciLayoutCatalogo() ));

    connect(btCarica, SIGNAL(clicked()), parent, SLOT( caricaDati() ));
}
