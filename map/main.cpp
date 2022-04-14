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
    ft::map<char,int> mymap2;
    //
    mymap.insert(ft::make_pair('b', 200));
    mymap.insert(ft::make_pair('a', 100));
    mymap.insert(ft::make_pair('c', 300));
	// 
    mymap2.insert(ft::make_pair('d', 400));
    mymap2.insert(ft::make_pair('e', 500));
    mymap2.insert(ft::make_pair('f', 600));


    mymap2.insert(mymap.begin(), mymap.end());

    ft::map<char,int>::iterator it2 = mymap2.begin();
    ft::map<char,int>::iterator it = mymap2.begin();

	it = it2;
	// --it2;
    // std::cout << it2->first << '\n';
    // it++;
    // ft::cout << it->first << " => " << it->second << '\n';
    // it++;
    // ft::cout << it->first << " => " << it->second << '\n';
    // it++;
    // for (ft::map<char,int>::iterator it = mymap2.begin(); it != mymap2.end(); it++)
        // std::cout << it->first << " => " << it->second << '\n';
}
