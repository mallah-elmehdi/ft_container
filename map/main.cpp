#include "ft.hpp"
#include <iostream>
#include <map>

#define LENGTH 100

std::map<int, int> std_map;
ft::map<int, int> ft_map;

void init_map()
{
	for (int i = 1; i <= LENGTH; i++)
	{
		std_map.insert(std::make_pair(i, i*10));
		ft_map.insert(ft::make_pair(i, i*10));
	}
}

void check_values(std::map<int, int> _std, ft::map<int, int> _ft)
{
	for (int i = 0; i < LENGTH; i++)
	{
		if ((int)_std[i] != (int)_ft[i]);
		{
			std::cout << " =========== [KO]\n";
			return ;
		}
	}
	std::cout << " =========== [OK]\n";
}

void member_functions()
{
	//
	std::cout << "\n-------------------- Member functions\n\n";
	
	std::cout << "+ copy constructor";
	std::map<int, int> std_map_copy(std_map);
	ft::map<int, int> ft_map_copy(ft_map);
	check_values(std_map_copy, ft_map_copy);
	
	std::cout << "+ range constructor";
	std::map<int, int> std_map_range(std_map.begin(), std_map.end());
	ft::map<int, int> ft_map_range(ft_map.begin(), ft_map.end());
	check_values(std_map_copy, ft_map_copy);
}

int main()
{
	//
	init_map();
	// 
	member_functions();
}