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
//
// }

// BFS algorithm in C++

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Bobnet {
    private:
        int nodes;
        int links;
        int gatways;
        vector<int> *graph;
        vector<int> gates;
    public:
        Bobnet()
        {
            cin >> nodes >> links >> gatways; cin.ignore();
            graph = new vector<int>[nodes];
            for (int i = 0; i < links; i++) {
                int n1, n2;
                cin >> n1 >> n2; cin.ignore();
                if (find(graph[n1].begin(), graph[n1].end(), n2) == graph[n1].end())
                    graph[n1].push_back(n2);
                if (find(graph[n2].begin(), graph[n2].end(), n1) == graph[n2].end())
                    graph[n2].push_back(n1);
            }
            for (size_t i = 0; i < nodes; i++) {
              for (std::vector<int>::iterator it = graph[i].begin(); it != graph[i].end(); it++) {
                cout << *it;
              }
            }
            for (int i = 0; i < gatways; i++) {
                int ei;
                cin >> ei; cin.ignore();
                gates.push_back(ei);
              }
        }
        void sever_link(int start_node)
        {
            vector<bool> visted(nodes, false);
            vector<int> q;

            q.push_back(start_node);
            while (!q.empty())
            {
                visted[q.front()] = true;
                for (
                    vector<int>::iterator it = graph[q.front()].begin();
                    it != graph[q.front()].end();
                    it++
                )
                {
                    if (find(gates.begin(), gates.end(), *it) != gates.end())
                        cout << q.front() << " " << *it << endl;
                    q.push_back(*it);
                }
                q.erase(q.begin());
            }
        }
};

int main()
{
    Bobnet bob;
    while (1) {
        int si;
        cin >> si; cin.ignore();
        bob.sever_link(si);
    }
}
