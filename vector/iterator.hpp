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
			iterator(iterator &copy)
			{
				this->ptr = copy->ptr;
			}
			/* operator = */
			iterator &operator=(const iterator &copy)
			{
				this->ptr = copy->ptr;
			}

	};

}
#endif