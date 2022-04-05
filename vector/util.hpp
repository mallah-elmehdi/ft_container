#ifndef _UTIL_HPP_
#define _UTIL_HPP_
// * [EQUAL] *
namespace ft 
{
    template <class Iterator, class T>
    void fill(Iterator first, Iterator last, const T &val)
    {
        while (first != last)
        {
			*first = val;
			first++;
        }
    }
    
	template <class Iterator1, class Iterator2>
    void copy(Iterator1 first, Iterator1 last, Iterator2 result)
    {
        while (first != last)
        {
			*result = *first;
			result++; 
			first++;
        }
    }
    
	template<class Iterator1, class Iterator2>
    void copy_backward(Iterator1 first, Iterator1 last, Iterator2 result)
    {
        while (last != first)
		{
			*(--result) = *(--last);
		}
    }
}
#endif
