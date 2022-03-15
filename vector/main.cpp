#include <iostream>
#include <vector>
#include "vector.hpp"
#include "iterator.hpp"

int main()
{
	//std::vector<int> test(5);
	//for (size_t i = 0; i < 5; i++)
	//{
	//	test[i] = i + 1;
	//}
	//std::vector<int>::iterator it = test.begin();
	std::vector<int>::iterator it2;
	std::cout << "vector : "<< it2.operator->() << std::endl;
	
	ft::iterator<int> _it;
	ft::iterator<int> _it2;
	std::cout << "ft : "<< _it.operator->() << std::endl;

	//std::vector<int> test(5);
	//std::vector<int>::iterator it2 = test.begin();
	//for (size_t i = 0; i < 5; i++)
	//{
	//	test[i] = i + 3;
	//}
	//it = it2;
	//std::cout << *it << std::endl;
	//std::cout << *it2 << std::endl;
	
	//std::cout << "================================" << std::endl;
	
	//ft::iterator<int> _it;
	//ft::iterator<int> _it2;
	//_it = _it2;
}