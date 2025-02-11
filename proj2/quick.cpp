//NAME: Kylie Norosky
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

//wrapper function to perform qsort
void quick_sort(List &l, bool numeric) {
	if(l.head == nullptr) return;

	l.head = qsort(l.head, numeric);
}

//Call Recursive Functions
Node *qsort(Node *head, bool numeric) {
	Node *left;
	Node *right;
	Node *pivot = head; //experiement with
	if((head == nullptr) || (head->next == nullptr)) {
		return head; //sort over, reached last node
	}

	//using pivot, call partition function to split into 2 sublists
	partition(head, pivot, left, right, numeric);

	left = qsort(left, numeric);
	right = qsort(right, numeric);

	//set pivot between sublists
	pivot->next = right;
	
	//return pivot as head if left list is empty
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

	return head;
}

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

//combines left and right lists
Node *concatenate(Node *left, Node *right) {
	if(left == nullptr) return right;
	
	//find last node of left sublist
	Node *last = left;
	while(last->next != nullptr) {
		last = last->next;
	}
	last->next = right; //set last left's next to point to right node
	
	return left;
}
