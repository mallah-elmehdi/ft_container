#ifndef _BD_ITERATOR_
#define _BD_ITERATOR_

# include <iterator>
# include "node.hpp"
# include "pair.hpp"

namespace ft
{
    template <class Key, class T>
    class bd_iterator {
    	public:
    		// + + + + + + + + + Member type
    		typedef ft::pair<const Key, T>                  value_type;
    		typedef std::ptrdiff_t							difference_type;
    		typedef Node<Key, T>*  							pointer;
    		typedef Node<Key, T>&						    reference;
    		typedef std::bidirectional_iterator_tag			iterator_category;
    	private:
    		pointer iter;
    	public:
    		// + + + + + + + + + Member functions
    		//default constuctor
    		bd_iterator(void) : iter() {}
    		//copy constuctor
    		bd_iterator(pointer x) : iter(x) {}
    		bd_iterator(const bd_iterator &it) : iter(it.base()) {}
    		template <class Ty>
    		bd_iterator(const bd_iterator<Ty> &it) : iter(it.base()) {}
    		// base
    		pointer base(void) const
    		{
    			return iter;
    		}
    		// + + + + + + + + + Operator overload
    		//operator=
    		bd_iterator& operator=(bd_iterator const &it)
    		{
    			iter = it.base();
    			return (*this);
    		}
    		//operator*
    		reference operator*(void) const
    		{
    			pointer tmp = iter;
    			return *tmp;
    		}
    		//operator->
    		pointer operator->(void) const
    		{
    			return &(operator*());;
    		}
    		//operator++ (pre)
    		bd_iterator& operator++(void)
    		{
    			iter++;
    			return (*this);
    		}
    		//operator++ (post)
    		bd_iterator operator++(int)
    		{
    			bd_iterator temp(*this);
    			iter++;
    			return (temp);
    		}
    		//operator-- (pre)
    		bd_iterator& operator--(void)
    		{
    			iter--;
    			return (*this);
    		}
    		//operator-- (post)
    		bd_iterator operator--(int)
    		{
    			bd_iterator temp(*this);
    			iter--;
    			return (temp);
    		}
    };
    template <class Iterator>
    bool operator==(const bd_iterator<Iterator>& x, const bd_iterator<Iterator>& y)
    {
    	return (x.base() == y.base());
    }
    template <class Iterator>
    bool operator!=(const bd_iterator<Iterator>& x, const bd_iterator<Iterator>& y)
    {
    	return (x.base() != y.base());
    }
}

#endif
