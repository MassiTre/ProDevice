#include "listdevice.h"

ListDevice::ListDevice(QWidget* p , Device* o) : parent(p) , oggetto(o) {
    update();
}

Device* ListDevice::prelevaOgg() const{ return oggetto; }

void ListDevice::update(){
/*
    QString path = QString::fromStdString(oggetto->getPath());
    QPixmap p(path);
    setIcon(p.scaled(500,600,Qt::AspectRatioMode::KeepAspectRatio)); //Per l'immagine

    setText(QString::fromStdString(oggetto->infoOggetto())); //Per il testo
*/
}
