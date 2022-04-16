#ifndef _RED_BLACK_TREE_UTIL_
#define _RED_BLACK_TREE_UTIL_

# define BLACK 1
# define RED 0

#include "ft.hpp"

template <class key_type, class mapped_type, class node, class compare, class allocator, class rebind>
    class Red_Black_Tree_Util {		
		protected:
			typedef ft::pair<key_type, mapped_type>		value_type;
			typedef ft::NodePair<value_type>			node_pair;

		protected:
            allocator	alloc;
            rebind		reb;
			compare		comp;
            node		nil;
            node		root;

		public:
			// -------------------------------
			void initTree()
			{
				root = reb.allocate(sizeof(node));
				reb.construct($root, node());
				root.color = BLACK;
				root.nil = true;
				root.root = true;
				// 
				nil = reb.allocate(sizeof(node));
				reb.construct(&nil, node());
				nil.color = BLACK;
				nil.nil = true;
				nil.root = true;
			}
			// -------------------------------
            nodePair initPair(const value_type &val)
            {
                nodePair newNode;
                newNode.pairv = allocator.allocate(sizeof(value_type));
                allocator.construct(&newNode.pairv, ft::make_pair(val.first, val.second));;
                newNode.color = RED;
                newNode.right = nil;
                newNode.left = nil;
                newNode.parent = nil;
                newNode.nil = false;
                newNode.root = false;
                return (newNode);
            }
			// -------------------------------
			node first()
			{
				node nodeCheck = root;
                node nodeHold = nodeCheck;

				while (nodeCheck.nil == false)
				{
                    nodeHold = nodeCheck;
					nodeCheck = nodeCheck.left;
				}
				return (nodeHold);
			}
			// -------------------------------
			node nil()
			{
				return (nil);
			}
			// -------------------------------
			node last()
			{
                node nodeCheck = this.root;
                node nodeHold = nodeCheck;

				while (nodeCheck.nil == false)
				{
                    nodeHold = nodeCheck;
					nodeCheck = nodeCheck->right;
				}
				return (nodeHold);
			}
			// -------------------------------
            bool insert(const value_type &val)
            {
                nodePair newNode = initPair(val);
                // creat root node
                if (root.nil == true)
                {
                    root = newNode;
                    root.root = true;
                    root.color = BLACK;
                }
                // add new nodes after the this->root
                else
                {
                    nodePair nodeCheck = root;
                    nodePair nodeHold;
                    while (nodeCheck->nil == false)
                    {
                        nodeHold = nodeCheck;
						if (newNode.pairv.first == nodeCheck.pairv.first)
						{
							alloc.destroy(newNode->pairv);
							allocator.deallocate(newNode->pairv, sizeof(value_type));
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
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        //     // recolor methode
        //     void recolor(Node<value_type> *node)
        //     {
        //         if (node->color == RED) node->color = BLACK;
        //         else node->color = RED;
        //     }
        //     // leftRotate
        //     void leftRotate(Node<value_type> *node)
        //     {
        //         Node<value_type> *nodeHold = node->right;
        //         node->right = nodeHold->left;

        //         if (nodeHold->left != nil)
        //             nodeHold->left->parent = node;

        //         nodeHold->parent = node->parent;

        //         if (node->parent == nil)
        //         {
        //             root = nodeHold;
        //             root->color = BLACK;
        //         }
        //         else if (node == node->parent->left)
        //             node->parent->left = nodeHold;
        //         else
        //             node->parent->right = nodeHold;

        //         nodeHold->left = node;
        //         node->parent = nodeHold;

        //     }
        //     // rightRotate
        //     void rightRotate(Node<value_type> *node)
        //     {
        //         Node<value_type> *nodeHold = node->left;
        //         node->left = nodeHold->right;

        //         if (nodeHold->right != nil)
        //             nodeHold->right->parent = node;

        //         nodeHold->parent = node->parent;
        //         if (node->parent == nil)
        //         {
        //             root = nodeHold;
        //             root->color = BLACK;
        //         }
        //         else if (node == node->parent->right)
        //             node->parent->right = nodeHold;
        //         else
        //             node->parent->left = nodeHold;

        //         nodeHold->right = node;
        //         node->parent = nodeHold;
        //     }
        //     // make suitableRotation
        //     void suitableRotation(Node<value_type> *node)
        //     {
        //         if (node == node->parent->right && node->parent == node->parent->parent->left)
        //         {
        //             recolor(node);
        //             recolor(node->parent->parent);
        //             leftRotate(node->parent);
        //             rightRotate(node->parent);
        //         }
        //         else if (node == node->parent->left && node->parent == node->parent->parent->right)
        //         {
        //             recolor(node);
        //             recolor(node->parent->parent);
        //             rightRotate(node->parent);
        //             leftRotate(node->parent);
        //         }
        //         else if (node == node->parent->right && node->parent == node->parent->parent->right)
        //         {
        //             recolor(node->parent);
        //             recolor(node->parent->parent);
        //             leftRotate(node->parent->parent);
        //         }
        //         else if (node == node->parent->left && node->parent == node->parent->parent->left)
        //         {
        //             recolor(node->parent);
        //             recolor(node->parent->parent);
        //             rightRotate(node->parent->parent);
        //         }
        //     }
        //     // check the conflict
        //     bool conflict(Node<value_type> *node)
        //     {
        //         if (node && node->parent && node->color == RED && node->parent->color == RED)
        //             return (true);
        //         return (false);
        //     }
        //     // check the Tree
        //     void checkTree(Node<value_type> *newNode)
        //     {
        //         Node<value_type> *nodeParent, *nodeUncle;
        //         int  i = 0;
        //         while (conflict(newNode))
        //         {
        //             // get the new node parent and new node uncle
        //             nodeParent = newNode->parent;
        //             if (nodeParent->parent->left == nodeParent)
        //                 nodeUncle = nodeParent->parent->right;
        //             else
        //                 nodeUncle = nodeParent->parent->left;
        //             // check if the nodeUncle is RED
        //             if (nodeUncle->color == RED)
        //             {
        //                 recolor(nodeParent);
        //                 recolor(nodeUncle);
        //                 if (nodeParent->parent != root)
        //                     recolor(nodeParent->parent);
        //             }
        //             else
        //                 suitableRotation(newNode);
        //             // loop iteration
        //             newNode = newNode->parent->parent;
        //         }
        //     }
        //     void printHelper(Node<value_type> *root, std::string indent, bool last) {
        //         if (root != nil) {
        //             std::cout << indent;
        //             if (last) {
        //                 std::cout << "R----";
        //                 indent += "   ";
        //             } else {
        //                 std::cout << "L----";
        //                 indent += "|  ";
        //             }

        //           std::string sColor = root->color == RED ? "RED" : "BLACK";
        //           std::cout << root->pairv->first << "(" << sColor << ")" << std::endl;
        //           printHelper(root->left, indent, false);
        //           printHelper(root->right, indent, true);
        //         }
        //     }
		// public :
        //     void printTree()
        //     {
        //         if (root) {
        //           printHelper(root, "", true);
        //         }
        //     }
};

#endif
