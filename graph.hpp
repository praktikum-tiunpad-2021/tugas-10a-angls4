#pragma once

#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

namespace strukdat {

template <typename VertexType>
class graph {
  /**
   * @brief Tipe data dari adjacency list. (BOLEH DIUBAH)
   *
   * @note
   * Misal:
   *
   * adj_list_type adj_list =
   *
   * | map key  |             list_type
   * | - - - -  | - - - - - - - - - - - - - - - - -
   * | vertex_1 | vertex_2, vertex_5, vertex_4, ...
   * | vertex_2 | vertex_1, vertex_3
   * |   ...    |           ...
   *
   * maka,
   *
   * adj_list[vertex_2]; // { vertex_1, vertex_3 }
   */
  using list_type = std::unordered_set<VertexType>;
  using adj_list_type = std::unordered_map<VertexType, list_type>;

 public:
  /**
   * @brief Default constructor.
   *
   * @constructor
   */
  graph() {}

  /**
   * @brief Menambahkan vertex baru pada graph
   *
   * @param val nilai dari vertex yang akan ditambahkan
   */
  adj_list_type & list = _adj_list;

  void add_vertex(const VertexType &val) {
    // Contoh implementasi. (BOLEH DIUBAH)
    // inisialisasi _adj_list[val] dengan list kosong
    list.insert(std::make_pair(val, list_type()));  //boleh diganti

    // if(list[val].empty())
    // if(list.size < val) list.reserve(list.size() + 1);
  }

  void remove_vertex(const VertexType &val) {
      list.erase(val);

      for(auto &i : list){
        get<1>(i).erase(val);
      }
  }

  /**
   * @brief Menambahkan edge baru dari 2 vertex
   *
   * @param val1 nilai vertex 1
   * @param val2 nilai vertex 2
   */
  void add_edge(const VertexType &val1, const VertexType &val2) {
      list_type &list1 = list[val1], &list2 = list[val2];

      list1.insert(val2);

      list2.insert(val1);
  }

  /**
   * @brief Menghapus vertex baru pada graph
   *
   * @param val nilai dari vertex yang akan dihapus
   */
  void remove_edge(const VertexType &val1, const VertexType &val2) {
    // if(list.find(val1) == list.end()) return;
    // if(list.find(val2) == list.end()) return;

    list[val1].erase(val2);
    list[val2].erase(val1);
  }

  /**
   * @brief Mengembalikan ordo dari graph.
   *
   * @note
   * Ordo graph adalah jumlah node pada graph
   *
   * @return jumlah node pada graph
   */
  size_t order() const {
    return list.size();
  }

  /**
   * @brief Cek apakah 2 vertex bertetangga satu sama lain.
   *
   * @param val1 nilai vertex 1
   * @param val2 nilai vertex 2
   *
   * @return vertex-vertex saling bertetangga
   */
  bool is_edge(const VertexType &val1, const VertexType &val2) const {
    list_type &list1 = list[val1], &list2 = list[val2];

    if(list1.find(val2) == list1.end()) return false;  
    if(list2.find(val1) == list2.end()) return false; 
    return true;
  }

  /**
   * @brief Melakukan BFS traversal pada graph
   *
   * @param root vertex awal
   * @param func fungsi yang akan dieksekusi pada setiap vertex
   */
  void bfs(const VertexType &root,
           std::function<void(const VertexType &)> func) const {
  
    list_type visited;
    queue<VertexType> que;

    que.push(root);
    visited.insert(root);

    while(!que.empty()){
      
      for(auto x : list[que.front()]){
        if(visited.find(x) == visited.end()){
          que.push(x);
          visited.insert(x);  
        }
      }

      func(que.front());
      que.pop();
    }
  }
  void dfsI(const VertexType &root, list_type visited,
           std::function<void(const VertexType &)> func) const{

    func(root);        
    visited.insert(root);
    for(auto x : list[root]){
      if(visited.find(x) == visited.end())
      dfsI(x,visited,func);
    }
    return;
  }
  /**
   * @brief Melakukan DFS traversal pada graph
   *
   * @param root vertex awal
   * @param func fungsi yang akan dieksekusi pada setiap vertex
   */
  void dfs(const VertexType &root,
           std::function<void(const VertexType &)> func) const {
    
    list_type visited;
    dfsI(root,visited,func);
  }

 private:
  /**
   * @brief Adjacency list dari graph
   *
   * @private
   */
  adj_list_type _adj_list;
  
};

}  // namespace strukdat