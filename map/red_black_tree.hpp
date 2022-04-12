#ifndef _RED_BLACK_TREE_
#define _RED_BLACK_TREE_

// aliases
# define BLACK 1
# define RED 0

// inclues
# include <iostream>
# include "pair.hpp"
# include "make_pair.hpp"

// create node
template <class Key, class T>
    class Node {
        public:
            // attribute
            ft::make_pair<Key, T>       pairv;
            Node<Key, T>                *parent;
            Node<Key, T>                *left;
            Node<Key, T>                *right;
            int                         color;
};

template <class Key, class T, class Allocator = std::allocator<ft::pair<const Key,T> > >
    class Red_Black_Tree {

        private:
            // attribute
            Allocator allocator;
            Node<Key, T> *nil;
            Node<Key, T> *root;

        private:
            // private member funtion
            Node<Key, T> *initNode(const ft::pair<const Key, T> &val)
            {
                // creat new node
                Node<Key, T> *newNode = new Node<Key, T>();
                // reserve memory to the pair
                newNode->pairv = alloc.allocate(sizeof(std::pair<const Key, T>));
                // construct the pair
                alloc.construct(newNode->pairv, ft::make_pair(val.first, val.second));;
                // add other node info
                newNode->color = RED;
                newNode->right = nil;
                newNode->left = nil;
                newNode->parent = nil;
                return (newNode);
            }
            // recolor methode
            void recolor(Node<Key, T> *node)
            {
                if (node->color == RED) node->color = BLACK;
                else node->color = RED;
            }
            // leftRotate
            void leftRotate(Node<Key, T> *node)
            {
                Node<Key, T> *nodeHold = node->right;
                node->right = nodeHold->left;

                if (nodeHold->left != nil)
                    nodeHold->left->parent = node;

                nodeHold->parent = node->parent;

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
            void rightRotate(Node<Key, T> *node)
            {
                Node<Key, T> *nodeHold = node->left;
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
            void suitableRotation(Node<Key, T> *node)
            {
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
            bool conflict(Node<Key, T> *node)
            {
                if (node->color == RED && node->parent->color == RED)
                    return (true);
                return (false);
            }
            // check the Tree
            void checkTree(Node<Key, T> *newNode)
            {
                Node<Key, T> *nodeParent, *nodeUncle;
                int  i = 0;
                while (conflict(newNode))
                {
                    // get the new node parent and new node uncle
                    nodeParent = newNode->parent;
                    if (nodeParent->parent->left == nodeParent)
                        nodeUncle = nodeParent->parent->right;
                    else
                        nodeUncle = nodeParent->parent->left;
                    // check if the nodeUncle is RED
                    if (nodeUncle != NULL && nodeUncle->color == RED)
                    {
                        recolor(nodeParent);
                        recolor(nodeUncle);
                        if (nodeParent->parent != root)
                            recolor(nodeParent->parent);
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
                nil = new Node<Key, T>();
                nil->color = BLACK;
                nil->right = NULL;
                nil->left = NULL;
                nil->parent = NULL;
                nil->pairv = NULL;
                root = NULL;
            }
            // inserting new node to the Tree
            void insert(const ft::pair<const Key, T> &val)
            {
                Node<Key, T> *newNode = initNode(val);
                // creat root node
                if (root == NULL)
                {
                    root = newNode;
                    root->color = BLACK;
                }
                // add new nodes after the root
                else
                {
                    Node<Key, T> *nodeCheck = root;
                    Node<Key, T> *nodeHold;
                    while (nodeCheck != nil)
                    {
                        nodeHold = nodeCheck;
                        if (newNode->pairv.first < nodeCheck->pairv.first)
                            nodeCheck = nodeCheck->left;
                        else
                            nodeCheck = nodeCheck->right;
                    }
                    newNode->parent = nodeHold;
                    if (newNode->pairv.first < nodeHold->pairv.first)
                        nodeHold->left = newNode;
                    else
                        nodeHold->right = newNode;
                    checkTree(newNode);
                }
            }
            void printTree()
            {
                if (root) {
                  printHelper(root, "", true);
                }
            }
            void printHelper(Node<Key, T> *root, std::string indent, bool last) {
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
                  std::cout << root->pairv.first << "(" << sColor << ")" << std::endl;
                  printHelper(root->left, indent, false);
                  printHelper(root->right, indent, true);
                }
            }
};

#endif
