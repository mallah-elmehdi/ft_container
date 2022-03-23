#include <iostream>
#include <vector>
// #include "vector.hpp"
#include "iterator.hpp"

int main()
{
	int *ptr1 = new int[10];
	int *ptr2 = new int[10];

	for (size_t i = 0; i < 10; i++) {
		ptr1[i] = i;
		ptr2[i] = i + 1;
	}

	ft::iterator<int> it;
	ft::iterator<int> it1(ptr1);
	ft::iterator<int> it2(it1);

	it2 += 5;
	it2 -= 1;
	std::cout << it2[1] << std::endl;
}
