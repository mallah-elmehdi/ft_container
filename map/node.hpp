#ifndef _NODE_
#define _NODE_


template <class value_type>
    class Node {
        public:
            // attribute
            value_type						*pairv;
            Node<value_type>                *parent;
            Node<value_type>                *left;
            Node<value_type>                *right;
            int                        		color;
};

#endif
