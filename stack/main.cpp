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
	for (int i = 0; i < LENGTH; i++)
	{
		std_vector[i] = i + 1;
		ft_vector[i] = i + 1;
	}
}

// ======================================================== TEST FUNCTIONS

void member_functions()
{
	big_title("Member functions");
	
	_title("constructor");
	std::stack<int, std::vector<int> > std_stack_default(std_vector);
	ft::stack<int, ft::vector<int> > ft_stack_default(ft_vector);

	{
		if (std_stack_default.size() != ft_stack_default.size())
		{
			ko();
			return ;
		}
		for (int i = 1; i <= LENGTH; i++)
		{
			if (std_stack_default.top() != ft_stack_default.top())
			{
				ko();
				return ;
			}
			std_stack_default.pop();
			ft_stack_default.pop();
		}
		ok();
	}
	_title("empty");
	{
		if (std_stack_default.empty() != ft_stack_default.empty())
		{
			ko();
			return;
		}
		ok();
	}

	for (int i = 0; i < LENGTH; i++)
	{
		std_stack_default.push(i);
		ft_stack_default.push(i);
	}

	_title("size");
	{
		if (std_stack_default.size() != ft_stack_default.size())
		{
			ko();
			return;
		}
		ok();
	}

	_title("top");
	{
		if (std_stack_default.top() != ft_stack_default.top())
		{
			ko();
			return;
		}
		ok();
	}

	_title("push");
	{
		std_stack_default.push(5);
		ft_stack_default.push(5);
		if (std_stack_default.top() != ft_stack_default.top())
		{
			ko();
			return;
		}
		ok();
	}
	_title("pop");
	{
		std_stack_default.pop();
		ft_stack_default.pop();
		if (std_stack_default.top() != ft_stack_default.top())
		{
			ko();
			return;
		}
		ok();
	}
	big_title("Non-member function overloads");

	_title("relational operators");
	{
		std::vector<int> std_vector_help(LENGTH);
		ft::vector<int> ft_vector_help(LENGTH);
		
		std::stack<int, std::vector<int> > std_stack_help(std_vector_help);
		ft::stack<int, ft::vector<int> > ft_stack_help(ft_vector_help);
		
		if (
			(std_stack_default == std_stack_help) != (std_stack_default == std_stack_help)
			|| 
			(std_stack_default != std_stack_help) != (std_stack_default != std_stack_help)
			||
			(std_stack_default < std_stack_help) != (std_stack_default < std_stack_help)
			||
			(std_stack_default <= std_stack_help) != (std_stack_default <= std_stack_help)
			||
			(std_stack_default > std_stack_help) != (std_stack_default > std_stack_help)
			||
			(std_stack_default >= std_stack_help) != (std_stack_default >= std_stack_help)
		)
		{
			ko();
			return;
		}
		ok();
	}

}

int main()
{
    std::cout << On_Cyan << BBlack << "\n***********************************\n" << Color_Off;
    std::cout << On_Cyan << BBlack << "************** STACK **************\n" << Color_Off;
    std::cout << On_Cyan << BBlack << "***********************************\n" << Color_Off;
	init_map();
	member_functions();
	std::cout << "\n";
}