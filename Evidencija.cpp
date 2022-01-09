//
// Created by pavle on 09-Jan-22.
//

#include "Evidencija.h"

ostream &operator<<(ostream &os, const Evidencija &ev) {
    os << ev.banka << "\n";
    for(ev.naPrvi(); ev.postojiTekuci(); ev.naSledeci()) {
        os << *ev.dohvTekuci() << "\n";
    }
    return os;
}

Evidencija &Evidencija::dodajTransakciju(Transakcija &transakcija) {
    bool postojiKlijent = false;
    for(naPrvi(); postojiTekuci(); naSledeci()) {
        if(dohvTekuci() == transakcija.dohvRacun1()->dohvVlasnika() || dohvTekuci() == transakcija.dohvRacun2()->dohvVlasnika()) {
            postojiKlijent = true;
            break;
        }
    }
    if(!postojiKlijent) throw GKlijentiNePostoje();

    transakcije += &transakcija;
    return *this;
}

Lista<Transakcija *> Evidencija::dohvUspesneTransakcije(const Datum &datumTransakcija) {
    Lista<Transakcija*> fTransakcije;
    for(transakcije.naPrvi(); transakcije.postojiTekuci(); transakcije.naSledeci()) {
        if(transakcije.dohvTekuci()->dohvDatum() == datumTransakcija) {
            fTransakcije += transakcije.dohvTekuci();
        }
    }
    return fTransakcije;
}
