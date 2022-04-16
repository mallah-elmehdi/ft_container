#ifndef _RBT_TRAITS_HPP
#define _RBT_TRAITS_HPP

template <class _key_type, class _mapped_type, class _value_type, class _node>
class Rbt_Traits
{
	public:
		typedef _key_type		key_type;
		typedef _mapped_type	mapped_type;
		typedef _value_type		value_type;
		typedef _node			node;
};

#endif
