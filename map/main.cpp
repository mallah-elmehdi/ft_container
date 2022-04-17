#include "ft.hpp"
#include <map>

int a = 100;
int b = 1;
void ok()
{
	for (size_t i = 11; i <= 2000; i++)
	{
		std::cout <<  "mymap.insert(ft::make_pair(" << i << ", " <<  a * i <<"));" << "\n";
	}
	
}

int main()
{
    // ft::map<int,int> mymap2;
    ft::map<int,int> mymap; 

	// ok();
mymap.insert(ft::make_pair(14, 1400));

mymap.insert(ft::make_pair(11, 1100));
mymap.insert(ft::make_pair(12, 1200));
mymap.insert(ft::make_pair(13, 1300));
mymap.insert(ft::make_pair(15, 1500));
mymap.insert(ft::make_pair(16, 1600));
mymap.insert(ft::make_pair(17, 1700));
mymap.insert(ft::make_pair(18, 1800));
mymap.insert(ft::make_pair(29, 2900));
mymap.insert(ft::make_pair(19, 1900));

mymap.insert(ft::make_pair(24, 2400));
mymap.insert(ft::make_pair(445, 44500));
mymap.insert(ft::make_pair(26, 2600));
mymap.insert(ft::make_pair(27, 2700));
mymap.insert(ft::make_pair(28, 2800));
mymap.insert(ft::make_pair(441, 44100));
mymap.insert(ft::make_pair(30, 3000));
mymap.insert(ft::make_pair(31, 3100));

mymap.insert(ft::make_pair(436, 43600));
mymap.insert(ft::make_pair(437, 43700));
mymap.insert(ft::make_pair(438, 43800));
mymap.insert(ft::make_pair(439, 43900));
mymap.insert(ft::make_pair(440, 44000));
mymap.insert(ft::make_pair(1415, 141500));
mymap.insert(ft::make_pair(442, 44200));
mymap.insert(ft::make_pair(25, 2500));
mymap.insert(ft::make_pair(443, 44300));
mymap.insert(ft::make_pair(446, 44600));
mymap.insert(ft::make_pair(447, 44700));
mymap.insert(ft::make_pair(448, 44800));
mymap.insert(ft::make_pair(449, 44900));

mymap.insert(ft::make_pair(1110, 111000));
mymap.insert(ft::make_pair(1111, 111100));
mymap.insert(ft::make_pair(1112, 111200));
mymap.insert(ft::make_pair(1113, 111300));
mymap.insert(ft::make_pair(1114, 111400));

mymap.insert(ft::make_pair(1411, 141100));
mymap.insert(ft::make_pair(444, 44400));
mymap.insert(ft::make_pair(1413, 141300));
mymap.insert(ft::make_pair(1412, 141200));
mymap.insert(ft::make_pair(1414, 141400));
mymap.insert(ft::make_pair(1416, 141600));
mymap.insert(ft::make_pair(1417, 141700));
mymap.insert(ft::make_pair(1418, 141800));
mymap.insert(ft::make_pair(1419, 141900));
mymap.insert(ft::make_pair(1420, 142000));
mymap.insert(ft::make_pair(1421, 142100));

mymap.insert(ft::make_pair(1871, 187100));
mymap.insert(ft::make_pair(1872, 187200));
mymap.insert(ft::make_pair(1873, 187300));
mymap.insert(ft::make_pair(1874, 187400));
mymap.insert(ft::make_pair(1875, 187500));
mymap.insert(ft::make_pair(1876, 187600));
mymap.insert(ft::make_pair(1877, 187700));
mymap.insert(ft::make_pair(1878, 187800));

mymap.insert(ft::make_pair(1996, 199600));
mymap.insert(ft::make_pair(1997, 199700));
mymap.insert(ft::make_pair(1998, 199800));
mymap.insert(ft::make_pair(1999, 199900));
mymap.insert(ft::make_pair(2000, 200000));

	
	// mymap2.insert(mymap.begin(), mymap.end());
	// mymap2 = mymap;
	// ft::map<int,int>::iterator it = mymap.begin();
	// it--;
	// std::cout << it->first << " => " << it->second << \n;
	

	for (ft::map<int,int>::iterator it = mymap.begin(); it != mymap.end(); it++)
        std::cout << it->first << " => " << it->second << "\n";
}
