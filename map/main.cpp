#include <iostream>
#include <map>
#include <vector>
#include "map.hpp"
#include "make_pair.hpp"
#include "pair.hpp"

int main()
{
    std::map<char,int> mymap;
    std::vector<int> myvector;

	std::cout << mymap.max_size() << "\n";
	std::cout << myvector.max_size() << "\n";
}
