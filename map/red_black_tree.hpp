#ifndef _RED_BLACK_TREE_
#define _RED_BLACK_TREE_

#include "ft.hpp"

template <class Key_T, class Compare, class Allocator>
    class Red_Black_Tree : public Red_Black_Tree_Util<Key_T, Compare, Allocator> {
		private:
			typedef typename Red_Black_Tree_Util<Key_T, Compare, Allocator>::value_type				value_type;
			typedef typename Red_Black_Tree_Util<Key_T, Compare, Allocator>::iterator				iterator;
			typedef typename Red_Black_Tree_Util<Key_T, Compare, Allocator>::const_iterator			const_iterator;

		private:	
			Compare compare = Red_Black_Tree_Util<Key_T, Compare, Allocator>::compare;

		public:
            Red_Black_Tree()
            {
                this->nil = new Node<value_type>();
                this->nil->color = BLACK;
                this->nil->right = this->nil;
                this->nil->left = this->nil;
                this->nil->parent = this->nil;
                this->nil->nil = true;
                this->nil->pairv = this->allocator.allocate(sizeof(value_type));
                this->allocator.construct(this->nil->pairv, value_type());
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
			const Node<value_type>* begin() const
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
			const Node<value_type>* end() const
			{
				return (this->nil);
			}
			// last()
			Node<value_type>* last()
			{
                Node<value_type> *nodeCheck = this->root;
                Node<value_type> *nodeHold = nodeCheck;

				while (nodeCheck != this->nil)
				{
                    nodeHold = nodeCheck;
					nodeCheck = nodeCheck->right;
				}
				return (nodeHold);
			}
			// last()
			const Node<value_type>* last() const 
			{
                Node<value_type> *nodeCheck = this->root;
                Node<value_type> *nodeHold = nodeCheck;

				while (nodeCheck != this->nil)
				{
                    nodeHold = nodeCheck;
					nodeCheck = nodeCheck->right;
				}
				return (nodeHold);
			}
			Node<value_type>* first()
			{
				return (this->nil);
			}
			const Node<value_type>* first() const
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
            // clearing the Tree
            void clear()
            {
                this->allocator.destroy(this->nil->pairv);
                this->allocator.deallocate(this->nil->pairv, sizeof(value_type));
                delete this->nil;
            }

};


#endif
