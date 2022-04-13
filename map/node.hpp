#ifndef _NODE_
#define _NODE_


template <class Key, class T>
    class Node {
        public:
            // attribute
            ft::pair<const Key, T>		*pairv;
            Node<Key, T>                *parent;
            Node<Key, T>                *left;
            Node<Key, T>                *right;
            int                         color;
};

#endif
