#ifndef _NODE_
#define _NODE_

#include "ft.hpp"

template <class value_type>
class Node {
	public:
		// attribute
		value_type				*pairv;
		Node<value_type>		*parent;
		Node<value_type>		*left;
		Node<value_type>		*right;
		int						color;
		bool					nil;
};

template <class value_type>
class Node<const value_type> {
	public:
		// attribute
		const value_type			*pairv;
		Node<const value_type>		*parent;
		Node<const value_type>		*left;
		Node<const value_type>		*right;
		int							color;
		bool						nil;
};

#endif
