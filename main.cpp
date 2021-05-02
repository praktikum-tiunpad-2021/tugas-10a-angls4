/*
 * Bebas disini bisa masukin apa aja.
 * Misal mau testing atau debugging sendiri.
 *
 * Disini ada contoh code, boleh dihapus.
 */

#include <iostream>

#include "graph.hpp"

using namespace std;

void REQUIRE(bool a){
  if(a) cout<<"true"<<endl;
  if(!a) cout<<"false"<<endl;
}

int main() {
 
  strukdat::graph<int> g;

  g.add_vertex('a');
  g.add_vertex('b');
  g.add_vertex('c');
  g.add_vertex('d');
  g.add_vertex('e');

  g.add_edge('a', 'b');
  g.add_edge('a', 'c');
  g.add_edge('b', 'd');
  g.add_edge('c', 'e');

  std::vector<char> ans;
  const std::vector<char> sol1 = {'a', 'b', 'd', 'c', 'e'};
  const std::vector<char> sol2 = {'a', 'c', 'e', 'b', 'd'};

  g.dfs('a', [&ans](char a) { ans.push_back(a); });
  REQUIRE((std::equal(ans.begin(), ans.end(), sol1.begin(), sol1.end()) ||
           std::equal(ans.begin(), ans.end(), sol2.begin(), sol2.end())));

  // strukdat::graph<char> g;
  // // cout<<"true"<<endl;
  // g.add_vertex('a');
  // g.add_vertex('b');
  // g.add_vertex('c');
  // g.add_vertex('d');
  // g.add_vertex('e');
  // // cout<<"true"<<endl;
  // g.add_edge('a', 'b');
  // g.add_edge('a', 'c');
  // g.add_edge('b', 'd');
  // g.add_edge('c', 'e');
  // // cout<<"true"<<endl;
  // pri(g.is_edge('a','b'));
  // // cout<<"true"<<endl;
  // // g.bfs('a', [](char a) { std::cout << a << ' '; });

  return 0;
}
