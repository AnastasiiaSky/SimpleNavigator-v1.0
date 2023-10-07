#ifndef SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#define SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../s21_graph/s21_graph.h"

const int INF = std::numeric_limits<int>::max();

namespace s21 {
class s21_Graph;
class GraphAlgorithms {
 public:
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

  // Дейкстра
  int GetShortestPathBetweenVertices(s21_Graph &graph, int vertex1,
                                     int vertex2);
};

}  // namespace s21

#endif  // SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_