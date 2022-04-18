#ifndef _RED_BLACK_TREE_UTIL_
#define _RED_BLACK_TREE_UTIL_

# define BLACK 1
# define RED 0

#include "ft.hpp"

template <class value_type, class compare, class allocator>
    class Red_Black_Tree {

		public:
			typedef ft::Node<value_type>								node;
			typedef typename allocator::template rebind<node>::other	rebind;

		protected:
            allocator	alloc;
            rebind		reb;
			compare		comp;
            // node		*nil;
            node		*root = NULL;

		public:
			// -------------------------------
			node *nil_node(node *parent)
			{
				node	*nil;
				nil = reb.allocate(sizeof(node));
				reb.construct(nil, node());

				nil->pairv = alloc.allocate(sizeof(value_type));
                alloc.construct(nil->pairv, ft::make_pair(typename value_type::first_type(), typename value_type::second_type()));

				nil->color = BLACK;
				nil->nil = true;
				nil->root = false;

                nil->right = NULL;
                nil->left = NULL;
                nil->parent = parent;

				return (nil);
			}
			// -------------------------------
            node *initPair(const value_type &val)
            {
                node *newNode;
				
				newNode = reb.allocate(sizeof(node));
				reb.construct(newNode, node());
				
				newNode->pairv = alloc.allocate(sizeof(value_type));
                alloc.construct(newNode->pairv, ft::make_pair(val.first, val.second));
				
				newNode->color = RED;
				newNode->nil = false;
				newNode->root = false;
                
                newNode->right = nil_node(newNode);
                newNode->left = nil_node(newNode);
                newNode->parent = NULL;
                
				return (newNode);
            }
			// -------------------------------
            bool insert(const value_type &val)
            {
                node *newNode = initPair(val);

                if (root == NULL)
                {
                    root = newNode;
                    root->root = true;
                    root->color = BLACK;
                }

                else
                {
                    node *nodeCheck = root;
                    node *nodeHold;
                    while (nodeCheck->nil == false)
                    {
                        nodeHold = nodeCheck;
						if (newNode->pairv->first == nodeCheck->pairv->first)
						{
							destroy(newNode);
							return(false);
						}
                        else if (comp(newNode->pairv->first, nodeCheck->pairv->first))
                            nodeCheck = nodeCheck->left;
						else
                            nodeCheck = nodeCheck->right;
                    }
                    newNode->parent = nodeHold;
                    if (comp(newNode->pairv->first, nodeHold->pairv->first))
					{
						destroy(nodeHold->left);
                        nodeHold->left = newNode;
					}
                    else
					{
						destroy(nodeHold->right);
                        nodeHold->right = newNode;
					}
                    checkTree(newNode);
                }
                return(true);
            }
			void destroy(node *_node)
			{
				if (_node->right && _node->right->nil) destroy_node(_node->right);
				if (_node->left && _node->left->nil) destroy_node(_node->left);
				destroy_node(_node);
			}
			void destroy_node(node *_node)
			{
				alloc.destroy(_node->pairv);
				alloc.deallocate(_node->pairv, sizeof(value_type));
				_node->pairv = NULL; 
				
				reb.destroy(_node);
				reb.deallocate(_node, sizeof(node));
				_node = NULL;
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
			node *end() const
			{
                node* nodeCheck = this->root;

				while (nodeCheck->nil == false)
				{
					nodeCheck = nodeCheck->right;
				}
				return (nodeCheck);
			}
			//-------------------------------
			node *get_root() const
			{
				return (this->root);
			}
			// -------------------------------
            void recolor(node *_node)
            {
                if (_node->color == RED) _node->color = BLACK;
                else _node->color = RED;
            }
			// -------------------------------
            void leftRotate(node *_node)
            {
                node *nodeHold = _node->right;
                _node->right = nodeHold->left;

                if (nodeHold->left->nil == false)
                    nodeHold->left->parent = _node;

                nodeHold->parent = _node->parent;

                if (_node->parent == NULL)
                {
                    root = nodeHold;
                    root->color = BLACK;
                }
                else if (_node == _node->parent->left)
                    _node->parent->left = nodeHold;
                else
                    _node->parent->right = nodeHold;

                nodeHold->left = _node;
                _node->parent = nodeHold;

            }
			// -------------------------------
            void rightRotate(node *_node)
            {
                node *nodeHold = _node->left;
                _node->left = nodeHold->right;

                if (nodeHold->right->nil == false)
                    nodeHold->right->parent = _node;

                nodeHold->parent = _node->parent;
                if (_node->parent == NULL)
                {
                    root = nodeHold;
                    root->color = BLACK;
                }
                else if (_node == _node->parent->right)
                    _node->parent->right = nodeHold;
                else
                    _node->parent->left = nodeHold;

                nodeHold->right = _node;
                _node->parent = nodeHold;
            }
			// -------------------------------
            void suitableRotation(node *_node)
            {
                if (_node == _node->parent->right && _node->parent == _node->parent->parent->left)
                {
                    recolor(_node);
                    recolor(_node->parent->parent);
                    leftRotate(_node->parent);
                    rightRotate(_node->parent);
                }
                else if (_node == _node->parent->left && _node->parent == _node->parent->parent->right)
                {
                    recolor(_node);
                    recolor(_node->parent->parent);
                    rightRotate(_node->parent);
                    leftRotate(_node->parent);
                }
                else if (_node == _node->parent->right && _node->parent == _node->parent->parent->right)
                {
                    recolor(_node->parent);
                    recolor(_node->parent->parent);
                    leftRotate(_node->parent->parent);
                }
                else if (_node == _node->parent->left && _node->parent == _node->parent->parent->left)
                {
                    recolor(_node->parent);
                    recolor(_node->parent->parent);
                    rightRotate(_node->parent->parent);
                }
            }
			// -------------------------------
            bool conflict(node *_node)
            {
                if (_node && _node->parent && _node->color == RED && _node->parent->color == RED)
                    return (true);
                return (false);
            }
			// -------------------------------
            void checkTree(node *newNode)
            {
                node *nodeParent, *nodeUncle;
                int  i = 0;
                while (conflict(newNode))
                {
                    // get the new node parent and new node uncle
                    nodeParent = newNode->parent;
                    if (nodeParent->parent->left == nodeParent)
                        nodeUncle = nodeParent->parent->right;
                    else
                        nodeUncle = nodeParent->parent->left;
                    // check if the nodeUncle is RED
                    if (nodeUncle->color == RED)
                    {
                        recolor(nodeParent);
                        recolor(nodeUncle);
                        if (nodeParent->parent != root)
                            recolor(nodeParent->parent);
                    }
                    else
                        suitableRotation(newNode);
                    // loop iteration
					if (newNode->parent == NULL)
						break;
					newNode = newNode->parent->parent;
                }
            }
			// -------------------------------
			size_t num_of_child(node *_node)
			{
				size_t child = 0;
				if (_node->right->nil == false) child++;
				if (_node->left->nil == false) child++;
				return (child);
			}
			// -------------------------------
			node *replace_children_2(node *_node)
			{
				node *nodeHold = _node->right;
				node *nodeSmall;
				// node *nodeTemp = _node;
				
				while (nodeHold->nil == false)
				{
					nodeSmall = nodeHold;
					nodeHold = nodeHold->left;
				}

				nodeHold = _node;
				_node = nodeSmall;
				nodeSmall = nodeHold;
				return (_node);
			}
			node *replace_children_1(node *_node)
			{
				node *nodeChild = _node->left->nil ? _node->right : _node->left;
				node *nodeHold = nodeChild;

				nodeChild = _node;
				_node = nodeHold;
				return (_node);
			}
			// -------------------------------
			bool del(node *_node)
			{
				size_t number_of_children = num_of_child(_node);
				if (number_of_children == 2)
				{
					return (del(replace_children_2(_node)));
				}
				else if (number_of_children == 1)
				{
					return (del(replace_children_1(_node)));
				}
				else
				{
					if (_node->color == RED)
					{
						
					}
				}
			}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
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
