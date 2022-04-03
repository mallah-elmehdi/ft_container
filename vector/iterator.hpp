#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_
// * LIBRARIES *
# include <iterator>
// * FT NAMESPACE - [ITERATOR] *
namespace ft
{
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
			ra_iterator(void) : iter() {}
			//iterator with ptr param
			ra_iterator(pointer ptr)
			{
				iter = ptr;
			}
			//copy constuctor
			ra_iterator(const ra_iterator &it)
			{
				iter = it.iter;
			}
			// base
			pointer base(void) const
			{
				return iter;
			}
			// + + + + + + + + + Operator overload
			//operator=
			ra_iterator& operator=(ra_iterator const &it)
			{
				iter = it.iter;
				return (*this);
			}
			//operator==
			bool operator==(const ra_iterator &it)
			{
				return (iter == it.iter);
			}
			//operator!=
			bool operator!=(const ra_iterator &it)
			{
				return (iter != it.iter);
			}
			//operator*
			reference operator*(void) const
			{
				return *iter;
			}
			//operator->
			pointer operator->(void) const
			{
				return iter;
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
			//operator-
			ra_iterator operator-(difference_type n) const
			{
				ra_iterator temp(iter - n);
				return (temp);
			}
			difference_type operator-(const ra_iterator& _it)
			{
				return (iter - _it.iter);
			}
			//operator<
			bool operator<(const ra_iterator &it)
			{
				return (iter < it.iter);
			}
			//operator>
			bool operator>(const ra_iterator &it)
			{
				return (iter > it.iter);
			}
			//operator<=
			bool operator<=(const ra_iterator &it)
			{
				return (iter <= it.iter);
			}
			//operator>=
			bool operator>=(const ra_iterator &it)
			{
				return (iter >= it.iter);
			}
			//operator+=
			ra_iterator& operator+=(difference_type n)
			{
				iter = iter + n;
				return (*this);
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
}

#endif
