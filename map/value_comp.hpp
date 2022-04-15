#ifndef _VALUE_COMP_
#define _VALUE_COMP_

#include "map.hpp"
#include "pair.hpp"

namespace ft
{
	template <class Key, class T, class Compare, class Alloc>
	class value_comp
	{
		friend ft::map;
		
		protected:
			Compare comp;
			value_comp (Compare c) : comp(c) {}
		
		public:
			typedef bool								result_type;
			typedef value_type							first_argument_type;
			typedef value_type							second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
	};
}

#endif
