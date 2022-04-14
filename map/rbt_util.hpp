#ifndef _RED_BLACK_TREE_UTIL_
#define _RED_BLACK_TREE_UTIL_

// aliases
# define BLACK 1
# define RED 0

// inclues
# include <iostream>
# include <memory>
# include "make_pair.hpp"
# include "pair.hpp"
# include "node.hpp"
# include "less.hpp"


template <class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key,T> > >
    class Red_Black_Tree_Util {

        protected:
            typedef Key                                             key_type;
            typedef T                                               mapped_type;
            typedef ft::pair<const key_type, mapped_type>           value_type;

        protected:
            Node<value_type>	*nil;
            Node<value_type>	*root;
			Compare			compare;
            Allocator		allocator;

		protected:
            // private member funtion
            Node<value_type> *initNode(const value_type &val)
            {
                // creat new node
                Node<value_type> *newNode = new Node<value_type>();
                // reserve memory to the pair
                newNode->pairv = allocator.allocate(sizeof(value_type));
                // construct the pair
                allocator.construct(newNode->pairv, ft::make_pair(val.first, val.second));;
                // add other node info
                newNode->color = RED;
                newNode->right = nil;
                newNode->left = nil;
                newNode->parent = nil;
                newNode->nil = false;
                return (newNode);
            }
            // recolor methode
            void recolor(Node<value_type> *node)
            {
                if (node->color == RED) node->color = BLACK;
                else node->color = RED;
            }
            // leftRotate
            void leftRotate(Node<value_type> *node)
            {
                Node<value_type> *nodeHold = node->right;
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
            void rightRotate(Node<value_type> *node)
            {
                Node<value_type> *nodeHold = node->left;
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
            void suitableRotation(Node<value_type> *node)
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
            bool conflict(Node<value_type> *node)
            {
                if (node && node->parent && node->color == RED && node->parent->color == RED)
                    return (true);
                return (false);
            }
            // check the Tree
            void checkTree(Node<value_type> *newNode)
            {
                Node<value_type> *nodeParent, *nodeUncle;
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
                    if (nodeUncle->color == RED)
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
            void printHelper(Node<value_type> *root, std::string indent, bool last) {
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
                  std::cout << root->pairv->first << "(" << sColor << ")" << std::endl;
                  printHelper(root->left, indent, false);
                  printHelper(root->right, indent, true);
                }
            }
		public :
            void printTree()
            {
                if (root) {
                  printHelper(root, "", true);
                }
            }
};

#endif
