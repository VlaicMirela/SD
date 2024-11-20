#include "collectionB.h"
#include <string>
#include <bits/stdc++.h>
using namespace std;

CollectionB::CollectionB()
{

}


CollectionB::~CollectionB()
{
}


CollectionB::CollectionB(const CollectionB &collection)
{
    this -> bancnote = collection.bancnote;
}


CollectionB& CollectionB::operator=(const CollectionB &collection)
{
    this -> bancnote = collection.bancnote;
    return *this;
}

void CollectionB::adauga(std::pair<int, int> bac)
{
    int gasit=0;
    for (int i = 0; i < this->bancnote.size(); i++)
    {
        if(this->bancnote[i].first == bac.first)
        {
            gasit=1;
            this->bancnote[i].second = this->bancnote[i].second + bac.second;
        }
    }
    if(!gasit)
        this -> bancnote.push_back(bac);
}

void CollectionB::remove(unsigned int index)
{
    for (int i = 0; i < this->bancnote.size(); i++)
    {
        if(this->bancnote[i].first == index)
        {
            this -> bancnote.erase(index);
        }
    }
    if(index < this -> bancnote.size())
    {
        this -> bancnote.erase(index);
    }
}

List<std::pair<int, int>> CollectionB::getList()
{
    return this -> bancnote;
}


void CollectionB::eliminare(unsigned int index, int value) {
    this -> bancnote[index].second = this -> bancnote[index].second-value;
    if(this -> bancnote[index].first == 0)
        remove(index);
}
