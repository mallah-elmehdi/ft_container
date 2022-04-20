#include "ft.hpp"
#include <iostream>
#include <map>


ft::map<int, int> ft_map;
std::map<int, int> std_map;

void init_map()
{
	for (size_t i = 1; i <= 100; i++)
	{
		ft_map.insert(ft::make_pair(i, i*10));
		std_map.insert(std::make_pair(i, i*10));
	}
}

void member_functions()
{
	//
	std::cout << "-------------------- Member functions\n";
	std::cout << "+ copy constructor\n";
	ft::map<int, int> ft_map_copy(ft_map);
	std::map<int, int> std_map_copy(std_map);
	std::cout << "+ range constructor\n";
	ft::map<int, int> ft_map_range(ft_map.begin(), ft_map.end());
	ft::map<int, int> std_map_range(std_map.begin(), std_map.end());


	

	std::cout << "+ [ STD ] + (constructor)\n";

	std::map<int, int> std_map;
}

int main()
{
	//
	init_map();
	// 
}