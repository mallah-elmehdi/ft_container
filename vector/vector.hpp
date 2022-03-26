#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_
// * LIBRARIES *
# include <iostream>
# include <memory>
# include <cstddef>
# include <stdexcept>
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
			size_type					_size;
			size_type					_capacity;
		public:
			// + + + + + + + + + Member functions
			/* Constructor */
			//default
			explicit vector (const allocator_type& alloc = allocator_type()) : vect(), allocator(alloc), _size(0), _capacity(0) {}
			//fill
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : allocator(alloc), _size(n), _capacity(n)
			{
				this->vect = this->allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
				{
					this->vect[i] = val;
				}
			}
			//range
			// template <class InputIterator>
			// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : allocator(alloc)
			// {
			//
			// }
			//copy
			vector (const vector& x)
			{
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->allocator = x.allocator;
				if (this->_capacity)
				{
					this->vect = this->allocator.allocate(this->_capacity);
					for (size_type i = 0; i < this->_size; i++) {
						this->vect[i] = x.vect[i];
					}
				}
			}
			vector& operator=(const vector& x)
			{
				this->~vector();
				this->_size = x._size;
				this->_capacity = x._size;
				this->allocator = x.allocator;
				if (this->_capacity)
				{
					this->vect = this->allocator.allocate(this->_capacity);
					for (size_type i = 0; i < this->_size; i++) {
						this->vect[i] = x.vect[i];
					}
				}
				return (*this);
			}
			/* Destructor */
			~vector()
			{
				this->allocator.deallocate(this->vect, this->_capacity);
			};
			/* Iterators */
			iterator begin()
			{
				return (iterator(this->vect));
			}
			const_iterator begin() const
			{
				return (const_iterator(this->vect));
			}
			iterator end()
			{
				return (iterator(this->vect + this->_size));
			}
			const_iterator end() const
			{
				return (const_iterator(this->vect + this->_size));
			}
			iterator rbegin()
			{
				return (reverse_iterator(this->vect));
			}
			const_iterator rbegin() const
			{
				return (const_reverse_iterator(this->vect));
			}
			iterator rend()
			{
				return (reverse_iterator(this->vect + this->_size));
			}
			const_iterator rend() const
			{
				return (const_reverse_iterator(this->vect + this->_size));
			}
			/* Capacity */
			size_type size() const
			{
				return (this->_size);
			}
			size_type max_size() const
			{
				return (this->allocator.max_size());
			}
			void resize(size_type n, value_type val = value_type())
			{
				if (n >= this->_capacity)
				{
					size_type temp_capacity = this->_capacity;
					//change capacity
					this->_capacity = n >= 2 * this->_capacity ? n : this->_capacity * 2;
					//get the new temp_vect
					pointer temp_vect = this->allocator.allocate(this->_capacity);
					for (size_type i = 0; i < this->_size; i++) {
						temp_vect[i] = this->vect[i];
					}
					//dealocate the vect
					this->allocator.deallocate(this->vect, temp_capacity);
					for (size_type i = this->_size; i < n; i++) {
						temp_vect[i] = val;
					}
					//change size
					this->_size = n;
					this->vect = temp_vect;
				}
				else
				{
					if (n > this->_size)
					{
						for (size_type i = this->_size; i < n; i++) {
							this->vect[i] = val;
						}
					}
					this->_size = n;
				}
			}
			size_type capacity() const
			{
				return (this->_capacity);
			}
			bool empty() const
			{
				return (this->_size == 0);
			}
			void reserve(size_type n)
			{
				if (n > this->max_size())
					throw std::length_error("length_error");
				if (this->_capacity < n)
				{
					pointer temp_vect = this->allocator.allocate(n);
					for (size_type i = 0; i < this->_size; i++) {
						temp_vect[i] = this->vect[i];
					}
					this->allocator.deallocate(this->vect, this->_capacity);
					this->_capacity = n;
					this->vect = temp_vect;
				}
			}
			/* Element access */
			reference operator[](size_type n)
			{
				return (this->vect[n]);
			}
			const_reference operator[](size_type n) const
			{
				return (this->vect[n]);
			}
			reference at(size_type n)
			{
				if (n < this->_size)
					return (this->vect[n]);
				throw std::out_of_range("out_of_range");
			}
			const_reference at(size_type n) const
			{
				if (n < this->_size)
					return (this->vect[n]);
				throw std::out_of_range("out_of_range");
			}
			reference front()
			{
				return (*this->begin());
			}
			const_reference front() const
			{
				return (*this->begin());
			}
			reference back()
			{
				return (*(this->end() - 1));
			}
			const_reference back() const
			{
				return (*(this->end() - 1));
			}
			/* Modifiers */
			// range
			// template <class InputIterator> void assign (InputIterator first, InputIterator last);
			// fill
			// void assign (size_type n, const value_type& val);
			void push_back (const value_type& val)
			{
				if (this->_size == this->_capacity)
				{
					size_type temp_capacity = this->_capacity;
					this->_capacity = this->_capacity ? this->_capacity * 2 : 1;
					pointer temp_vect = this->allocator.allocate(this->_capacity);
					for (size_type i = 0; i < this->_size; i++) {
						temp_vect[i] = this->vect[i];
					}
					//dealocate the vect
					this->allocator.deallocate(this->vect, temp_capacity);
					temp_vect[this->_size] = val;
					//change size
					this->vect = temp_vect;
				}
				else
					this->vect[this->_size] = val;
				this->_size++;
			}
			void pop_back()
			{
				this->allocator.destroy(this->back());
				this->_size--;
			}
			// single element
			iterator insert(iterator position, const value_type& val)
			{

			}
			// fill
			void insert(iterator position, size_type n, const value_type& val)
			{

			}
			// range
			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last);
			/* Allocator */
			allocator_type get_allocator(void) const
			{
				return this->allocator;
			}
	};

}
#endif
