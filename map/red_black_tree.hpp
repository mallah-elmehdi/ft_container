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
            node		*nil;
            node		*root = NULL;

		public:
			Red_Black_Tree()
			{
				nil = nil_node(NULL);
			}
			// -------------------------------
			node *nil_node(node *parent)
			{
				node	*nil;
				nil = reb.allocate(sizeof(node));
				reb.construct(nil, node());

				nil->pairv = nil_pair();

				nil->color = BLACK;
				nil->nil = true;
				nil->root = false;

                nil->right = NULL;
                nil->left = NULL;
                nil->parent = parent;

				return (nil);
			}
			// -------------------------------
			value_type *nil_pair()
			{
				value_type *_pair = alloc.allocate(sizeof(value_type));
                alloc.construct(_pair, ft::make_pair(typename value_type::first_type(), typename value_type::second_type()));
				return (_pair);
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
				destroy_pair(_node->pairv);
				
				reb.destroy(_node);
				reb.deallocate(_node, sizeof(node));

				_node = NULL;
			}
			void destroy_pair(value_type *_pair)
			{
				alloc.destroy(_pair);
				alloc.deallocate(_pair, sizeof(value_type));
			}
			// -------------------------------
			node *first() const
			{
				node* nodeCheck = this->root;
				node* nodeHold = nodeCheck;

				if (nodeHold == NULL)
					return (nil);

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

				if (nodeHold == NULL)
					return (nil);

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

				if (nodeCheck == NULL)
					return (nil);

				while (nodeCheck->nil == false)
				{
					nodeCheck = nodeCheck->right;
				}
				return (nodeCheck);
			}
			//-------------------------------
			node *begin() const
			{
                node* nodeCheck = this->root;

				if (nodeCheck == NULL)
					return (nil);

				while (nodeCheck->nil == false)
				{
					nodeCheck = nodeCheck->left;
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
                    root->root = true;
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
                    root->root = true;
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
			void swap_colors(node *_node1, node *_node2)
			{
				int color = _node1->color;
				_node1->color = _node2->color;
				_node2->color = color;
			}
			// -------------------------------
			node *replace_children_2(node *_node)
			{
				node *nodeSmall = _node->right;
				value_type *pairHold;
				
				while (nodeSmall->nil == false)
				{
					nodeSmall = nodeSmall->left;
				}
				nodeSmall = nodeSmall->parent;

				pairHold = _node->pairv;
				
				_node->pairv = nodeSmall->pairv;
				nodeSmall->pairv = pairHold;

				return (nodeSmall);
			}
			node *replace_children_1(node *_node)
			{
				node *nodeChild = _node->left->nil ? _node->right : _node->left;
				value_type *pairHold;

				pairHold = _node->pairv;
				
				_node->pairv = nodeChild->pairv;
				nodeChild->pairv = pairHold;

				return (nodeChild);
			}
			// -------------------------------
			bool all_family_black(node *_node)
			{
				if (_node == NULL)
					std::cout << "----------- _node hnaaaaaaaaaaaaaaaaaaaaaaaaa\n";
				if (_node->right == NULL)
					std::cout << "----------- right hnaaaaaaaaaaaaaaaaaaaaaaaaa\n";
				if (_node->left == NULL)
					std::cout << "----------- left hnaaaaaaaaaaaaaaaaaaaaaaaaa\n";
				return (_node->color == BLACK && _node->right->color == BLACK && _node->left->color == BLACK);
			}
			// ------------------------------- 
			bool check_family_color_1(node *_node, node *nodeSibling)
			{
				if (_node->parent->left == _node)
				{
					if (nodeSibling->left->color == RED && nodeSibling->right->color == BLACK)
						return (true);
					return (false);
				}
				else
				{
					if (nodeSibling->right->color == RED && nodeSibling->left->color == BLACK)
						return (true);
				}
				return (false);
			}
			// ------------------------------- 
			bool check_family_color_2(node *_node, node *nodeSibling)
			{
				if (_node->parent->left == _node)
				{
					if (nodeSibling->right->color == RED)
						return (true);
					return (false);
				}
				else
				{
					if (nodeSibling->left->color == RED)
						return (true);
				}
				return (false);
			}
			// -------------------------------
			node *near_node_child_sibling(node *_node, node *nodeSibling)
			{
				if (_node->parent->left == _node)
					return (nodeSibling->left);
				return (nodeSibling->right);
			}
			// -------------------------------
			node *far_node_child_sibling(node *_node, node *nodeSibling)
			{
				if (_node->parent->right == _node)
					return (nodeSibling->left);
				return (nodeSibling->right);
			}
			// -------------------------------
			bool check_sibling(node *_node)
			{
				node *nodeSibling;
				
				nodeSibling = _node->parent->right == _node ? _node->parent->left : _node->parent->right;

				if (nodeSibling->nil || all_family_black(nodeSibling))
				{
					nodeSibling->color = RED;
					if (_node->parent->color == RED)
					{
						_node->parent->color = BLACK;
						return (true);
					}
					return (false);
				}
				else if (nodeSibling->color == RED)
				{
					nodeSibling->color = BLACK;
					_node->parent->color = RED;
					if (_node->parent->left == _node)
						leftRotate(_node->parent);
					else
						rightRotate(_node->parent);
					return (false);
				}
				else if (check_family_color_1(_node, nodeSibling))
				{
					node *nodeNearChildSibling = near_node_child_sibling(_node, nodeSibling);
					
					nodeSibling->color = RED;
					nodeNearChildSibling->color = BLACK;
					
					if (_node->parent->left == _node)
						rightRotate(nodeSibling);
					else
						leftRotate(nodeSibling);
				}
				else if (check_family_color_2(_node, nodeSibling))
				{
					node *nodeFarChildSibling = far_node_child_sibling(_node, nodeSibling);

					swap_colors(_node->parent, nodeSibling);

					nodeFarChildSibling->color = BLACK;

					if (_node->parent->left == _node)
						leftRotate(_node->parent);
					else
						rightRotate(_node->parent);

					return (true);
				}
				return (false);
			}
			// -------------------------------
			void del_after_replace(node *_node)
			{
				node *nodeHold = _node;
				while (_node->color == BLACK)
				{
					if (_node->root) break;
					if (check_sibling(_node)) break;
					_node = _node->parent;
				}
				destroy_node(nodeHold->left);
				destroy_node(nodeHold->right);
				destroy_pair(nodeHold->pairv);
				nodeHold->left = NULL;
				nodeHold->right = NULL;
				nodeHold->pairv = nil_pair();
				nodeHold->nil = true;
				nodeHold->root = false;
				nodeHold->color = BLACK;
				// destroy(nodeHold);
			}
			// -------------------------------
			void del(node *_node)
			{
				while (num_of_child(_node) != 0)
				{
					if (num_of_child(_node) == 2)
					{
						_node = replace_children_2(_node);
					}
					else if (num_of_child(_node) == 1)
					{
						_node = replace_children_1(_node);
					}
				}
				// std::cout << "_node->color : " << _node->color <<"\n";
				del_after_replace(_node);
			}
			void clear()
			{
				destroy(nil);
				nil = NULL;
			}
			void clearRoot()
			{
				root = NULL;
			}
			node *search(const value_type &val) const
			{
				if (root == NULL)
					return (end());

				node *nodeCheck = root;
				
				while (nodeCheck->nil == false)
				{
					if (val.first == nodeCheck->pairv->first)
					{
						return(nodeCheck);
					}
					else if (comp(val.first, nodeCheck->pairv->first))
						nodeCheck = nodeCheck->left;
					else
						nodeCheck = nodeCheck->right;
				}
				return (end());
			}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            void printHelper(Node<value_type> *root, std::string indent, bool last) {
                if (root != NULL) {
                    std::cout << indent;
                    if (last) {
                        std::cout << "R----";
                        indent += "   ";
                    } else {
                        std::cout << "L----";
                        indent += "|  ";
                    }

                  std::string sColor = root->color == RED ? "RED" : "BLACK";
                  std::cout << root->pairv->first << "(" << sColor << ")" << std::endl;
                  printHelper(root->left, indent, false);
                  printHelper(root->right, indent, true);
                }
            }
            void printTree()
            {
                if (root) {
                  printHelper(root, "", true);
                }
            }
};

#endif
