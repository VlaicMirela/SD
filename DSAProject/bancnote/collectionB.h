#ifndef SDALAB3_COLLECTIONB_H
#define SDALAB3_COLLECTIONB_H
#include "../LinkedList/list.h"
#include <iostream>
class CollectionB {
private:
    List<std::pair<int, int>> bancnote;
public:
    CollectionB();
    ~CollectionB();
    CollectionB(const CollectionB &collection);
    CollectionB& operator=(const CollectionB &collection);
    void remove(unsigned int index);
    List<std::pair<int, int>> getList();
    std::pair<int, int> index(unsigned int index);
    void eliminare(unsigned int index, int value);

    void adauga(std::pair<int, int> bac);
};


#endif //SDALAB3_COLLECTIONB_H
