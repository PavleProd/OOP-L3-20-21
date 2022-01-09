//
// Created by pavle on 09-Jan-22.
//

#include "Klijent.h"
#include "Greske.h"

Racun &Klijent::dohvRacun(int brRacuna) const {
    for(racuni.naPrvi(); racuni.postojiTekuci(); racuni.naSledeci()) {
        if(brRacuna == racuni.dohvTekuci()->dohvBrojRacuna()) {
            return *racuni.dohvTekuci();
        }
    }

    throw GRacunNePostoji();
}

void Klijent::ispis(ostream &os) const {
    Osoba::ispis(os);
    os << "\n";
    for(racuni.naPrvi(); racuni.postojiTekuci(); racuni.naSledeci()) {
        os << *racuni.dohvTekuci() << "\n";
    }
}
