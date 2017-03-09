#include <iostream>
#include "bst.h"
#include "assert.h"

using namespace std;

int main()
{
    bst* m_bst = new bst();

    m_bst->inOrderTraverse();
    m_bst->preOrderTraverse();
    m_bst->postOrderTraverse();
    m_bst->levelTraverse();

    assert(m_bst->search_ite(13) == false);
    assert(m_bst->search_rec(17) == false);
    assert(m_bst->count_lt_key(17) == 0);

    m_bst->insert(9);
    m_bst->insert(5);
    m_bst->insert(13);
    m_bst->insert(7);
    m_bst->insert(11);
    m_bst->insert(1);
    m_bst->insert(17);
    m_bst->insert(3);
    m_bst->insert(15);

    m_bst->inOrderTraverse();
    m_bst->preOrderTraverse();
    m_bst->postOrderTraverse();
    m_bst->levelTraverse();

    assert(m_bst->isBST());
    m_bst->mroot->setKey(4);
    assert(m_bst->isBST());
    m_bst->mroot->setKey(9);

    assert(m_bst->search_ite(13) == true);
    assert(m_bst->search_ite(3) == true);
    assert(m_bst->search_ite(43) == false);
    assert(m_bst->search_rec(17) == true);
    assert(m_bst->search_rec(100) == false);
    m_bst->levelTraverse();

    assert(m_bst->count_lt_key(17) == 8);

    return 1;
}

