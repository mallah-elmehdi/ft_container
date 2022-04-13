#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include "map.hpp"
#include "make_pair.hpp"
#include "pair.hpp"

int main()
{
 ft::map<char,int> mymap;

  mymap.insert(ft::make_pair('b', 100));
  mymap.insert(ft::make_pair('a', 200));
  mymap.insert(ft::make_pair('c', 300));

  // show content:

  for (ft::map<char,int>::iterator it=mymap.begin(); it != mymap.end(); it++)
    std::cout << it->first << " => " << it->second << '\n';
}
