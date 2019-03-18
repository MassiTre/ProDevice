#include "gerarchia.h"
using std::cin;

Device::Device(std::string path, std::string mod, std::string prod, std::string dim, std::string proc, int ram, int mem, double p) :
    pathImmagine(path), modello(mod), produttore(prod), dimensioneSchermo(dim), processore(proc), memoriaRam(ram), memoria(mem), prezzo(p) {}

Mobile::Mobile(std::string path, std::string mod, std::string prod, std::string dim, std::string proc, int ram, int mem, double p, bool sd, bool j, bool fID, int pxf, int pxp) :
    Device(path,mod,prod,dim,proc,ram,mem,p), schedaSD(sd), jack(j), faceID(fID), pxFrontali(pxf), pxPosteriori(pxp) {}

Smartphone::Smartphone(std::string path, std::string mod, std::string prod, std::string dim, std::string proc, int ram, int mem, double p, bool sd, bool j, bool fID, int pxf, int pxp, bool sim) :
    Device(path,mod,prod,dim,proc,ram,mem,p), Mobile(path,mod,prod,dim,proc,ram,mem,p,sd,j,fID,pxf,pxp), dualSIM(sim) {}

Tablet::Tablet(std::string path, std::string mod, std::string prod, std::string dim, std::string proc, int ram, int mem, double p,  bool sd, bool j, bool fID, int pxf, int pxp, bool sim) :
    Device(path,mod,prod,dim,proc,ram,mem,p), Mobile(path,mod,prod,dim,proc,ram,mem,p,sd,j,fID,pxf,pxp), SIM(sim) {}


Computer::Computer(std::string path, std::string mod, std::string prod, std::string dim, std::string proc, int ram, int mem, double p, bool touch, bool cd, int usb) :
    Device(path,mod,prod,dim,proc,ram,mem,p), touchscreen(touch), lettoreCD(cd), porteUSB(usb) {}

Portatile::Portatile(std::string path, std::string mod, std::string prod, std::string dim, std::string proc, int ram, int mem, double p, bool touch, bool cd, int usb, bool ete, bool cam, bool luce, int pxw) :
    Device(path,mod,prod,dim,proc,ram,mem,p), Computer(path,mod,prod,dim,proc,ram,mem,p,touch,cd,usb), ethernet(ete), webcam(cam), luceTastiera(luce), pxWebcam(pxw) {}

Fisso::Fisso(std::string path, std::string mod, std::string prod, std::string dim, std::string proc, int ram, int mem, double p, bool touch, bool cd, int usb, bool bl, bool wf) :
    Device(path,mod,prod,dim,proc,ram,mem,p), Computer(path,mod,prod,dim,proc,ram,mem,p,touch,cd,usb), bluetooth(bl), wifi(wf) {}

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

/********************* GET ********************/

std::string Device::getModello() const { return modello; }
std::string Device::getProduttore() const { return produttore; }
std::string Device::getDimensioneSchermo() const { return dimensioneSchermo; }
std::string Device::getProcessore() const { return processore; }
int Device::getMemoriaRam() const { return memoriaRam; }
int Device::getMemoria() const { return memoria; }
double Device::getPrezzo() const { return prezzo; }
std::string Device::getPathImmagine() const{ return pathImmagine; }

bool Mobile::getSchedaSD() const { return schedaSD; }
bool Mobile::getJack() const { return jack; }
bool Mobile::getFaceID() const { return faceID; }
int Mobile::getPxFrontali() const { return pxFrontali; }
int Mobile::getPxPosteriori() const { return pxPosteriori; }

bool Smartphone::getDualSIM() const { return dualSIM; }

bool Tablet::getSIM() const { return SIM; }

bool Computer::getTouchscreen() const { return touchscreen; }
bool Computer::getLettoreCD() const { return lettoreCD; }
int Computer::getPorteUSB() const { return porteUSB; }

bool Portatile::getEthernet() const { return ethernet; }
bool Portatile::getWebcam() const { return webcam; }
bool Portatile::getLuceTastiera() const { return luceTastiera; }
int Portatile::getPxWebcam() const { return pxWebcam; }

bool Fisso::getBluetooth() const { return bluetooth; }
bool Fisso::getWifi() const { return wifi; }

bool Convertibile::getPenna() const { return penna; }
bool Convertibile::getStaccaTastiera() const { return staccaTastiera; }

/********************* GET TIPo ********************/
std::string Smartphone::getTipo() const {
    return "smartphone";
}
std::string Tablet::getTipo() const {
    return "tablet";
}
std::string Portatile::getTipo() const {
    return "portatile";
}
std::string Fisso::getTipo() const {
    return "fisso";
}
std::string Convertibile::getTipo() const {
    return "convertibile";
}
/********************* SET ********************/

void Device::setModello(std::string m) {modello = m;}
void Device::setProduttore(std::string p) {produttore = p;}
void Device::setDimensioneSchermo(std::string d) {dimensioneSchermo = d;}
void Device::setProcessore(std::string p) {processore = p;}
void Device::setMemoriaRam(int ram) {memoriaRam = ram;}
void Device::setMemoria(int m) {memoria = m;}
void Device::setPrezzo(double p) {prezzo = p; }

void Mobile::setSchedaSD(bool sd) {schedaSD = sd;}
void Mobile::setJack(bool j) {jack = j;}
void Mobile::setFaceID(bool f) {faceID = f;}
void Mobile::setPxFrontali(int px) {pxFrontali = px;}
void Mobile::setPxPosteriori(int px) {pxPosteriori = px;}

void Smartphone::setDualSIM(bool ds) {dualSIM = ds;}

void Tablet::setSIM(bool s) {SIM = s;}

void Computer::setTouchscreen(bool t) {touchscreen = t;}
void Computer::setLettoreCD(bool cd) {lettoreCD = cd;}
void Computer::setPorteUSB(int usb) {porteUSB = usb;}

void Portatile::setEthernet(bool e) {ethernet = e;}
void Portatile::setWebcam(bool w) {webcam = w;}
void Portatile::setLuceTastiera(bool lt) {luceTastiera = lt;}
void Portatile::setPxWebcam(int px) {pxWebcam = px;}

void Fisso::setBluetooth(bool b) {bluetooth = b;}
void Fisso::setWifi(bool w) {wifi = w;}

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

/********************* == ********************/

bool Device::operator==(const Device& d) const {
    return modello == d.modello && produttore == d.produttore;
}


bool Mobile::operator==(const Device& m) const {
    const Mobile* pm = dynamic_cast<const Mobile*>(&m);
    return pm && schedaSD == pm->schedaSD && Device::operator==(m);
}

bool Smartphone::operator==(const Device& s) const {
    const Smartphone* ps = dynamic_cast<const Smartphone*>(&s);
    return ps && dualSIM == ps->dualSIM && Mobile::operator==(s);
}

bool Tablet::operator==(const Device& t) const {
    const Tablet* pt = dynamic_cast<const Tablet*>(&t);
    return pt && SIM == pt->SIM && Mobile::operator==(t);
}


bool Computer::operator==(const Device& c) const {
    const Computer* pc = dynamic_cast<const Computer*>(&c);
    return pc && touchscreen == pc->touchscreen && Device::operator==(c);
}

bool Portatile::operator==(const Device& p) const {
    const Portatile* pp = dynamic_cast<const Portatile*>(&p);
    return pp && luceTastiera == pp->luceTastiera && Computer::operator==(p);
}

bool Fisso::operator==(const Device& f) const {
    return dynamic_cast<const Fisso*>(&f) && Computer::operator==(f);
}

bool Convertibile::operator==(const Device& c) const {
    return dynamic_cast<const Convertibile*>(&c) && Tablet::operator==(c) && Portatile::operator==(c);
}
/********** extra sui prezzi ***************/

int Mobile::extraSchedaSD = 20;
int Smartphone::extraDualSIM = 30;
int Tablet::extraSIM = 30;

int Computer::extraTouchscreen = 100;
int Portatile::extraLuceTastiera = 70;

/********** calcola prezzo *****************/

double Mobile::calcolaPrezzo() const {
    return extraSchedaSD*schedaSD + getPrezzo();
}

double Smartphone::calcolaPrezzo() const {
    return extraDualSIM*dualSIM + Mobile::calcolaPrezzo();
}

double Tablet::calcolaPrezzo() const {
    return extraSIM*SIM + Mobile::calcolaPrezzo();
}


double Computer::calcolaPrezzo() const {
    return extraTouchscreen*touchscreen + getPrezzo();
}

double Portatile::calcolaPrezzo() const {
    return extraLuceTastiera*luceTastiera + Computer::calcolaPrezzo();
}

double Fisso::calcolaPrezzo() const {
    return Computer::calcolaPrezzo();
}

double Convertibile::calcolaPrezzo() const {
    return Tablet::calcolaPrezzo() + Portatile::calcolaPrezzo() - getPrezzo();
}

/*********** stampa specifiche *************/
std::string Device::stampaSpecifiche() const{
    std::string str = "";
    return str.append(" Modello: " + getModello())
            .append("     Produttore: " + getModello())
            .append("\n Schermo: " + getModello())
            .append("     Prcessore: " + getModello())
            .append("\n Ram: " + std::to_string(getMemoriaRam()) + " GB")
            .append("     Memoria: " + std::to_string(getMemoria()) + " GB");
}

std::string Mobile::stampaSpecifiche() const{
    std::string str = Device::stampaSpecifiche();
    return str.append("\n SchedaSD: ").append(getSchedaSD() ? "Si" : "No")
            .append("     Jack: ").append(getJack() ? "Si" : "No")
            .append("     FaceID: ").append(getFaceID() ? "Si" : "No")
            .append("\n Fotocamera frontale: " + std::to_string(getPxFrontali()) + " MPX")
            .append("     Fotocamera posteriore: " + std::to_string(getPxPosteriori()) ).append(" MPX");
}

std::string Smartphone::stampaSpecifiche() const{
    std::string str = Mobile::stampaSpecifiche();
    return str.append("\n Dual SIM: ").append(getDualSIM() ? "Si" : "No");
}

std::string Tablet::stampaSpecifiche() const{
    std::string str = Mobile::stampaSpecifiche();
    return str.append("\n SIM: ").append(getSIM() ? "Si" : "No");
}


std::string Computer::stampaSpecifiche() const{
    std::string str = dynamic_cast<const Convertibile*>(this) ? "" : Device::stampaSpecifiche();
    return str.append("\n Touchscreen: ").append(getTouchscreen() ? "Si" : "No")
            .append("     lettoreCD: ").append(getLettoreCD() ? "Si" : "No")
            .append("     PorteUSB: " + std::to_string(getPorteUSB()) );
}

std::string Portatile::stampaSpecifiche() const{
    std::string str = Computer::stampaSpecifiche();
    std::string webcam_string = getWebcam() ? std::to_string(getPxWebcam()).append(" MPX") : "No";
    return str.append("\n Ethernet: ").append(getEthernet() ? "Si" : "No")
            .append("     Tastiera Retroilluminata: ").append(getLuceTastiera() ? "Si" : "No")
            .append("\n Webcam: " + webcam_string);
}

std::string Fisso::stampaSpecifiche() const{
    std::string str = Computer::stampaSpecifiche();
    return str.append("\n Bluetooth: ").append(getBluetooth() ? "Si" : "No")
            .append("     WiFi: ").append(getWifi() ? "Si" : "No");
}

std::string Convertibile::stampaSpecifiche() const{
    std::string str = Tablet::stampaSpecifiche() + Portatile::stampaSpecifiche();
    return str.append("\n Penna inclusa: ").append(getPenna() ? "Si" : "No")
            .append("     Tastiera rimuovibile: ").append(getStaccaTastiera() ? "Si" : "No");
}
