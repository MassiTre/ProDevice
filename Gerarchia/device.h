#ifndef DEVICE_H
#define DEVICE_H

#include <string>

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

    virtual std::string getTipo() const = 0;

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

#endif // DEVICE_H
