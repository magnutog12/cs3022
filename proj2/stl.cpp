// stl.cpp
// Reference: https://stackoverflow.com/questions/5122804/how-to-sort-with-a-lambda

#include "volsort.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void stl_sort(List &l, bool numeric) {
    // vector of Nodes because we cant sort directly
    vector<Node*> vec;
    Node* node = l.head;
    
    // load into new vector and traverse using ->next
    while(node){
        vec.push_back(node);
        node = node->next;
    }

    if(vec.empty()) return;

    if(numeric){
        // found source for using sort with this lambda function
        sort(vec.begin(), vec.end(), [](Node* a, Node* b){
            return a->number < b->number; // use comparator for ascending order
        });
    }else{
        sort(vec.begin(), vec.end(), [](Node* a, Node* b){
            return a->string < b->string; // seperate sort for strings
        });
    }

    // reset head
    l.head = vec[0];
    
    // set the next of each node to print sorted order
    for(size_t i = 0; i < vec.size(); i++){
        vec[i]->next = vec[i+1];
    }
    
}

