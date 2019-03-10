#include "controller.h"
#include <QFileDialog>

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

void Controller::caricaDati(){
    QString file = QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/Dati Dispositivi" , "File XML(*.xml)");

    if(file!=""){
        catalogoLayout->getLista()->clear();
        modello->setNuovaPath(file.toStdString());
        modello->carica();

        Container<Device*>::iterator b_it = modello->it_begin();
        Container<Device*>::iterator e_it = modello->it_end();

        for(; b_it != e_it; ++b_it){
          catalogoLayout->getLista()->aggiungiDevice(*b_it);
        }

        modello->setSalvataggio(true);
        esciLayoutCatalogo();
    }
}
