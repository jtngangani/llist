#include "llnode.h"
#include <cstddef>

llnode::llnode()
{
    data = 0;
    next = NULL;
}

llnode::llnode(int data)
{
    this->data = data;
    this->next = NULL;
}

int llnode::getData()
{
    return data;
}

llnode* llnode::getNext()
{
    return next;
}

void llnode::setData(int data)
{
    this->data = data;
}

void llnode::setNext(llnode* ptr)
{
    next = ptr;
}


