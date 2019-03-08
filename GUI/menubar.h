#ifndef MENUBAR_H
#define MENUBAR_H

#include <qmenubar.h>
#include <qwidget.h>

class MenuBar : public QMenuBar {
    Q_OBJECT
private:
    QWidget* parent;

    QAction* voceHome;
    QAction* voceAggiungi;
    QAction* voceCerca;
    QAction* voceCatalogo;

    QMenu* menuOpzioni;
    QAction* optionSalva;
    QAction* optionCarica;
    QAction* optionEsci;

public:
    MenuBar(QWidget* = nullptr);
    QAction* getVoceHome() const;
    QAction* getVoceAggiungi() const;
    QAction* getVoceCerca() const;
    QAction* getVoceCatalogo() const;

    QMenu* getMenuOpzioni() const;
    QAction* getOptionSalva() const;
    QAction* getOptionCarica() const;
    QAction* getOptionEsci() const;
};

#endif // MENUBAR_H
