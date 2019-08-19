#ifndef LAYOUTHOME_H
#define LAYOUTHOME_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QIcon>
#include <QString>
#include <QAction>

class LayoutHome : public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    // layout principale (verticale) ***/
    QVBoxLayout* vBox;

    QHBoxLayout* hBox; // layout orizzontale per i tre pulsanti
    QPushButton* btAggiungi;
    QPushButton* btCerca;
    QPushButton* btCatalogo;

    QPushButton* btCarica;

public:
    LayoutHome(QWidget* =nullptr);
};

#endif // LAYOUTHOME_H
