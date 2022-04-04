#ifndef _REVERSE_ITERATOR_HPP_
#define _REVERSE_ITERATOR_HPP_
// * LIBRARIES *
# include <iostream>
# include "iterator_traits.hpp"
// * FT NAMESPACE - [REVERSE ITERATOR] *
namespace ft
{
template <class Iterator>
class ra_reverse_iterator {
	public:
		// + + + + + + + + + Member type
		typedef Iterator													iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type			difference_type;
		typedef typename iterator_traits<Iterator>::value_type				value_type;
		typedef typename iterator_traits<Iterator>::pointer					pointer;
		typedef typename iterator_traits<Iterator>::reference				reference;
		typedef typename iterator_traits<Iterator>::iterator_category		iterator_category;
	private:
		Iterator iter;
	public:
		// + + + + + + + + + Member functions
		//default constuctor
		ra_reverse_iterator(void) : iter() {}
		//copy constuctor
		explicit ra_reverse_iterator(Iterator x) : iter(x) {}
		template <class Ty>
		ra_reverse_iterator(const ra_reverse_iterator<Ty> &it) : iter(it.base()) {}
		// base
		Iterator base(void) const
		{
			return iter;
		}
		// + + + + + + + + + Operator overload
		//operator=
		ra_reverse_iterator& operator=(ra_reverse_iterator const &it)
		{
			iter = it.base();
			return (*this);
		}
		//operator*
		reference operator*(void) const
		{
			Iterator tmp = iter;
			return *--tmp;
		}
		//operator->
		pointer operator->(void) const
		{
			return &(operator*());;
		}
		//operator++ (pre)
		ra_reverse_iterator& operator++(void)
		{
			iter--;
			return (*this);
		}
		//operator++ (post)
		ra_reverse_iterator operator++(int)
		{
			ra_reverse_iterator temp(*this);
			iter--;
			return (temp);
		}
		//operator-- (pre)
		ra_reverse_iterator& operator--(void)
		{
			iter++;
			return (*this);
		}
		//operator-- (post)
		ra_reverse_iterator operator--(int)
		{
			ra_reverse_iterator temp(*this);
			iter++;
			return (temp);
		}
		//operator+
		ra_reverse_iterator operator+(difference_type n) const
		{
			ra_reverse_iterator temp(iter - n);
			return (temp);
		}
		//operator+=
		ra_reverse_iterator& operator+=(difference_type n)
		{
			iter = iter - n;
			return (*this);
		}
		//operator-
		ra_reverse_iterator operator-(difference_type n) const
		{
			ra_reverse_iterator temp(iter + n);
			return (temp);
		}
		//operator-=
		ra_reverse_iterator& operator-=(difference_type n)
		{
			iter = iter + n;
			return (*this);
		}
		//operator[]
		reference operator[](difference_type n) const
		{
			return (iter[n - 1]);
		}
};
template <class Iterator>
bool operator==(const ra_reverse_iterator<Iterator>& x, const ra_reverse_iterator<Iterator>& y)
{
	return (x.base() == y.base());
}
template <class Iterator>
bool operator<(const ra_reverse_iterator<Iterator>& x, const ra_reverse_iterator<Iterator>& y)
{
	return (x.base() > y.base());
}
template <class Iterator>
bool operator!=(const ra_reverse_iterator<Iterator>& x, const ra_reverse_iterator<Iterator>& y)
{
	return (x.base() != y.base());
}
template <class Iterator>
bool operator>(const ra_reverse_iterator<Iterator>& x, const ra_reverse_iterator<Iterator>& y)
{
	return (x.base() < y.base());
}
template <class Iterator>
bool operator>=(const ra_reverse_iterator<Iterator>& x, const ra_reverse_iterator<Iterator>& y)
{
	return (x.base() <= y.base());
}
template <class Iterator>
bool operator<=(const ra_reverse_iterator<Iterator>& x, const ra_reverse_iterator<Iterator>& y)
{
	return (x.base() >= y.base());
}
template <class Iterator>
typename ra_reverse_iterator<Iterator>::difference_type operator-(const ra_reverse_iterator<Iterator>& x, const ra_reverse_iterator<Iterator>& y)
{
	return (y.base() - x.base());
}
template <class Iterator>
	ra_reverse_iterator<Iterator>operator+(typename ra_reverse_iterator<Iterator>::difference_type n, const ra_reverse_iterator<Iterator>& x)
{
	return (ra_reverse_iterator<Iterator> (x.base() - n));
}
}
#endif
