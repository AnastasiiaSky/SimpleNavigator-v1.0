#ifndef SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#define SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_

#include <math.h>

#include <algorithm>  // !!! возможно не надо
#include <iostream>
#include <list>   /// Заменить на самописные
#include <queue>  /// Заменить на самописные
#include <random>
#include <stack>   /// Заменить на самописные
#include <vector>  /// Заменить на самописные
// #include <limits> // !!! возможно не надо
// #include <limits.h> // !!! возможно не надо

#include "../s21_graph/s21_graph.h"
#include "../conteiners/s21_helpsrc.h"
#include "../conteiners/s21_list.h"
#include "../conteiners/s21_stack.h"
#include "../conteiners/s21_queue.h"



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

  // Главный метод алгоритма поиска в глубину
  std::vector<int> DepthFirstSearch(s21_Graph &graph, int start_vertex);
  // перегрузка для проверки связности
  std::vector<int> DepthFirstSearch(matrix graph_matrix,
                                    int start_point);

  // Главный метод алгоритма поиска в ширину
  std::vector<int> BreadthFirstSearch(s21_Graph &graph, int start_vertex);

  // Метод проверки посещенных точек
  bool CheckVisited(std::vector<int> visited_vertices,
                    int current_vertix) noexcept;

  // Дейкстра
  int GetShortestPathBetweenVertices(s21_Graph &graph, int vertex1,
                                     int vertex2);

  // Метод поиска пути по алгоритму Флойда Уошера
  std::vector<std::vector<int>> GetShortestPathsBetweenAllVertices(
      s21_Graph &graph);

  TsmResult SolveTravelingSalesmanProblem(s21_Graph &graph);

  // Метод вывода результата пути
  void PrintResultOfDepthFirstSearch(
      std::vector<int> visited_vertices) noexcept;
  // Алгоритм Прима
  std::vector<std::vector<int>> GetLeastSpanningTree(s21_Graph &graph);
  // Все ли точки посещены
  bool IsAllVisited(std::vector<bool> visited_of_not);
  // Преобразование направленной матрицы в ненаправленную
  std::vector<std::vector<int>> ConvertToUndirected(
      const matrix graph_matrix);
  // Получение минимальных координат
  std::pair<int, int> GetMinCoordinats(
      matrix working_matrix);
  // Получение веса остовного дерева
  int GetSpanningTreeWeigt(matrix least_spanning_tree);

  // Метод ввывода матрицы смежности
  void PrintAdjacencyMatrix(
      matrix adjacency_matrix) noexcept;

  // private:
  // Рассчитывает вероятность прохождения по текущему ребру
  void CreateProbabilityMatrix(
      std::vector<std::vector<double>> &pobability_list,
      std::vector<std::vector<double>> pheramone_matrix,
      matrix matrix_adjacency);

  // Пересчитывает количество ферамонта на текущему ребре
  void RecalculatePheramoneMatrix(
      std::vector<std::vector<double>> &pheramone_matrix, int distance);

  // Генерируем рандомное число в заданном диапозоне
  int Vertex_random(int min, int max) const;

  // Выбираем рандомно вершину, в которую идем
  int SelectNextVertex(std::list<double> probability_list);
};

}  // namespace s21

#endif  // SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
