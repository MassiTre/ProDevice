#ifndef CONVERTIBILE_H
#define CONVERTIBILE_H

#include "tablet.h"
#include "portatile.h"

class Convertibile : public Tablet , public Portatile {
    bool penna;
    bool staccaTastiera;
public:
    Convertibile(
            // campi device
            std::string = "", std::string = "no info", std::string = "no info", std::string = "no info", std::string = "no info", int = 0, int = 0, double = 0.0,
            // campi mobile
            bool = true, bool = true, bool = true, int = 0, int = 0,
            // campi tablet
            bool = false,
            // campi computer
            bool = false, bool = false, int = 0,
            // campi Portatile
            bool = false, bool = true, bool = false,
            // campi propi
            bool = false, bool = false);

    virtual std::string getTipo() const;

    bool getPenna() const;
    bool getStaccaTastiera() const;

    void setPenna(bool);
    void setStaccaTastiera(bool);
    void setPxFrontali(int px);
    void setPxWebcam(int px);

    virtual bool operator==(const Device&) const;

    virtual double calcolaPrezzo() const;
    virtual std::string stampaSpecifiche() const;

};

#endif // CONVERTIBILE_H
