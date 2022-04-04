#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_
// * LIBRARIES *
# include <iterator>
// * FT NAMESPACE - [ITERATOR] *
//vector class template
template <class T>
class ra_iterator {
	public:
		// + + + + + + + + + Member type
		typedef T										value_type;
		typedef ptrdiff_t								difference_type;
		typedef T*  									pointer;
		typedef T&										reference;
		typedef std::random_access_iterator_tag			iterator_category;
	private:
		pointer iter;
	public:
		// + + + + + + + + + Member functions
		//default constuctor
		ra_iterator() : iter() {}
		//copy constuctor
		explicit ra_iterator(pointer x) : iter(x) {}
		template <class Ty>
		ra_iterator(const ra_iterator<Ty> &it) : iter(it.base()) {}
		// base
		pointer base(void) const
		{
			return iter;
		}
		// + + + + + + + + + Operator overload
		//operator=
		ra_iterator& operator=(ra_iterator const &it)
		{
			iter = it.base();
			return (*this);
		}
		//operator*
		reference operator*(void) const
		{
			pointer tmp = iter;
			return *tmp;
		}
		//operator->
		pointer operator->(void) const
		{
			return &(operator*());;
		}
		//operator++ (pre)
		ra_iterator& operator++(void)
		{
			iter++;
			return (*this);
		}
		//operator++ (post)
		ra_iterator operator++(int)
		{
			ra_iterator temp(*this);
			iter++;
			return (temp);
		}
		//operator-- (pre)
		ra_iterator& operator--(void)
		{
			iter--;
			return (*this);
		}
		//operator-- (post)
		ra_iterator operator--(int)
		{
			ra_iterator temp(*this);
			iter--;
			return (temp);
		}
		//operator+
		ra_iterator operator+(difference_type n) const
		{
			ra_iterator temp(iter + n);
			return (temp);
		}
		//operator+=
		ra_iterator& operator+=(difference_type n)
		{
			iter = iter + n;
			return (*this);
		}
		//operator-
		ra_iterator operator-(difference_type n) const
		{
			ra_iterator temp(iter - n);
			return (temp);
		}
		//operator-=
		ra_iterator& operator-=(difference_type n)
		{
			iter = iter - n;
			return (*this);
		}
		//operator[]
		reference operator[](difference_type n) const
		{
			return (iter[n]);
		}
};
template <class Iterator>
bool operator==(const ra_iterator<Iterator>& x, const ra_iterator<Iterator>& y)
{
	return (x.base() == y.base());
}
template <class Iterator>
bool operator<(const ra_iterator<Iterator>& x, const ra_iterator<Iterator>& y)
{
	return (x.base() < y.base());
}
template <class Iterator>
bool operator!=(const ra_iterator<Iterator>& x, const ra_iterator<Iterator>& y)
{
	return (x.base() != y.base());
}
template <class Iterator>
bool operator>(const ra_iterator<Iterator>& x, const ra_iterator<Iterator>& y)
{
	return (x.base() > y.base());
}
template <class Iterator>
bool operator>=(const ra_iterator<Iterator>& x, const ra_iterator<Iterator>& y)
{
	return (x.base() >= y.base());
}
template <class Iterator>
bool operator<=(const ra_iterator<Iterator>& x, const ra_iterator<Iterator>& y)
{
	return (x.base() <= y.base());
}
template <class Iterator>
typename ra_iterator<Iterator>::difference_type operator-(const ra_iterator<Iterator>& x, const iterator<Iterator>& y)
{
	return (x.base() - y.base());
}
template <class Iterator>
	iterator<Iterator>operator+(typename iterator<Iterator>::difference_type n, const iterator<Iterator>& x)
{
	return (iterator<Iterator> (x.base() + n));
}
#endif
