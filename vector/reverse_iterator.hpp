#ifndef _REVERSE_ITERATOR_HPP_
#define _REVERSE_ITERATOR_HPP_
// * LIBRARIES *
# include <iostream>
# include "iterator_traits.hpp"
// * FT NAMESPACE - [REVERSE ITERATOR] *
//vector class template
namespace ft
{
	template <class Iterator>
	class reverse_iterator {
		public:
			// + + + + + + + + + Member type
			typedef Iterator														iterator_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type			difference_type;
			typedef typename ft::iterator_traits<Iterator>::value_type				value_type;
			typedef typename ft::iterator_traits<Iterator>::pointer					pointer;
			typedef typename ft::iterator_traits<Iterator>::reference				reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category		iterator_category;
		private:
			Iterator iter;
		public:
			// + + + + + + + + + Member functions
			//default constuctor
			reverse_iterator(void) : iter() {}
			//test
			reverse_iterator(pointer ptr)
			{
				this->iter = ptr;
			}
			//copy constuctor
			reverse_iterator(const reverse_iterator &it) : iter(it.base()) {}
			// base
			pointer base(void) const
			{
				return this->iter;
			}
			// + + + + + + + + + Operator overload
			//operator=
			reverse_iterator& operator=(reverse_iterator const &it)
			{
				this->iter = it.iter;
				return (*this);
			}
			//operator==
			bool operator==(const reverse_iterator &it)
			{
				return (this->iter == it.iter);
			}
			//operator!=
			bool operator!=(const reverse_iterator &it)
			{
				return (this->iter != it.iter);
			}
			//operator*
			reference operator*(void) const
			{
				Iterator temp = this->iter;
				return *--temp;
			}
			//operator->
			pointer operator->(void) const
			{
				return &(operator*());;
			}
			//operator++ (pre)
			reverse_iterator& operator++(void)
			{
				this->iter--;
				return (*this);
			}
			//operator++ (post)
			reverse_iterator operator++(int)
			{
				reverse_iterator temp(*this);
				this->iter--;
				return (temp);
			}
			//operator-- (pre)
			reverse_iterator& operator--(void)
			{
				this->iter++;
				return (*this);
			}
			//operator-- (post)
			reverse_iterator operator--(int)
			{
				reverse_iterator temp(*this);
				this->iter++;
				return (temp);
			}
			//operator+
			reverse_iterator operator+(difference_type n) const
			{
				reverse_iterator temp(this->iter - n);
				return (temp);
			}
			//operator-
			reverse_iterator operator-(difference_type n) const
			{
				reverse_iterator temp(this->iter + n);
				return (temp);
			}
			//operator<
			bool operator<(const reverse_iterator &it)
			{
				return (this->iter > it.iter);
			}
			//operator>
			bool operator>(const reverse_iterator &it)
			{
				return (this->iter < it.iter);
			}
			//operator<=
			bool operator<=(const reverse_iterator &it)
			{
				return (this->iter >= it.iter);
			}
			//operator>=
			bool operator>=(const reverse_iterator &it)
			{
				return (this->iter <= it.iter);
			}
			//operator+=
			reverse_iterator& operator+=(difference_type n)
			{
				this->iter = this->iter - n;
				return (*this);
			}
			//operator-=
			reverse_iterator& operator-=(difference_type n)
			{
				this->iter = this->iter + n;
				return (*this);
			}
			//operator[]
			reference operator[](difference_type n) const
			{
				return (this->iter[n - 1]);
			}
	};
}
#endif
