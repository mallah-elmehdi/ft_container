#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_
// * LIBRARIES *
# include <iostream>
# include <cstddef>
// * FT NAMESPACE - [ITERATOR] *
//vector class template
template <class T>
class ra_iterator {
	public:
		// + + + + + + + + + Member type
		typedef T																	value_type;
		typedef std::ptrdiff_t													difference_type;
		typedef T*  															pointer;
		typedef T&																	reference;
		typedef std::random_access_iterator_tag				iterator_category;
	private:
		pointer iter;
	public:
		// + + + + + + + + + Member functions
		//default constuctor
		ra_iterator(void) : iter() {}
		//test
		ra_iterator(pointer ptr)
		{
			this->iter = ptr;
		}
		//copy constuctor
		ra_iterator(const ra_iterator &it)
		{
			this->iter = it.iter;
		}
		// base
		pointer base(void) const
		{
			return this->iter;
		}
		// + + + + + + + + + Operator overload
		//operator=
		ra_iterator& operator=(ra_iterator const &it)
		{
			this->iter = it.iter;
			return (*this);
		}
		//operator==
		bool operator==(const ra_iterator &it)
		{
			return (this->iter == it.iter);
		}
		//operator!=
		bool operator!=(const ra_iterator &it)
		{
			return (this->iter != it.iter);
		}
		//operator*
		reference operator*(void) const
		{
			return *this->iter;
		}
		//operator->
		pointer operator->(void) const
		{
			return this->iter;
		}
		//operator++ (pre)
		ra_iterator& operator++(void)
		{
			this->iter++;
			return (*this);
		}
		//operator++ (post)
		ra_iterator operator++(int)
		{
			ra_iterator temp(*this);
			this->iter++;
			return (temp);
		}
		//operator-- (pre)
		ra_iterator& operator--(void)
		{
			this->iter--;
			return (*this);
		}
		//operator-- (post)
		ra_iterator operator--(int)
		{
			ra_iterator temp(*this);
			this->iter--;
			return (temp);
		}
		//operator+
		ra_iterator operator+(difference_type n) const
		{
			ra_iterator temp(this->iter + n);
			return (temp);
		}
		//operator-
		ra_iterator operator-(difference_type n) const
		{
			ra_iterator temp(this->iter - n);
			return (temp);
		}
		//operator<
		bool operator<(const ra_iterator &it)
		{
			return (this->iter < it.iter);
		}
		//operator>
		bool operator>(const ra_iterator &it)
		{
			return (this->iter > it.iter);
		}
		//operator<=
		bool operator<=(const ra_iterator &it)
		{
			return (this->iter <= it.iter);
		}
		//operator>=
		bool operator>=(const ra_iterator &it)
		{
			return (this->iter >= it.iter);
		}
		//operator+=
		ra_iterator& operator+=(difference_type n)
		{
			this->iter = this->iter + n;
			return (*this);
		}
		//operator-=
		ra_iterator& operator-=(difference_type n)
		{
			this->iter = this->iter - n;
			return (*this);
		}
		//operator[]
		reference operator[](difference_type n) const
		{
			return (this->iter[n]);
		}
};

#endif
