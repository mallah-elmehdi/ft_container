#ifndef _RED_BLACK_TREE_
#define _RED_BLACK_TREE_

#include "ft.hpp"

template <class value_type, class compare, class allocator>
    class Red_Black_Tree : public Red_Black_Tree_Util<value_type, compare, allocator> {

		private:  
			typedef ft::Node<value_type>		node;

		public:
			// -------------------------------
			Red_Black_Tree()
			{
				this->initTree();
			}
			// -------------------------------
			node *first() const
			{
				node* nodeCheck = this->root;
				node* nodeHold = nodeCheck;

				while (nodeCheck->nil == false)
				{
					nodeHold = nodeCheck;
					nodeCheck = nodeCheck->left;
				}
				return (nodeHold);
			}
			// -------------------------------
			node *last() const
			{
                node* nodeCheck = this->root;
                node* nodeHold = nodeCheck;

				while (nodeCheck->nil == false)
				{
                    nodeHold = nodeCheck;
					nodeCheck = nodeCheck->right;
				}
				return (nodeHold);
			}
			//-------------------------------
			node *get_root() const
			{
				return (this->root);
			}
			// -------------------------------
			node *get_nil() const
			{
				return (this->nil);
			}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            // // clearing the Tree
            // void clear()
            // {
            //     this->allocator.destroy(this->nil->pairv);
            //     this->allocator.deallocate(this->nil->pairv, sizeof(value_type));
            //     delete this->nil;
            // }

};


#endif
