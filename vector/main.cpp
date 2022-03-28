#include <iostream>
#include <vector>
#include "vector.hpp"
#include "iterator.hpp"

int main()
{
  std::vector<int> v(10, 2);
  v.reserve(100);
  std::cout  << "capacity = " << v.capacity() << "\n";
  std::cout  << "size = " << v.size() << "\n";
  // std::vector<int> v1;
  std::vector<int>::iterator it = v.begin();
  // std::cout << &(*it) << std::endl;
  // v1 = v;
  // it = v1.begin();
  // std::cout << &(*it) << std::endl;
  v.insert(v.end() + 1, 11, 0);
  // std::cout << *it << std::endl;
  // for (std::vector<int>::iterator it = v.begin() ; it != v.end(); it++) {
  //   std::cout << *it << std::endl;
  // }
  std::cout  << "capacity = " << v.capacity() << "\n";
  std::cout  << "size = " << v.size() << "\n";
}
