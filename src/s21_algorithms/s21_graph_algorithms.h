#ifndef SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#define SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../s21_graph/s21_graph.h"

namespace s21 {
class s21_Graph;
class GraphAlgorithms {
 public:
  const int inf = 2147483647;
  // Главный метод алгоритма поиска в глубину
  std::vector<int> DepthFirstSearch(s21_Graph graph, int start_vertex);

  // Главный метод алгоритма поиска в ширину
  std::vector<int> BreadthFirstSearch(s21_Graph graph, int start_vertex);

  // Метод проверки посещенных точек
  bool CheckVisited(std::vector<int> visited_vertices,
                    int current_vertix) noexcept;

  // Метод вывода результата
  void PrintResultOfDepthFirstSearch(
      std::vector<int> visited_vertices) noexcept;

  std::vector<std::vector<int>> GetLeastSpanningTree(s21_Graph &graph);
  bool IsAllVisited(std::vector<bool> visited_of_not);
  std::pair<int, int> GetMinCoordinats(
      std::vector<std::vector<int>> working_matrix);
};

}  // namespace s21

#endif  // SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
