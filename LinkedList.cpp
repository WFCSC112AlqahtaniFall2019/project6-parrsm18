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
    Node* curr = list.head;
    Node* copy = head;
    while (curr->next != nullptr){
        copy->next = new Node(curr->next->value);
        copy = copy->next;
        curr = curr->next;
    }
     //cout << "Copy constructor called" << endl;
}

LinkedList& LinkedList::operator=(const LinkedList &assignment) {
    LinkedList objToCopy;
    swap(objToCopy.head, head);

    //cout << "Copy assignment operator called" << endl;

    return *this;
}

LinkedList::~LinkedList() {
    Node* curr = head; // Node is set to the head
    Node* afterCurr = curr->next; // Node is set to one after the head
    while(curr->next != nullptr){ // Iterates until current reaches the end of the list
        delete(curr); // Deletes current
        curr = afterCurr; // Sets current equal to the next node in the list
        afterCurr = afterCurr->next; // Moves afterCurr one position ahead of current
    }

    //cout << "Destructor called" << endl;
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
    Node* temp;
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
        else { // This branch is entered when the value of the current node is less than the previous node
            if(curr->value < head->value){ // This branch is entered if the node that needs to be moved is less than the head in which case the head pointer needs to manipulated
                 previous->next = curr->next; // Links the previous node to the node after the current node
                 curr->next = nullptr; // breaks the connection between current and the next node
                 curr->next = head; // Links the current node to the head
                 head = curr; // Sets the head equal to the current node at the beginning of the list
            }
            else{ // This branch is entered when the node that needs to be moved is not less than the head and needs to be inserted somewhere else in the list
                temp = head; // Sets temp to the beginning of the list
                while (curr->value > temp->next->value && temp->next != nullptr){ // Iterates over the list and sets temp to the location that the current node needs to be set to
                    temp = temp->next; // Moves temp forward to the next node
                }
                previous->next = curr->next; // Links the previous node to the node after the current node
                curr->next = nullptr; // breaks the connection between current and the next node
                curr->next = temp->next; // Links the current node that needs to be inserted to the node after temporary
                temp->next = curr; // Links temporary to the current node which was just relocated
            }
        }
        curr = previous->next; // Moves current one position ahead of previous
    }
}