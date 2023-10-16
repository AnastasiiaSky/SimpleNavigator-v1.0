#ifndef SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#define SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_

#include <math.h>


#include <iostream>
#include <queue>
#include <random>
#include <stack>
#include <vector>

#include "../conteiners/s21_helpsrc.h"
#include "../conteiners/s21_list.h"
#include "../conteiners/s21_queue.h"
#include "../conteiners/s21_stack.h"
#include "../s21_graph/s21_graph.h"

namespace s21 {

struct TsmResult {
  int *vertices;  // массив с искомым маршрутом (с порядком обхода вершин).
                  // Вместо int* можно использовать std::vector<int>
  double distance;  // длина этого маршрута
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
  TsmResult SolveTravelingSalesmanProblem(s21_Graph &graph);
  void PrintResultWay(std::vector<int> visited_vertices) noexcept;
  std::vector<std::vector<int>> GetLeastSpanningTree(s21_Graph &graph);
  int GetGraphWeigt(matrix adjacency_matrix);
  void PrintAdjacencyMatrix(matrix adjacency_matrix) noexcept;

  private:
  void CreateProbabilityMatrix(
      std::vector<std::vector<double>> &pobability_list,
      std::vector<std::vector<double>> pheramone_matrix,
      matrix matrix_adjacency);
  void RecalculatePheramoneMatrix(
      std::vector<std::vector<double>> &pheramone_matrix, int distance);
  int Vertex_random(int min, int max) const;
  int SelectNextVertex(std::list<double> probability_list);
  bool CheckVisited(std::vector<int> visited_vertices,
                    int current_vertix) noexcept;
  bool IsAllVisited(std::vector<bool> visited_of_not);
  std::vector<std::vector<int>> ConvertToUndirected(const matrix graph_matrix);
  std::pair<int, int> GetMinCoordinats(matrix working_matrix);
};

}  // namespace s21

#endif  // SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
