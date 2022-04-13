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

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  mymap.begin();

//   for (ft::map<char,int>::iterator it=mymap.begin(); it != mymap.end(); ++it)
    // std::cout << it->first << " => " << it->second << '\n';
}
