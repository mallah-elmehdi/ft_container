#ifndef _PAIR_
#define _PAIR_

#include "ft.hpp"

template <class T1, class T2>
class pair
{
	public:
		//  +++++ Member types
		typedef T1      first_type;
		typedef T2      second_type;

	public:
		//  +++++ Member variables
		first_type      first;
		second_type     second;

	public:
		//  +++++ Member functions
		pair() : first(first_type()), second(second_type()) {}

		pair (const first_type& a, const second_type& b) : first(a), second(b) {}

		template<class U, class V>
		pair(const pair<U, V> &p) : first(p.first), second(p.second) {}

		pair& operator= (const pair& pr)
		{
			first = pr.first;
			second = pr.second;
			return (*this);
		}
};
// +++++ relational operators
template <class T1, class T2>
	bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return lhs.first==rhs.first && lhs.second==rhs.second; }

template <class T1, class T2>
	bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return !(lhs==rhs); }

template <class T1, class T2>
	bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

template <class T1, class T2>
	bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return !(rhs<lhs); }

template <class T1, class T2>
	bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return rhs<lhs; }

template <class T1, class T2>
	bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return !(lhs<rhs); }


#endif
