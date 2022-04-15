#ifndef _FT_
#define _FT_

# include <iostream>
# include <iterator>
# include <stdexcept>
# include <memory>
# include <cstddef>

namespace ft
{
	// VECTOR
	#include "vector/equal.hpp"
	#include "vector/lexicographical_compare.hpp"
	#include "vector/iterator.hpp"
	#include "vector/reverse_iterator.hpp"

	// MAP
	#include "map/map.hpp"
	#include "map/less.hpp"
	#include "map/node.hpp"
	#include "map/value_comp.hpp"
	#include "map/make_pair.hpp"
	#include "map/pair.hpp"
	#include "map/reverse_iterator.hpp"
	#include "map/red_black_tree.hpp"
	#include "map/rbt_util.hpp"
	#include "map/iterator.hpp"

}

#endif