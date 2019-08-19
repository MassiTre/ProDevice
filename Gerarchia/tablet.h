#ifndef TABLET_H
#define TABLET_H

#include "mobile.h"

class Tablet : public Mobile {
    bool SIM;

    static int extraSIM;
public:
    Tablet(std::string = "", std::string = "no info", std::string = "no info", std::string = "no info", std::string = "no info", int = 0, int = 0, double = 0.0, bool = true, bool = true, bool = true, int = 0, int = 0, bool = false);

    virtual std::string getTipo() const;

    bool getSIM() const;

    void setSIM(bool);

    virtual bool operator==(const Device&) const;

    virtual double calcolaPrezzo() const;
    virtual std::string stampaSpecifiche() const;

};

#endif // TABLET_H
