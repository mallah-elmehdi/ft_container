#ifndef _RED_BLACK_TREE_
#define _RED_BLACK_TREE_

// aliases
# define BLACK 1
# define RED 0

// create node
template <class T>
class Node {
public:
    // attribute
    T       data;
    Node    *parent = NULL;
    Node    *left = NULL;
    Node    *right = NULL;
    int     color;
}

template <class T>
class Red_Black_Tree {
private:
    // attribute
    Node *root = NULL;
    // private member funtion
    Node *initNode(T key)
    {
        Node *newNode = new Node<T>();
        newNode->data = key;
        newNode->color = RED;
        return (newNode);
    }
    // check the Tree
    void checkTree(Node *newNode);
    {
        
    }
public:
    // Red_Black_Tree() {}
    // inserting new node to the Tree
    void insert(T key)
    {
        Node *newNode = initNode(key);
        // creat root node
        if (root == NULL)
        {
            root = newNode;
            root->color = BLACK;
        }
        // add new nodes after the root
        else
        {
            Node *nodeCheck = root;
            Node *nodeHold;
            while (nodeCheck != NULL)
            {
                nodeHold = nodeCheck;
                if (newNode->data < nodeCheck->data)
                    nodeCheck = nodeCheck->left;
                else
                    nodeCheck = nodeCheck->right;
            }
            newNode->parent = nodeHold;
            if (newNode->data < nodeHold->data)
                nodeHold->left = newNode;
            else
                nodeHold->right = newNode;
            checkTree();
        }
    }
}

#endif
