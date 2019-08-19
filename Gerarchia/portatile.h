#ifndef PORTATILE_H
#define PORTATILE_H

#include "computer.h"

class Portatile : public Computer {
    bool ethernet;
    bool webcam;
    bool luceTastiera;
    int pxWebcam;

    static int extraLuceTastiera;
public:
    Portatile(std::string = "", std::string = "no info", std::string = "no info", std::string = "no info", std::string = "no info", int = 0, int = 0, double = 0.0, bool = false, bool = false, int = 0, bool = false, bool = true, bool = false, int = 0);

    virtual std::string getTipo() const;

    bool getEthernet() const;
    bool getWebcam() const;
    bool getLuceTastiera() const;
    int getPxWebcam() const;

    void setEthernet(bool);
    void setWebcam(bool);
    void setLuceTastiera(bool);
    void setPxWebcam(int);

    virtual bool operator==(const Device&) const;

    virtual double calcolaPrezzo() const;
    virtual std::string stampaSpecifiche() const;

};

#endif // PORTATILE_H
