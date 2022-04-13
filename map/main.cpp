#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include "map.hpp"
#include "make_pair.hpp"
#include "pair.hpp"

int main()
{
    std::map<int, int> mymap;

	mymap.insert(std::make_pair(10, 22));
	mymap.insert(std::make_pair(1, 3));
	mymap.insert(std::make_pair(0, 1));
	mymap.insert(std::make_pair(3, -22));
	mymap.insert(std::make_pair(102, 332));

    std::map<int, int>::iterator it = mymap.begin();

	std::cout << *it << "\n";
}
