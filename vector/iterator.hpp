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
				// none
			}
			/* copy constuctor */
			iterator(iterator &it)
			{
				this->ptr = it->ptr;
			}
			/* operator = */
			iterator &operator=(const iterator &it)
			{
				this->ptr = it->ptr;
				return (this);
			}
			/* operator == */
			bool &operator==(const iterator &it)
			{
				return (this->ptr == it->ptr);
			}
			/* operator != */
			bool &operator!=(const iterator &it)
			{
				return (this->ptr != it->ptr);
			}
			/* operator ++ (pre) */
			iterator &operator++(void)
			{
				this->ptr++;
				return (this);
			}
			/* operator ++ (post) */
			iterator &operator++(int)
			{
				T *temp = this->ptr;
				this->ptr++;
				return ();
			}
	};

}
#endif