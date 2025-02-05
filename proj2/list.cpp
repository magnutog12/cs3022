#include "volsort.h"


List::List() {
    head = nullptr;
}

List::~List() {
    Node* node = head;
    while(node != nullptr){
        Node* temp = node;
        node = node->next;
        delete temp;
    }
}

void List::push_front(const std::string &s) {
     // Make a new node
    // Place in front of head node
    // stoi the value 
    
    Node* newNode = new Node();
    newNode->string = s;
    newNode->number = stoi(s);    
    newNode->next = head;
    head = newNode;
}
