#include "node.h"

#ifndef CURS7_P_LIST_H
#define CURS7_P_LIST_H
#include <iostream>
using namespace std;

template <class T>
class List {
private:
    /* definiti o reprezentare inlantuita pe elementele din lista */
    Node<T>* first;

public:
    /// constructor implicit
    List () {
        this->first=nullptr;
    }

    /// \return dimensiunea listei
    int size() const;

    ///  verifica daca lista e vida
    /// \return true, daca lista e vida, altfel returneaza false
    bool is_empty() const;

    /// adaugare element la sfarsit
    /// \param e - elementul adaugat
    void push_back(T e);

    ///
    /// \param i - pozitia unui elem in lista , 0<=i<size()
    /// \return  elementul de pe pozitia i
    /// \raise   exceptie daca i nu e valid
    T get_at(int i) const;

    // modifica element de pe pozitia i si returneaza vechea valoare
    //arunca exceptie daca i nu e valid
    T update(int i, T e);



    // adaugare element pe o pozitie i
    //arunca exceptie daca i nu e valid
    //void set_at(int i, T e);

    // sterge element de pe o pozitie i si returneaza elementul sters
    //arunca exceptie daca i nu e valid
    //T delete_at(int i);

    // cauta element si returneaza prima pozitie pe care apare (sau -1)
    //int search(T e)  const;

    // returnare iterator
//    Iterator iterator() const;

    ///
    /// destructor
    ~List();

    T erase(int i);

    void set_at(int i, T e);

    T search(int e) const;

    void push_front(T e);
    T& operator[](int i);
    bool operator==(const List& list);
    T& operator=(const List& list);

    Node<T> * end();

    Node<T> * begin();
};

template <class T>
T& List<T>:: operator[](int i) {
    if(i < 0 || i >= size())
        throw invalid_argument("pozitia nu e valida");
    Node<T>* crt = first;
    int noE = 0;
    while (noE < i){
        crt = crt->next;
        noE++;
    }
    return crt->info;
}

template <class T>
T& List<T>:: operator=(const List& list) {
    first = list.first;
}

template <class T>
bool List<T>:: operator==(const List& list) {
    Node<T>* crt1 = first, crt2 = list.first;
    if(list.size() != size())
        return 0;
    while(crt1 != nullptr and crt2 != nullptr) {
        if(crt1 != crt2)
            return 0;
        crt1 = crt1->next;
        crt2 = crt2->next;
    }
    return 1;
}

template<class T>
T List<T>::update(int i, T e) {
    if(i < 0 || i >= size())
        throw invalid_argument("pozitia nu e valida");
    Node<T>* crt = first;
    int noE = 0;
    while (noE < i){
        crt = crt->next;
        noE++;
    }
    T old_value = crt->info;
    crt->info = e;

    return old_value;
}

template<class T>
T List<T>::get_at(int i) const {
    if(i < 0 || i >= size())
        throw invalid_argument("pozitia nu e valida");
    Node<T>* crt = first;
    int noE = 0;
    while (noE < i){
        crt = crt->next;
        noE++;
    }
    return crt->info;
}

template<class T>
void List<T>::push_back(T e) {
    Node<T>* newNode = new Node<T>(e, nullptr, nullptr);
    if(first == nullptr){
        first = newNode;
    }
    else{
        Node<T>* last=first;
        while (last->next != nullptr){
            last= last->next;
        }
        newNode->prev = last;
        last->next = newNode;
    }
}

template<class T>
void List<T>::push_front(T e) {
    Node<T>* newNode = new Node<T>(e, nullptr, nullptr);
    if(first == nullptr){
        first = newNode;
    }
    else
    {
        Node<T>* last=first;
        newNode->next = last;
        last->prev = newNode;
        first = newNode;
    }
}

template<class T>
T List<T>::erase(int i) {
    if (i < 0 || i >= size())
        throw invalid_argument("pozitia nu e valida");

    if(i == 0) {
        first = first->next;
        if(first != nullptr)
            first->prev = nullptr;
    }
    else {
        int nr = 0;
        Node<T>* crt = first;
        while(nr < i) {
            nr++;
            crt = crt->next;
        }
        crt->prev->next = crt->next;
        if(crt->next != nullptr)
            crt->next->prev = crt->prev;
    }
}

template<class T>
bool List<T>::is_empty() const {
    return first == nullptr;
}

template<class T>
int List<T>::size() const {
    int contor = 0;
    Node<T>* last = first;
    while(last != nullptr)
    {
        contor++;
        last = last->next;
    }
    return contor;
}

template<class T>
List<T>::~List() {
    //parcurgem lista inlantuita pana nu mai avem elemente in ea
    while(first != nullptr) {
        Node<T>* temp = first; //salvam first intr un nod temporar
        first = first->next; //ne deplasam pe urmatorul element din lista(dupa first)
        delete temp; //eliminam nodul temporar(vechiul first)
    }
}

template<class T>
void List<T>::set_at(int i, T e) {
    Node<T> *newNode = new Node<T>(e, nullptr, nullptr);

    if (i < 0 || i >= size())
        throw invalid_argument("pozitia nu e valida");
    int cont = 0;
    Node<T> *crt = first;
    if (i != 0) {
        while (cont < i) {
            cont++;
            crt = crt->next;
        }

        newNode->next = crt->next;
        crt->next = newNode;
    } else {
        newNode->next = crt;
        crt = newNode;
    }
}

template<class T>
T List<T>::search(int e) const {int nr=0;
    Node<T>* crt = first;
    while(crt!= nullptr) {
        crt = crt->next;
        nr++;
        if(crt->info==e)
            return nr;
    }
    return -1;

}

template <class T>
Node<T> * List<T>::begin() {
    return first;
}

template <class T>
Node<T> * List<T>::end() {
    Node<T>* crt = first;
    while(crt->next != nullptr) {
        crt = crt->next;
    }
    return crt;
}

#endif //CURS7_P_LIST_H
