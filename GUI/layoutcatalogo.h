#ifndef LAYOUTCATALOGO_H
#define LAYOUTCATALOGO_H

#include "listdevice/devicewidgetlista.h"
#include <QPushButton>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QCheckBox>

class LayoutCatalogo : public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    /*** layout principale (verticale) ***/
    QVBoxLayout* vBox;
    DeviceWidgetLista* lista; // risultati

    QHBoxLayout* hBts; // layout orizzontale per pulsanti
    QPushButton* btModifica;
    QPushButton* btElimina;
public:
    LayoutCatalogo(QWidget* =nullptr);

    DeviceWidgetLista *getLista() const;
};

#endif // LAYOUTCATALOGO_H
