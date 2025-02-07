
//PROGRAM: quick.cpp
//DESCRIPTION: custom implementation of quick sort. 
/* divide and conquer but amongst a pivot. Use head node as starting point. 
 * pivot canbe ANYTHING you choose, try few options. DONT FORGET TO ADD PIVOT NODE BACK TO LIST
 * */
#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

/* quick_sort takes a struct List and whether or not the comparison should be numeric
 * and performs the quick sort algorithm. This function serves as a wrapper or helper
 * function for the recursive qsort function.
 */
//wrapper function
void quick_sort(List &l, bool numeric) {
    //Is comparison numeric?
	if(numeric) {
		
	}
	//perform algorithm: call qsort function here
    
}

/*qsort is the recursive portion of the algorithm and calls partition to divide the
 * list and calls concatenate to conquer. It returns the new head of the list. */
//Recursive, divide and concatenate. 
Node *qsort(Node *head, bool numeric) {

    //call partition function
	
	return qsort( , ); //recursive
}

/* partition is a helper function that splits the singly-linked list into two left and
 * right lists such that all elements less than the pivot are in the left side and
 * everything else is on the right. */
//splits linked list based on pivot
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    //
}

/*concatenate is a helper function that combines both the left and right lists and
* returns the new head of the list. */
//combines left and right lists
Node *concatenate(Node *left, Node *right) {
    //
}
