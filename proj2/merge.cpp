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
    if(l.head == nullptr){
       return;
    }
    if(numeric){
    l.head = msort(l.head, numeric);
    }
    else {
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
    if(numeric){
    split(head, left, right);
    left = msort(left, numeric);
    right = msort(right, numeric);
    }
else {
    split(head, left, right);
    left = msort(left, numeric);
    right = msort(right, numeric);
}
return merge(left, right, numeric);
}

void split(Node *head, Node *&left, Node *&right)
{
    if(head == nullptr || head->next == nullptr){
        left = head;
        right = nullptr;
        return;
    }
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

Node *merge(Node *left, Node *right, bool numeric)
{
    Node merger;
    Node *new_list = &merger;
    while(left != nullptr && right != nullptr){
    if (numeric)
        {
            if(left == nullptr){
                return right;
            }
            if(right == nullptr){
                return left;
            }
            if (left->number <= right->number)
            {
                new_list->next = left;
            
                left = left->next;
            }
            else
            {
                new_list->next = right;
                
                right = right->next;
            }
        }
        else if(numeric == false)
        {
            if(left == nullptr){
                return right;
            }
            if(right == nullptr){
                return left;
            }
            if (left->string <= right->string)
            {
                new_list->next = left;
                left = left->next;
            }
            else
            {
                new_list->next = right;
            
                right = right->next;
            }
        }
    }
    return new_list;
}
