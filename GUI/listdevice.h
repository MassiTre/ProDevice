#ifndef LISTDEVICE_H
#define LISTDEVICE_H

#include<QListWidgetItem>
#include"Gerarchia/gerarchia.h"

class ListDevice : public QListWidgetItem{
private:
    QWidget* parent;
    Device* oggetto;
public:
    ListDevice(QWidget*, Device* =nullptr);
    Device* prelevaOgg() const;
    void update();
};

#endif // LISTDEVICE_H
