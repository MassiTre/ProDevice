#ifndef FISSO_H
#define FISSO_H

#include "computer.h"

class Fisso : public Computer {
    bool bluetooth;
    bool wifi;
public:
    Fisso(std::string = "", std::string = "no info", std::string = "no info", std::string = "no info", std::string = "no info", int = 0, int = 0, double = 0.0, bool = false, bool = false, int = 0, bool = false, bool = true);

    virtual std::string getTipo() const;

    bool getBluetooth() const;
    bool getWifi() const;

    void setBluetooth(bool);
    void setWifi(bool);

    virtual bool operator==(const Device&) const;

    double calcolaPrezzo() const;
    virtual std::string stampaSpecifiche() const;
};

#endif // FISSO_H
