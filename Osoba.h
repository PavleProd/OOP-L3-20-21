#ifndef PROGRAMI_OSOBA_H
#define PROGRAMI_OSOBA_H

#include <string>
#include <iostream>

#include "Datum.h"

using namespace std;

class Osoba {
private:
    string ime, maticniBroj;
    Datum datumRodjenja;
protected:
    virtual void ispis(ostream& os) const {
        os << "O(" << ime << "," << maticniBroj << "," << datumRodjenja << ")";
    }
public:
    Osoba(string ime_, string maticniBroj_, const Datum datumRodjenja_)
        : ime(move(ime_)), maticniBroj(move(maticniBroj_)), datumRodjenja(datumRodjenja_) {}
    Osoba(const Osoba&) = delete;
    Osoba& operator=(const Osoba&) = delete;

    friend ostream& operator<<(ostream& os, const Osoba& osoba) {
        osoba.ispis(os);
        return os;
    }

    const string &dohvIme() const {
        return ime;
    }

    const string &dohvMaticniBroj() const {
        return maticniBroj;
    }

    const Datum &dohvDatumRodjenja() const {
        return datumRodjenja;
    }
};


#endif //PROGRAMI_OSOBA_H
