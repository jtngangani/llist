#include <iostream>
#include <iomanip>
#include "llist.h"
#include <assert.h>

using namespace std;

int main()
{
    llist* list = new llist();

    assert(list->getLength() == 0);
    assert(list->pop_head() == -1);
    assert(list->pop_tail() == -1);
    list->reverseList();
    list->printList();

    list->push_front(20);
    list->reverseList();
    list->printList();

    assert(list->pop_head() == 20);
    list->push_front(20);
    assert(list->pop_tail() == 20);

    list->push_front(20);
    list->push_front(5);
    list->push_front(7);
    list->push_back(15);
    // 7 5 20 15

    assert(list->getLength() == 4);
    assert(list->pop_head() == 7);
    assert(list->pop_tail() == 15);
    assert(list->getLength() == 2);
    list->printList();
    //5 20
    assert(list->removeData(73) == -1);
    assert(list->removeData(20) == 1);
    list->printList();
    assert(list->removeData(5) == 1);
    list->printList();
    assert(list->removeData(5) == -1);
    list->printList();
    
    list->push_front(20);
    list->push_front(5);
    list->push_front(7);
    list->push_back(15);
    
    list->reverseList();
    list->printList();
    list->partition(5);

    list->printList();
    return 0;
}


