#include "computer.h"
#include "convertibile.h"

/*** costruttore ***/
Computer::Computer(std::string path, std::string mod, std::string prod, std::string dim, std::string proc, int ram, int mem, double p, bool touch, bool cd, int usb) :
    Device(path,mod,prod,dim,proc,ram,mem,p), touchscreen(touch), lettoreCD(cd), porteUSB(usb) {}

/*** metodi get ***/
bool Computer::getTouchscreen() const { return touchscreen; }
bool Computer::getLettoreCD() const { return lettoreCD; }
int Computer::getPorteUSB() const { return porteUSB; }

/*** metodi set ***/
void Computer::setTouchscreen(bool t) {touchscreen = t;}
void Computer::setLettoreCD(bool cd) {lettoreCD = cd;}
void Computer::setPorteUSB(int usb) {porteUSB = usb;}

/*** overloading operatore uguaglianza ***/
bool Computer::operator==(const Device& c) const {
    const Computer* pc = dynamic_cast<const Computer*>(&c);
    return pc && touchscreen == pc->touchscreen && Device::operator==(c);
}

/*** stampa specifiche ***/
std::string Computer::stampaSpecifiche() const{
    std::string str = dynamic_cast<const Convertibile*>(this) ? "" : Device::stampaSpecifiche();
    return str.append("\n Touchscreen: ").append(getTouchscreen() ? "Si" : "No")
            .append("     lettoreCD: ").append(getLettoreCD() ? "Si" : "No")
            .append("     PorteUSB: " + std::to_string(getPorteUSB()) );
}
/*** variabili statiche - aumento del prezzo ***/
int Computer::extraTouchscreen = 100;

/*** calcolo prezzo totale ***/
double Computer::calcolaPrezzo() const { return extraTouchscreen*touchscreen + getPrezzo(); }
