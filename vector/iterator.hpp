#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_
// * FT NAMESPACE - [ITERATOR] *
namespace ft {
	//include libraries
	# include <iostream>
	//vector class template
	template <class T>
	class iterator {
		public:
			// + + + + + + + + + Member type
			typedef T																	value_type;
			typedef std::ptrdiff_t										difference_type;
			typedef T*  															pointer;
			typedef T&																reference;
			typedef std::random_access_iterator_tag		iterator_category;
		private:
			pointer iter;
		public:
			// + + + + + + + + + Member functions
			//default constuctor
			iterator(void) : iter() {}
			//copy constuctor
			iterator(const iterator &it)
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
			iterator& operator=(iterator const &it)
			{
				this->iter = it.iter;
				return (*this);
			}
			//operator==
			bool operator==(const iterator &it)
			{
				return (this->iter == it.iter);
			}
			//operator!=
			bool operator!=(const iterator &it)
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
			iterator& operator++(void)
			{
				this->iter++;
				return (*this);
			}
			//operator++ (post)
			iterator operator++(int)
			{
				iterator temp(*this);
				this->iter++;
				return (temp);
			}
			//operator-- (pre)
			iterator& operator--(void)
			{
				this->iter--;
				return (*this);
			}
			//operator-- (post)
			iterator operator--(int)
			{
				iterator temp(*this);
				this->iter--;
				return (temp);
			}
			//operator+
			iterator operator+(difference_type n) const
			{
				iterator temp(*this);
				for (difference_type i = 0; i < n; i++)
					++temp
				return (temp);
			}
			//operator-
			iterator operator-(difference_type n) const
			{
				iterator temp(*this);
				for (difference_type i = 0; i < n; i++)
					--temp
				return (temp);
			}
			//operator<
			bool operator<(const iterator &it)
			{
				return (this->iter < it.iter)
			}
			//operator>
			bool operator>(const iterator &it)
			{
				return (this->iter > it.iter)
			}
			//operator<=
			bool operator<=(const iterator &it)
			{
				return (this->iter <= it.iter)
			}
			//operator>=
			bool operator>=(const iterator &it)
			{
				return (this->iter >= it.iter)
			}
			//operator+=
			iterator& operator+=(difference_type n)
			{
				this->iter = this->iter + n;
				return (this);
			}
			//operator-=
			iterator& operator-=(difference_type n)
			{
				this->iter = this->iter - n;
				return (this);
			}
			//operator[]
			reference operator[](difference_type n) const
			{
				return (this->iter[n]);
			}
	};

}
#endif
