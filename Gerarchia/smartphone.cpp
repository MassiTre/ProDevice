#include "smartphone.h"

/*** costruttore ***/
Smartphone::Smartphone(std::string path, std::string mod, std::string prod, std::string dim, std::string proc, int ram, int mem, double p, bool sd, bool j, bool fID, int pxf, int pxp, bool sim) :
    Device(path,mod,prod,dim,proc,ram,mem,p), Mobile(path,mod,prod,dim,proc,ram,mem,p,sd,j,fID,pxf,pxp), dualSIM(sim) {}

/*** metodi get ***/
bool Smartphone::getDualSIM() const { return dualSIM; }
std::string Smartphone::getTipo() const { return "smartphone"; }

/*** metodi set ***/
void Smartphone::setDualSIM(bool ds) {dualSIM = ds;}

/*** overloading operatore uguaglianza ***/
bool Smartphone::operator==(const Device& s) const {
    const Smartphone* ps = dynamic_cast<const Smartphone*>(&s);
    return ps && dualSIM == ps->dualSIM && Mobile::operator==(s);
}

/*** stampa specifiche ***/
std::string Smartphone::stampaSpecifiche() const{
    std::string str = Mobile::stampaSpecifiche();
    return str.append("\n Dual SIM: ").append(getDualSIM() ? "Si" : "No");
}

/*** variabili statiche - aumento del prezzo ***/
int Smartphone::extraDualSIM = 30;

/*** calcolo prezzo totale ***/
double Smartphone::calcolaPrezzo() const {
    return extraDualSIM*dualSIM + Mobile::calcolaPrezzo();
}
