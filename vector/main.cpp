#include <iostream>
#include <vector>
#include "vector.hpp"
#include "iterator.hpp"

int main()
{
  std::vector<int> v(10, 4);
	ft::vector<int> iv(10, 4);
	// for (size_t i = 0; i < 10; i++) {
	// 	v[i] = i;
	// }
	// // std::vector<int>::iterator vit = v.begin();
  // std::cout << v.size() << std::endl;
  // std::cout << v.capacity() << std::endl;
  v.resize(5, 9);
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << std::endl;
  }
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
