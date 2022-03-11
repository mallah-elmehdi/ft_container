#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_
// ============ FT NAMESPACE
namespace ft {
	/* include libraries */
	# include <iostream>
	# include <memory>

	/* vector class template */
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		private:
			alloc _alloc;
			T *array;
		public:
			/* member type */
			typedef T									value_type;
			typedef Alloc								allocator_type;
			typedef allocator_type::reference			reference;
			typedef allocator_type::const_reference		const_reference;
			typedef allocator_type::pointer				pointer;
			typedef allocator_type::const_pointer		const_pointer;
			typedef allocator_type::reference			const_reference;
			typedef allocator_type::reference			const_reference;

			/* default */
			explicit vector (const allocator_type& alloc = allocator_type());
			
			/* fill */
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			
			/* range */
			//template <class InputIterator>
			//		vector (InputIterator first, InputIterator last,
			//				const allocator_type& alloc = allocator_type());
			
			/* copy */
			vector (const vector& x);

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

			/* [] overwrite */
			T get(size_t index)
			{
				return array[index];
			}
	};

}
#endif