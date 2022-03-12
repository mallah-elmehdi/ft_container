#include <iostream>
#include <vector>
#include "vector.hpp"

int main()
{
	std::vector<int> salam(50000, 2);

	for (size_t i = 0; i < 50000; i++)
	{
		std::cout << salam[i] << std::endl;
	}
	
	std::cout << "=========================\n";
	
	ft::vector<int> ok(50000, 2);

	for (size_t i = 0; i < 50000; i++)
	{
		std::cout << ok.get(i) << std::endl;
	}

}