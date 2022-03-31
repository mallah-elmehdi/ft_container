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
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Deck {
    private:
        queue<string> *players = new queue<string>[2];
        queue<string> holder;
        vector<string> deck = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
        int tours = 0;
    public:
        Deck() {
            for (int i = 0; i < 2; i++)
            {
                int n;
                cin >> n; cin.ignore();
                cout << "n = " << n << endl;
                for (int j = 0; j < n; j++) {
                    string card;
                    cin >> card; cin.ignore();
                    players[i].push(card);
                }
            }
        }
        void chuffle(int player, int chfl_nmr)
        {
            for (int i = 0; i < chfl_nmr; i++)
            {
                holder.push(players[0].front());
                players[0].pop();
            }
            for (int i = 0; i < chfl_nmr; i++)
            {
                holder.push(players[1].front());
                players[1].pop();
            }
            if (player != -1) {
                while (holder.size())
                {
                    players[player].push(holder.front());
                    holder.pop();
                }
            }
        }
        void play(void)
        {
            while (players[0].size() || players[1].size())
            {
                tours++;
                string p1_deck = players[0].front();
                string p2_deck = players[1].front();
                p1_deck = p1_deck.substr(0, p1_deck.size() - 1);
                p2_deck = p2_deck.substr(0, p2_deck.size() - 1);
                cout << "p1_deck = " << p1_deck << endl;
                cout << "p2_deck = " << p2_deck << endl;
                if (find(deck.begin(), deck.end(), p1_deck) > find(deck.begin(), deck.end(), p2_deck)) {
                    chuffle(0, 1);
                }
                else if (find(deck.begin(), deck.end(), p1_deck) < find(deck.begin(), deck.end(), p2_deck)) {
                    chuffle(1, 1);
                }
                else {
                    chuffle(-1, 3);
                }
            }
        }
        void result()
        {
            if (players[0].size() == 0)
                cout << "2";
            else
                cout << "1";
            cout << " " << tours << endl;
        }
};



int main()
{
    Deck mydeck;
    mydeck.play();
    mydeck.result();
}
