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
    		bd_iterator(void) : iter(), node() {}
    		//copy constuctor
    		bd_iterator(Node<value_type> *x) : node(x), iter(x->pairv) {}
    		bd_iterator(const bd_iterator &it) : iter(it.iter), node(it.node) {}
    		template <class _pair_type>
    		bd_iterator(const bd_iterator<_pair_type> &it) : iter(it.iter), node(it.node) {}
    		// base
    		pointer base(void) const
    		{
    			return iter;
    		}
    		Node<value_type> *nodeBase(void) const
    		{
    			return node;
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
				if (node->right->nil == false)
				{
					node = node->right;
					
					while (node->left->nil == false)
					{
						node = node->left;
					}
				}
				else
				{
					Node<value_type> *p = node->parent;
					while (p->nil == false && node == p->right)
					{
						node = p;
						p = p->parent;
					}
					node = p;
				}
				iter = node->pairv;
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
				if (node->left->nil == false)
				{
					node = node->left;
					
					while (node->right->nil == false)
					{
						node = node->right;
					}
				}
				else
				{
					Node<value_type> *p = node->parent;
					while (p->nil == false && node == p->left)
					{
						node = p;
						p = p->parent;
					}
					node = p;
				}
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
