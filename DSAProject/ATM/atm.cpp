#include "atm.h"
#include <iostream>
#include<cstdlib>
using namespace std;

ATM::ATM() {

}

ATM::~ATM(){


void ATM::afisare(List<List<int>>& rezultat) {
    int nr=0;
    for (int i =0; i < rezultat.size(); i++) {
        List<std::pair<int, int>> numar;
        for (int j = 0; j < rezultat[i].size(); j++) {
            bool gasit = false;
            for (int k = 0; k < numar.size(); k++) {
                if (numar[k].first == rezultat[i][j]) {
                    numar[k].second++;
                    gasit = true;
                    break;
                }
            }
            if (!gasit) {
                numar.push_back({rezultat[i][j], 1});
            }
        }
        cout<<++nr<<". ";
        for (int j = 0; j < numar.size(); j++) {
            cout<< numar[j].second << " bancnote de " << numar[j].first << ", ";
        }
        cout << endl;
    }
}


void ATM::adaugareBancnote() {
    bool continua = 1;
    do {
        cout << "Tipul de bancnota ce trebuie adaugata: ";
        int currency;
        cin >> currency;
        cout << "Numarul de bancnote adaugate: ";
        int value;
        cin >> value;
        cout << endl;
        std::pair<int, int> bac;
        bac.first = currency;
        bac.second = value;
        this->banca.adauga(bac);
        cout << "Doriti sa mai adaugati bancnote\n"<<"0 sau 1: ";
        cin >> continua;
    }while(continua == 1);
}

void ATM::tranzactieAutomata(List<std::pair<int, int>>& bani, int sum, int& confirmare) {
        int total = 0;
        List<std::pair < int, int>>
        lista = this->banca.getList();
        for (int it = 0; it < lista.size(); it++) {
            int currency = lista[it].first, value;
            if (lista[it].second * lista[it].first > sum)
                value = sum / lista[it].first;
            else
                value = lista[it].second;
            if (currency * value > 0) {
                std::pair<int, int> bac;
                bac.first = currency;
                bac.second = value;
                total += currency * value;
                bani.push_back(bac);
                this->banca.eliminare(it, value);
                sum = sum - currency * value;
            }
        }
        if (sum != 0) {
            cout << "Bancomatul nu dispune de suma ceruta\n";
            confirmare = 0;
        } else {
            cout << "doresti sa fi platit in acest mod?\n";
            for (int i = 0; i < bani.size(); i++)
                cout << "bancnota: " << bani[i].first << " numarul lor: " << bani[i].second << endl;
            cout << "0 sau 1: ";
            cin >> confirmare;
            cout << endl;
        }
    }


void ATM::tranzactie() {
    srand((unsigned) time(NULL));
    int random = rand();
    int id = random, confirmare = 1, optiune, suma;

    cout << "Adaugare suma dorita: ";
    cin >> suma;
    cout << "Doriti suma de bani sa fie selectata \n 1.in mod automat \n sau \n 2.doriti sa faceti aceasta selectie manual?\n"
         << "1 sau 2: ";
    cin >> optiune;
    cout << endl;
    List<std::pair<int, int>> bani;

    if(optiune == 1) {
        this->tranzactieAutomata(bani, suma, confirmare);
    }
    else {
    }

    if (confirmare) {
        Tranzactie tranzactie1 = Tranzactie(id, suma, bani);
        tranzactii.push_back(tranzactie1);
        cout<<"Tranzactie reusita!\n";
    }
}

void ATM::afisareTranzactii() {
    for(int i = 0; i < this->tranzactii.size(); i++){
        cout << "\nid: "<<this->tranzactii[i].getidTranzactie()
             << " suma: "<<this->tranzactii[i].getsuma()<<endl
             << "bancnote folosite: "<<endl;
        for(int j = 0; j < this->tranzactii[i].getElemente().size(); j++)
            cout << "bancnota: " << this->tranzactii[i].getElemente()[j].first
                 <<" numarul lor: "<<this->tranzactii[i].getElemente()[j].second<<endl;
    }
    cout<<endl;
}

void ATM::menu() {
    bool rulare = true;
    while(rulare) {
        cout << endl
             << "1. Adaugare bancnote \n"
             << "2. Inregistrare tranzactie \n"
             << "3. Afisare tranzactii\n"
             << "0. Inchiderea aplciatie \n"
             <<"\n Alege optiune: ";

        int optiune;
        cin >> optiune;

        switch (optiune) {

            case 1: {
                adaugareBancnote();
                List<std::pair<int, int>> lista = this->banca.getList();
                cout<<"Au fost adaugate bancnotele: \n";
                for(int i = 0; i < lista.size();i++)
                    cout<<lista[i].first<<" "<<lista[i].second<<endl;
                break;
            }
            case 2: {
                this->tranzactie();
                break;
            }
            case 3: {
                this->afisareTranzactii();
                break;
            }
            case 0:
            {
                rulare = false;
                break;
            }
            default:
                break;
        }
    }
}