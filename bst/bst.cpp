#include <iostream>
#include <iomanip>

#include "bst.h"

using namespace std;

bst::bst()
{
    mroot = NULL;
}

bool bst::search_ite(int key)
{
    node* root = mroot;
    while(root != NULL)
    {

        if(key == root->getKey())
            return true;

        if(key < root->getKey())
            root = root->getLeft();
        else
            root = root->getRight();
    }

    return false;
}

bool bst::search_rec(int key)
{
    node* root = mroot;
    return search_recur(root, key);
    
}

bool bst::search_recur(node* root, int key)
{
    if(root == NULL)
        return false;

    if(key == root->getKey())
        return true;

    if(key < root->getKey())
        return search_recur(root->getLeft(),key);
    else
        return search_recur(root->getRight(),key);
}

void bst::insert(int key)
{
    node* tmproot = mroot;
    node* p_node = new node(key);
    
    if(mroot == NULL)
    {
        mroot = p_node;
        return;
    }
    
    while(1)
    {   
        if(key < mroot->getKey())
            if( mroot->getLeft() == NULL)
            {
                mroot->setLeft(p_node);
                break;
            }
            else
                mroot = mroot->getLeft();
        else
            if( mroot->getRight() == NULL)
            {
                mroot->setRight(p_node);
                break;
            }
            else
                mroot = mroot->getRight();
    }

    mroot = tmproot;
}

void bst::remove(int key)
{}

void bst::preOrderTraverse()
{   
    //tree traversal is recursive which requires passing "next root" argument 
    //to the next recursive call. Since here, we dont want user to be concerned 
    //about BST root, we dont include as an argument to the interface function.
    //hence, we need to have helper function that can take root as an argument.    
    cout<<" **** Pre Order Traversal of BST ****\n";
    preOrderHelp(mroot);
    cout<<endl<<endl;
} 

void bst::preOrderHelp(node* root)
{
    if(root == NULL)
        return;
    else
    {
        cout<<root->getKey()<<"\t";
        preOrderHelp(root->getLeft());
        preOrderHelp(root->getRight());
    }

}

void bst::postOrderTraverse()
{
    cout<<" **** Post Order Traversal of BST ****\n";
    postOrderHelp(mroot);
    cout<<endl<<endl;
} 

void bst::postOrderHelp(node* root)
{
    if(root == NULL)
        return;
    else
    {
        postOrderHelp(root->getLeft());
        postOrderHelp(root->getRight());
        cout<<root->getKey()<<"\t";
    }
}

void bst::inOrderTraverse()
{
    cout<<" **** In Order Traversal of BST ****\n";
    inOrderHelp(mroot);
    cout<<endl<<endl;
}

void bst::inOrderHelp(node* root)
{
    if(root == NULL)
        return;
    else
    {   
        inOrderHelp(root->getLeft());
        cout<<root->getKey()<<"\t";
        inOrderHelp(root->getRight());
    }
}

int bst::count_lt_key(int key)
{
    //In order traversal. count number of nodes with value less than key
    if(search_rec(key) == false)
        return 0;
    else
        return countHelp(mroot, key);
}

int bst::countHelp(node* root, int key)
{
    if(root == NULL)
        return 0;
    else
    {
        int a = countHelp(root->getLeft(), key);
        if(root->getKey() < key)
        {
            a++;           
        }
        else if (root->getKey() >= key)
        {
            return a;
        }
        
        
        int b = countHelp(root->getRight(), key);
        return a + b;
    }
}

void bst::levelTraverse()
{
    
    cout<<" **** Level Order Traversal of BST ****\n";
    queue<node* >bfsqueue;
    
    node* root = mroot;
    
    if(root == NULL)
        return;
    else
        bfsqueue.push(root);

    while(not bfsqueue.empty())
    {
        node* temp = bfsqueue.front();
        bfsqueue.pop();
        cout<<temp->getKey()<<"\t";

        if(temp->getLeft() != NULL)
            bfsqueue.push(temp->getLeft());

        if(temp->getRight() != NULL)
            bfsqueue.push(temp->getRight());
    }

}

bool bst::isBST()
{
    return isBSThelp(mroot);
}

bool bst::isBSThelp(node* root)
{
    if(root == NULL)
        return true;
    
    if(root->getLeft() != NULL)
    {
        if( (root->getKey() < root->getLeft()->getKey())) 
            return false;
    }

    if(root->getRight() != NULL)
    {
        if( (root->getKey() > root->getRight()->getKey())) 
            return false;
    }

    return (isBSThelp(root->getLeft()) and isBSThelp(root->getRight()) );
}

void bst::createLL(vector<list<node*> >* vectorLL, int level)
{
   node* root = mroot;
   if(root == NULL)
      return;

  createLLHelp(vectorLL, root, 0);
}

void bst::createLLHelp(vector<list<node*> >* vectorLL, node* root, int level)
{
    cout<<"Inside "<<__PRETTY_FUNCTION__<<endl;
    if(root == NULL)
    {
        cout<< " Root is null.. returning"<<endl;
        return;
    }
    
    cout<<"Root = "<<root->getKey()<<endl;
    //Call createLL for left
   createLLHelp(vectorLL, root->getLeft(), level + 1);
   
   //Push root into correct level queue
   if( vectorLL[level] != NULL)
   {
     cout<<"Pushing "<<root->getKey()<<" at level "<<level<<endl;
      vectorLL[level].push_back(root);
   else
   {
     cout<<"Creating a new list and Pushing "<<root->getKey()<<" at level "<<level<<endl;
      vectorLL[level] = new list<node*>(); 
      vectorLL[level].push_back(root);
   }

    //Call createLL for right
   createLLHelp(vectorLL, root->getRight(), level + 1);

}


        
    
