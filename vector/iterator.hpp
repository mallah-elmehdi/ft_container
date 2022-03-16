#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_
// * FT NAMESPACE - [ITERATOR] * 
namespace ft {
	template <class T>
	class iterator {
		public:
			// + + + + + + + + + Member type
			/* typedef T         value_type; */
			/* typedef Distance  difference_type; */
			/* typedef Pointer   pointer; */
			/* typedef Reference reference; */
			/* typedef Category  iterator_category; */
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
			bool operator==(const iterator& it)
			{
				return (this->iter == it.iter);
			}
			//operator!=
			bool operator!=(const iterator& it)
			{
				return (this->iter != it.iter);
			}
			//operator*
			T& operator*(void)
			{
				return *this->iter;
			}
			//operator->
			T* operator->(void)
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
				iterator<T> temp(*this);
				this->iter++;
				return (temp);
			}
			T& operator[](int n)
			{
				return (this->iter[n]);
			}
	};

}
#endif