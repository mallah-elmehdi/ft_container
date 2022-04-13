#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include "map.hpp"
#include "make_pair.hpp"
#include "pair.hpp"

int main()
{
    ft::map<int, int> mymap;

	mymap.insert(ft::make_pair(10, 22));
	mymap.insert(ft::make_pair(1, 3));
	mymap.insert(ft::make_pair(0, 1));
	mymap.insert(ft::make_pair(3, -22));
	mymap.insert(ft::make_pair(102, 332));

	std::cout << mymap[10] << "\n";
	std::cout << mymap[0] << "\n";
	std::cout << mymap[1] << "\n";
	std::cout << mymap[102] << "\n";
}
