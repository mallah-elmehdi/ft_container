#ifndef _RED_BLACK_TREE_
#define _RED_BLACK_TREE_


// inclues
# include <iostream>
# include <memory>
# include "rbt_util.hpp"
# include "make_pair.hpp"
# include "pair.hpp"
# include "less.hpp"
# include "iterator.hpp"

template <class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key,T> > >
    class Red_Black_Tree : public Red_Black_Tree_Util<Key, T, Compare, Allocator> {
        private:
            typedef Key                                             key_type;
            typedef T                                               mapped_type;
            typedef ft::pair<const key_type, mapped_type>           value_type;
            typedef ft::bd_iterator<value_type>						iterator;
            typedef ft::bd_iterator<const value_type>				const_iterator;

		private:
			Compare			compare;

		public:
            Red_Black_Tree()
            {
                this->nil = new Node<value_type>();
                this->nil->color = BLACK;
                this->nil->right = NULL;
                this->nil->left = NULL;
                this->nil->parent = NULL;
                this->root = this->nil;
            }
			// begin()
			Node<value_type>* begin()
			{
                Node<value_type> *nodeCheck = this->root;
                Node<value_type> *nodeHold = nodeCheck;

				while (nodeCheck != this->nil)
				{
                    nodeHold = nodeCheck;
					nodeCheck = nodeCheck->left;
				}
				return (nodeHold);
			}
			// end()
			Node<value_type>* end()
			{
				return (this->nil);
			}
            // inserting new node to the Tree
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
            // get a node
            Node<value_type>* get_node(const key_type& k)
            {
                Node<value_type> *nodeCheck = this->root;
				while (nodeCheck != this->nil)
				{
					if (k == nodeCheck->pairv->second)
						break;
					else if (compare(k, nodeCheck->pairv->first))
						nodeCheck = nodeCheck->left;
					else
						nodeCheck = nodeCheck->right;
				}
                return (nodeCheck);
            }
            // clearing the Tree
            void clear()
            {
                // this->clearHelp(begin());
                delete this->nil;
            }
};

#endif
