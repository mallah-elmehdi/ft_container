#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_
// * LIBRARIES *
# include <iterator>
// * FT NAMESPACE - [ITERATOR] *
namespace ft
{
	//vector class template
	template <class T>
	class iterator {
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
			iterator(void) : iter() {}
			//iterator with ptr param
			iterator(pointer ptr)
			{
				iter = ptr;
			}
			//copy constuctor
			template <class Ty>
			iterator(const iterator<Ty> &it) : iter(it.base()) {}
			// base
			pointer base(void) const
			{
				return iter;
			}
			// + + + + + + + + + Operator overload
			//operator=
			iterator& operator=(iterator const &it)
			{
				iter = it.iter;
				return (*this);
			}
			//operator==
			bool operator==(const iterator &it)
			{
				return (iter == it.iter);
			}
			//operator!=
			bool operator!=(const iterator &it)
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
			iterator& operator++(void)
			{
				iter++;
				return (*this);
			}
			//operator++ (post)
			iterator operator++(int)
			{
				iterator temp(*this);
				iter++;
				return (temp);
			}
			//operator-- (pre)
			iterator& operator--(void)
			{
				iter--;
				return (*this);
			}
			//operator-- (post)
			iterator operator--(int)
			{
				iterator temp(*this);
				iter--;
				return (temp);
			}
			//operator+
			iterator operator+(difference_type n) const
			{
				iterator temp(iter + n);
				return (temp);
			}
			//operator-
			iterator operator-(difference_type n) const
			{
				iterator temp(iter - n);
				return (temp);
			}
			difference_type operator-(const iterator& _it)
			{
				return (iter - _it.iter);
			}
			//operator<
			bool operator<(const iterator &it)
			{
				return (iter < it.iter);
			}
			//operator>
			bool operator>(const iterator &it)
			{
				return (iter > it.iter);
			}
			//operator<=
			bool operator<=(const iterator &it)
			{
				return (iter <= it.iter);
			}
			//operator>=
			bool operator>=(const iterator &it)
			{
				return (iter >= it.iter);
			}
			//operator+=
			iterator& operator+=(difference_type n)
			{
				iter = iter + n;
				return (*this);
			}
			//operator-=
			iterator& operator-=(difference_type n)
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
