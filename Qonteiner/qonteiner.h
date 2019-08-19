#ifndef QONTAINER_H
#define QONTAINER_H

// Template contenitore
template<class T>
class Container{
private:
    class Nodo;

    class SmartP{
        friend class constiterator;
    public:
        Nodo* punt;
        SmartP(Nodo* p = 0);
        SmartP(const SmartP&);
        ~SmartP();
        SmartP& operator=(const SmartP&);
        Nodo& operator*() const;
        Nodo* operator->() const;
        bool operator==(const SmartP&) const;
        bool operator!=(const SmartP&) const;
    };

    static SmartP copy(const SmartP&, const SmartP&);

    class Nodo{
    public:
        T info; // Device
        SmartP prev, next;
        int riferimenti;
        Nodo(const T& =0, const SmartP& = 0, const SmartP& =0);
        Nodo();
    };

    SmartP primo;
    SmartP ultimo;

public:

    /*** inserimeto ***/
    void insertFront(const T&);
    void insertBack(const T&);

    class constiterator { /*** iteratore costrante ***/
      private:
        const SmartP* pt;
        bool pte;
      public:
        constiterator();
        constiterator(const SmartP* =nullptr, bool =false);
        constiterator(const constiterator&);
        constiterator& operator++();
        constiterator& operator--();
        const T operator*() const;
        const T operator->() const;
        bool operator==(const constiterator&) const;
        bool operator!=(const constiterator& x) const;
      };

    class iterator { /*** iteratore (NON constante) ***/
      private:
         SmartP* pt;
        bool pte;
      public:
        iterator();
        iterator(SmartP* = nullptr, bool = false);
        iterator(const iterator&);
        iterator& operator++();
        iterator& operator--();
        T operator*() const;
        T operator->() const;
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;
      };

    void elimina(const T&);

    iterator it_begin() ;
    iterator it_end() ;

    constiterator cit_begin() const;
    constiterator cit_end() const;

    T cerca(const T&) const;
};


/***** SmartP *****/

template<class T>
Container<T>::SmartP::SmartP(Nodo* p) : punt(p) { if(punt) punt->riferimenti++; }

template<class T>
Container<T>::SmartP::SmartP(const SmartP& s) : punt(s.punt) { if(punt) punt->riferimenti++; }

template<class T>
Container<T>::SmartP::~SmartP() {
    if(punt){
        punt->riferimenti--;
        if(punt->riferimenti == 0)
            delete punt;
    }
}

template<class T>
typename Container<T>::SmartP& Container<T>::SmartP::operator=(const SmartP& s){
    if(this != &s){
        Nodo* t = punt;
        punt = s.punt;
        if(punt) punt->riferimenti++;
        if(t){
            t->riferimenti--;
            if(t->riferimenti == 0) delete t;
        }
    }
    return *this;
}

template<class T>
typename Container<T>::Nodo& Container<T>::SmartP::operator*() const{ return *punt; }

template<class T>
typename Container<T>::Nodo* Container<T>::SmartP::operator->() const{ return (punt); }

template<class T>
bool Container<T>::SmartP::operator==(const SmartP& p) const{ return punt == p.punt; }

template<class T>
bool Container<T>::SmartP::operator!=(const SmartP& p) const{ return punt != p.punt; }

template<class T>
typename Container<T>::SmartP Container<T>::copy(const SmartP& fst, const SmartP& lst) {
    if(fst == nullptr) return lst = 0;
        SmartP f = new Nodo(fst->info,nullptr,nullptr), p = f;
        while(fst->next != nullptr) {
            p->next = new Nodo(fst->next->info,p,nullptr);
            fst = fst->next;
            p=p->next;
           }
    lst=p;
    return f;
}

/***** Container *****/

template<class T>
void Container<T>::insertFront(const T& t){
    primo = new Nodo(t, nullptr, primo);

        if(ultimo == nullptr){
            ultimo = primo;

        }
        else (primo->next)->prev = primo;
}

template<class T>
void Container<T>::insertBack(const T& t){
    ultimo = new Nodo(t, ultimo, nullptr);

        if(primo == nullptr){
            primo = ultimo;
            }
        else (ultimo->prev)->next = ultimo;
}

template<class T>
typename Container<T>::constiterator Container<T>::cit_begin() const{
    if(primo == nullptr) return constiterator(nullptr);
    return constiterator(&primo, false); }

template<class T>
typename Container<T>::constiterator Container<T>::cit_end() const{
    if( primo == nullptr ) return constiterator(nullptr);
    return constiterator(&(ultimo->next), true);
}

template<class T>
typename Container<T>::iterator Container<T>::it_begin() {
    if(primo == nullptr) return iterator(nullptr);
    return iterator(&primo, false);
}

template<class T>
typename Container<T>::iterator Container<T>::it_end() {
    if( primo == nullptr ) return iterator(nullptr);
    return iterator(&(ultimo->next), true);;
}

template<class T>
T Container<T>::cerca(const T& ric) const {

    constiterator cit = cit_begin();
    for( ; cit != cit_end(); ++cit) {
        if(*(*cit) == *ric) {
            return *cit;
        }
    }
    return nullptr;
}

template<class T>
void Container<T>::elimina(const T& s){
    SmartP p = primo; //p scorre la lista
    SmartP precedente = nullptr; //prev è il nodo che precede quello puntato da p
    SmartP q; //Punta al nodo precedente
    SmartP originale = primo; //Qui metto il primo originale
    primo = 0;
    while(p!=0 && !((p.punt)->info == s)){

          q = new Nodo((p.punt)->info, (p.punt)->prev, (p.punt)->next);

          if((p.punt)->prev == nullptr) primo = q;
          else{
                (precedente.punt)->next = q;
                (q.punt)->prev = precedente;
          }

          precedente = q;
          p = p.punt->next;
    }

    if(p == 0) { primo = originale; }
    else {
            if(precedente == nullptr && (p.punt)->next == nullptr) primo = ultimo = nullptr;
            else{
                if(precedente == nullptr){
                    primo = (p.punt)->next;
                    (primo.punt)->prev = nullptr;
                }
                else{
                    if(p->next!=nullptr){
                        (precedente.punt)->next = (p.punt)->next;
                        (p.punt)->next->prev = precedente; }
                    else{
                        (precedente.punt)->next = (p.punt)->next;
                        ultimo = precedente;
                        }
                    }
                }
    }
}

/***** Nodo *****/

template <class T>
Container<T>::Nodo::Nodo(const T& t, const SmartP& p, const SmartP& n): info(t), prev(p), next(n), riferimenti(0) {}

template<class T>
Container<T>::Nodo::Nodo(): riferimenti(0) {}

/***** iteratore costante *****/

template<class T>
Container<T>::constiterator::constiterator() : pt(nullptr), pte(false) {}

template<class T>
Container<T>::constiterator::constiterator(const SmartP* p, bool pastEnd) : pt(p), pte(pastEnd) {}

template<class T>
Container<T>::constiterator::constiterator(const constiterator& cit) : pt(cit.pt), pte(cit.pte) {}

template<class T>
typename Container<T>::constiterator& Container<T>::constiterator::operator++(){
    if(!pte && pt != 0){
        if((*pt)->next == nullptr) {
            pt = &((*pt)->next);
            pte=true;
        }
        else pt = &((*pt)->next);
    }
    return *this;
}

template<class T>
typename Container<T>::constiterator& Container<T>::constiterator::operator --(){
    if(pte){
        pt = &((*pt)->prev);
        pte = false;
    }
    else{
        if(pt) &((*pt)->next);
    }
    return *this;
}

template<class T>
const T Container<T>::constiterator::operator* () const { return ((**pt).info); }

template<class T>
const T Container<T>::constiterator::operator->() const { return &((**pt).info); }

template<class T>
bool Container<T>::constiterator::operator==(const constiterator& x) const{ return pt == x.pt; }

template<class T>
bool Container<T>::constiterator::operator!=(const constiterator& x) const{ return pt != x.pt; }

/***** iteratore *****/

template<class T>
Container<T>::iterator::iterator() : pt(nullptr), pte(false) {}

template<class T>
Container<T>::iterator::iterator( SmartP* p, bool passEnd) : pt(p), pte(passEnd) {}

template<class T>
Container<T>::iterator::iterator(const iterator& it) : pt(it.pt), pte(it.pte) {}

template<class T>
typename Container<T>::iterator& Container<T>::iterator::operator++(){
    if(!pte && pt != 0){
        if((*pt)->next == nullptr) {
            pt = &((*pt)->next);
            pte = true;
        }
        else pt = &((*pt)->next);
    }
    return *this;
}

template<class T>
typename Container<T>::iterator& Container<T>::iterator::operator--(){
    if(pte){
        pt = &((*pt)->prev);
        pte = false;
    }
    else{
        if(pt) pt = &((*pt)->next);
    }
    return *this;
}

template<class T>
T Container<T>::iterator::operator* () const{ return ((*(*pt)).info); }

template<class T>
T Container<T>::iterator::operator->() const { return &((*(*pt)).info); }

template<class T>
bool Container<T>::iterator::operator==(const iterator& x) const{ return pt == x.pt; }

template<class T>
bool Container<T>::iterator::operator!=(const iterator& x) const{ return pt != x.pt; }

#endif // QONTAINER_H
