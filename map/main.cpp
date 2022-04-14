#include <iostream>
#include <map>
#include <vector>
#include <memory>
// #include "map.hpp"
// #include "make_pair.hpp"
// #include "pair.hpp"

// void ok(std::string str, int i)
// {
//     std::string hold = str;
//     if (i < 10) ok(str.append(i, 'a'), i + 1);
//     std::cout << hold << "\n";
// }

int main()
{
    std::map<char,int> mymap;
    std::map<char,int> mymap2;
    //
    // mymap.insert(std::make_pair('b', 200));
    // mymap.insert(std::make_pair('a', 100));
    // mymap.insert(std::make_pair('c', 300));
	// // 
    // mymap2.insert(std::make_pair('d', 400));
    // mymap2.insert(std::make_pair('e', 500));
    // mymap2.insert(std::make_pair('f', 600));


    // mymap2.insert(mymap.begin(), mymap.end());

    std::map<char,int>::iterator it;

	++it;
	
	// --it2;
    // std::cout << it2->first << '\n';
    // it++;
    // std::cout << it->first << " => " << it->second << '\n';
    // it++;
    // std::cout << it->first << " => " << it->second << '\n';
    // it++;
    // for (std::map<char,int>::iterator it = mymap2.begin(); it != mymap2.end(); it++)
        std::cout << it->first << " => " << it->second << '\n';
}
