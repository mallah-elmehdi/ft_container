#include <iostream>
#include <vector>
#include "vector.hpp"
#include "iterator.hpp"
#include "equal.hpp"

 // int main()
 // {
     // ft::vector<int> v1(5, -1);
     // ft::vector<int> v2(3, 1);
     //
     // std::cout << "------------- before" << std::endl;
     // std::cout << &v1.front() << std::endl;
     // std::cout << &v2.front() << std::endl;
     // for (ft::vector<int>::iterator it = v1.begin(); it != v1.end(); it++) std::cout << *it << std::endl;
     // for (ft::vector<int>::iterator it = v2.begin(); it != v2.end(); it++) std::cout << *it << std::endl;
     // std::cout  << "v1 capacity = " << v1.capacity() << "\n";
     // std::cout  << "v1 size = " << v1.size() << "\n";
     // std::cout  << "v2 capacity = " << v2.capacity() << "\n";
     // std::cout  << "v2 size = " << v2.size() << "\n";
     // std::cout << "------------- after" << std::endl;
     // v1.swap(v2);
     // std::cout << &v1.front() << std::endl;
     // std::cout << &v2.front() << std::endl;
     // for (ft::vector<int>::iterator it = v1.begin(); it != v1.end(); it++) std::cout << *it << std::endl;
     // for (ft::vector<int>::iterator it = v2.begin(); it != v2.end(); it++) std::cout << *it << std::endl;
     // std::cout  << "v1 capacity = " << v1.capacity() << "\n";
     // std::cout  << "v1 size = " << v1.size() << "\n";
     // std::cout  << "v2 capacity = " << v2.capacity() << "\n";
     // std::cout  << "v2 size = " << v2.size() << "\n";
    //for (size_t i = 0; i < 5; i++)
    //{
    //    v[i] = i + 1;
    //}
    //v.reserve(60);
    //std::cout << "------------- before" << std::endl;

    //for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    //{
    //    std::cout << *it << std::endl;
    //}
    //std::cout  << "capacity = " << v.capacity() << "\n";
    //std::cout  << "size = " << v.size() << "\n";

    //std::cout << "------------- after" << std::endl;

    //v.erase(v.end());
    //for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    //{
    //    std::cout << *it << std::endl;
    //}
    //std::cout  << "capacity = " << v.capacity() << "\n";
    //std::cout  << "size = " << v.size() << "\n";

    // std::is_integral<char> ok;
    // std::cout  <<  ok.value  << "\n";
 // }


bool mypredicate (int i, int j) {
  return (i + j > 0);
}

int main () {
  int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
  std::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

  // using default comparison:
  if ( ft::equal (myvector.begin(), myvector.end(), myints) )
    std::cout << "The contents of both sequences are equal.\n";
  else
    std::cout << "The contents of both sequences differ.\n";

  myvector[3]=81;                                 // myvector: 20 40 60 81 100

  // using predicate comparison:
  if ( ft::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
    std::cout << "The contents of both sequences are equal.\n";
  else
    std::cout << "The contents of both sequences differ.\n";

  return 0;
}
