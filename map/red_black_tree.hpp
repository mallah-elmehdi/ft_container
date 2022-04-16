#ifndef _RED_BLACK_TREE_
#define _RED_BLACK_TREE_

#include "ft.hpp"

template <class key_value, class mapped_type, class node, class compare, class allocator, class rebind>
    class Red_Black_Tree : public Red_Black_Tree_Util<key_value, mapped_type, node, compare, allocator, rebind> {

		// private:	
		// 	Compare compare = Red_Black_Tree_Util<Key_T, Compare, Allocator>::compare;

		public:
			/* --------------------------------------------- constructor */
			Red_Black_Tree()
            {
				this->initTree();
            }
			/* --------------------------------------------- member functions */
				// template <class InputIterator>
				// typedef typename InputIterator::value_type	value_type;
				// typedef ft::NodePair<value_type>*			node_pair;

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            ft::pair<iterator, bool> insert(const value_type &val)
            {
                Node<value_type> *newNode = this->initNode(val);
                // creat root node
                if (this->root == this->nil)
                {
                    this->root = newNode;
                    this->root->color = BLACK;
                }
                // add new nodes after the this->root
                else
                {
                    Node<value_type> *nodeCheck = this->root;
                    Node<value_type> *nodeHold;
                    while (nodeCheck != this->nil)
                    {
                        nodeHold = nodeCheck;
						if (newNode->pairv->first == nodeCheck->pairv->first)
						{
							this->allocator.destroy(newNode->pairv);
							this->allocator.deallocate(newNode->pairv, sizeof(value_type));
							delete newNode;
							return(ft::make_pair(iterator(nodeCheck), false));
						}
                        else if (compare(newNode->pairv->first, nodeCheck->pairv->first))
                            nodeCheck = nodeCheck->left;
						else
                            nodeCheck = nodeCheck->right;
                    }
                    newNode->parent = nodeHold;
                    if (compare(newNode->pairv->first, nodeHold->pairv->first))
                        nodeHold->left = newNode;
                    else
                        nodeHold->right = newNode;
                    this->checkTree(newNode);
                }
                return(ft::make_pair(iterator(newNode), true));
            }
            // // clearing the Tree
            // void clear()
            // {
            //     this->allocator.destroy(this->nil->pairv);
            //     this->allocator.deallocate(this->nil->pairv, sizeof(value_type));
            //     delete this->nil;
            // }

};


#endif
