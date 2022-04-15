#ifndef _UTIL_HPP_
#define _UTIL_HPP_

#include "ft.hpp"

template <class Iterator, class Insert>
void fill_map(Iterator first, Iterator last, Insert insert)
{
	while (first != last)
	{
		insert(*first);
		first++;
	}
}

// template <class Iterator1, class Iterator2, class Allocator>
// void copy(Iterator1 first, Iterator1 last, Iterator2 result, Allocator allocator)
// {
// 	while (first != last)
// 	{
// 		allocator.construct(&*result, *first);
// 		result++;
// 		first++;
// 	}
// }

// template<class Iterator1, class Iterator2, class Allocator>
// void copy_backward(Iterator1 first, Iterator1 last, Iterator2 result, Allocator allocator)
// {
// 	while (last != first)
// 	{
// 		allocator.construct(&*(--result), *(--last));
// 	}
// }

// template <class T> void swap(T& a, T& b)
// {
// 	T c(a);
// 	a = b;
// 	b = c;
// }

#endif
