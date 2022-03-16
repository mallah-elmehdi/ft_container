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
			typedef T									value_type; 
			/* typedef Distance  							difference_type; */
			typedef T*  								pointer; 
			typedef T&									reference; 
			typedef std::random_access_iterator_tag		iterator_category;
		private:
			T* iter;
		public:
			// + + + + + + + + + Member functions
			//default constuctor
			iterator() {}
			//copy constuctor
			iterator(iterator const &it)
			{
				this->iter = it.iter;
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
			reference operator*(void)
			{
				return *this->iter;
			}
			//operator->
			pointer operator->(void)
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
				iterator<value_type> temp(*this);
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
			iterator operator++(int)
			{
				iterator<value_type> temp(*this);
				this->iter--;
				return (temp);
			}
			// * --------------------------------------------- DONE 
			// ! operator+
			iterator operator+(value_type n) const
			{
				iterator<value_type> temp(*this )
				return (this->iter + n);
			}
			// ! operator-
			iterator operator-(value_type n) const
			{
				this->iter = this->iter - n;
				return (this);
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
			bool operator<(const iterator &it)
			{
				return (this->iter <= it.iter)
			}
			//operator>=
			bool operator>(const iterator &it)
			{
				return (this->iter >= it.iter)
			}
			//operator+=
			/* iterator operator+=(value_type n)
			{
				this->iter = this->iter + n;
				return (this);
			} */
			//operator-=
			/* iterator operator-(value_type n) const
			{
				this->iter = this->iter - n;
				return (this);
			} */
			T& operator[](int n)
			{
				return (this->iter[n]);
			}
	};

}
#endif