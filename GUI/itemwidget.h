#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include "listdevice.h"
#include <QListWidget>
#include <QScrollBar>

class itemWidget : public QListWidget{
    Q_OBJECT
private:
    QWidget* parent;
public:
    itemWidget(QWidget* =nullptr);
    void aggiungiDevice(Device*);
    ListDevice* oggettoCorrente() const;
};

#endif // ITEMWIDGET_H
