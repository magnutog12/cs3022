 // qsort.cpp

#include "volsort.h"

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <array>
#include <iostream>
#include <algorithm>

using namespace std;


//The qComparisonInt function is from Dr. Emrich's 302 course notes.
int qComparisonInt(const void *a, const void *b){
    const Node* ia = *(const Node **) a;
    const Node* ib = *(const Node **) b;
    if(ia->number > ib->number){
        return 1;
    }
    else if(ia->number < ib->number){
        return -1;
    }
    else{
        return 0;
    }
}

int cstring_cmp(const void *a, const void *b){
    const Node *ia = *(const Node **)a;
    const Node *ib = *(const Node **)b;
    char const *ai = ia->string.c_str();
    char const *bi = ib->string.c_str();

    return strcmp(ai, bi);
}

void qsort_sort(List &l, bool numeric) {
    Node* top = l.head;
    int count = 0;

    while(top){
        count++;
        top = top->next;
    }
   
    if(count == 0){ 
        return;
    };

    Node** array;
    array = new Node*[count];

    top = l.head;
    int index = 0;
    while(top){
        array[index] = top;
        top = top->next;
        index++;
    }

    if(numeric){
        qsort(array, count, sizeof(Node*), qComparisonInt);
    }
    else{
        qsort(array, count, sizeof(Node*), cstring_cmp);
    }

    for(int i = 0; i < count - 1; i++){
            array[i]->next = array[i + 1]; 
    }

    array[index-1]->next = nullptr;

    l.head = array[0];
    
    delete array;
}

