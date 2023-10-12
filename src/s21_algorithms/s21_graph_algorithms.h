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
  // перегрузка для проверки связности
  std::vector<int> DepthFirstSearch(std::vector<std::vector<int>> graph_matrix,
                                    int start_point);

  // Главный метод алгоритма поиска в ширину
  std::vector<int> BreadthFirstSearch(s21_Graph graph, int start_vertex);

  // Метод проверки посещенных точек
  bool CheckVisited(std::vector<int> visited_vertices,
                    int current_vertix) noexcept;

  // Метод вывода результата
  void PrintResultOfDepthFirstSearch(
      std::vector<int> visited_vertices) noexcept;
  // Метод проверки связный ли граф или нет
  bool IsGraphConnected(std::vector<std::vector<int>> adjacency_list);

  // Метод поиска минимального оставного дерева
  std::vector<std::vector<int>> GetLeastSpanningTree(s21_Graph &graph);
  // Метод проверки все ли вершины посещены
  bool IsAllVisited(std::vector<bool> visited_of_not);
  // Метод преобразования направленного графа в ненаправленный
  std::vector<std::vector<int>> ConvertToUndirected(
      std::vector<std::vector<int>> graph_matrix);
  // Метод получения минимального веса ребра для построения минимально остовного
  // дерева
  std::pair<int, int> GetMinCoordinats(
      std::vector<std::vector<int>> working_matrix);
  // Метод получения веса минимального оставного дерева
  int GetSpanningTreeWeigt(std::vector<std::vector<int>> least_spanning_tree);
};

}  // namespace s21

#endif  // SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
