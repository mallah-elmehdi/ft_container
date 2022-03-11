#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_
// ============ FT NAMESPACE 
namespace ft {
	/* include libraries */ 
	# include <iostream>
	# include <memory>

	/* vector class template */
	template <class T, class alloc = std::allocator<T> >
	class vector {
		private:
			alloc _alloc;
		protected:
			T *array;
		public:
			vector()
			{
				
			}
			/* one parametre */
			vector(size_t lenght)
			{
				this->array = _alloc.allocate(lenght);

			}
			/* two parametres */
			vector(size_t lenght, T init_value)
			{
				this->array = _alloc.allocate(lenght);
				for (size_t i = 0; i < lenght; i++)
				{
					this->array[i] = init_value;
				}
				
			}
			~vector()
			{

			}
			/* [] overwrite */
			T get(size_t index)
			{
				return array[index];
			}
	};

}
#endif