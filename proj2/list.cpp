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
    // stoi the value - if fail, default to 0

    int value;
    for(size_t i = 0; i < s.size(); i++){
        if(!isdigit(s[i])){
            value = stoi(s);
        }
        else{
            value = 0;
        }
    }

    Node* newNode = new Node();
    newNode->number = value;
    newNode->next = head;
    head = newNode;
}
