
// Created by Spaca on 4/6/2023.
//

#ifndef LAB2SD_TRANZACTIE_H
#define LAB2SD_TRANZACTIE_H
#include "../LinkedList/list.h"
#include<string>
#include "../bancnote/collectionB.h"


class Tranzactie {
private:
    int idTranzactie,suma;
    List<std::pair<int, int>> elemente;
public:
    Tranzactie();
    Tranzactie(int idTranzactie, int suma, List<std::pair<int, int>> elemente);
    Tranzactie(const Tranzactie& tranzactie);
    ~Tranzactie();
    int getidTranzactie() const;
    int getsuma() const;
    List<std::pair<int, int>> getElemente();
    void setidTranzactie(int idTranzactie);
    void setSuma(int suma);
    void setElemente(List<std::pair<int, int>> elemente);
};

#endif //LAB2SD_TRANZACTIE_H
