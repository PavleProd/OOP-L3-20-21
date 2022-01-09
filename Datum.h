#ifndef PROGRAMI_DATUM_H
#define PROGRAMI_DATUM_H

#include <iostream>

class Datum {
private:
    int dan,mesec,godina;
public:
    explicit Datum(int dan_ = 1, int mesec_ = 1, int godina_ = 2021) {
        dan = dan_;
        mesec = mesec_;
        godina = godina_;
    }

    friend bool operator ==(const Datum& datum1, const Datum& datum2) {
        return (datum1.dan == datum2.dan) && (datum1.mesec == datum2.mesec) && (datum1.godina == datum2.godina);
    }

    friend std::ostream& operator<<(std::ostream& os, const Datum& datum) {
        os << datum.dan << "." << datum.mesec << "." << datum.godina << ".";
        return os;
    }
};


#endif //PROGRAMI_DATUM_H
