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
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			// void deleteNode(int data) {
			// 	deleteNodeHelper(this->root, data);
			// }
			// void deleteNodeHelper(NodePtr node, int key) {
			// 	NodePtr z = TNULL;
			// 	NodePtr x, y;
			// 	while (node != TNULL) {
			// 	if (node->data == key) {
			// 		z = node;
			// 	}

			// 	if (node->data <= key) {
			// 		node = node->right;
			// 	} else {
			// 		node = node->left;
			// 	}
			// 	}

			// 	if (z == TNULL) {
			// 	cout << "Key not found in the tree" << endl;
			// 	return;
			// 	}

			// 	y = z;
			// 	int y_original_color = y->color;
			// 	if (z->left == TNULL) {
			// 	x = z->right;
			// 	rbTransplant(z, z->right);
			// 	} else if (z->right == TNULL) {
			// 	x = z->left;
			// 	rbTransplant(z, z->left);
			// 	} else {
			// 	y = minimum(z->right);
			// 	y_original_color = y->color;
			// 	x = y->right;
			// 	if (y->parent == z) {
			// 		x->parent = y;
			// 	} else {
			// 		rbTransplant(y, y->right);
			// 		y->right = z->right;
			// 		y->right->parent = y;
			// 	}

			// 	rbTransplant(z, y);
			// 	y->left = z->left;
			// 	y->left->parent = y;
			// 	y->color = z->color;
			// 	}
			// 	delete z;
			// 	if (y_original_color == 0) {
			// 	deleteFix(x);
			// 	}
			// }
};


#endif
