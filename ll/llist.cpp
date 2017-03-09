#include "llist.h"
#include <iostream>
#include <iomanip>
#include <cstddef>

llist::llist()
{
    head = NULL;
}

llist::llist(int data)
{
    head = new llnode(data);
}

int llist::getLength()
{
    cout<<" Inside "<<__PRETTY_FUNCTION__<<endl;
    llnode* curr = head;
    int len = 0;
    while(curr)
    {
        curr = curr->getNext();
        len++;
    }

    return len;
}

void llist::push_front(int data)
{
    cout<<" Inside "<<__PRETTY_FUNCTION__<<endl;
    llnode* node = new llnode(data);
    if(head == NULL)
    {
        head = node;
        head->setNext(NULL);
    }
    else
    {
        node->setNext(head);
        head = node;
    } 
}

void llist::printList()
{
    cout<<" Inside "<<__PRETTY_FUNCTION__<<endl;
    llnode* curr = head;
    while(curr)
    {
        cout<<curr->getData()<<"\t";
        curr = curr->getNext();
    }

    cout<<endl;
}

int llist::pop_head()
{
    cout<<" Inside "<<__PRETTY_FUNCTION__<<endl;
    if(head == NULL)
        return -1;
    else
    {
        int temp = head->getData();
        llnode* headbckup = head;
        head = head->getNext();
        delete headbckup;
        return temp;
    }
}

void llist::push_back(int data)
{
    cout<<" Inside "<<__PRETTY_FUNCTION__<<endl;
    llnode* newnode = new llnode(data);
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        llnode* curr = head;
        while(curr->getNext())
        {
            curr = curr->getNext();
        }
        curr->setNext(newnode);
        newnode->setNext(NULL);
        cout<<"Here inside push_back"<<endl;
    }
}

int llist::pop_tail()
{
    cout<<" Inside "<<__PRETTY_FUNCTION__<<endl;
    if(head == NULL)
        return -1;
    else if(head->getNext() == NULL)        //size = 1
    {
        int retVal = head->getData();
        delete head;
        head = NULL;
        return retVal;
    }
    else
    {
        llnode* curr;
        llnode* prev;
        prev = head;
        curr = head->getNext();

        while(curr->getNext())
        {
            curr = curr->getNext();
            prev = prev->getNext();
        }

        int retVal = curr->getData();
        prev->setNext(NULL);
        delete curr;

        return retVal;
    }
}

int llist::removeData(int data)
{
    cout<<" Inside "<<__PRETTY_FUNCTION__<<endl;
    if(head == NULL)
    {
        return -1;
    }
    else if(head->getData() == data)
    {
        llnode* temp = head;
        head = head->getNext();
        delete temp;
        return 1;
    }
    else
    {
        llnode* curr = head;
        while(curr->getNext() != NULL and curr->getNext()->getData() != data)
        {
            if(curr->getNext() != NULL)
                curr = curr->getNext();
            else
             break;   
        }

        if(curr->getNext() == NULL)
            return -1;
        else
        {
            llnode* tmp = curr->getNext();
            curr->setNext(curr->getNext()->getNext());
            delete tmp;
            return 1;
        }

    } 
}

void llist::reverseList()
{
    cout<<" Inside "<<__PRETTY_FUNCTION__<<endl;
    if(head == NULL)
        return;

    llnode* prev = NULL;
    llnode* curr = head;
    llnode* next = head->getNext();

    while(curr != NULL)
    {    //Reverse next pointer for curr node
        curr->setNext(prev);

        //Check if the curr node is the last node in the list
        //if yes then assign head to it and return
        
        prev = curr;
        curr = next;
        if(next != NULL)
            next = next->getNext();
    }      
    
    head = prev;
}

void llist::partition(int x)
{
    llist* before = new llist(-1);
    llist* after = new llist(-1);

    llnode* runner = head;

    while(runner)
    {
        if(runner->getData() < x)
        {
            before->push_back(runner->getData());
        }
        else if(runner->getData() > x) 
        {
            after->push_back(runner->getData());
        }
        runner = runner->getNext();
    }

        
        before->pop_head();
        after->pop_head();

        before->push_back(x);
        before->append(after);
        
        head = before->getHead();
}


void llist::append(llist* list)
{
    if(head == NULL)
        head = list->getHead();

    if(list->getHead() != NULL)
    {
        // append the list to llist
        this->getTail()->setNext(list->getHead());
    }

}
    
llnode* llist::getHead()
{
    return head;
}

llnode* llist::getTail()
{
    if(head == NULL)
        return NULL;

    llnode* tail = head;
    llnode* next = head->getNext();

    while(next)
    {
        next = next->getNext();
        tail = tail->getNext();
    }

    return tail;
}

