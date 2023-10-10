#ifndef SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#define SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_

#include <algorithm> // !!! возможно не надо
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <limits> // !!! возможно не надо
#include <limits.h> // !!! возможно не надо

#include "../s21_graph/s21_graph.h"


namespace s21 {
class s21_Graph;
class GraphAlgorithms {
 public:

  const int inf = std::numeric_limits<int>::max();;  // !!! Перенести в класс, наверное

  // Главный метод алгоритма поиска в глубину
  std::vector<int> DepthFirstSearch(s21_Graph graph, int start_vertex);  
      
  // Главный метод алгоритма поиска в ширину
  std::vector<int> BreadthFirstSearch( s21_Graph graph, int start_vertex); 

  // Метод проверки посещенных точек
  bool CheckVisited(std::vector<int> visited_vertices,int current_vertix) noexcept;

  // Метод поиска пути по алгоритму Флойда Уошера
  std::vector<std::vector<int>> FloydWarshall(s21_Graph graph);

  // Метод вывода результата пути 
  void PrintResultOfDepthFirstSearch(std::vector<int> visited_vertices) noexcept;  

  // Метод ввывода матрицы смежности
  void PrintAdjacencyMatrix(std::vector<std::vector<int>> adjacency_matrix) noexcept;

};

}  // namespace s21

#endif  // SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
