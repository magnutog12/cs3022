
//PROGRAM: quick.cpp
//DESCRIPTION: custom implementation of quick sort. 
/* divide and conquer but amongst a pivot. Use head node as starting point. 
 * pivot canbe ANYTHING you choose, try few options. DONT FORGET TO ADD PIVOT NODE BACK TO LIST
 * */
#include "volsort.h"
#include <string> //uses to_string()
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
	if(l.head == NULL) return;
	
	l = qsort(l.head, numeric);
}

/*qsort is the recursive portion of the algorithm and calls partition to divide the
 * list and calls concatenate to conquer. It returns the new head of the list. */
//Recursive, divide and concatenate. 
Node *qsort(Node *head, bool numeric) {
	Node *left;
	Node *right;
	Node *pivot = head; //experiement with
	if(head == nullptr) {
		return head; //sort over, reached last node
	}

	//use head as pivot
	//call partition function to split into 2 sublists
	partition(head, pivot, left, right, numeric);

	left = qsort(left, numeric);
	right = qsort(right, numeric);
	
	//set pivot between sublists
	pivot->right = right; //?check
	concatenate(left, right);
	
	return head;
}

/* partition is a helper function that splits the singly-linked list into two left and
 * right lists such that all elements less than the pivot are in the left side and
 * everything else is on the right. */
//splits linked list based on pivot
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
	//initialize start to each sublist
	left = nullptr;
	right = nullptr;
	//initialize the end to each sublist
	Node *leftEnd = nullptr;
	Node *rightEnd = nullptr;
	
	//use node following pivot
	Node *curr = pivot->right;
	pivot->right = nullptr; //detach pivot
	
while(curr != nullptr) {
	if(numeric) {
		//numerical. sort number
		int nodeVal = curr->number; //access number value
		int pivotVal = pivot->number;

		if(nodeVal <= pivotVal) { //goes on left sublist
			curr->next = left;
			curr = left;
			left = left->next;
		}
		
		else { //goes on right sublist
			curr->next = right;
			curr = right
			right = right->next;
		}
	}

	//NOT NUMERIC, SORT STRING NOW
	else {
		//sort strings
		string nodeVal = curr->string;
		string nodeVal = curr->string;
		if(nodeVal <= pivotVal) { //goes on left sublist
			curr->next = left;
			curr = left;
			left = left->next;
		}
        else { //goes on right sublist
			curr->next = right;
			curr = right
            right = right->next;
		}
	}
	curr->next = (left == nullptr) ? right;
}
	//increment left pointer until element is greater than pivot or points to start
	//Decrement right pointer until points to element less than pivot
	//check if done? If not: swap the two elements incr left, dec right, repeat
	
}

/*concatenate is a helper function that combines both the left and right lists and
 * returns the new head of the list. */
//combines left and right lists
Node *concatenate(Node *left, Node *right) {
	//
}
