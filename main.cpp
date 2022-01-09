#include <iostream>
#include <exception>

#include "Datum.h"
#include "Osoba.h"
#include "Racun.h"
#include "DinarskiRacun.h"
#include "DevizniRacun.h"
#include "Lista.h"
#include "Transakcija.h"
#include "Klijent.h"
#include "Evidencija.h"

using namespace std;

int main() {
    try {
        Osoba pp("Pavle Prodanovic", "2409001710101", Datum(24, 9, 2001));

        DinarskiRacun dinR(pp, 0);
        DevizniRacun devR(pp, 1);

        dinR += 500;
        devR += 100;

        Transakcija tr(devR, dinR, 50, Datum(9, 1, 2022));
        cout << tr << "\n";

        Klijent ia("Igor Antonijevic", "jmbg", Datum(15,12,2001));
        DinarskiRacun dinR2(ia, 0);
        DevizniRacun devR2(ia, 1);

        dinR2 += 10000;
        devR2 += 100;

        ia += dinR2;
        ia += devR2;

        Transakcija tr2(devR2, dinR2, 50, Datum(9, 1, 2022));

        Evidencija ev("uniCredit");
        ev += &ia;
        ev.dodajTransakciju(tr2);

        cout << ev << "\n";
    }
    catch(const exception& e) {
        cout << e.what() << "\n";
    }
}
