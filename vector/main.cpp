#include <iostream>
#include <vector>
#include "vector.hpp"
#include "iterator.hpp"

 int main()
 {
    ft::vector<int> v(5);
    for (size_t i = 0; i < 5; i++)
    {
        v[i] = i + 1;
    }
    //v.reserve(60);
    std::cout << "------------- before" << std::endl;
    
    for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout  << "capacity = " << v.capacity() << "\n";
    std::cout  << "size = " << v.size() << "\n";
    
    std::cout << "------------- after" << std::endl;
    
    v.erase(v.end());
    for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout  << "capacity = " << v.capacity() << "\n";
    std::cout  << "size = " << v.size() << "\n";
 }