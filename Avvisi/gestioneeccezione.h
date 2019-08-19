#ifndef GESTIONEECCEZIONE_H
#define GESTIONEECCEZIONE_H

#include <iostream>
#include <string>

class GestioneEccezione {
private:
    std::string eccezione;
public:
    GestioneEccezione(std::string);
    std::string getEccezione() const;
    void stampaEccezione() const;
};

#endif // GESTIONEECCEZIONE_H
