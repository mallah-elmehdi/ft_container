#ifndef _RED_BLACK_TREE_
#define _RED_BLACK_TREE_


// inclues
# include <iostream>
# include <memory>
# include "rbt_util.hpp"
# include "make_pair.hpp"
# include "pair.hpp"

template <class Key, class T, class Allocator = std::allocator<ft::pair<const Key,T> > >
    class Red_Black_Tree : public Red_Black_Tree_Util<Key, T, Allocator> {
        
		public:
            Red_Black_Tree()
            {
                this->nil = new Node<Key, T>();
                this->nil->color = BLACK;
                this->nil->right = NULL;
                this->nil->left = NULL;
                this->nil->parent = NULL;
                this->root = NULL;
            }
            // inserting new node to the Tree
            void insert(const ft::pair<const Key, T> &val)
            {
                Node<Key, T> *newNode = initNode(val);
                // creat root node
                if (this->root == NULL)
                {
                    this->root = newNode;
                    this->root->color = BLACK;
                }
                // add new nodes after the this->root
                else
                {
                    Node<Key, T> *nodeCheck = this->root;
                    Node<Key, T> *nodeHold;
                    while (nodeCheck != this->nil)
                    {
                        nodeHold = nodeCheck;
                        if (newNode->pairv->first < nodeCheck->pairv->first)
                            nodeCheck = nodeCheck->left;
                        else
                            nodeCheck = nodeCheck->right;
                    }
                    newNode->parent = nodeHold;
                    if (newNode->pairv->first < nodeHold->pairv->first)
                        nodeHold->left = newNode;
                    else
                        nodeHold->right = newNode;
                    checkTree(newNode);
                }
            }
			// find node my key
			T& get_value (const Key& k, size_t size)
			{
				Node<Key, T> *nodeCheck = this->root;
				Node<Key, T> *nodeHold;
				while (nodeCheck != this->nil)
				{
					nodeHold = nodeCheck;
					if (newNode->pairv->first < nodeCheck->pairv->first)
						nodeCheck = nodeCheck->left;
					else
						nodeCheck = nodeCheck->right;
				}
			}
};

#endif
