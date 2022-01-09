#ifndef PROGRAMI_RACUN_H
#define PROGRAMI_RACUN_H

#include "Osoba.h"

class Racun {
private:
    Osoba *vlasnik;
    int brojRacuna;
protected:
    double stanje = 0.;
    void ispis(ostream& os) const {
        os << "R:" << brojRacuna << ":=:" << stanje << "-" << dohvOznaku();
    }
public:
    Racun(Osoba& vlasnik_, int brojRacuna_) : vlasnik(&vlasnik_), brojRacuna(brojRacuna_) {}
    Racun(const Racun&) = delete;
    Racun& operator=(const Racun&) = delete;

    Osoba* dohvVlasnika() const {
        return vlasnik;
    }

    int dohvBrojRacuna() const {
        return brojRacuna;
    }

    double dohvStanje() const {
        return stanje;
    }

    virtual bool prenos(Racun& racun, double iznos);

    virtual const string& dohvOznaku() const = 0;

    friend ostream& operator<<(ostream& os, const Racun& racun) {
        racun.ispis(os);
        return os;
    }

    Racun& operator+=(double iznos) {
        stanje += iznos;
        return *this;
    }
};


#endif //PROGRAMI_RACUN_H
