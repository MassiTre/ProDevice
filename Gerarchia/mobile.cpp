#include "mobile.h"

/*** costruttore ***/
Mobile::Mobile(std::string path, std::string mod, std::string prod, std::string dim, std::string proc, int ram, int mem, double p, bool sd, bool j, bool fID, int pxf, int pxp) :
    Device(path,mod,prod,dim,proc,ram,mem,p), schedaSD(sd), jack(j), faceID(fID), pxFrontali(pxf), pxPosteriori(pxp) {}

/*** metodi get ***/
bool Mobile::getSchedaSD() const { return schedaSD; }
bool Mobile::getJack() const { return jack; }
bool Mobile::getFaceID() const { return faceID; }
int Mobile::getPxFrontali() const { return pxFrontali; }
int Mobile::getPxPosteriori() const { return pxPosteriori; }

/*** metodi set ***/
void Mobile::setSchedaSD(bool sd) {schedaSD = sd;}
void Mobile::setJack(bool j) {jack = j;}
void Mobile::setFaceID(bool f) {faceID = f;}
void Mobile::setPxFrontali(int px) {pxFrontali = px;}
void Mobile::setPxPosteriori(int px) {pxPosteriori = px;}

/*** overloading operatore uguaglianza ***/
bool Mobile::operator==(const Device& m) const {
    const Mobile* pm = dynamic_cast<const Mobile*>(&m);
    return pm && schedaSD == pm->schedaSD && Device::operator==(m);
}

/*** stampa specifiche ***/
std::string Mobile::stampaSpecifiche() const{
    std::string str = Device::stampaSpecifiche();
    return str.append("\n SchedaSD: ").append(getSchedaSD() ? "Si" : "No")
            .append("     Jack: ").append(getJack() ? "Si" : "No")
            .append("     FaceID: ").append(getFaceID() ? "Si" : "No")
            .append("\n Fotocamera frontale: " + std::to_string(getPxFrontali()) + " MPX")
            .append("     Fotocamera posteriore: " + std::to_string(getPxPosteriori()) ).append(" MPX");
}

/*** variabili statiche - aumento del prezzo ***/
int Mobile::extraSchedaSD = 20;

/*** calcolo prezzo totale ***/
double Mobile::calcolaPrezzo() const {
    return extraSchedaSD*schedaSD + getPrezzo();
}
