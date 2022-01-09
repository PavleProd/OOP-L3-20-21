#ifndef PROGRAMI_GRESKE_H
#define PROGRAMI_GRESKE_H

#include <exception>

class GTekuciNePostoji : public std::exception {
    const char* what() const noexcept override {
        return "Greska: Tekuci element ne postoji!";
    }
};

class GRacunNePostoji : public std::exception {
    const char* what() const noexcept override {
        return "Greska: Racun sa zadatim brojem ne postoji!";
    }
};

class GKlijentiNePostoje : public std::exception {
    const char* what() const noexcept override {
        return "Greska: Nijedan od klijenata u transakciji ne postoji u banci!";
    }
};


#endif //PROGRAMI_GRESKE_H
