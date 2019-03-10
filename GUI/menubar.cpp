#include "menubar.h"

MenuBar::MenuBar(QWidget* p):
    parent(p),
    voceHome(new QAction("Home", this)),
    voceAggiungi(new QAction("Aggiungi", this)),
    voceCerca(new QAction("Cerca", this)),
    voceCatalogo(new QAction("Catalogo", this)),
    menuOpzioni(new QMenu("Opzioni", this)),
    optionSalva(new QAction("Salva", menuOpzioni)),
    optionCarica(new QAction("Carica", menuOpzioni)),
    optionEsci(new QAction("Esci", menuOpzioni))
{

    addAction(voceHome);
    addAction(voceAggiungi);
    addAction(voceCerca);
    addAction(voceCatalogo);

    QList<QAction*> actionList;
    actionList.push_back(optionSalva);
    actionList.push_back(optionCarica);
    actionList.push_back(optionEsci);

    menuOpzioni->addActions(actionList);
    actionList.clear();
    addMenu(menuOpzioni);

    connect(voceHome, SIGNAL(triggered()), parent, SLOT(esciLayoutHome()));
    connect(voceAggiungi, SIGNAL(triggered()), parent, SLOT(esciLayoutAggiungi()));
    connect(voceCerca, SIGNAL(triggered()), parent, SLOT(esciLayoutCerca()));
    connect(voceCatalogo, SIGNAL(triggered()), parent, SLOT(esciLayoutCatalogo()));

    connect(optionCarica, SIGNAL(triggered()), parent, SLOT(caricaDati()));
}
