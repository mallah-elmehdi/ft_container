#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include "map.hpp"
#include "make_pair.hpp"
#include "pair.hpp"

char a = 'a';
int b = 1;
void ok()
{
	for (size_t i = 0; i < 26; i++)
	{
		std::cout <<  "mymap.insert(ft::make_pair('" << a++ << "', " << b++ <<"));" << "\n";
	}
	
}

int main()
{
    ft::map<char,int> mymap;
    // ft::map<char,int> mymap2;
    // //
    // mymap.insert(ft::make_pair('b', 200));
    // mymap.insert(ft::make_pair('a', 100));
    // mymap.insert(ft::make_pair('c', 300));
	// // 
    // mymap2.insert(ft::make_pair('d', 400));
    // mymap2.insert(ft::make_pair('e', 500));
    // mymap2.insert(ft::make_pair('f', 600));

	mymap.insert(ft::make_pair('d', 4));
	mymap.insert(ft::make_pair('j', 10));
	mymap.insert(ft::make_pair('y', 25));
	mymap.insert(ft::make_pair('f', 6));
	mymap.insert(ft::make_pair('g', 7));
	mymap.insert(ft::make_pair('a', 1));
	mymap.insert(ft::make_pair('i', 9));
	mymap.insert(ft::make_pair('h', 8));
	mymap.insert(ft::make_pair('m', 13));
	mymap.insert(ft::make_pair('e', 5));
	mymap.insert(ft::make_pair('b', 2));
	mymap.insert(ft::make_pair('k', 11));
	mymap.insert(ft::make_pair('n', 14));
	mymap.insert(ft::make_pair('r', 18));
	mymap.insert(ft::make_pair('u', 21));
	mymap.insert(ft::make_pair('o', 15));
	mymap.insert(ft::make_pair('l', 12));
	mymap.insert(ft::make_pair('v', 22));
	mymap.insert(ft::make_pair('p', 16));
	mymap.insert(ft::make_pair('z', 26));
	mymap.insert(ft::make_pair('t', 20));
	mymap.insert(ft::make_pair('s', 19));
	mymap.insert(ft::make_pair('c', 3));
	mymap.insert(ft::make_pair('w', 23));
	mymap.insert(ft::make_pair('q', 17));
	mymap.insert(ft::make_pair('x', 24));
	mymap.insert(ft::make_pair('d', 4));
	mymap.insert(ft::make_pair('j', 10));
	mymap.insert(ft::make_pair('y', 25));
	mymap.insert(ft::make_pair('f', 6));
	mymap.insert(ft::make_pair('g', 7));
	mymap.insert(ft::make_pair('a', 1));
	mymap.insert(ft::make_pair('i', 9));
	mymap.insert(ft::make_pair('h', 8));
	mymap.insert(ft::make_pair('m', 13));
	mymap.insert(ft::make_pair('e', 5));
	mymap.insert(ft::make_pair('b', 2));
	mymap.insert(ft::make_pair('k', 11));
	mymap.insert(ft::make_pair('n', 14));
	mymap.insert(ft::make_pair('r', 18));
	mymap.insert(ft::make_pair('u', 21));
	mymap.insert(ft::make_pair('o', 15));
	mymap.insert(ft::make_pair('l', 12));
	mymap.insert(ft::make_pair('v', 22));
	mymap.insert(ft::make_pair('p', 16));
	mymap.insert(ft::make_pair('z', 26));
	mymap.insert(ft::make_pair('t', 20));
	mymap.insert(ft::make_pair('s', 19));
	mymap.insert(ft::make_pair('c', 3));
	mymap.insert(ft::make_pair('w', 23));
	mymap.insert(ft::make_pair('q', 17));
	mymap.insert(ft::make_pair('x', 24));

    // mymap2.insert(mymap.begin(), mymap.end());

	ft::map<char, int>::iterator it = mymap.begin();

	// ok();
	++it;
	++it;
	++it;
	++it;
	++it;
	it++;
	it++;
	it++;
	it++;
	it++;
	
	// --it2;
    // ft::cout << it2->first << '\n';
    // it++;
    // std::cout << it->first << " => " << it->second << '\n';
    // it++;
    // ft::cout << it->first << " => " << it->second << '\n';
    // it++;
    // for (ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); it++)
        std::cout << it->first << " => " << it->second << '\n';
}
