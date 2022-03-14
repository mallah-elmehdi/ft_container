#include <iostream>
#include <vector>
#include "vector.hpp"

int main()
{
	std::vector<int> test(5, 1);
	std::cout << "capacity : " << test.capacity() << std::endl;
	std::cout << "size : " << test.size() << std::endl;
	test.push_back(10);
	test.push_back(10);
	test.push_back(10);
	test.push_back(10);
	test.push_back(10);
	std::cout << "capacity : " << test.capacity() << std::endl;
	std::cout << "size : " << test.size() << std::endl;
	test.push_back(10);
	std::cout << "capacity : " << test.capacity() << std::endl;
	std::cout << "size : " << test.size() << std::endl;
}