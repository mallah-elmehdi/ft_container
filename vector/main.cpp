#include <iostream>
#include <vector>
#include "vector.hpp"
#include "iterator.hpp"

int main()
{
  ft::vector<int> v(10, 2);
  // v.reserve(1000);
  // ft::vector<int> v1;
  ft::vector<int>::iterator it = v.begin();
  // std::cout << &(*it) << std::endl;
  // v1 = v;
  // it = v1.begin();
  // std::cout << &(*it) << std::endl;
  it = v.insert(it, 9);
  // std::cout << *it << std::endl;
  for (ft::vector<int>::iterator it = v.begin() ; it != v.end(); it++) {
    std::cout << *it << std::endl;
  }
  std::cout  << "capacity = " << v.capacity() << "\n";
  std::cout  << "size = " << v.size() << "\n";
}
