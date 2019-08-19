#include "gestioneeccezione.h"

GestioneEccezione::GestioneEccezione(std::string e) : eccezione(e) {}

std::string GestioneEccezione::getEccezione() const { return eccezione; }


void GestioneEccezione::stampaEccezione() const {
    std::cout << "Errore: " << getEccezione() << std::endl;
}
