//
// Created by pavle on 09-Jan-22.
//

#include "DevizniRacun.h"

const string DevizniRacun::oznaka = "EUR";
double DevizniRacun::srednjiKurs = 118.5;

bool DevizniRacun::prenos(Racun &racun, double iznos) {
    if(stanje < iznos) return false;

    stanje -= iznos;
    if(racun.dohvOznaku() == "RSD") {
        racun += iznos * dohvKurs();
    }
    else {
        racun += iznos;
    }

    return true;
}
