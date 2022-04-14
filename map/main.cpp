#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include "map.hpp"
#include "make_pair.hpp"
#include "pair.hpp"

// void ok(std::string str, int i)
// {
//     std::string hold = str;
//     if (i < 10) ok(str.append(i, 'a'), i + 1);
//     std::cout << hold << "\n";
// }

int main()
{
    ft::map<char,int> mymap;
    //
    mymap.insert(::make_pair('b', 100));
    mymap.insert(::make_pair('a', 200));
    mymap.insert(::make_pair('c', 300));

    // ft::map<char,int> mymap2(mymap);

    ft::map<char,int>::iterator it = mymap.begin();

    mymap.insert(it, std::make_pair('d', 400));

    // ft::map<char,int>::iterator it2=mymap.end();
    // std::cout << bool(it == it) << '\n';
    // it++;
    // std::cout << it->first << " => " << it->second << '\n';
    // it++;
    // std::cout << it->first << " => " << it->second << '\n';
    // it++;
    for (ft::map<char,int>::iterator it=mymap.begin(); it != mymap.end(); it++)
        std::cout << it->first << " => " << it->second << '\n';
}
