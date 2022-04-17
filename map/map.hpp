#ifndef _MAP_
#define _MAP_

#include "ft.hpp"

template < class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<Key, T> > >
class map
{
	public:
		// +++++++ Member types
		typedef Key                                            				key_type;
		typedef T                                              				mapped_type;
		typedef ft::pair<key_type, mapped_type>          					value_type;
		typedef Compare                                        				key_compare;
		typedef Allocator	                                   				allocator_type;
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer						const_pointer;
		typedef ptrdiff_t													difference_type;
		typedef size_t														size_type;
		typedef ft::bd_iterator<value_type>									iterator;
		typedef ft::bd_iterator<value_type>									const_iterator;
		typedef ft::reverse_iterator<iterator>								reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
		
		template <class __Key, class __T, class __Compare, class __Alloc>
		class value_comp_class
		{
			friend map;
			
			protected:
				__Compare comp;
				value_comp_class (__Compare c) : comp(c) {}
			
			public:
				typedef bool								result_type;
				typedef value_type							first_argument_type;
				typedef value_type							second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		};
		typedef	value_comp_class<key_type, mapped_type, Compare, allocator_type>	value_compare;

	private:
		typedef ft::Node<value_type>									node;
		typedef typename allocator_type::template rebind<node>::other	rebind;

		Red_Black_Tree<value_type, key_compare, allocator_type>			tree;
		size_t															_size;
		allocator_type													alloc;
		rebind															reb;
		key_compare														comp;

	private:
		void clearHelp(iterator it)
		{
			if (it != end())
			{
				node* nodeHold = it.nodes();
				
				alloc.destroy(it.base());
				alloc.deallocate(it.base(), sizeof(value_type));
				
				clearHelp(++it);
				
				reb.destroy(nodeHold);
				reb.deallocate(nodeHold, sizeof(node));

				if (nodeHold->right->nil == true)
					tree.destroy_node(nodeHold->right);
				if (nodeHold->left->nil == true)
					tree.destroy_node(nodeHold->left);
			}
		}
	public:
		explicit map (const key_compare& compare = key_compare(), const allocator_type& allocator = allocator_type())
		: _size(0), alloc(allocator), comp(compare) {}
		
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& compare = key_compare(), const allocator_type& allocator = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false)
		: _size(0), alloc(allocator), comp(compare)
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
		}
		map (const map& x) : _size(0), alloc(x.alloc), comp(x.comp)
		{
			map(begin(), end());
		}
		map& operator= (const map& x)
		{
			clear();
			for (iterator it = x.begin(); it != x.end(); it++)
			{
				insert(*it);
			}
			return (*this);
		}
		~map()
		{
			clear();
		}

		/* --------------------------------------------- Iterators */
		
		iterator begin()
		{
			return (iterator(tree.first()));
		}
		const_iterator begin() const
		{
			return (const_iterator(tree.first()));
		}
		iterator end()
		{
			return (iterator(tree.end()));
		}
		const_iterator end() const
		{
			return (const_iterator(tree.end()));
		}
		reverse_iterator rbegin()
		{
			return (reverse_iterator(tree.last()));
		}
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(tree.last()));
		}
		reverse_iterator rend()
		{
			return (reverse_iterator(tree.first()));
		}
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(tree.first()));
		}

		/* Capacity */

		bool empty() const
		{
			return (size() == 0);
		}
		size_type size() const
		{
			return (_size);
		}
		size_type max_size() const
		{
			return (alloc.max_size());
		}

		/* Element access */

		mapped_type& operator[] (const key_type& k)
		{
			return insert(ft::make_pair(k, mapped_type())).first->second;
		}

		/* Modifiers */

		ft::pair<iterator,bool> insert(const value_type& val)
		{
			if (tree.insert(val))
			{
				_size++;
				return (ft::make_pair(find(val.first), true));
			}
			return (ft::make_pair(find(val.first), false));
		}
		iterator insert (iterator position, const value_type& val)
		{
			return (insert(val).first);
		}
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(*first);
				++first;
			}
		}
    	void erase (iterator position)
		{
			erase(position->first);
		}
		size_type erase (const key_type& k)
		{
			if (tree.destroy(k))
			{
				_size--;
				return (1);
			}
			return (0);
		}
		void erase (iterator first, iterator last)
		{
			while (first != last)
			{
				erase(first);
				++first;
			}
		}
		void clear()
		{
			if (size())
			{
				clearHelp(begin());
				_size = 0;
			}
		}

		/* Observers */

		key_compare key_comp() const
		{
			return (comp);
		}
		value_compare value_comp() const
		{
			return (value_compare());
		}

		/* Operations */
		
		iterator find (const key_type& k)
		{
			iterator it = begin();
			while (it != end())
			{
				if (it->first == k)
					break;
				++it;
			}
			return (it);
		}
		const_iterator find (const key_type& k) const
		{
			const_iterator it = begin();
			while (it != end())
			{
				if (it->first == k)
					break;
				++it;
			}
			return (it);
		}
		size_type count (const key_type& k) const
		{
			if (find(k) != end()) return (1);
			return (0);
		}
		iterator lower_bound (const key_type& k)
		{
			iterator it = begin();
			while (it != end())
			{
				if (comp(it->first, k) == false)
					break ;
				++it;
			}
			return (it);
		}
		const_iterator lower_bound (const key_type& k) const
		{
			const_iterator it = begin();
			while (it != end())
			{
				if (comp(it->first, k) == false)
					break ;
				++it;
			}
			return (it);
		}
		iterator upper_bound (const key_type& k)
		{
			iterator it = begin();
			while (it != end())
			{
				if (comp(k, it->first) == true)
					break ;
				++it;
			}
			return (it);
		}
		const_iterator upper_bound (const key_type& k) const
		{
			const_iterator it = begin();
			while (it != end())
			{
				if (comp(k, it->first) == true)
					break ;
				++it;
			}
			return (it);
		}
		pair<iterator,iterator> equal_range (const key_type& k)
		{
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}

		/* Allocator */

		allocator_type get_allocator() const
		{
			return (alloc);
		}

};

#endif
