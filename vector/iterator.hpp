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
				this->ptr = copy->ptr;
			}
			/* operator = */
			iterator &operator=(const iterator &it)
			{
				this->ptr = copy->ptr;
			}
			/* operator == */
			bool &operator==(const iterator &it)
			{
				this->ptr == copy->ptr;
			}
			/* operator != */
			bool &operator==(const iterator &it)
			{
				this->ptr != copy->ptr;
			}
	};

}
#endif