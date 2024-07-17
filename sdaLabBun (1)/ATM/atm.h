#ifndef LAB2SD_MENIU_H
#define LAB2SD_MENIU_H
#include "../tranzactie/tranzactie.h"
#include "../bancnote/collectionB.h"
#include "../LinkedList/list.h"
#include "../ATM/backtracing/Backtracking.h"
class ATM {
private:
    List<Tranzactie> tranzactii;
    CollectionB banca = CollectionB();
    void afisare(List<List<int>> &rezultat);
    void tranzactieAutomata(List<std::pair<int, int>> &bani, int sum, int& confirmare);
    void tranzactieManuala(List<std::pair<int, int>> &bani, int sum);
public:
    ATM();
    ~ATM();
    void adaugareBancnote();
    void menu();
    void tranzactie();
    void afisareTranzactii();

    List<List<int>>
    getAllCombinations(List<int> bancnote, List<int> numar, int target);

    void findCombinations(List<int> &bancnote, List<int> &numar, int target, List<int> &curr,
                          List<List<int>> &res, int pos);

    void afisare(List<List<int>> &rezultat, List<int> banknotes);
};

#endif //LAB2SD_MENIU_H
