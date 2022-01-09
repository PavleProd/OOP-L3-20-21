#ifndef PROGRAMI_LISTA_H
#define PROGRAMI_LISTA_H

#include "Greske.h"

template<typename T>
class Lista {
private:
    struct Elem {
        T podatak;
        Elem* sled;
        explicit Elem(const T& podatak_) : podatak(podatak_), sled(nullptr) {}
    };

    Elem *prvi, *posl;
    mutable Elem *tek, *pret;

    int brojElemenata = 0;

    void kopiraj(const Lista& lista), premesti(Lista& lista), oslobodi();
public:
    Lista() {
        prvi = posl = tek = pret = nullptr;
    }
    Lista(const Lista& lista) { kopiraj(lista); }
    Lista(Lista&& lista) { premesti(lista); }
    ~Lista() { oslobodi(); }
    Lista& operator=(const Lista& lista);
    Lista& operator=(Lista&& lista);

    int dohvBrojElemenata() const {
        return brojElemenata;
    }
    bool postojiTekuci() const {
        return tek != nullptr;
    }
    const Lista& naPrvi() const;
    const Lista& naSledeci() const;

    T& dohvTekuci() const;
    Lista& obrisiTekuci();
    T& dohvTekuci() {
        return (const_cast<const Lista&>(*this)).dohvTekuci();
    }

    Lista& operator+=(const T& podatak);

};

template<typename T>
Lista<T> &Lista<T>::operator+=(const T &podatak) {
    Elem *elem = new Elem(podatak);
    if(!prvi) {
        prvi = posl = elem;
    }
    else {
        posl->sled = elem;
        posl = elem;
    }
    brojElemenata++;
    return *this;
}

template<typename T>
const Lista<T> &Lista<T>::naPrvi() const {
    tek = prvi;
    pret = nullptr;
    return *this;
}

template<typename T>
const Lista<T> &Lista<T>::naSledeci() const {
    pret = tek;
    if(tek) {
        tek = tek->sled;
    }
    return *this;
}

template<typename T>
T &Lista<T>::dohvTekuci() const {
    if(!postojiTekuci()) throw GTekuciNePostoji();

    return tek->podatak;
}

template<typename T>
Lista<T> &Lista<T>::obrisiTekuci() {
    if(!postojiTekuci()) throw GTekuciNePostoji();

    Elem *old = tek;
    if(tek == prvi) {
        prvi = tek->sled;
    }
    else if(tek == posl) {
        posl = pret;
    }
    tek = tek->sled;

    delete old;
    return *this;
}

template<typename T>
Lista<T> &Lista<T>::operator=(const Lista &lista) {
    if(this != *lista) {
        oslobodi();
        kopiraj(lista);
    }

    return *this;
}

template<typename T>
Lista<T> &Lista<T>::operator=(Lista &&lista) {
    if(this != *lista) {
        oslobodi();
        premesti(lista);
    }

    return *this;
}

template<typename T>
void Lista<T>::kopiraj(const Lista<T> &lista) {
    brojElemenata = lista.brojElemenata;
    prvi = posl = tek = pret = nullptr;
    for(Elem *tren = lista.prvi; tren; tren = tren->sled) {
        Elem *elem = new Elem(tren->podatak);
        if(!prvi) {
            prvi = posl = elem;
        }
        else {
            posl->sled = elem;
            posl = elem;
        }
        if(lista.tek == tren) tek = tren;
        if(lista.pret == tren) pret = tren;
    }
}

template<typename T>
void Lista<T>::premesti(Lista<T> &lista) {
    brojElemenata = lista.brojElemenata;
    prvi = lista.prvi;
    posl = lista.posl;
    tek = lista.tek;
    pret = lista.pret;

    lista.prvi = lista.posl = lista.tek = lista.pret = nullptr;
    lista.brojElemenata = 0;
}

template<typename T>
void Lista<T>::oslobodi() {
    while(prvi) {
        tek = prvi;
        prvi = prvi->sled;
        delete tek;
    }
    prvi = posl = tek = pret = nullptr;
    brojElemenata = 0;
}


#endif //PROGRAMI_LISTA_H
