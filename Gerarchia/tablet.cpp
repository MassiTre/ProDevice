#include "tablet.h"

/*** costruttore ***/
Tablet::Tablet(std::string path, std::string mod, std::string prod, std::string dim, std::string proc, int ram, int mem, double p,  bool sd, bool j, bool fID, int pxf, int pxp, bool sim) :
    Device(path,mod,prod,dim,proc,ram,mem,p), Mobile(path,mod,prod,dim,proc,ram,mem,p,sd,j,fID,pxf,pxp), SIM(sim) {}

/*** metodi get ***/
bool Tablet::getSIM() const { return SIM; }
std::string Tablet::getTipo() const { return "tablet"; }

/*** metodi set ***/
void Tablet::setSIM(bool s) {SIM = s;}

/*** overloading operatore uguaglianza ***/
bool Tablet::operator==(const Device& t) const {
    const Tablet* pt = dynamic_cast<const Tablet*>(&t);
    return pt && SIM == pt->SIM && Mobile::operator==(t);
}

/*** stampa specifiche ***/
std::string Tablet::stampaSpecifiche() const{
    std::string str = Mobile::stampaSpecifiche();
    return str.append("\n SIM: ").append(getSIM() ? "Si" : "No");
}

/*** variabili statiche - aumento del prezzo ***/
int Tablet::extraSIM = 30;

/*** calcolo prezzo totale ***/
double Tablet::calcolaPrezzo() const { return extraSIM*SIM + Mobile::calcolaPrezzo(); }
