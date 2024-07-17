#ifndef CURS7_P_NODE_H
#define CURS7_P_NODE_H

template <typename T>
class List;

template <class T>
class Node {
private:

public:
    Node<T>* prev;
    T info;
    Node<T>* next;
    Node(T info,Node<T>* prev, Node<T>* next) : info(info), next(next), prev(prev){}
    Node(T info) : info(info){ next= nullptr; prev= nullptr;}
    friend class List<T>;
};

#endif //CURS7_P_NODE_H
