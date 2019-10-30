//
// Created by Steven on 10/24/2019.
//

#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;

}
LinkedList::LinkedList(const LinkedList &list) {

}
LinkedList::~LinkedList() {

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
void LinkedList::PrintList() {
    Node* cursor = head;
    if (!cursor)
        cout << "empty list" << endl;
    else{
        while(cursor){
            cout << cursor->value << "\t";
            cursor = cursor->next;
        }
    }
    cout << endl;
}

void LinkedList::Sort() {
    Node* temp = head;
    Node* previous = head;
    Node* curr = head->next;

    if (head->next == nullptr || head == nullptr){ // Returns if the list is of size 0 or 1. A list of this size would inherently be sorted
        return;
    }

    while (curr != nullptr){ //Iterates until it gets to the node that points to null
        if(curr->value >= previous->value){ // If the current value is already greater than or equal to the previous value than no nodes need to be switched
            previous = previous->next; // Moves previous to the next node
            curr = curr->next; // Moves current to the next node
        }
        else { // This branch is entered when the value of the current node is less than
            if(curr->value < head->value){ // This branch is entered if the node that needs to be moved is less than the head in which case the head pointer needs to manipulated
                 previous->next = curr->next;
                 curr->next = nullptr;
                 curr->next = head;
                 head = curr;
            }
            else{
                temp = head;
                while (curr->value > temp->next->value && nullptr != temp->next){
                    temp = temp->next;
                }
                previous->next = curr->next;
                curr->next = temp->next;
                temp->next = curr;
            }
        }
        curr = previous->next;
    }

}