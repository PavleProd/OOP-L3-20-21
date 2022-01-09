//
// Created by pavle on 09-Jan-22.
//

#include "DinarskiRacun.h"
#include "DevizniRacun.h"

const string DinarskiRacun::oznaka = "RSD";

bool DinarskiRacun::prenos(Racun &racun, double iznos) {
    if(stanje < iznos) return false;

    stanje -= iznos;
    if(racun.dohvOznaku() == "EUR") {
        racun += iznos / DevizniRacun::dohvKurs();
    }
    else {
        racun += iznos;
    }

    return true;
}
