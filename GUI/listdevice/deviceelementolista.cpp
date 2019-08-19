#include "deviceelementolista.h"

DeviceElementoLista::DeviceElementoLista(QWidget* p, Device* d): parent(p), oggetto(d) {
    aggiornaOggetto();
}

Device* DeviceElementoLista::oggettoCorrente() const {
    return oggetto;
}

void DeviceElementoLista::aggiornaOggetto() {

    QString pathImmagine = QString::fromStdString(oggetto->getPathImmagine());
    QPixmap immagine(pathImmagine);
    setIcon(immagine.scaled(500, 600, Qt::AspectRatioMode::KeepAspectRatio));

    setText(QString::fromStdString(oggetto->stampaSpecifiche()));
}
