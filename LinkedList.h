//
// Created by Steven on 10/24/2019.
//
#include "Node.h"

#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H

class LinkedList{
public:
    LinkedList();
    LinkedList(const LinkedList &list);
    LinkedList& operator= (const LinkedList &objToCopy);
    ~LinkedList();
    void Append(int newNode);
    void Sort();
    void PrintList();

private:
    int size;
    Node* head;
};

#endif //BINARYINSERTIONSORT_LINKEDLIST_H
