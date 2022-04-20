#include "ft.hpp"
#include <iostream>
#include <iomanip>
#include <map>

#define LENGTH 100
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

std::map<int, int> std_map;
ft::map<int, int> ft_map;

std::map<int, int>::iterator std_map_it;
ft::map<int, int>::iterator ft_map_it;

std::map<int, int>::const_iterator std_map_cit;
ft::map<int, int>::const_iterator ft_map_cit;

// ======================================================== HELP FUNCTIONS

void ok()
{
	std::cout << BGreen << "[OK]\n" << Color_Off;
}

void ko()
{
	std::cout << BRed << "[KO]\n" << Color_Off;
}

void title(std::string str)
{
	std::cout << BBlue << "+ " << std::setw(20) << std::left << str << Color_Off;
}

void big_title(std::string str)
{
	std::cout << On_Purple << BWhite << "\n-------------------- " << str << Color_Off << "\n\n";
}

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
	
	title("begin");
	std_map_it = std_map_it;
	ft::map<int, int>::iterator ft_map_it;
	check_values(std_map_default, ft_map_default);

}

int main()
{
	// 
	init_map();
	// 
	member_functions();

}