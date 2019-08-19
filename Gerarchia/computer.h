#ifndef COMPUTER_H
#define COMPUTER_H

#include "device.h"

class Computer : virtual public Device {
    bool touchscreen;
    bool lettoreCD;
    int porteUSB;

    virtual std::string getTipo() const = 0;

    static int extraTouchscreen;
public:
    Computer(std::string, std::string, std::string, std::string, std::string, int, int, double, bool, bool, int);

    bool getTouchscreen() const;
    bool getLettoreCD() const;
    int getPorteUSB() const;

    void setTouchscreen(bool);
    void setLettoreCD(bool);
    void setPorteUSB(int);

    virtual bool operator==(const Device&) const;

    virtual double calcolaPrezzo() const;
    virtual std::string stampaSpecifiche() const;

};

#endif // COMPUTER_H
