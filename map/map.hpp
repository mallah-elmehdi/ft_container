#ifndef _MAP_
#define _MAP_

# include  "pair.hpp"

namespace ft
{
    template < class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T> > >
    class map
    {
        public:
            // +++++++ Member types
            typedef Key             key_type;
            typedef T               mapped_type;
            typedef value_type      ft::pair<const key_type, mapped_type>;

            typedef Key     key_type;
            typedef Key     key_type;
            typedef Key     key_type;
            typedef Key     key_type;

    }
}

#endif
