
//PROGRAM: quick.cpp
//DESCRIPTION: custom implementation of quick sort. 
/* divide and conquer but amongst a pivot. Use head node as starting point. 
 * pivot canbe ANYTHING you choose, try few options. DONT FORGET TO ADD PIVOT NODE BACK TO LIST
 * */
#include "volsort.h"
#include <iostream>

using namespace std;


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
	if(l.head == nullptr) return;

	l.head = qsort(l.head, numeric);
}

/*qsort is the recursive portion of the algorithm and calls partition to divide the
 * list and calls concatenate to conquer. It returns the new head of the list. */
//Recursive, divide and concatenate. 
Node *qsort(Node *head, bool numeric) {
	Node *left;
	Node *right;
	Node *pivot = head; //experiement with
	if((head == nullptr) || (head->next == nullptr)) {
		return head; //sort over, reached last node
	}

	//use head as pivot
	//call partition function to split into 2 sublists
	partition(head, pivot, left, right, numeric);

	left = qsort(left, numeric);
	right = qsort(right, numeric);

	//set pivot between sublists
	pivot->next = right;
	
	//set pivot as head if left list is empty
	if(left == nullptr) return pivot;
	//attach pivot to end of left list
	else {
		Node *last = left;
		while(last->next != nullptr) {
			last = last->next;
		}
		last->next = pivot;
		return left;
	}
	concatenate(left, right);

//	return head;
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
	Node *curr = pivot->next;
	pivot->next = nullptr; //detach pivot

	while(curr != nullptr) {
		Node *tmp = curr->next; //store in temporary node
		curr->next = nullptr;
		if(numeric) { //numerical. sort number
			//gather node and pivot value
			int nodeVal = curr->number;
			int pivotVal = pivot->number;

			if(nodeVal <= pivotVal) { //goes on left sublist
				//assign current value
				if(left == nullptr) {
					left = curr;
					leftEnd = curr;
				}
				else {
					leftEnd->next = curr;
					leftEnd = curr;
				}
			}

			else { //goes on right sublist
				//assign current value
				if(right == nullptr) {
					right = curr;
					rightEnd = curr;
				}
				else {
					rightEnd->next = curr;
					rightEnd = curr;
				}
			}
		}

		//NOT NUMERIC, SORT STRING NOW
		else { //sort strings
			string nodeVal = curr->string;
			string pivotVal = pivot->string;
			if(nodeVal <= pivotVal) { //goes on left sublist
				if(left == nullptr) {
					left = curr;
					leftEnd = curr;
				}
				else {
					leftEnd->next = curr;
					leftEnd = curr;
				}

			}
			else { //goes on right sublist
				 //assign current value
                if(right == nullptr) {
                    right = curr;
                    rightEnd = curr;
                }
                else {
                    rightEnd->next = curr;
                    rightEnd = curr;
                }
			}
		}
		curr = tmp;
	}
}
//increment left pointer until element is greater than pivot or points to start
//Decrement right pointer until points to element less than pivot
//check if done? If not: swap the two elements incr left, dec right, repeat


/*concatenate is a helper function that combines both the left and right lists and
 * returns the new head of the list. */
//combines left and right lists
Node *concatenate(Node *left, Node *right) {
	/*first find the last node of the first linked list. Then, update the 
	 * next pointer of the last node to the head node the second linked list */
	/*left->next = right;
	return left; */
	if(left == nullptr) return right;
	//find last node of left sublist
	Node *last = left;
	while(last->next != nullptr) {
		last = last->next;
	}
	last->next = right;
	
	return left;
}
