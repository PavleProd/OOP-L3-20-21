#ifndef PROGRAMI_EVIDENCIJA_H
#define PROGRAMI_EVIDENCIJA_H

#include "Klijent.h"
#include "Transakcija.h"

class Evidencija : public Lista<Klijent*> {
private:
    string banka;
    Lista<Transakcija*> transakcije;
public:
    Evidencija(string banka_) : banka(move(banka_)) {}

    Evidencija& dodajTransakciju(Transakcija& transakcija);
    Lista<Transakcija*> dohvUspesneTransakcije(const Datum& datumTransakcija);

    friend ostream& operator<<(ostream& os, const Evidencija& evidencija);
};


#endif //PROGRAMI_EVIDENCIJA_H
