#include <iostream>
#include <vector>
// #include "vector.hpp"
// #include "iterator.hpp"

int main()
{
  std::vector<int> v(5);
  try {

    v.reserve(v.max_size() + 100);
  }
  catch(const std::length_error& le)
  {
    std::cerr << le.what() << '\n';

}
  // ft::vector<int>::iterator _it = v.begin();
  // _it += 5;
  // v.insert(_it, 1, 3);
  // for (ft::vector<int>::iterator it = v.begin() ; it != v.end(); it++) {
    // std::cout << *it << std::endl;
  // }
  std::cout  << "capacity = " << v.capacity() << "\n";
  std::cout  << "size = " << v.size() << "\n";
}
