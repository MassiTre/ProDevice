#include "convertibile.h"

/*** costruttore ***/
Convertibile::Convertibile(
        // campi device
        std::string path, std::string mod, std::string prod, std::string dim, std::string proc, int ram, int mem, double p,
        // campi mobile e tablet
        bool sd, bool j, bool fID, int pxf, int pxp, bool sim,
        // campi computer e portatile
        bool touch, bool cd, int usb, bool ete, bool cam, bool luce, /*int pxw,*/
        // campi propri
        bool pen, bool stacca
        ) :
    Device(path,mod,prod,dim,proc,ram,mem,p),
    Tablet(path,mod,prod,dim,proc,ram,mem,p,sd,j,fID,pxf,pxp,sim),
    Portatile(path,mod,prod,dim,proc,ram,mem,p,touch,cd,usb,ete,cam,luce,pxf),
    penna(pen), staccaTastiera(stacca) {}
    // pxf = pixel fotocamera frontale (mobile) = pixel webcam (portatile)

/*** metodi get ***/
bool Convertibile::getPenna() const { return penna; }
bool Convertibile::getStaccaTastiera() const { return staccaTastiera; }
std::string Convertibile::getTipo() const { return "convertibile"; }

/*** metodi set ***/
void Convertibile::setPenna(bool p) {penna = p;}
void Convertibile::setStaccaTastiera(bool st) {staccaTastiera = st;}
void Convertibile::setPxFrontali(int px) {
    Mobile::setPxFrontali(px);
    Portatile::setPxWebcam(px);
}
void Convertibile::setPxWebcam(int px) {
    Mobile::setPxFrontali(px);
    Portatile::setPxWebcam(px);
}

/*** overloading operatore uguaglianza ***/
bool Convertibile::operator==(const Device& c) const {
    return dynamic_cast<const Convertibile*>(&c) && Tablet::operator==(c) && Portatile::operator==(c);
}

/*** stampa specifiche ***/
std::string Convertibile::stampaSpecifiche() const{
    std::string str = Tablet::stampaSpecifiche() + Portatile::stampaSpecifiche();
    return str.append("\n Penna inclusa: ").append(getPenna() ? "Si" : "No")
            .append("     Tastiera rimuovibile: ").append(getStaccaTastiera() ? "Si" : "No");
}

/*** calcolo prezzo totale ***/
double Convertibile::calcolaPrezzo() const { return Tablet::calcolaPrezzo() + Portatile::calcolaPrezzo() - getPrezzo(); }
