#ifndef SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#define SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_

#include <algorithm> // !!! возможно не надо
#include <iostream>
#include <list> /// Заменить на самописные
#include <queue> /// Заменить на самописные
#include <stack> /// Заменить на самописные
#include <vector> /// Заменить на самописные
#include <cmath>
#include <random> 
// #include <limits> // !!! возможно не надо
// #include <limits.h> // !!! возможно не надо

#include "../s21_graph/s21_graph.h"

namespace s21 {

  struct TsmResult {
    std::vector<int> path;
    int random;
    std::vector<double> tmp;
    int vertices;   // !!! надо со * // массив с искомым маршрутом (с порядком обхода вершин). Вместо int* можно использовать std::vector<int>
    double distance;  // длина этого маршрута
    double distance2;  // длина этого маршрута

  };

class s21_Graph;
class GraphAlgorithms {
 public:

  const int inf = std::numeric_limits<int>::max();  // !!! Перенести в класс, наверное



  // Главный метод алгоритма поиска в глубину
  std::vector<int> DepthFirstSearch(s21_Graph &graph, int start_vertex);
  // перегрузка для проверки связности
  std::vector<int> DepthFirstSearch(std::vector<std::vector<int>> graph_matrix,
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
  std::vector<std::vector<int>> GetShortestPathsBetweenAllVertices(s21_Graph &graph);


  TsmResult SolveTravelingSalesmanProblem(s21_Graph &graph);

  // Метод вывода результата пути 
  // !!! Переименовать метод
  void PrintResultOfDepthFirstSearch(std::vector<int> visited_vertices) noexcept; // он должен в выводи быть без стрелочек
  // Метод вывода результата пути 
  // !!! Переименовать метод
  void PrintResultOfDepthFirstSearch(std::vector<double> visited_vertices) noexcept;


  // Алгоритм Прима
  std::vector<std::vector<int>> GetLeastSpanningTree(s21_Graph & graph);
  // Все ли точки посещены
  bool IsAllVisited(std::vector<bool> visited_of_not);
  // Преобразование направленной матрицы в ненаправленную
  std::vector<std::vector<int>> ConvertToUndirected(const std::vector<std::vector<int>> graph_matrix);
  // Получение минимальных координат
  std::pair<int,int> GetMinCoordinats(std::vector<std::vector<int>> working_matrix);  
  // Получение веса остовного дерева
  int GetSpanningTreeWeigt(std::vector<std::vector<int>> least_spanning_tree);

  // Метод ввывода матрицы смежности int
  void PrintAdjacencyMatrix(std::vector<std::vector<int>> matrix) noexcept;

  // Метод ввывода матрицы смежности double
  void PrintAdjacencyMatrix(std::vector<std::vector<double>> matrix) noexcept;

  // private:
    // Рассчитывает вероятность прохождения по текущему ребру
    int CreateProbabilityPath(std::vector<double> &pobability_list,
    std::vector<std::vector<double>> pheramone_matrix, std::vector<std::vector<int>> matrix_adjacency, int vertex);

    // Пересчитывает количество ферамонта на текущему ребре
    void RecalculatePheramoneMatrix (std::vector<std::vector<double>> &pheramone_matrix, std::vector<std::vector<int>> temp_path, int distance);

    // Генерируем рандомное число в заданном диапозоне
    int VertexRandom(int min, int max) const;

    // Выбираем рандомно вершину, в которую идем 
    int SelectNextVertex (std::vector<double> probability_list, int ver);

    

};

}  // namespace s21

#endif  // SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
