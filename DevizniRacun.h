#ifndef PROGRAMI_DEVIZNIRACUN_H
#define PROGRAMI_DEVIZNIRACUN_H

#include "Racun.h"

class DevizniRacun : public Racun {
private:
    static const string oznaka;
    static double srednjiKurs;
public:
    DevizniRacun(Osoba& vlasnik, int brojRacuna) : Racun(vlasnik, brojRacuna) {}

    const string& dohvOznaku() const override { return oznaka; }

    static double dohvKurs() {
        return srednjiKurs;
    }

    static void postKurs(double noviKurs) {
        srednjiKurs = noviKurs;
    }

    bool prenos(Racun& racun, double iznos) override;
};


#endif //PROGRAMI_DEVIZNIRACUN_H
