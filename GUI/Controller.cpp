#include "controller.h"

Controller::Controller(Modello* m, QWidget* parent) :
    QWidget(parent),
    menu(new MenuBar(this)),
    modello(m),
    mainLayout(new QVBoxLayout(this)),
    homeLayout(new LayoutHome(this)),
    aggiungiLayout(new LayoutAggiungi(this)),
    cercaLayout(new LayoutCerca(this)),
    catalogoLayout(new LayoutCatalogo(this))
{
    mainLayout->setMenuBar(menu);
    mainLayout->addWidget(homeLayout);
    mainLayout->addWidget(aggiungiLayout);
    mainLayout->addWidget(cercaLayout);
    mainLayout->addWidget(catalogoLayout);

    aggiungiLayout->hide();
    cercaLayout->hide();
    catalogoLayout->hide();

    setLayout(mainLayout);
}

void Controller::esciLayoutHome() const {
    aggiungiLayout->hide();
    cercaLayout->hide();
    catalogoLayout->hide();

    homeLayout->show();
}

void Controller::esciLayoutAggiungi() const {
    homeLayout->hide();
    cercaLayout->hide();
    catalogoLayout->hide();

    aggiungiLayout->show();
}

void Controller::esciLayoutCerca() const {
    homeLayout->hide();
    aggiungiLayout->hide();
    catalogoLayout->hide();

    cercaLayout->show();
}

void Controller::esciLayoutCatalogo() const {
    homeLayout->hide();
    aggiungiLayout->hide();
    cercaLayout->hide();

    catalogoLayout->show();
}
