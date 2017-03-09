#include <iostream>
#include <iomanip>

#include "node.h"

using namespace std;

node::node(int key)
{
    this->key = key;
    this->left = NULL;
    this->right = NULL;
}

void node::setLeft(node* left)
{
    this->left = left;
}

void node::setRight(node* right)
{
    this->right = right;
}

void node::setKey(int key)
{
    this->key = key;
}

int node::getKey()
{
    return key;
}

node* node::getLeft()
{
    return left;
}

node* node::getRight()
{
    return right;
}
