#ifndef NODE_H
#define NODE_H

class node
{
    node* left;
    node* right;
    int key;

    public:
        node(int key);
        void setLeft(node* left);
        void setRight(node* right);
        void setKey(int key);
        int getKey();
        node* getLeft();
        node* getRight();
};

#endif
