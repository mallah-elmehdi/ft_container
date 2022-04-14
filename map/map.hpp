#ifndef _MAP_
#define _MAP_

# include "pair.hpp"
# include "less.hpp"
# include "iterator.hpp"
# include "reverse_iterator.hpp"
# include "red_black_tree.hpp"
# include <cstddef>
# include <memory>

namespace ft
{
    template < class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:
            // +++++++ Member types
            typedef Key                                             key_type;
            typedef T                                               mapped_type;
            typedef ft::pair<const key_type, mapped_type>           value_type;
            typedef Compare                                         key_compare;
            typedef Allocator	                                    allocator_type;
            typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
            typedef ptrdiff_t										difference_type;
            typedef size_t											size_type;
			typedef ft::bd_iterator<value_type>						iterator;
			typedef ft::bd_iterator<const value_type>				const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

        private:
            Red_Black_Tree<key_type, mapped_type, Compare, allocator_type>	tree;
			size_t															_size;
			allocator_type													allocator;
			key_compare														compare;

		private:
			void clearHelp(iterator it)
			{
				if (it != end())
				{
					Node<value_type> *nodeHold = it.nodeBase();
                    allocator.destroy(it.base());
                    allocator.deallocate(it.base(), sizeof(value_type));
					clearHelp(++it);
					delete nodeHold;
				}
			}

		public:

            /* Member functions */

		    explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            : _size(0), allocator(alloc), compare(comp) {}


            template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _size(0), compare(comp), allocator(alloc)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

			map (const map& x) : _size(0), allocator(x.allocator), compare(x.compare)
			{
				for (iterator it = x.begin(); it != x.end(); it++) insert(*it);
			}

            ~map()
            {
                clear();
            }
			/* Iterators */

			iterator begin()
			{
				return (iterator(tree.begin()));
			}
			const_iterator begin() const
			{
				return (const_iterator(tree.begin()));
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
				return (allocator.max_size());
			}

			/* Element access */

			mapped_type& operator[] (const key_type& k)
			{
                return insert(ft::make_pair(k, mapped_type())).first->second;
			}

			/* Modifiers */

			ft::pair<iterator,bool> insert(const value_type& val)
            {
				_size++;
                return (tree.insert(val));
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

            void clear()
            {
				clearHelp(begin());
                tree.clear();
                _size = 0;
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
					if (compare(it->first, k) == false)
						break;
					++it;
				}
				return ();
			}
			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator it = begin();
				while (it != end())
				{
					if (compare(it->first, k) == false)
						break;
					++it;
				}
				return (const_iterator());
			}
    };
}

#endif
