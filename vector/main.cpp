#include <iostream>
#include <vector>
// #include "vector.hpp"
#include "iterator.hpp"

int main()
{
	std::vector<int> v(10);
	for (size_t i = 0; i < 10; i++) {
		v[i] = i;
	}
	std::vector<int>::iterator vit = v.begin();
	std::reverse_iterator<std::vector<int>::iterator> ex(vit);
	std::cout << *ex << std::endl;

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
