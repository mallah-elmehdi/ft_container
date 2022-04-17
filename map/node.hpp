#ifndef _NODE_
#define _NODE_

#include "ft.hpp"

template <class value_type>
class Node {
	public:
		value_type	*pairv;
		Node		*parent;
		Node		*left;
		Node		*right;
		int			color;
		bool		root;
		bool		nil;
};

#endif
