#include <iostream>
#include "map.hpp"
#include "make_pair.hpp"
#include "pair.hpp"

int main()
{
    ft::map<char,int> mymap;

    mymap.insert(ft::make_pair<char, int>('a', 22));
}
