#include <iostream>
#include <vector>
#include "vector.hpp"
#include "iterator.hpp"

int main()
{
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2(it);
	std::cout << "vector : "<< *it << std::endl;
	std::cout << "vector : "<< *it2 << std::endl;
	
	//ft::iterator<int> _it;
	//ft::iterator<int> _it2(_it);
	//std::cout << "ft : " << *_it << std::endl;
	//std::cout << "ft : " << *_it2 << std::endl;

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