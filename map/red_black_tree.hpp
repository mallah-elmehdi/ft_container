#ifndef _RED_BLACK_TREE_
#define _RED_BLACK_TREE_

// create node
template <class T>
class Node {
public:
    T       data;
    Node    *parent;
    Node    *left;
    Node    *right;
    int     color;
}

template <class T>
class Red_Black_Tree {
private:
    Node *root;
public:
    Red_Black_Tree()
    {

    }
}

#endif
