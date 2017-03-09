#ifndef LLIST_H
#define LLIST_H

#include "llnode.h"

using namespace std;

class llist
{
    llnode* head;
    
    public:
    llist();
    llist(int data);
    void push_front(int data);
    void push_back(int data);
    int pop_head();
    int pop_tail();
    int getLength();
    int removeData(int);
    void printList();
    void reverseList();
    llnode* getHead();
    llnode* getTail();
    void append(llist* );
    void partition(int );
};

#endif
