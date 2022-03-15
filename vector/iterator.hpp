#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_
// * FT NAMESPACE - [ITERATOR] *  
namespace ft {
	/* include libraries */
	// none
	/* iterator class template */
	template <class T>
	class iterator {
		private:
			T* ptr;
		public:
			/* default constuctor */
			iterator()
			{
				T list[5] = {100,2,3,4,5};
				ptr = list;
				// null
			}
			/* copy constuctor */
			iterator(iterator &it)
			{
				this->ptr = it.ptr;
			}
			// * OPERATOR OVERLOAD * 
			/* operator = iterator */
			iterator& operator=(const iterator& it)
			{
				this->ptr = it->ptr;
				return (*this);
			}
			/* operator == */
			bool operator==(const iterator& it)
			{
				return (this->ptr == it->ptr);
			}
			/* operator != */
			bool operator!=(const iterator& it)
			{
				return (this->ptr != it->ptr);
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
			// +++++++++++++++++++++++++++++++++++++++++
			///* operator ++ (pre) */
			iterator& operator++(void)
			{
				this->ptr++;
				return (*this);
			}
			
			T& operator[](int n)
			{
				return (this->ptr[n]);
			}

			///* operator ++ (post) */
			//iterator& operator++(int)
			//{
			//	iterator temp = *this;
			//	this->ptr++;
			//	return (temp);
			//}
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