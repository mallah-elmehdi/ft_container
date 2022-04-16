#ifndef _NODE_
#define _NODE_

#include "ft.hpp"

class Node {
	public:
		Node	*parent;
		Node	*left;
		Node	*right;
		int		color;
		bool	root;
		bool	nil;

		virtual void ok() {};
};

template <class value_type>
class NodePair : public Node {
	public:
		value_type	pairv;
};

#endif
