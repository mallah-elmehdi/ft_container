#ifndef _ITERATOR_TRAITS_HPP_
#define _ITERATOR_TRAITS_HPP_
// * LIBRARIES *
# include <iostream>
# include <cstddef>
// * FT NAMESPACE - [ITERATOR TRAITS] *
//vector class template
template <class Iterator>
class iterator_traits {
	public:
		// + + + + + + + + + Member type
    typedef typename Iterator::difference_type    difference_type;
    typedef typename Iterator::value_type         value_type;
    typedef typename Iterator::pointer            pointer;
    typedef typename Iterator::reference          reference;
    typedef typename Iterator::iterator_category  iterator_category;
};
template <class T>
class iterator_traits<T*> {
	public:
		// + + + + + + + + + Member type
    typedef std::ptrdiff_t                    difference_type;
    typedef T                                 value_type;
    typedef T*                                pointer;
    typedef T&                                reference;
    typedef std::random_access_iterator_tag   iterator_category;
};
template <class T>
class iterator_traits<const T*> {
	public:
		// + + + + + + + + + Member type
    typedef std::ptrdiff_t                    difference_type;
    typedef T                                 value_type;
    typedef const T*                          pointer;
    typedef const T&                          reference;
    typedef std::random_access_iterator_tag   iterator_category;
};
#endif
