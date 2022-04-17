#ifndef _BD_ITERATOR_
#define _BD_ITERATOR_

#include "ft.hpp"

template <class pair_type>
class bd_iterator {
	public:
		// + + + + + + + + + Member type
		typedef pair_type			                  	value_type;
		typedef std::ptrdiff_t							difference_type;
		typedef value_type*  							pointer;
		typedef value_type&								reference;
		typedef std::bidirectional_iterator_tag			iterator_category;
		typedef ft::Node<value_type>					node;
	
	private:
		pointer	iter;
		node	*_node;
	
	public:
		operator bd_iterator<const pair_type> () const
		{
			return bd_iterator<const pair_type>(_node);
		}
		//default constuctor
		bd_iterator(void) : iter(), _node() {}
		
		//copy constuctor
		bd_iterator(node *x) : iter(x->pairv), _node(x) {}
		
		bd_iterator(const bd_iterator &it) : iter(it.iter), _node(it._node) {}
		
		template <class _pair_type>
		bd_iterator(const bd_iterator<_pair_type> &it) : iter(it.iter), _node(it._node) {}
		// + + + + + + + + + Operator overload
		pointer base()
		{
			return (iter);
		}
		node *nodes()
		{
			return (_node);
		}
		//operator=
		bd_iterator& operator=(bd_iterator const &it)
		{
			iter = it.iter;
			_node = it._node;
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
			node *nodeHold = _node;
			if (_node->right->nil == false)
			{
				_node =_node->right;
				
				while (_node->left->nil == false)
				{
					_node =_node->left;
				}
			}
			else
			{
				node *p = _node->parent;
				while (p && p->nil == false && _node == p->right)
				{
					_node = p;
					p = p->parent;
				}
				_node = p;
			}
			if (_node == NULL)
				_node = nodeHold->right;
			iter = _node->pairv;
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
			if (_node->nil == true)
				_node = _node->parent;
			else if (_node->left->nil == false)
			{
				_node = _node->left;
				
				while (_node->right->nil == false)
				{
					_node = _node->right;
				}
			}
			else
			{
				node *p = _node->parent;
				while (p->nil == false && _node == p->left)
				{
					_node = p;
					p = p->parent;
				}
				_node = p;
			}
			iter = _node->pairv;
			return (*this);
		}
		//operator-- (post)
		bd_iterator operator--(int)
		{
			bd_iterator temp(*this);
			this->operator--();
			return (temp);
		}
		bool operator==(const bd_iterator& it)
		{
			return (iter == it.iter);
		}
		bool operator!=(const bd_iterator& it)
		{
			return (iter != it.iter);
		}
};

#endif
