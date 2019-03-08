#include "itemwidget.h"

itemWidget::itemWidget(QWidget* p) : parent(p){
    setIconSize(QSize(150,150));
    addScrollBarWidget(new QScrollBar(Qt::Orientation::Vertical,parent), Qt::AlignRight);
}

void itemWidget::aggiungiDevice(Device* d){
    ListDevice* oggetto = new ListDevice(parent, d);
    addItem(oggetto);
}

ListDevice* itemWidget::oggettoCorrente() const{
    return static_cast<ListDevice*>(QListWidget::currentItem());
}
