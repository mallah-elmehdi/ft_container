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
#include <list>

using namespace std;

class Graph {
  int numVertices;
  list<int>* adjLists;
  bool* visited;

   public:
  Graph(int vertices);
  void addEdge(int src, int dest);
  void BFS(int startVertex);
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_back(dest);
  adjLists[dest].push_back(src);
  for (int i = 0; i < 4; i++) {
    for (list<int>::iterator it = adjLists[i].begin(); it != adjLists[i].end(); it++) {
      cout << *it  << " ";
    }
    cout << "\n**\n";
  }
  cout << "\n------------------\n";
}

// BFS algorithm
void Graph::BFS(int startVertex) {
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    cout << "Visited " << currVertex << " ";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.BFS(2);

  return 0;
}
