#ifndef _RED_BLACK_TREE_
#define _RED_BLACK_TREE_

// aliases
# define BLACK 1
# define RED 0

// inclues
# include <iostream>
# include <iomanip>
# include <math.h>

// create node
template <class T>
class Node {
    public:
        // attribute
        T           data;
        Node<T>     *parent;
        Node<T>     *left;
        Node<T>     *right;
        int         color;
};

template <class T>
    class Red_Black_Tree {
    private:
        // attribute
        Node<T> *nil;
        Node<T> *root;
        // private member funtion
        Node<T> *initNode(T key)
        {
            Node<T> *newNode = new Node<T>();
            newNode->data = key;
            newNode->color = RED;
            newNode->right = nil;
            newNode->left = nil;
            newNode->parent = nil;
            return (newNode);
        }
        // recolor methode
        void recolor(Node<T> *node)
        {
            if (node->color == RED) node->color = BLACK;
            else node->color = RED;
        }
        // leftRotate
        void leftRotate(Node<T> *node)
        {
            Node<T> *nodeHold = node->right;
            node->right = nodeHold->left;

            if (nodeHold->left != nil)
                nodeHold->left->parent = node;

            nodeHold->parent = node->parent;
            // std::cout << "node->parent->data : " << node->parent->data << "\n";

            if (node->parent == nil)
            {
                root = nodeHold;
                root->color = BLACK;
            }
            else if (node == node->parent->left)
                node->parent->left = nodeHold;
            else
                node->parent->right = nodeHold;

            nodeHold->left = node;
            node->parent = nodeHold;

        }
        // rightRotate
        void rightRotate(Node<T> *node)
        {
            Node<T> *nodeHold = node->left;
            node->left = nodeHold->right;

            if (nodeHold->right != nil)
                nodeHold->right->parent = node;

            nodeHold->parent = node->parent;
            if (node->parent == nil)
            {
                root = nodeHold;
                root->color = BLACK;
            }
            else if (node == node->parent->right)
                node->parent->right = nodeHold;
            else
                node->parent->left = nodeHold;

            nodeHold->right = node;
            node->parent = nodeHold;
        }
        // make suitableRotation
        void suitableRotation(Node<T> *node)
        {
            // recolor(node->parent);
            // recolor(node->parent->parent);
            // if (node->parent->right == node)
            //     leftRotate(node->parent);
            // else if (node->parent->left == node)
            //     rightRotate(node->parent);
            // if (node->parent == node->parent->parent->right)
            //     leftRotate(node->parent);
            // else if (node->parent == node->parent->parent->left)
            //     rightRotate(node->parent);
            if (node == node->parent->right && node->parent == node->parent->parent->left)
            {
                recolor(node);
                recolor(node->parent->parent);
                leftRotate(node->parent);
                rightRotate(node->parent);
            }
            else if (node == node->parent->left && node->parent == node->parent->parent->right)
            {
                recolor(node);
                recolor(node->parent->parent);
                rightRotate(node->parent);
                leftRotate(node->parent);
            }
            else if (node == node->parent->right && node->parent == node->parent->parent->right)
            {
                recolor(node->parent);
                recolor(node->parent->parent);
                leftRotate(node->parent->parent);
            }
            else if (node == node->parent->left && node->parent == node->parent->parent->left)
            {
                recolor(node->parent);
                recolor(node->parent->parent);
                rightRotate(node->parent->parent);
            }
        }
        // check the conflict
        bool conflict(Node<T> *node)
        {
            if (node->color == RED && node->parent->color == RED)
                return (true);
            return (false);
        }
        // check the Tree
        void checkTree(Node<T> *newNode)
        {
            Node<T> *nodeParent, *nodeUncle;
            int  i = 0;
            while (conflict(newNode))
            {
                // std::cout << i++ << '\n';
                // std::cout << "newNode : " << newNode->data << '\n';
                // get the new node parent and new node uncle
                nodeParent = newNode->parent;
                if (nodeParent->parent->left == nodeParent)
                    nodeUncle = nodeParent->parent->right;
                else
                    nodeUncle = nodeParent->parent->left;
                // check if the parent is RED
                // std::cout<< "nodeUncle : " << nodeUncle->data << "\n";
                // std::cout<< "nodeUncle->color : " << nodeUncle->color << "\n";
                if (nodeUncle != NULL && nodeUncle->color == RED)
                {
                    // std::cout<< "newNode : " << newNode->data << "\n";
                    // std::cout<< "nodeParent : " << nodeParent->data << "\n";
                    // std::cout<< "nodeUncle : " << nodeUncle->data << "\n";
                    recolor(nodeParent);
                    recolor(nodeUncle);
                    // std::cout<< "nodeParent->parent->data : " << nodeParent->parent->data << "\n";
                    // std::cout<< "nodeUncle : " << nodeUncle->data << "\n";
                    // std::cout<< "root->data : " << root->data << "\n";
                    if (nodeParent->parent != root)
                    {
                        // std::cout << "nodeParent->parent = " << nodeParent->parent->data << "\n";
                        recolor(nodeParent->parent);
                    }
                }
                else
                    suitableRotation(newNode);
                // loop iteration
                newNode = newNode->parent->parent;
            }
        }
    public:
        Red_Black_Tree()
        {
            nil = new Node<T>();
            nil->data = -1;
            nil->color = BLACK;
            nil->right = NULL;
            nil->left = NULL;
            nil->parent = NULL;
            root = NULL;
        }
        // inserting new node to the Tree
        void insert(T key)
        {
            Node<T> *newNode = initNode(key);
            // creat root node
            if (root == NULL)
            {
                root = newNode;
                root->color = BLACK;
            }
            // add new nodes after the root
            else
            {
                Node<T> *nodeCheck = root;
                Node<T> *nodeHold;
                while (nodeCheck != nil)
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
                checkTree(newNode);
            }
        }
        void printTree() {
            // std::cout << root->data << "\n";
            if (root) {
              printHelper(root, "", true);
            }
        }
        void printHelper(Node<T> *root, std::string indent, bool last) {
            if (root != nil) {
                std::cout << indent;
                if (last) {
                    std::cout << "R----";
                    indent += "   ";
                } else {
                    std::cout << "L----";
                    indent += "|  ";
                }

              std::string sColor = root->color == RED ? "RED" : "BLACK";
              std::cout << root->data << "(" << sColor << ")" << std::endl;
              printHelper(root->left, indent, false);
              printHelper(root->right, indent, true);
            }
        }
};

#endif
