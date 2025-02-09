// qsort.cpp

#include "volsort.h"

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <array>
#include <iostream>

using namespace std;

int int_cmp(const void *a, const void *b){
    const int *ia = (const int *) a;
    const int *ib = (const int*) b;
    return *ia - *ib;
}

int cstring_cmp(const void *a, const void *b){
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
}

void qsort_sort(List &l, bool numeric) {
    Node* top = l.head;
    int count = 0;
    

    while(top){
        count++;
        top = top->next;
    }
    
    Node* array[count];

    top = l.head;
    int index = 0;
    while(top){
        array[index] = top;
        top = top->next;
        index++;
    }

    if(numeric == true){
        qsort(array, count, sizeof(Node*), int_cmp);
    }
    else{
        qsort(array, count, sizeof(Node*), cstring_cmp);
    }

    for(int i = 0; i < count; i++){
        array[i]->next = array[i+1];
    }

}

