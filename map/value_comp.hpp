#ifndef _VALUE_COMP_
#define _VALUE_COMP_

#include "map.hpp"
#include "pair.hpp"

namespace ft
{
	template <class Key, class T, class Compare, class Alloc>
	class value_comp
	{
		protected:
			Compare compare;
			value_comp (Compare c) : comp(c) {}
		public:
            typedef ft::pair<const Key, T>		value_type;
			typedef value_comp					value_compare;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return compare(x.first, y.first);
			}
    };
}

#endif
