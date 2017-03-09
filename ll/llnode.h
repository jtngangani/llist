#ifndef LLNODE_H
#define LLNODE_H

using namespace std;

class llnode
{
    int data;
    llnode* next;

    public:
    llnode();
    llnode(int data);
    int getData();
    llnode* getNext();
    void setData(int );
    void setNext(llnode*);
};

#endif
