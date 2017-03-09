#ifndef BST_H
#define BST_H

#include <queue>
#include <vector>
#include <list>
#include "node.h"

using namespace std;

class bst
{
    //node* mroot;

    public:
        node* mroot;
        bst();
        bool search_ite(int key);
        bool search_rec(int key);
        bool search_recur(node*, int);
        void insert(int key);
        void remove(int key);
        void preOrderTraverse();            //DFS
        void postOrderTraverse();           // "
        void inOrderTraverse();             // "
        void preOrderHelp(node*);
        void postOrderHelp(node*);
        void inOrderHelp(node*);
        void levelTraverse();               //BFS
        int count_lt_key(int key);          //returns -1 if key is absent
        int countHelp(node*, int key);
        bool isBST();
        bool isBSThelp(node*);
        void createLL(vector<list<node*> >* vectorLL, int level); 
        void createLLHelp(vector<list<node*> >* vectorLL, node* root, int level); 
};

#endif
