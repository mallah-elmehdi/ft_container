// #include <iostream>
// // #include <vector>
// // #include "vector.hpp"
// // #include "iterator.hpp"
//
// int main()
// {
//   // std::vector<int> v(10, 2);
//   // v.reserve(20);
//   // std::cout  << "capacity = " << v.capacity() << "\n";
//   // std::cout  << "size = " << v.size() << "\n";
//   // // std::vector<int> v1;
//   // // std::vector<int>::iterator it = v.begin();
//   // // std::cout << &(*it) << std::endl;
//   // // v1 = v;
//   // // it = v1.begin();
//   // // std::cout << &(*it) << std::endl;
//   // v.insert(v.end(), 11, 0);
//   // // v.insert(v.end(), 11, 0);
//   // // std::cout << *it << std::endl;
//   // // for (std::vector<int>::iterator it = v.begin() ; it != v.end(); it++) {
//   // //   std::cout << *it << std::endl;
//   // // }
//   // std::cout  << "capacity = " << v.capacity() << "\n";
//   // std::cout  << "size = " << v.size() << "\n";
// }

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

std::string print_row(std::string t, std::string row, int l)
{
    int move;
    std::string output;
    for(std::string::iterator it = t.begin(); it != t.end(); it++)
    {
        move = (toupper(*it) - 65 < 0 || toupper(*it) - 65 > 25) ? 26 : toupper(*it) - 65;
        output.append(row.substr(move * l, l));
    }
    output.append("\n");
}

int main()
{
    int l;
    std::cin >> l; std::cin.ignore();
    int h;
    std::cin >> h; std::cin.ignore();
    std::string t;
    std::string output;
    std::getline(std::cin, t);
    for (int i = 0; i < h; i++) {
        std::string row;
        std::getline(std::cin, row);
        output.append(print_row(t, row, l));
    }
    std::cout << output << std::endl;
}
