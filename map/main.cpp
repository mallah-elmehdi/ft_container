#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include "map.hpp"
#include "make_pair.hpp"
#include "pair.hpp"

int main()
{
    std::map<long long,int> mymap;
    ft::map<short,int> myvector;

	std::cout << mymap.max_size() << "\n";
	std::cout << myvector.max_size() << "\n";
}
