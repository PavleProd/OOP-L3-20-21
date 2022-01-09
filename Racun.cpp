//
// Created by pavle on 09-Jan-22.
//

#include "Racun.h"

bool Racun::prenos(Racun &racun, double iznos) {
    if(stanje < iznos) return false;

    stanje-=iznos;
    racun.stanje += iznos;
    return true;
}

