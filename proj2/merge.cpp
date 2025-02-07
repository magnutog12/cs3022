// merge.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, bool numeric);
void split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

void merge_sort(List &l, bool numeric)
{ 
    if(l.head != nullptr){
       return;
    }
    if(numeric){
    l.head = msort(l.head, numeric);
    }
}

Node *msort(Node *head, bool numeric)
{
    Node *left;
    Node *right;
    //Base case, cant access List->size
    if(head == nullptr || head->next == nullptr){
        return head;
    }
   else{
    split(head, left, right);
    left = msort(left, numeric);
    right = msort(right, numeric);
    
   }
   return merge(left, right, numeric);

}

void split(Node *head, Node *&left, Node *&right)
{
   
    Node *slow = head;
    Node *fast = head->next;
    // When fast pointer is at null - slow is the middle node
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Break the link and have right = the midpoint's sublist
    right = slow->next;
    slow->next = nullptr;
    left = head;
}
// Recreated from Dr. Emrich's notes
Node *merge(Node *left, Node *right, bool numeric)
{   
    Node merger;
    Node *new_list = &merger;
    while(left != nullptr && right != nullptr){
    if (numeric)
        {
            if (left->number <= right->number)
            {
                new_list->next = left;
                new_list = left;
                left = left->next;
            }
            else
            {
                new_list->next = right;
                new_list = right;
                right = right->next;
            }
        }
        else
        {
            if(left->string < right->string)
            {
                new_list->next = left;
                new_list = left;
                left = left->next;
            }
            else
            {
                new_list->next = right;
                new_list = right;
                right = right->next;
            }
        }
    }
    new_list->next = (left == nullptr) ? right : left;
    return merger.next;
}
