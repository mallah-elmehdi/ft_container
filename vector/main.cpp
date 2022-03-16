#include <iostream>
#include <vector>
#include "vector.hpp"
#include "iterator.hpp"

int main()
{
	std::vector<int> test(5);
	for (size_t i = 0; i < 5; i++)
	{
		test[i] = i + 1;
	}
	std::vector<int>::iterator it = test.begin();
	std::vector<int>::iterator it2 = it++;
	std::cout << "vector : " << *it << " " << *it2 << std::endl;
	int *_test = new int(5);
	for (size_t i = 0; i < 5; i++)
	{
		_test[i] = i + 1;
	}
	it.op
}