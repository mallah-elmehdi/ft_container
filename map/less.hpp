#ifndef _LESS_
#define _LESS_

namespace ft
{
    template <class T>
    class less
    {
        public:
            // +++++ Member types
            typedef T       first_argument_type;
            typedef T       second_argument_type;
            typedef bool    result_type;

        public:
            // +++++ Member functions
            bool operator() (const T& x, const T& y) const {return x < y;}

    };
}

#endif
