#ifndef LAYOUTHOME_H
#define LAYOUTHOME_H

#include <QWidget>
#include <QPushButton>

#include <QIcon>
#include <QString>

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QToolButton>

#include <QAction>

class LayoutHome : public QWidget {
    Q_OBJECT
private:
    QWidget* parent;

    // QIcon iconAggiungi;

    // QToolButton* btAggiungi;
    QPushButton* btAggiungi;
    QPushButton* btCerca;
    QPushButton* btCatalogo;

    QPushButton* btCarica;
    QPushButton* btSalva;

    // static QIcon iconAggiungi;

public:
    LayoutHome(QWidget* =nullptr);
};

#endif // LAYOUTHOME_H
