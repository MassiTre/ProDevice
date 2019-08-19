#include "fisso.h"

/*** costruttore ***/
Fisso::Fisso(std::string path, std::string mod, std::string prod, std::string dim, std::string proc, int ram, int mem, double p, bool touch, bool cd, int usb, bool bl, bool wf) :
    Device(path,mod,prod,dim,proc,ram,mem,p), Computer(path,mod,prod,dim,proc,ram,mem,p,touch,cd,usb), bluetooth(bl), wifi(wf) {}

/*** metodi get ***/
bool Fisso::getBluetooth() const { return bluetooth; }
bool Fisso::getWifi() const { return wifi; }
std::string Fisso::getTipo() const { return "fisso"; }

/*** metodi set ***/
void Fisso::setBluetooth(bool b) {bluetooth = b;}
void Fisso::setWifi(bool w) {wifi = w;}

/*** overloading operatore uguaglianza ***/
bool Fisso::operator==(const Device& f) const {
    return dynamic_cast<const Fisso*>(&f) && Computer::operator==(f);
}

/*** stampa specifiche ***/
std::string Fisso::stampaSpecifiche() const{
    std::string str = Computer::stampaSpecifiche();
    return str.append("\n Bluetooth: ").append(getBluetooth() ? "Si" : "No")
            .append("     WiFi: ").append(getWifi() ? "Si" : "No");
}

/*** calcolo prezzo totale ***/
double Fisso::calcolaPrezzo() const { return Computer::calcolaPrezzo(); }

