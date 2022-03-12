#include <iostream>
#include <vector>
#include "vector.hpp"

int main()
{
	std::vector<int> salam(5, 2);

	for (size_t i = 0; i < 5; i++)
	{
		std::cout << salam[i] << std::endl;
	}
	std::cout << "=========================\n";
	ft::vector<int> ok(5, 2);

	//for (size_t i = 0; i < 5; i++)
	//{
	//	std::cout << ok.get(i) << std::endl;
	//}

}