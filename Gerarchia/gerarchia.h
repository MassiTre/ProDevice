#ifndef GERARCHIA_H
#define GERARCHIA_H

#include<string>
#include<iostream>
#include<sstream>
#include<iomanip>

//************************ GERARCHIA ********************************************/
class Device {
private:
    std::string pathImmagine;
    std::string modello;
    std::string produttore;
    std::string dimensioneSchermo;
    std::string processore;
    int memoriaRam;
    int memoria;
    double prezzo;
public:
    virtual ~Device() = default;
    Device(std::string, std::string, std::string, std::string, std::string, int, int, double);

    std::string getPathImmagine() const;
    std::string getModello() const;
    std::string getProduttore() const;
    std::string getDimensioneSchermo() const;
    std::string getProcessore() const;
    int getMemoriaRam() const;
    int getMemoria() const;
    double getPrezzo() const;
    std::string getImmagine() const;

    void setPathImmagine(std::string);
    void setModello(std::string);
    void setProduttore(std::string);
    void setDimensioneSchermo(std::string);
    void setProcessore(std::string);
    void setMemoriaRam(int);
    void setMemoria(int);
    void setPrezzo(double);

    virtual bool operator==(const Device&) const;

    virtual double calcolaPrezzo() const = 0;
    virtual std::string stampaSpecifiche() const;
};

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

class Smartphone : public Mobile {
    bool dualSIM;

    static int extraDualSIM;
public:
    Smartphone(std::string = "", std::string = "no info", std::string = "no info", std::string = "no info", std::string = "no info", int = 0, int = 0, double = 0.0, bool = true, bool = true, bool = true, int = 0, int = 0, bool = false);

    bool getDualSIM() const;

    void setDualSIM(bool);

    virtual bool operator==(const Device&) const;

    virtual double calcolaPrezzo() const;
    virtual std::string stampaSpecifiche() const;
};

class Tablet : public Mobile {
    bool SIM;

    static int extraSIM;
public:
    Tablet(std::string = "", std::string = "no info", std::string = "no info", std::string = "no info", std::string = "no info", int = 0, int = 0, double = 0.0, bool = true, bool = true, bool = true, int = 0, int = 0, bool = false);

    bool getSIM() const;

    void setSIM(bool);

    virtual bool operator==(const Device&) const;

    virtual double calcolaPrezzo() const;
    virtual std::string stampaSpecifiche() const;

};


class Computer : virtual public Device {
    bool touchscreen;
    bool lettoreCD;
    int porteUSB;

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

class Portatile : public Computer {
    bool ethernet;
    bool webcam;
    bool luceTastiera;
    int pxWebcam;

    static int extraLuceTastiera;
public:
    Portatile(std::string = "", std::string = "no info", std::string = "no info", std::string = "no info", std::string = "no info", int = 0, int = 0, double = 0.0, bool = false, bool = false, int = 0, bool = false, bool = true, bool = false, int = 0);

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

class Fisso : public Computer {
    bool bluetooth;
    bool wifi;
public:
    Fisso(std::string = "", std::string = "no info", std::string = "no info", std::string = "no info", std::string = "no info", int = 0, int = 0, double = 0.0, bool = false, bool = false, int = 0, bool = false, bool = true);

    bool getBluetooth() const;
    bool getWifi() const;

    void setBluetooth(bool);
    void setWifi(bool);

    virtual bool operator==(const Device&) const;
    virtual std::string stampaSpecifiche() const;
};

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
            bool = false, bool = true, bool = false, // int = 0,
            // campi propi
            bool = false, bool = false);

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

#endif // GERARCHIA_H
