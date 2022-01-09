#ifndef PROGRAMI_TRANSAKCIJA_H
#define PROGRAMI_TRANSAKCIJA_H

#include "Racun.h"
#include "Datum.h"

class Transakcija {
private:
    Racun *racun1, *racun2;
    Datum datum;
    double iznos;
    bool uspesna;
public:
    Transakcija(Racun& racun1_, Racun& racun2_, double iznos_, const Datum& datum_) : datum(datum_){
        racun1 = &racun1_;
        racun2 = &racun2_;
        iznos = iznos_;
        uspesna = racun1->prenos(*racun2, iznos);
    }

    Transakcija& operator~() {
        uspesna = false;
        return *this;
    }

    Racun *dohvRacun1() const {
        return racun1;
    }

    Racun *dohvRacun2() const {
        return racun2;
    }

    const Datum &dohvDatum() const {
        return datum;
    }

    double dohvIznos() const {
        return iznos;
    }

    bool operator*() const {
        return uspesna;
    }

    friend ostream& operator<<(ostream& os, const Transakcija& t) {
        os << *t.racun1 << "->" << *t.racun2 << ":" << t.iznos << "-" << t.datum << "-" << t.uspesna;
        return os;
    }
};


#endif //PROGRAMI_TRANSAKCIJA_H
