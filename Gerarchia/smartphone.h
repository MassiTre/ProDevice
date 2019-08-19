#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include "mobile.h"

class Smartphone : public Mobile {
    bool dualSIM;

    static int extraDualSIM;
public:
    Smartphone(std::string = "", std::string = "no info", std::string = "no info", std::string = "no info", std::string = "no info", int = 0, int = 0, double = 0.0, bool = true, bool = true, bool = true, int = 0, int = 0, bool = false);

    virtual std::string getTipo() const;

    bool getDualSIM() const;

    void setDualSIM(bool);

    virtual bool operator==(const Device&) const;

    virtual double calcolaPrezzo() const;
    virtual std::string stampaSpecifiche() const;
};

#endif // SMARTPHONE_H
