#ifndef CONTROLLER_H
#define CONTROLLER_H



#include <QWidget>
#include <QVBoxLayout>

#include "modello.h"
#include "menubar.h"
#include "layouthome.h"
#include "layoutaggiungi.h"
#include "layoutcerca.h"
#include "layoutcatalogo.h"

class Controller : public QWidget
{
        Q_OBJECT
    private:
        MenuBar* menu;
        Modello* modello;
        QVBoxLayout* mainLayout;
        LayoutHome* homeLayout;
        LayoutAggiungi* aggiungiLayout;
        LayoutCerca* cercaLayout;
        LayoutCatalogo* catalogoLayout;

    public:
        Controller(Modello*, QWidget* = nullptr);
        Modello *getModello();
    public slots:
        void esciLayoutHome() const;
        void esciLayoutAggiungi() const;
        void esciLayoutCerca() const;
        void esciLayoutCatalogo() const;

        void caricaDati();

};

#endif // CONTROLLER_H
