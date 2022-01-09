#ifndef PROGRAMI_KLIJENT_H
#define PROGRAMI_KLIJENT_H

#include "Osoba.h"
#include "Racun.h"
#include "Lista.h"

class Klijent : public Osoba {
private:
    Lista<Racun*> racuni;
protected:
    void ispis(ostream& os) const override;
public:
    Klijent(string ime, string maticniBroj, const Datum datumRodjenja)
        : Osoba(move(ime), move(maticniBroj), datumRodjenja) {}

    Racun& dohvRacun(int brRacuna) const;

    Klijent& operator+=(Racun& racun) {
        racuni += &racun;
        return *this;
    }
};


#endif //PROGRAMI_KLIJENT_H
