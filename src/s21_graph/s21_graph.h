#ifndef SRC_S21_GRAPH_H_
#define SRC_S21_GRAPH_H_
#include <cstring>
#include <iostream>
#include <vector>  /// Заменить на самописные

#include "../s21_algorithms/s21_graph_algorithms.h"

class GraphAlgorithms;

// using Matrix = std::vector<std::vector<int>>; // Возможно заменить для
// упрощения вида)

namespace s21 {
class s21_Graph {
 public:
  s21_Graph() = default;  // базовый конструктор
  s21_Graph(int size) { this->size_ = size; }  // конструктор с параметром size
  ~s21_Graph() = default;  // деструктор
  std::vector<std::vector<int>>
  getAdjacencyMatrix();  // геттер матрицы смежности
  std::vector<std::vector<int>>
  getAdjacencyList();  // геттер спискасмежности (списка вершин)
  std::vector<std::pair<int, int>>
  getEdgesList();  // геттер списка инцидентности(списка ребер)
  int get_graph_size();
  bool checkFile(const std::string& filename);  // !!! Возможно с большой буквы 
  // bool IsGraphConnected(s21_Graph &graph);
  bool IsGraphConnected(s21_Graph &graph, std::string filename);
  std::vector<int> FindPath(s21_Graph &graph, int start_vertex);
  void MakeMatrixUndirected(s21::s21_Graph &graph);
  bool IsDerrected(std::vector<std::vector<int>> AdjacencyMatrix);

  void LoadGraphFromFile(std::string filename);  // загрузка графа из файла
  void ExportGraphToDot(std::string filename);  // выгрузка графа в файл

 private:
  int size_;                                       // размер графа
  std::vector<std::vector<int>> AdjacencyMatrix_;  // матрица смежности
  std::vector<std::pair<int, int>> edgesList_;   // список ребер
  std::vector<std::vector<int>> adjacencyList_;  // список вершин
};

}  // namespace s21

#endif  // SRC_S21_GRAPH_H_