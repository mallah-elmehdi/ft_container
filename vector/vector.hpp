#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_
// * LIBRARIES *
# include <iostream>
# include <memory>
# include <cstddef>
# include "iterator.hpp"
# include "reverse_iterator.hpp"
// * FT NAMESPACE - [VECTOR] *
namespace ft {
	//vector class template
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			// + + + + + + + + + Member type
			typedef T																					value_type;
			typedef std::ptrdiff_t														difference_type;
			typedef Allocator																	allocator_type;
			typedef size_t																		size_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef	ra_iterator<T> 														iterator;
			typedef	ra_iterator<const T> 											const_iterator;
			typedef	ra_reverse_iterator<iterator>							reverse_iterator;
			typedef	ra_reverse_iterator<const_iterator>				const_reverse_iterator;
		private:
			pointer 					vect;
			allocator_type 		allocator;
		public:
			// + + + + + + + + + Member functions
			/* Constructor */
			//default
			explicit vector (const allocator_type& alloc = allocator_type()) : vect(), allocator(alloc) {}
			//fill
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : allocator(alloc)
			{
				this->vect = this->allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
				{
					this->vect[i] = val;
				}
			}
			// //range
			// template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			// {
			//
			// }
			// //copy
			// vector (const vector& x)
			// {
			//
			// }
			/* Destructor */
			// ~vector() {};
			/* Iterators */
			iterator begin()
			{
				return (iterator(this->vect[0]));
			}
			const_iterator begin() const
			{
				return (const_iterator(this->vect[0]));
			}
			/* Allocator */
			allocator_type get_allocator(void) const
			{
				return this->allocator;
			}
	};

}
#endif
