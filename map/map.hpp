#ifndef _MAP_
#define _MAP_

# include "pair.hpp"
# include "less.hpp"
// # include  "iterator.hpp"
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

        private:
            Red_Black_Tree<key_type, mapped_type, allocator_type>	tree;
			size_t													_size;
			allocator_type											allocator;
        public:
            // // +++++++ Member functions
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            : _size(0), allocator(alloc) {}

            
            // template <class InputIterator>
            //   map (InputIterator first, InputIterator last,
            //        const key_compare& comp = key_compare(),
            //        const allocator_type& alloc = allocator_type());
            //
            // map (const map& x);
			// Capacity
			bool empty() const { return (size() == 0); }
			size_type size() const { return (_size); }
			size_type max_size() const { return (allocator.max_size()); }
			// Element access
			mapped_type& operator[] (const key_type& k) 
			{
				try { return tree[k]; }
				catch(...) { /*(*((insert(ft::make_pair(k,mapped_type()))).first)).second*/ }
			}
            // Modifiers
            pair<iterator,bool> insert(const value_type& val)
            {
				try { tree[val.first]; }
				catch(...) {
					tree.insert(val);
					tree.printTree();
					_size++;
				}
            }

			iterator insert (iterator position, const value_type& val);
			range (3)	
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last);
    };
}

#endif
