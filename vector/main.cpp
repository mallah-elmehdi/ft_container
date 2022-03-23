#include <iostream>
#include <vector>
// #include "vector.hpp"
// #include "iterator.hpp"

template <class T>
class ok {
	private:
		T* i;
	public:
		ok() : i() {
			std::cout << i << "\n";
		}
};

int main()
{
	std::vector<int>::iterator it;
	//
	std::cout << it.base() << "\n";
	// ok<int> a;
}
