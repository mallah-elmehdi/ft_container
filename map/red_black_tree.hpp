#ifndef _RED_BLACK_TREE_
#define _RED_BLACK_TREE_


// inclues
# include <iostream>
# include <memory>
# include "rbt_util.hpp"
# include "make_pair.hpp"
# include "pair.hpp"
# include "less.hpp"

template <class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key,T> > >
    class Red_Black_Tree : public Red_Black_Tree_Util<Key, T, Compare, Allocator> {
        private:
			Compare			compare;
		public:
            Red_Black_Tree()
            {
                this->nil = new Node<Key, T>();
                this->nil->color = BLACK;
                this->nil->right = NULL;
                this->nil->left = NULL;
                this->nil->parent = NULL;
                this->root = this->nil;
            }
			// begin()
			Node<Key, T>* begin()
			{
                Node<Key, T> *nodeCheck = this->root;
                Node<Key, T> *nodeHold;
				
				while (nodeCheck != this->nil)
				{
                    nodeHold = nodeCheck;
					nodeCheck = nodeCheck->left;
				}
				return (nodeHold);
			}
			// end()
			Node<Key, T>* end()
			{
                Node<Key, T> *nodeCheck = this->root;
                Node<Key, T> *nodeHold;
				
				while (nodeCheck != this->nil)
				{
                    nodeHold = nodeCheck;
					nodeCheck = nodeCheck->right;
				}
				return (nodeHold);
			}
            // inserting new node to the Tree
            int insert(const ft::pair<const Key, T> &val)
            {
                Node<Key, T> *newNode = this->initNode(val);
                // creat root node
                if (this->root == this->nil)
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
						if (newNode->pairv->first == nodeCheck->pairv->first)
							return(0);
                        else if (compare(newNode->pairv->first, nodeCheck->pairv->first))
                            nodeCheck = nodeCheck->left;
						else
                            nodeCheck = nodeCheck->right;
                    }
                    newNode->parent = nodeHold;
                    if (compare(newNode->pairv->first, nodeCheck->pairv->first))
                        nodeHold->left = newNode;
                    else
                        nodeHold->right = newNode;
                    this->checkTree(newNode);
                }
				return (1);
            }
			// find node my key
			T& operator[] (const Key& k)
			{
				Node<Key, T> *nodeCheck = this->root;
				while (nodeCheck != this->nil)
				{
					if (k == nodeCheck->pairv->second)
						return (nodeCheck->pairv->second);
					else if (compare(k, nodeCheck->pairv->first))
						nodeCheck = nodeCheck->left;
					else
						nodeCheck = nodeCheck->right;
				}
			}
};

#endif
