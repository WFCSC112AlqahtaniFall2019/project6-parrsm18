//
// Created by Steven on 10/24/2019.
//

#include "LinkedList.h"
LinkedList::LinkedList() {
    head = nullptr;

}
int LinkedList::GetValue() {
    return value;
}

void LinkedList::Append(int newNode) {
    if (head == nullptr){
        head = new Node(newNode);
    }
    else {
        Node* cursor = head;
        while (cursor -> next != nullptr){
            cursor = cursor -> next;
        }
        cursor -> next = new Node (newNode);
    }
    size++;
}
void LinkedList::Sort() {
    for (int i = 0; i < ; i++) {

    }
}


