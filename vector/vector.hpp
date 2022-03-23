#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_
// * FT NAMESPACE - [VECTOR] *
namespace ft {
	//include libraries
	# include <iostream>
	# include <memory>
	# include "iterator.hpp"
	//vector class template
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			// + + + + + + + + + Member type
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef size_t										size_type;
			typedef	ft::iterator<T> 							iterator;
		private:
			pointer 			vect;
			allocator_type 		allocator;
		public:
			// + + + + + + + + + Member functions
			/* Constructor */
			//default
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				this->vect = nullptr;
			}
			//fill
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				this->allocator = alloc;
				this->vect = allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
				{
					this->vect[i] = val;
				}
			}
			//range
			//template <class InputIterator>
			//		vector (InputIterator first, InputIterator last,
			//				const allocator_type& alloc = allocator_type());
			//copy
			//vector (const vector& x)
			//{

			//}
			/* Destructor */
			~vector() {};
			/* Iterators */
			iterator begin()
			{
				iterator it_begin();
				return ()
			}
			/* Allocator */
			allocator_type get_allocator(void) const
			{
				return this->allocator;
			}
	};

}
#endif
