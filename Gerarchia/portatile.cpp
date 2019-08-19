#include "portatile.h"

/*** costruttore ***/
Portatile::Portatile(std::string path, std::string mod, std::string prod, std::string dim, std::string proc, int ram, int mem, double p, bool touch, bool cd, int usb, bool ete, bool cam, bool luce, int pxw) :
    Device(path,mod,prod,dim,proc,ram,mem,p), Computer(path,mod,prod,dim,proc,ram,mem,p,touch,cd,usb), ethernet(ete), webcam(cam), luceTastiera(luce), pxWebcam(pxw) {}

/*** metodi get ***/
bool Portatile::getEthernet() const { return ethernet; }
bool Portatile::getWebcam() const { return webcam; }
bool Portatile::getLuceTastiera() const { return luceTastiera; }
int Portatile::getPxWebcam() const { return pxWebcam; }
std::string Portatile::getTipo() const { return "portatile"; }

/*** metodi set ***/
void Portatile::setEthernet(bool e) {ethernet = e;}
void Portatile::setWebcam(bool w) {webcam = w;}
void Portatile::setLuceTastiera(bool lt) {luceTastiera = lt;}
void Portatile::setPxWebcam(int px) {pxWebcam = px;}

/*** overloading operatore uguaglianza ***/
bool Portatile::operator==(const Device& p) const {
    const Portatile* pp = dynamic_cast<const Portatile*>(&p);
    return pp && luceTastiera == pp->luceTastiera && Computer::operator==(p);
}

/*** stampa specifiche ***/
std::string Portatile::stampaSpecifiche() const{
    std::string str = Computer::stampaSpecifiche();
    std::string webcam_string = getWebcam() ? std::to_string(getPxWebcam()).append(" MPX") : "No";
    return str.append("\n Ethernet: ").append(getEthernet() ? "Si" : "No")
            .append("     Tastiera Retroilluminata: ").append(getLuceTastiera() ? "Si" : "No")
            .append("\n Webcam: " + webcam_string);
}

/*** variabili statiche - aumento del prezzo ***/
int Portatile::extraLuceTastiera = 70;

/*** calcolo prezzo totale ***/
double Portatile::calcolaPrezzo() const { return extraLuceTastiera*luceTastiera + Computer::calcolaPrezzo(); }
