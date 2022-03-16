#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_
// * FT NAMESPACE - [ITERATOR] *  
namespace ft {
	template <class T>
	class iterator {
		public:
			// + + + + + + + + + Member type
		private:
			T* ptr;
		public:
			// + + + + + + + + + Member functions
			/* default constuctor */
			iterator(T* _ptr)
			{
				this->ptr = _ptr;
				// null
			}
			/* copy constuctor */
			iterator(iterator const &it)
			{
				this->ptr = it.ptr;
			}
			// * OPERATOR OVERLOAD * 
			/* operator = iterator */
			iterator& operator=(iterator const &it)
			{
				this->ptr = it.ptr;
				return (*this);
			}
			/* operator == */
			bool operator==(const iterator& it)
			{
				return (this->ptr == it.ptr);
			}
			/* operator != */
			bool operator!=(const iterator& it)
			{
				return (this->ptr != it.ptr);
			}
			/* operator * */
			T& operator*(void)
			{
				return *this->ptr;
			}
			/* operator -> */
			T* operator->(void)
			{
				return this->ptr;
			}
			/* operator ++ (pre) */
			iterator& operator++(void)
			{
				this->ptr++;
				return (*this);
			}
			// +++++++++++++++++++++++++++++++++++++++++
			/* operator ++ (post) */
			iterator operator++(int)
			{
				iterator<T> temp(*this);
				this->ptr++;
				return (temp);
			}

			T& operator[](int n)
			{
				return (this->ptr[n]);
			}
			///* operator -- (pre) */
			//iterator &operator--(void)
			//{
			//	this->ptr--;
			//	return (*this);
			//}
			///* operator -- (post) */
			//iterator &operator--(int)
			//{
			//	iterator temp = *this;
			//	this->ptr--;
			//	return (temp);
			//}
	};

}
#endif