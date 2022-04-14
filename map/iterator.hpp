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
    		typedef value_type*  							pointer;
    		typedef value_type&								reference;
    		typedef std::bidirectional_iterator_tag			iterator_category;
    	private:
    		pointer				iter;
    		Node<value_type>	*node;
    	public:
    		// + + + + + + + + + Member functions
    		//default constuctor
    		bd_iterator(void) : iter(), node() {std::cout << "default\n";}
    		//copy constuctor
    		bd_iterator(Node<value_type> *x) : node(x), iter(x->pairv) {std::cout << "node\n";}
    		bd_iterator(const bd_iterator &it) : iter(it.iter), node(it.node) {std::cout << "copy\n";}
    		template <class _pair_type>
    		bd_iterator(const bd_iterator<_pair_type> &it) : iter(it.iter), node(it.node) {std::cout << "op =\n";}
    		// base
    		pointer base(void) const
    		{
    			return iter;
    		}
    		// + + + + + + + + + Operator overload
    		//operator=
    		bd_iterator& operator=(bd_iterator const &it)
    		{
    			iter = it.iter;
    			node = it.node;
    			return (*this);
    		}
    		//operator*
    		reference operator*(void) const
    		{
    			return (*iter);
    		}
    		//operator->
    		pointer operator->(void) const
    		{
    			return (iter);
    		}
    		//operator++ (pre)
    		bd_iterator& operator++(void)
    		{
				if (node->right->pairv != NULL)
				{
					node = node->right;
					
					while (node->left->pairv != NULL)
					{
						node = node->left;
					}
					iter = node->pairv;
				}
				else
				{
					Node<value_type> *p = node->parent;
					while (p != NULL && node == p->right)
					{
						node = p;
						p = p->parent;
					}
					if (node != NULL)
						iter = node->pairv;
				}
				
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
				if (node == NULL)
					std::cout << "NULL" << "\n";
				if (node->parent == NULL || node == node->parent->right)
					node = node->parent;
				else
					node = node->left;
				iter = node->pairv;
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
