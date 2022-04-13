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
	mymap.insert(ft::make_pair(10, 22));

	std::cout << mymap.size() << "\n";
}
