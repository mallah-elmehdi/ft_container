#ifndef _LESS_
#define _LESS_

#include "ft.hpp"

template <class T>
class less
{
	public:
		typedef T       first_argument_type;
		typedef T       second_argument_type;
		typedef bool    result_type;

	public:
		bool operator() (const T& x, const T& y) const {return x < y;}

};


#endif
