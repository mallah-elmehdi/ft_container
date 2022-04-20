#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>
#include "ft.hpp"

// Reset
#define Color_Off "\e[0m"       // Text Reset
// Bold
#define BBlack "\e[1;30m"       // Black
#define BRed "\e[1;31m"         // Red
#define BGreen "\e[1;32m"       // Green
#define BYellow "\e[1;33m"      // Yellow
#define BBlue "\e[1;34m"        // Blue
#define BPurple "\e[1;35m"      // Purple
#define BCyan "\e[1;36m"        // Cyan
#define BWhite "\e[1;37m"       // White
// Background
#define On_Black "\e[40m"       // Black
#define On_Red "\e[41m"         // Red
#define On_Green "\e[42m"       // Green
#define On_Yellow "\e[43m"      // Yellow
#define On_Blue "\e[44m"        // Blue
#define On_Purple "\e[45m"      // Purple
#define On_Cyan "\e[46m"        // Cyan
#define On_White "\e[47m"       // White

// ======================================================== GLOBAL VARIABLES

int LENGTH = 100;

std::vector<int> std_vector(LENGTH);
ft::vector<int> ft_vector(LENGTH);

// std::map<int, int>::iterator std_it;
// ft::map<int, int>::iterator ft_it;

// std::map<int, int>::const_iterator std_cit;
// ft::map<int, int>::const_iterator ft_cit;

// std::map<int, int>::reverse_iterator std_rit;
// ft::map<int, int>::reverse_iterator ft_rit;

// std::map<int, int>::const_reverse_iterator std_crit;
// ft::map<int, int>::const_reverse_iterator ft_crit;

// ======================================================== HELP FUNCTIONS

void ok()
{
	std::cout << BGreen << "[OK]\n" << Color_Off;
}

void ko()
{
	std::cout << BRed << "[KO]\n" << Color_Off;
}

void _title(std::string str)
{
	std::cout << BBlue << "+ " << std::setw(60) << std::left << str << Color_Off;
}

void big_title(std::string str)
{
	std::cout << On_Purple << BWhite << "\n-------------------- " << str << Color_Off << "\n\n";
}

void init_map()
{
	for (int i = 1; i <= LENGTH; i++)
	{
		
	}
}

void check_values(std::map<int, int> _std, ft::map<int, int> _ft)
{
	if (_std.size() != _ft.size())
	{
		std::cout << _std.size() << " != " << _ft.size() << "\n";
		ko();
		return ;
	}
	for (int i = 1; i <= LENGTH; i++)
	{
		if (_std[i] != _ft[i])
		{
			ko();
			return ;
		}
	}
	ok();
}

void check_iterator()
{
	if (std_it->first != ft_it->first || std_it->second != ft_it->second)
	{
		ko();
		return ;
	}
	ok();
}

void check_const_iterator()
{
	if (std_cit->first != ft_cit->first || std_cit->second != ft_cit->second)
	{
		ko();
		return ;
	}
	ok();
}

void check_reverse_iterator()
{
	if (std_rit->first != ft_rit->first || std_rit->second != ft_rit->second)
	{
		ko();
		return ;
	}
	ok();
}

void check_const_reverse_iterator()
{
	if (std_crit->first != ft_crit->first || std_crit->second != ft_crit->second)
	{
		ko();
		return ;
	}
	ok();
}

void check_capacity(bool results)
{
	if (!results)
	{
		ko();
		return ;
	}
	ok();
}

// ======================================================== TEST FUNCTIONS

void member_functions()
{
	big_title("Member functions");
	
	title("default constructor");
	std::map<int, int> std_map_default;
	ft::map<int, int> ft_map_default;
	check_values(std_map_default, ft_map_default);

	title("copy constructor");
	std::map<int, int> std_map_copy(std_map);
	ft::map<int, int> ft_map_copy(ft_map);
	check_values(std_map_copy, ft_map_copy);
	
	title("range constructor");
	std::map<int, int> std_map_range(std_map.begin(), std_map.end());
	ft::map<int, int> ft_map_range(ft_map.begin(), ft_map.end());
	check_values(std_map_range, ft_map_range);
	
	{
		title("destructor");
		std::map<int, int> std_map_destructor;
		ft::map<int, int> ft_map_destructor;
		check_values(std_map_destructor, ft_map_destructor);
	}

	title("operator=");
	std::map<int, int> std_map_operator = std_map;
	ft::map<int, int> ft_map_operator = ft_map;
	check_values(std_map_operator, ft_map_operator);
}

void iterators()
{
	big_title("Iterators");
	
	title("begin - [iterator]");
	std_it = std_map.begin();
	ft_it = ft_map.begin();
	check_iterator();

	title("begin - [const iterator]");
	std_cit = std_map.begin();
	ft_cit = ft_map.begin();
	check_const_iterator();

	title("end - [iterator]");
	std_it = --std_map.end();
	ft_it = --ft_map.end();
	check_iterator();

	title("end - [const iterator]");
	std_cit = --std_map.end();
	ft_cit = --ft_map.end();
	check_const_iterator();

	title("rbegin - [reverse iterator]");
	std_rit = std_map.rbegin();
	ft_rit = ft_map.rbegin();
	check_reverse_iterator();

	title("rbegin - [const reverse iterator]");
	std_crit = std_map.rbegin();
	ft_crit = ft_map.rbegin();
	check_const_reverse_iterator();

	title("rend - [reverse iterator]");
	std_rit = --std_map.rend();
	ft_rit = --ft_map.rend();
	check_reverse_iterator();

	title("rend - [const reverse iterator]");
	std_crit = --std_map.rend();
	ft_crit = --ft_map.rend();
	check_const_reverse_iterator();
}

int main()
{
	init_map();
	member_functions();
	iterators();

	std::cout << "\n";
}