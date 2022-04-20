#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include "ft.hpp"

template <class T, class Allocator = std::allocator<T> >
class vector {
	public:
		// + + + + + + + + + Member type
		typedef T												value_type;
		typedef ptrdiff_t										difference_type;
		typedef Allocator										allocator_type;
		typedef size_t											size_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef	ft::ra_iterator<T> 								iterator;
		typedef	ft::ra_iterator<const T> 						const_iterator;
		typedef	ft::reverse_iterator<iterator>					reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;
	private:
		pointer 				vect;
		allocator_type 			allocator;
		size_type				_size;
		size_type				_capacity;
	public:
		// + + + + + + + + + Member functions
		/* Constructor */
		explicit vector(const allocator_type& alloc = allocator_type()) : vect(), allocator(alloc), _size(0), _capacity(0)
		{
			//nothing
		}
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : allocator(alloc), _size(n), _capacity(n)
		{
			vect = allocator.allocate(n);
			ft::fill(begin(), begin() + n, val, allocator);
		}
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false) : _capacity(last - first), allocator(alloc)
		{
			_size = _capacity;
			vect = allocator.allocate(_capacity);
			ft::copy(first, last, begin(), allocator);
		}
		vector(const vector& x) : _size(x._size), _capacity(x._capacity), allocator(x.allocator)
		{
			vect = allocator.allocate(capacity());
			ft::copy(x.begin(), x.end(), begin(), allocator);
		}
		vector& operator=(const vector& x)
		{
			allocator = x.allocator;
			clear();
			reserve(x.capacity());
			_size = x._size;
			ft::copy(x.begin(), x.end(), begin(), allocator);
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
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
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
				size_type temp_size = size();
				pointer temp_vect = allocator.allocate(n);
				ft::copy(begin(), end(), temp_vect, allocator);
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
			std::cout << *(--end()) << "\n";
			return (*(end() - 1));
		}
		const_reference back() const
		{
			return (*(end() - 1));
		}
		/* Modifiers */
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false)
		{
			clear();
			difference_type n = last - first;
			if (n > capacity()) reserve(n);
			ft::copy(first, last, begin(), allocator);
			_size = n;
		}
		void assign (size_type n, const value_type& val)
		{
			clear();
			if (n > capacity()) reserve(n);
			resize(n, val);
		}
		void push_back (const value_type& val)
		{
			if (capacity() == 0)
				reserve(1);
			else if (size() == capacity())
				reserve(capacity() * 2);
			allocator.construct(&vect[size()], val);
			_size++;
		}
		void pop_back()
		{
			allocator.destroy(&back());
			_size--;
		}
		iterator insert(iterator position, const value_type& val)
		{
			difference_type distance = position > end() ? -1 : position - begin();
			if (capacity() == 0) reserve(1);
			else if (size() == capacity()) reserve(capacity() * 2);
			ft::copy_backward(begin() + distance, end(), end() + 1, allocator);
			allocator.construct(&*(begin() + distance), val);
			_size++;
			return begin() + distance;

		}
		void insert(iterator position, size_type n, const value_type& val)
		{
			difference_type distance = position > end() ? -1 : position - begin();
			if (capacity() == 0) reserve(size() + n);
			else if (size() + n > capacity()) (size() + n > capacity() * 2) ? reserve(size() + n) : reserve(capacity() * 2);
			ft::copy_backward(begin() + distance, end(), end() + n, allocator);
			ft::fill(begin() + distance, begin() + distance + n, val, allocator);
			_size += n;
		}
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false)
		{
			difference_type distance = last - first,
				this_distance = position > end() ? -1 : position - begin();
			if (capacity() == 0) reserve(size() + distance);
			if (size() + distance > capacity())
				(size() + distance > capacity() * 2) ? reserve(size() + distance) : reserve(capacity() * 2);
			ft::copy_backward(begin() + this_distance, end(), end() + distance, allocator);
			ft::copy(first, last, begin() + this_distance, allocator);
			_size += distance;
		}
		iterator erase(iterator position)
		{
			ft::copy(position + 1, end(), position, allocator);
			allocator.destroy(&(*position));
			_size--;
			return (position);
		}
		iterator erase(iterator first, iterator last)
		{
			ft::copy(last, end(), first, allocator);
			for (iterator it = last; it != end(); it++)
			{
				allocator.destroy(&(*it));
			}
			_size -= last - first;
			return (first);
		}
		void swap(vector& x)
		{
			ft::_swap(vect, x.vect);
			ft::_swap(_size, x._size);
			ft::_swap(_capacity, x._capacity);
			ft::_swap(allocator, x.allocator);
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
};
/* Non-member function overloads */
template <class T, class Alloc>
bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
template <class T, class Alloc>
bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (lhs.size() != rhs.size() || !ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
template <class T, class Alloc>
bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}
template <class T, class Alloc>
bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
}
template <class T, class Alloc>
bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (lhs < rhs || lhs == rhs);
}
template <class T, class Alloc>
bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (lhs > rhs || lhs == rhs);
}
template <class T, class Alloc>
void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	x.swap(y);
}

#endif
