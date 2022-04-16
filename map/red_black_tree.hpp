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
            // // clearing the Tree
            // void clear()
            // {
            //     this->allocator.destroy(this->nil->pairv);
            //     this->allocator.deallocate(this->nil->pairv, sizeof(value_type));
            //     delete this->nil;
            // }

};


#endif
