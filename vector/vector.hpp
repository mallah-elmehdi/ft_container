#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_
// * LIBRARIES *
# include <iostream>
# include <memory>
# include <cstddef>
# include <stdexcept>
# include "iterator.hpp"
# include "reverse_iterator.hpp"
# include "equal.hpp"
# include "lexicographical_compare.hpp"
// * FT NAMESPACE - [VECTOR] *
namespace ft {
	//vector class template
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			// + + + + + + + + + Member type
			typedef T												value_type;
			typedef std::ptrdiff_t									difference_type;
			typedef Allocator										allocator_type;
			typedef size_t											size_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef	ra_iterator<T> 									iterator;
			typedef	ra_iterator<const T> 							const_iterator;
			typedef	ra_reverse_iterator<iterator>					reverse_iterator;
			typedef	ra_reverse_iterator<const_iterator>				const_reverse_iterator;
		private:
			pointer 				vect;
			allocator_type 			allocator;
			size_type				_size;
			size_type				_capacity;
		public:
			// + + + + + + + + + Member functions
			/* Constructor */
			//default
			explicit vector (const allocator_type& alloc = allocator_type()) : vect(), allocator(alloc), _size(0), _capacity(0) {}
			//fill
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : allocator(alloc), _size(n), _capacity(n)
			{
				vect = allocator.allocate(n);
				std::fill(begin(), end(), val);
			}
			//range
			//template <class InputIterator>
			//vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : allocator(alloc)
			//{
			//
			//}
			//copy
			vector (const vector& x) : _size(x._size), _capacity(x._capacity), allocator(x.allocator)
			{
				vect = allocator.allocate(capacity());
				std::copy(x.begin(), x.end(), begin());
			}
			//operator=
			vector& operator=(const vector& x)
			{
				allocator = x.allocator;
				clear();
				reserve(x.capacity());
				_size = x._size;
				std::copy(x.begin(), x.end(), begin());
				return (*this);
			}
			/* Destructor */
			~vector()
			{
				clear();
				allocator.deallocate(vect, capacity());
			};
			/* Iterators */
			iterator begin()
			{
				return (iterator(vect));
			}
			const_iterator begin() const
			{
				return (const_iterator(vect));
			}
			iterator end()
			{
				return (iterator(vect + size()));
			}
			const_iterator end() const
			{
				return (const_iterator(vect + size()));
			}
			iterator rbegin()
			{
				return (reverse_iterator(vect));
			}
			const_iterator rbegin() const
			{
				return (const_reverse_iterator(vect));
			}
			iterator rend()
			{
				return (reverse_iterator(vect + size()));
			}
			const_iterator rend() const
			{
				return (const_reverse_iterator(vect + size()));
			}
			/* Capacity */
			size_type size() const
			{
				return (_size);
			}
			size_type max_size() const
			{
				return (allocator.max_size());
			}
			void resize(size_type n, value_type val = value_type())
			{
				if (n > capacity())
					(n > capacity() * 2) ? reserve(n) : reserve(capacity() * 2);
				while (size() > n) pop_back();
				while (size() < n) push_back(val);
			}
			size_type capacity() const
			{
				return (_capacity);
			}
			bool empty() const
			{
				return (_size == 0);
			}
			void reserve(size_type n)
			{
				if (n > max_size())
					throw std::length_error("length_error");
				if (n > capacity())
				{
					value_type temp_size = size();
					pointer temp_vect = allocator.allocate(n);
					std::copy(begin(), end(), temp_vect);
					this->~vector();
					_capacity = n;
					_size = temp_size;
					vect = temp_vect;
				}
			}
			/* Element access */
			reference operator[](size_type n)
			{
				return (vect[n]);
			}
			const_reference operator[](size_type n) const
			{
				return (vect[n]);
			}
			reference at(size_type n)
			{
				if (n < _size)
					return (vect[n]);
				throw std::out_of_range("out_of_range");
			}
			const_reference at(size_type n) const
			{
				if (n < _size)
					return (vect[n]);
				throw std::out_of_range("out_of_range");
			}
			reference front()
			{
				return (*begin());
			}
			const_reference front() const
			{
				return (*begin());
			}
			reference back()
			{
				return (*(end() - 1));
			}
			const_reference back() const
			{
				return (*(end() - 1));
			}
			/* Modifiers */
			// range
			// template <class InputIterator> void assign (InputIterator first, InputIterator last);
			// fill
			void assign (size_type n, const value_type& val)
			{
				clear();
				if (n > capacity()) reserve(n);
				resize(n, val);
			}
			void push_back (const value_type& val)
			{
				if (size() == capacity())
					reserve(capacity() * 2);
				vect[size()] = val;
				_size++;
			}
			void pop_back()
			{
				allocator.destroy(&back());
				_size--;
			}
			iterator insert(iterator position, const value_type& val)
			{
				difference_type distance = position > end() ? -1 : std::distance(begin(), position);
				if (size() == capacity()) reserve(capacity() * 2);
				std::copy_backward(begin() + distance, end(), end() + 1);
				*(begin() + distance) = val;
				_size++;
				return begin() + distance;

			}
			void insert(iterator position, size_type n, const value_type& val)
			{
				difference_type distance = position > end() ? -1 : std::distance(begin(), position);
				if (size() + n > capacity()) (size() + n > capacity() * 2) ? reserve(size() + n) : reserve(capacity() * 2);
				std::copy_backward(begin() + distance, end(), end() + n);
				std::fill(begin() + distance, begin() + distance + n, val);
				_size += n;
			}
			//template <class InputIterator>
			//void insert (iterator position, InputIterator first, InputIterator last);
			iterator erase(iterator position)
			{
				std::copy(position + 1, end(), position);
				allocator.destroy(&(*position));
				_size--;
				return (position);
			}
			iterator erase(iterator first, iterator last)
			{
				std::copy(last, end(), first);
				for (iterator it = last; it != end(); it++)
				{
					allocator.destroy(&(*it));
				}
				_size -= std::distance(first, last);
				return (first);
			}
			void swap(vector& x)
			{
				vector temp(x);
				x = *this;
				*this = temp;
			}
			void clear()
			{
				while (size())
				{
					pop_back();
				}
			}
			/* Allocator */
			allocator_type get_allocator(void) const
			{
				return allocator;
			}
			/* Non-member function overloads */
			template <class T, class Alloc>
				bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
				{
					return ()
				}
			template <class T, class Alloc>
				bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			template <class T, class Alloc>
				bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			template <class T, class Alloc>
				bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			template <class T, class Alloc>
				bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			template <class T, class Alloc>
				bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	};

}
#endif
