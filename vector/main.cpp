#include <iostream>
#include <vector>
#include "vector.hpp"
#include "iterator.hpp"

int main()
{
  std::cout << "====== vector ======\n";

  ft::vector<int> v(100);
  for (size_t i = 0; i < 100; i++) {
    v[i] = i;
  }
  v.resize(10);
  // std::cout << v.capacity() << "\n";
  // for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
  try {
    std::cout << v.at(9) << std::endl;

  }
  catch (const std::out_of_range& oor) {
    std::cerr << "Out of Range error: " << oor.what() << '\n';
  }
  // }

  // std::cout << "====== ft ======\n";
  // ft::vector<int> v(10);
  // for (size_t i = 0; i < 10; i++) {
  //   v[i] = i;
  //   std::cout << v[i] << std::endl;
  // }
  // for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
  //   std::cout << [] << std::endl;
  // }

  // ft::vector<int> iv(1);
  // std::cout << iv.empty() << std::endl;
  // std::cout << v.size() << std::endl;
  // std::cout << v.capacity() << std::endl;
  // v.resize(30, 9);
  // std::cout << v.size() << std::endl;
  // std::cout << v.capacity() << std::endl;
  // for (size_t i = 0; i < 10; i++) {
  //     std::cout << v[i] << std::endl;
  // }
	// int *ptr1 = new int[10];
	// int *ptr2 = new int[10];
	//
	// for (size_t i = 0; i < 10; i++) {
	// 	ptr1[i] = 12;
	// 	ptr2[i] = 22;
	// }
	//
	// ft::iterator<int> it;
	// ft::iterator<int> it1(ptr1);
	// ft::iterator<int> it2(it1);
	//
	// std::cout << *it2.base() << std::endl;
}
