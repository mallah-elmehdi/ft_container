#include "ft.hpp"
#include <iostream>
#include <iomanip>
#include <map>

#define LENGTH 100
// Reset
#define Color_Off '\033[0m'       // Text Reset
// Bold
#define BBlack '\033[1;30m'       // Black
#define BRed '\033[1;31m'         // Red
#define BGreen '\033[1;32m'       // Green
#define BYellow '\033[1;33m'      // Yellow
#define BBlue '\033[1;34m'        // Blue
#define BPurple '\033[1;35m'      // Purple
#define BCyan '\033[1;36m'        // Cyan
#define BWhite '\033[1;37m'       // White
// Background
#define On_Black '\033[40m'       // Black
#define On_Red '\033[41m'         // Red
#define On_Green '\033[42m'       // Green
#define On_Yellow '\033[43m'      // Yellow
#define On_Blue '\033[44m'        // Blue
#define On_Purple '\033[45m'      // Purple
#define On_Cyan '\033[46m'        // Cyan
#define On_White '\033[47m'       // White


std::map<int, int> std_map;
ft::map<int, int> ft_map;

void ok()
{
	std::cout << " =========== [OK]\n";
}

void ko()
{
	std::cout << " =========== [KO]\n";
}

void title(std::string str)
{
	std::cout << "+ " << std::setw(20) << std::left << str;
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

void member_functions()
{
	//
	std::cout << "\n-------------------- Member functions\n\n";
	
	title("copy constructor");
	std::map<int, int> std_map_copy(std_map);
	ft::map<int, int> ft_map_copy(ft_map);
	check_values(std_map_copy, ft_map_copy);
	
	title("range constructor");
	std::map<int, int> std_map_range(std_map.begin(), std_map.end());
	ft::map<int, int> ft_map_range(ft_map.begin(), ft_map.end());
	check_values(std_map_range, ft_map_range);
}

int main()
{
	//
	init_map();
	// 
	member_functions();

}