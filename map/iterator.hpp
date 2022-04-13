#ifndef _BD_ITERATOR_
#define _BD_ITERATOR_

# include <iterator>
# include "node.hpp"
# include "pair.hpp"

namespace ft
{
    template <class pair_type>
    class bd_iterator {
    	public:
    		// + + + + + + + + + Member type
    		typedef pair_type			                  	value_type;
    		typedef std::ptrdiff_t							difference_type;
    		typedef Node<value_type>*  						pointer;
    		typedef pair_type&								reference;
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
    		template <class _pair_type>
    		bd_iterator(const bd_iterator<_pair_type> &it) : iter(it.base()) {}
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
    			return *(tmp->pairv);
    		}
    		//operator->
    		pointer operator->(void) const
    		{
    			return &(operator*());;
    		}
    		//operator++ (pre)
    		bd_iterator& operator++(void)
    		{
				if (iter == iter->parent->right)
					iter = iter->right;
				else
					iter = iter->parent;
    			return (*this);
    		}
    		//operator++ (post)
    		bd_iterator operator++(int)
    		{
    			bd_iterator temp(*this);
				this->operator++();
    			return (temp);
    		}
    		//operator-- (pre)
    		bd_iterator& operator--(void)
    		{
				if (iter == iter->parent->right)
					iter = iter->parent;
				else
					iter = iter->left;
    			return (*this);
    		}
    		//operator-- (post)
    		bd_iterator operator--(int)
    		{
    			bd_iterator temp(*this);
    			this->operator--();
    			return (temp);
    		}
    };
    // template <class Iterator>
    // bool operator==(const bd_iterator<Iterator>& x, const bd_iterator<Iterator>& y)
    // {
    // 	return (x.base() == y.base());
    // }
    // template <class Iterator>
    // bool operator!=(const bd_iterator<Iterator>& x, const bd_iterator<Iterator>& y)
    // {
    // 	return (x.base() != y.base());
    // }
}

#endif
