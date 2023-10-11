#ifndef SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#define SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_

#include <algorithm>  // !!! возможно не надо
#include <iostream>
#include <list>    /// Заменить на самописные
#include <queue>   /// Заменить на самописные
#include <stack>   /// Заменить на самописные
#include <vector>  /// Заменить на самописные
// #include <limits> // !!! возможно не надо
// #include <limits.h> // !!! возможно не надо
#include <stdexcept>

#include "../s21_graph/s21_graph.h"

const int INF = std::numeric_limits<int>::max();

namespace s21 {

struct TsmResult {
  int* vertices;  // массив с искомым маршрутом (с порядком обхода вершин).
                  // Вместо int* можно использовать std::vector<int>
  double distance;  // длина этого маршрута
};

class s21_Graph;
class GraphAlgorithms {
 public:
  const int inf = std::numeric_limits<int>::max();
  ;  // !!! Перенести в класс, наверное

  // Главный метод алгоритма поиска в глубину
  std::vector<int> DepthFirstSearch(s21_Graph graph, int start_vertex);

  // Главный метод алгоритма поиска в ширину
  std::vector<int> BreadthFirstSearch(s21_Graph graph, int start_vertex);
  std::vector<int> BreadthFirstSearch(s21_Graph& graph, int start_vertex);

  // Метод проверки посещенных точек
  bool CheckVisited(std::vector<int> visited_vertices,
                    int current_vertix) noexcept;

  // Метод вывода результата
  void PrintResultOfDepthFirstSearch(
      std::vector<int> visited_vertices) noexcept;
};

}  // namespace s21

#endif  // SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
