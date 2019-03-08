#ifndef COMBOTIPODEVICE_H
#define COMBOTIPODEVICE_H

#include <QComboBox>
#include <QWidget>

class ComboTipoDevice : public QComboBox
{
    Q_OBJECT
public:
    ComboTipoDevice(QWidget * = nullptr);
};

#endif // COMBOTIPODEVICE_H
