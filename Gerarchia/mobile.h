#ifndef MOBILE_H
#define MOBILE_H

#include "device.h"

class Mobile : virtual public Device {
private:
    bool schedaSD;
    bool jack;
    bool faceID;
    int pxFrontali;
    int pxPosteriori;

    static int extraSchedaSD;
public:
    Mobile(std::string, std::string, std::string, std::string, std::string, int, int, double, bool, bool, bool, int, int);

    virtual std::string getTipo() const = 0;

    bool getSchedaSD() const;
    bool getJack() const;
    bool getFaceID() const;
    int getPxFrontali() const;
    int getPxPosteriori() const;

    void setSchedaSD(bool);
    void setJack(bool);
    void setFaceID(bool);
    void setPxFrontali(int);
    void setPxPosteriori(int);

    virtual bool operator==(const Device&) const;

    virtual double calcolaPrezzo() const;
    virtual std::string stampaSpecifiche() const;
};

#endif // MOBILE_H
