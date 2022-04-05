#include <iostream>
#include "s.hpp"



namespace ft
{
    class OK2 {
    public:
        void salam()
        {
            std::cout << "salam\n";
            ft::OK1 k;
            k.ok();
        }
    };
}

int main()
{
    ft::OK2 kk;
    kk.salam();
}
