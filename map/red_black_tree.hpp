#ifndef _RED_BLACK_TREE_
#define _RED_BLACK_TREE_

#include "ft.hpp"

template <class value_type, class compare, class allocator>
    class Red_Black_Tree : public Red_Black_Tree_Util<value_type, compare, allocator> {

		public:
			// -------------------------------
			Red_Black_Tree()
			{
				this->initTree();
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
