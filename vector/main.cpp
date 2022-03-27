#include <iostream>
#include <vector>
#include "vector.hpp"
#include "iterator.hpp"

int main()
{
  ft::vector<int> v(10);
  ft::vector<int> v1(v);

  // v = v1;
  // ft::vector<int>::iterator _it = v.begin();
  // _it += 5;
  // v.assign(11, -1);
  for (ft::vector<int>::iterator it = v.begin() ; it != v.end(); it++) {
    std::cout << *it << std::endl;
  }
  std::cout  << "capacity = " << v1.capacity() << "\n";
  std::cout  << "size = " << v1.size() << "\n";
}
