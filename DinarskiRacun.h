#ifndef PROGRAMI_DINARSKIRACUN_H
#define PROGRAMI_DINARSKIRACUN_H

#include "Racun.h"

class DinarskiRacun : public Racun {
private:
    static const string oznaka;
public:
    DinarskiRacun(Osoba& vlasnik, int brojRacuna) : Racun(vlasnik, brojRacuna) {}

    const string& dohvOznaku() const override { return oznaka; }
    bool prenos(Racun& racun, double iznos) override;
};


#endif //PROGRAMI_DINARSKIRACUN_H
