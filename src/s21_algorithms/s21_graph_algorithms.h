#ifndef SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#define SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <queue>


#include "../s21_graph/s21_graph.h"

namespace s21 {
class s21_Graph;
class GraphAlgorithms {
 public:
  std::vector<int> DepthFirstSearch(
      s21_Graph graph,
      int start_vertex);  // главный метод алгоритма поиска в глубину
      
  std::vector<int> BreadthFirstSearch(s21::s21_Graph graph, int start_vertex); // главный метод алгоритма поиска в ширину

  bool CheckVisited(std::vector<int> visited_vertices, int current_vertix) noexcept;  // метод проверки посещенных точек
  void PrintResultOfDepthFirstSearch(
      std::vector<int> visited_vertices) noexcept;  // метод вывода результата
};

}  // namespace s21

#endif  // SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
