#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_
// * FT NAMESPACE *  
namespace ft {
	/* include libraries */
	# include <iostream>
	# include <memory>
	/* vector class template */
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			/* member type */
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef size_t										size_type;
		private:
			pointer array;
			allocator_type _alloc;
		public:
			/* default */
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				this->array = nullptr;
			}
			/* fill */
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				this->array = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
				{
					this->array[i] = val;
				}
			}
			/* range */
			//template <class InputIterator>
			//		vector (InputIterator first, InputIterator last,
			//				const allocator_type& alloc = allocator_type());
			/* copy */
			//vector (const vector& x);
			/* [] overwrite */
			value_type get(size_t index)
			{
				return array[index];
			}

	};

}
#endif