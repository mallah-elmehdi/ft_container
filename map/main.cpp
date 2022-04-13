#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include "map.hpp"
#include "make_pair.hpp"
#include "pair.hpp"

void ok(std::string str, int i)
{
    std::string hold = str;
    if (i < 10) ok(str.append(i), i + 1);
    std::cout << hold << "\n";
}

int main()
{
    ok("hello", 1);
    // ft::map<char,int> mymap;
    //
    // mymap.insert(ft::make_pair('b', 100));
    // mymap.insert(ft::make_pair('a', 200));
    // mymap.insert(ft::make_pair('c', 300));

    // ft::map<char,int> mymap2(mymap);

    // ft::map<char,int>::iterator it = mymap.begin();
    // ft::map<char,int>::iterator it2=mymap.end();
    // std::cout << bool(it == it) << '\n';
    // it++;
    // std::cout << it->first << " => " << it->second << '\n';
    // it++;
    // std::cout << it->first << " => " << it->second << '\n';
    // it++;
    // for (ft::map<char,int>::iterator it=mymap2.begin(); it != mymap2.end(); it++)
    //     std::cout << it->first << " => " << it->second << '\n';
}
