#ifndef SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#define SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_

#include <math.h>

#include <cmath>
#include <iostream>
#include <list>   /// Заменить на самописные
#include <queue>  /// Заменить на самописные
#include <random>
#include <stack>   /// Заменить на самописные
#include <vector>  /// Заменить на самописные
// #include <limits> // !!! возможно не надо
// #include <limits.h> // !!! возможно не надо

#include "../conteiners/s21_helpsrc.h"
#include "../conteiners/s21_list.h"
#include "../conteiners/s21_queue.h"
#include "../conteiners/s21_stack.h"
#include "../s21_graph/s21_graph.h"

namespace s21 {

struct TsmResult {
  std::vector<int> path;
  int vertices;  // !!! надо со * // массив с искомым маршрутом (с порядком
                 // обхода вершин). Вместо int* можно использовать
                 // std::vector<int>
  double distance;   // длина этого маршрута
  double distance2;  // длина этого маршрута
};

class s21_Graph;
class GraphAlgorithms {
 public:
  using matrix = std::vector<std::vector<int>>;
  const int inf =
      std::numeric_limits<int>::max();  // !!! Перенести в класс, наверное

  std::vector<int> DepthFirstSearch(s21_Graph &graph, int start_vertex);
  std::vector<int> BreadthFirstSearch(s21_Graph &graph, int start_vertex);
  int GetShortestPathBetweenVertices(s21_Graph &graph, int vertex1,
                                     int vertex2);
  std::vector<std::vector<int>> GetShortestPathsBetweenAllVertices(
      s21_Graph &graph);
  std::vector<std::vector<int>> GetLeastSpanningTree(s21_Graph &graph);
  TsmResult SolveTravelingSalesmanProblem(s21_Graph &graph);
  void PrintResultWay(std::vector<int> visited_vertices) noexcept;
  int GetGraphWeigt(matrix adjacency_matrix);
  void PrintAdjacencyMatrix(matrix adjacency_matrix) noexcept;

  // private:
  // Рассчитывает вероятность прохождения по текущему ребру
  int CreateProbabilityPath(std::vector<double> &pobability_list,
                            std::vector<std::vector<double>> pheramone_matrix,
                            std::vector<std::vector<int>> adjacency_matrix,
                            int vertex);

  // Пересчитывает количество ферамонта на текущему ребре
  void RecalculatePheramoneMatrix(
      std::vector<std::vector<double>> &pheramone_matrix,
      std::vector<std::vector<int>> temp_path, int distance);

  // Генерируем рандомное число в заданном диапозоне
  double VertexRandom(double min, double max) const;

  // Выбираем рандомно вершину, в которую идем
  int SelectNextVertex(std::vector<double> probability_list);

 private:
  bool CheckVisited(std::vector<int> visited_vertices,
                    int current_vertix) noexcept;
  bool IsAllVisited(std::vector<bool> visited_of_not);
  std::vector<std::vector<int>> ConvertToUndirected(const matrix graph_matrix);
  std::pair<int, int> GetMinCoordinats(matrix working_matrix);
};

}  // namespace s21

#endif  // SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
