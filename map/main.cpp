#include "ft.hpp"

int a = 100;
int b = 1;
void ok()
{
	for (size_t i = 11; i <= 20; i++)
	{
		std::cout <<  "mymap2.insert(ft::make_pair('" << i << "', " <<  a * i <<"));" << "\n";
	}
	
}

int main()
{
    ft::map<int,int> mymap2;
    ft::map<int,int> mymap; 

	// ok();

	mymap.insert(ft::make_pair(4, 400));
	mymap.insert(ft::make_pair(6, 600));
	mymap.insert(ft::make_pair(9, 900));
	mymap.insert(ft::make_pair(1, 100));
	mymap.insert(ft::make_pair(14, 1400));
	mymap.insert(ft::make_pair(8, 800));
	mymap.insert(ft::make_pair(3, 300));
	mymap.insert(ft::make_pair(7, 700));
	mymap.insert(ft::make_pair(10, 1000));
	mymap.insert(ft::make_pair(19, 1900));
	mymap.insert(ft::make_pair(13, 1300));
	mymap.insert(ft::make_pair(12, 1200));
	mymap.insert(ft::make_pair(20, 2000));
	mymap.insert(ft::make_pair(17, 1700));
	mymap.insert(ft::make_pair(2, 200));
	mymap.insert(ft::make_pair(15, 1500));
	mymap.insert(ft::make_pair(16, 1600));
	mymap.insert(ft::make_pair(18, 1800));
	mymap.insert(ft::make_pair(11, 1100));
	mymap.insert(ft::make_pair(5, 500));

	// mymap2.insert(mymap.begin(), mymap.end());
	mymap2 = mymap;
    
	for (ft::map<int,int>::iterator it = mymap2.begin(); it != mymap2.end(); it++)
        std::cout << it->first << " => " << it->second << '\n';
}
