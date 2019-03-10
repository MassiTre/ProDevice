#ifndef MODELLO_H
#define MODELLO_H

#include <Gerarchia/gerarchia.h>
#include <Qonteiner/qonteiner.h>

class Modello
{
    private:
        Container<Device*>* list;
        std::string path;
        bool salvataggio;
    public:
        Modello(std::string = "../Salvataggio dati/Catalogo.xml");
        ~Modello();

        void salva(); //Salvataggio dei dati
        void carica(); //Caricamento dei dati
        void setNuovaPath(std::string);
        bool getSalvataggio() const;
        void setSalvataggio(bool);
        Container<Device*>::iterator it_begin();
        Container<Device*>::iterator it_end();
        Container<Device*>::constiterator cit_begin() const;
        Container<Device*>::constiterator cit_end() const;

        Container<Device*>* getList() const;
};

#endif // MODELLO_H
