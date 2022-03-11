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
			T *array;
		public:
		

			//default (1)
			explicit vector (const allocator_type& alloc = allocator_type());
			//fill (2)	
			explicit vector (size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type());
			//range (3)	
			//template <class InputIterator>
			//		vector (InputIterator first, InputIterator last,
			//				const allocator_type& alloc = allocator_type());
			//copy (4)	
			vector (const vector& x);	

			vector() 
			{
				/* constructor */
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
				/* dectructor */
			}
			/* [] overwrite */
			T get(size_t index)
			{
				return array[index];
			}
	};

}
#endif