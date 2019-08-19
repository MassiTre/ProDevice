#include "device.h"

/*** costruttore ***/
Device::Device(std::string path, std::string mod, std::string prod, std::string dim, std::string proc, int ram, int mem, double p) :
    pathImmagine(path), modello(mod), produttore(prod), dimensioneSchermo(dim), processore(proc), memoriaRam(ram), memoria(mem), prezzo(p) {}

/*** metodi get ***/
std::string Device::getPathImmagine() const{ return pathImmagine; }
std::string Device::getModello() const { return modello; }
std::string Device::getProduttore() const { return produttore; }
std::string Device::getDimensioneSchermo() const { return dimensioneSchermo; }
std::string Device::getProcessore() const { return processore; }
int Device::getMemoriaRam() const { return memoriaRam; }
int Device::getMemoria() const { return memoria; }
double Device::getPrezzo() const { return prezzo; }

/*** metodi set ***/
void Device::setPathImmagine(std::string path) { pathImmagine = path; }
void Device::setModello(std::string m) {modello = m;}
void Device::setProduttore(std::string p) {produttore = p;}
void Device::setDimensioneSchermo(std::string d) {dimensioneSchermo = d;}
void Device::setProcessore(std::string p) {processore = p;}
void Device::setMemoriaRam(int ram) {memoriaRam = ram;}
void Device::setMemoria(int m) {memoria = m;}
void Device::setPrezzo(double p) {prezzo = p; }

/*** overloading operatore uguaglianza ***/
bool Device::operator==(const Device& d) const {
    return modello == d.modello && produttore == d.produttore;
}

/*********** stampa specifiche *************/
std::string Device::stampaSpecifiche() const{
    std::string str = "";
    return str.append(" Modello: " + getModello())
            .append("     Produttore: " + getProduttore())
            .append("\n Schermo: " + getDimensioneSchermo())
            .append("     Prcessore: " + getProcessore())
            .append("\n Ram: " + std::to_string(getMemoriaRam()) + " GB")
            .append("     Memoria: " + std::to_string(getMemoria()) + " GB");
}
