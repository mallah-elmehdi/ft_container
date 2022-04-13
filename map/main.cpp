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
	mymap.insert(ft::make_pair(0, 19999));
	mymap.insert(ft::make_pair(-2, 232));
	mymap.insert(ft::make_pair(3, -22));
	mymap.insert(ft::make_pair(102, 332));

    ft::map<int, int>::iterator it = mymap.begin();
	it++;
	it++;
	std::cout << (*it).second << "\n";
}
