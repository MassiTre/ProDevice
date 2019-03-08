#include "Gerarchia.h"

Device::Device(std::string mod, std::string prod, std::string dim, std::string proc, std::string so, int ram, int mem, double p) :
        modello(mod), produttore(prod), dimensioneSchermo(dim), processore(proc), sistemaOperativo(so), memoriaRam(ram), memoria(mem), prezzo(p) {}


Mobile::Mobile(std::string mod, std::string prod, std::string dim, std::string proc, std::string so, int ram, int mem, double p, bool sd, bool j, bool fID, int pxf, int pxp) :
    Device(mod,prod,dim,proc,so,ram,mem,p), schedaSD(sd), jack(j), faceID(fID), pxFrontali(pxf), pxPosteriori(pxp) {}

Smartphone::Smartphone(std::string mod, std::string prod, std::string dim, std::string proc, std::string so, int ram, int mem, double p, bool sd, bool j, bool fID, int pxf, int pxp, bool sim) :
    Device(mod,prod,dim,proc,so,ram,mem,p), Mobile(mod,prod,dim,proc,so,ram,mem,p,sd,j,fID,pxf,pxp), dualSIM(sim) {}

Tablet::Tablet(std::string mod, std::string prod, std::string dim, std::string proc, std::string so, int ram, int mem, double p,  bool sd, bool j, bool fID, int pxf, int pxp, bool sim) :
    Device(mod,prod,dim,proc,so,ram,mem,p), Mobile(mod,prod,dim,proc,so,ram,mem,p,sd,j,fID,pxf,pxp), SIM(sim) {}


Computer::Computer(std::string mod, std::string prod, std::string dim, std::string proc, std::string so, int ram, int mem, double p, bool touch, bool cd, int usb) :
    Device(mod,prod,dim,proc,so,ram,mem,p), touchscreen(touch), lettoreCD(cd), porteUSB(usb) {}

Portatile::Portatile(std::string mod, std::string prod, std::string dim, std::string proc, std::string so, int ram, int mem, double p, bool touch, bool cd, int usb, bool ete, bool cam, bool luce, int pxw) :
    Device(mod,prod,dim,proc,so,ram,mem,p), Computer(mod,prod,dim,proc,so,ram,mem,p,touch,cd,usb), ethernet(ete), webcam(cam), luceTastiera(luce), pxWebcam(pxw) {}

Fisso::Fisso(std::string mod, std::string prod, std::string dim, std::string proc, std::string so, int ram, int mem, double p, bool touch, bool cd, int usb, bool bl, bool wf) :
    Device(mod,prod,dim,proc,so,ram,mem,p), Computer(mod,prod,dim,proc,so,ram,mem,p,touch,cd,usb), bluetooth(bl), wifi(wf) {}

Convertibile::Convertibile(
        // campi device
        std::string mod, std::string prod, std::string dim, std::string proc, std::string so, int ram, int mem, double p,
        // campi mobile e tablet
        bool sd, bool j, bool fID, int pxf, int pxp, bool sim,
        // campi computer e portatile
        bool touch, bool cd, int usb, bool ete, bool cam, bool luce, int pxw,
        // campi propri
        bool pen, bool stacca
        ) :
    Device(mod,prod,dim,proc,so,ram,mem,p),
    Tablet(mod,prod,dim,proc,so,ram,mem,p,sd,j,fID,pxf,pxp,sim),
    Portatile(mod,prod,dim,proc,so,ram,mem,p,touch,cd,usb,ete,cam,luce,pxw),
    penna(pen), staccaTastiera(stacca) {}

/********************* GET ********************/

std::string Device::getModello() const { return modello; }
std::string Device::getProduttore() const { return produttore; }
std::string Device::getDimensioneSchermo() const { return dimensioneSchermo; }
std::string Device::getProcessore() const { return processore; }
std::string Device::getSistemaOperativo() const { return sistemaOperativo; }
int Device::getMemoriaRam() const { return memoriaRam; }
int Device::getMemoria() const { return memoria; }
double Device::getPrezzo() const { return prezzo; }

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

/********************* SET ********************/

void Device::setModello(std::string m) {modello = m;}
void Device::setProduttore(std::string p) {produttore = p;}
void Device::setDimensioneSchermo(std::string d) {dimensioneSchermo = d;}
void Device::setProcessore(std::string p) {processore = p;}
void Device::setSistemaOperativo(std::string so) {sistemaOperativo = so;}
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

