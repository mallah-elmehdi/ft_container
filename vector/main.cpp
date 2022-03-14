#include <iostream>
#include <vector>
#include "vector.hpp"

int main()
{
	std::vector<int> test(5);
	std::vector<int>::iterator it = test.begin();
	for (size_t i = 0; i < 5; i++)
	{
		test[i] = i;
	}
	it + 1;
	std::cout << *it << std::endl;
}