// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <array>
#include <iostream>

int int_cmp(const void *a, const void *b){
    const int *ia = (const int *) a;
    const int *ib = (const int*) b;
    return *ia - *ib;
}

void qsort_sort(List &l, bool numeric) {
    //Choose pivot in list --> should be recursive
    Node* array[l.size()];

    if(numeric){
        
    }
    else{

    }

    Node* pivot = l.head;


}

