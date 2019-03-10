#include "layoutcatalogo.h"

LayoutCatalogo::LayoutCatalogo(QWidget* p) :
    QWidget(p),
    list(new itemWidget(this))
{
    QHBoxLayout* hBox = new QHBoxLayout();

    hBox->addWidget(list);
    list->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

itemWidget* LayoutCatalogo::getLista() const{ return list; }
