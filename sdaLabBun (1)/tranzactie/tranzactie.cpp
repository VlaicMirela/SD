#include "tranzactie.h"

Tranzactie::Tranzactie(int idTranzactie, int suma, List<std::pair<int, int>> elemente)
{
    this -> setidTranzactie(idTranzactie);
    this -> setSuma(suma);
    this -> setElemente(elemente);
}

Tranzactie::Tranzactie()
{

}
/* Deconstructor */

Tranzactie::~Tranzactie()
{

}

/* Copy */

Tranzactie::Tranzactie(const Tranzactie& tranzactie)
{
    this -> setidTranzactie(tranzactie.idTranzactie);
    this -> setSuma(tranzactie.suma);
    this -> setElemente(tranzactie.elemente);
}

/* Assign */


/* Getters */

int Tranzactie::getidTranzactie() const
{
    return this -> idTranzactie;
}

int Tranzactie::getsuma() const
{
    return this -> suma;
}

List<std::pair<int, int>> Tranzactie::getElemente()
{
    return this -> elemente;
}

/* Setters */

void Tranzactie::setElemente(List<std::pair<int, int>> elemente)
{
    this -> elemente = elemente;
}

void Tranzactie::setidTranzactie(int idTranzactie)
{
    this -> idTranzactie = idTranzactie;
}

void Tranzactie::setSuma(int suma)
{
    this -> suma = suma;
}
