#include "s21_graph.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <errno.h>

// 1) надо будет при открытии файла проверять, что там только цифры
// 2) что колличество рядов совпадает с колличестом колонок и что оно равно размеру
// 3) размер не отрицательный
// 4) если граф взвешенный то его веса должны быть не отрицательными 

std::vector<std::vector<int>> s21::s21_Graph::getAdjacencyMatrix() {
  if (AdjacencyMatrix_.size() < 1) return std::vector<std::vector<int>>();
  return AdjacencyMatrix_;
}

std::vector<std::pair<int, int>> s21::s21_Graph::getEdgesList() {
  for (int i = 0; i < size_; ++i) {
    for (int j = 0; j < size_; ++j) {
      // go thru cells and see if they don't include '0'
      if (AdjacencyMatrix_[i][j] != 0) {
        // if (they): push the position number into the edgesList
        edgesList_.push_back(std::make_pair(i, j));
      }
    }
  }
  return edgesList_;
}

int s21::s21_Graph::get_graph_size() { return size_; }

std::vector<std::vector<int>> s21::s21_Graph::getAdjacencyList() {
  std::vector<std::vector<int>> adjacencyList_(size_);
  for (int i = 0; i < size_; ++i) {
    for (int j = 0; j < size_; ++j) {
      if (AdjacencyMatrix_[i][j] != 0) {
        adjacencyList_[i].push_back(j);
      }
    }
  }
  return adjacencyList_;
}
// bool s21::s21_Graph::is_digits(const std::string &str)
// {
//     return std::all_of(str.begin(), str.end(), ::isdigit);
// }
//   bool s21::s21_Graph::isEqualToDimension(int i, int j, int dimension) {
//     return (i == j) && (j == dimension);
// }

bool s21::s21_Graph::checkFile(const std::string& filename) {
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        std::cout << "Error opening file";
        return false;
    }
    // dimention = size_ - первая цифра над матрицей в файле 
    // dimension - int и если туда придет не число то будет ошибка приведения типов так 
    // так что это блок №1 где мы проверяем что размерность у нас инт
    int dimension = 0;
    if (!(ifs >> dimension)) {
        return false;
    }
    // else if (ifs >> dimension) {
    //   if (dimension < 0)
    //     return false;
    // }
    std::vector<std::vector<int>> matrix;
    // по аналогии с dimentsion здесь также работает контроль типов что приходят только цифры
    int value;
    int row = 0;
    int col = 0;
    // value >=0 контролирует, что в случае со взвешенными графами у нас нет отрицательных чисел
    // условие далее  говорит что считываем только инты и они должны быть неотрицательными
    while (ifs >> value && value >= 0) {
      // начиная с нулевой колонки создаем пустой вектор
        if (col == 0) {
            matrix.push_back(std::vector<int>());
        }
        // пушим  неотрицательные инты в текущий ряд, увеличивая сччетчик колонок
        matrix[row].push_back(value);
        col++;
        // как только счетчик сравнялся  с размерностью size_
        // мы его обнуляем и начинаем считать ряды, таким образом заполняя матрицу с нового ряда
        // который пустым сразу создаем в соответствии с условием col == 0 выше
        if (col == dimension) {
            col = 0;
            row++;
        }
    }
// когда закончились значения в файле, мы сравниваем сколько насчитали рядов
// и если они не равны значению dimension, значит raw !=col: checkFile вернул  false 
    if (col != 0 || row != dimension) {
        return false;
    }

    ifs.close();
    return true;
}

void s21::s21_Graph::LoadGraphFromFile(std::string filename) {
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    std::cout << "Error opening file";
    return;
  }
  if(!checkFile(filename)) {std::cout << "Error opening file";}
  ifs >> size_;  // read the graph size from file
  if(size_ <= 0) { std::cout << "Dimension must be > 0"; return;}
  AdjacencyMatrix_.resize(size_,
                          std::vector<int>(size_));  // change the matrix size
  for (int i = 0; i < size_; ++i) {
    for (int j = 0; j < size_; ++j) {
      ifs >>
          AdjacencyMatrix_[i]
                          [j];  // take the values from the files to the  matrix
    }
  }
  ifs.close();
}


void s21::s21_Graph::ExportGraphToDot(std::string filename) {
  std::ofstream ofs(filename);
  if (!ofs.is_open()) {
    std::cout << "Error opening file";
    return;
  }
  
  ofs << "graph G {\n";
  for (int i = 0; i < size_; ++i) {
    for (int j = 0; j < size_; ++j) {
      if (AdjacencyMatrix_[i][j] != 0) {
        ofs << "  " << i << " -- " << j << ";\n";
      }
    }
  }
  ofs << "}\n";
  ofs.close();
}

// int main() {
//   s21::s21_Graph graph;
//   s21::GraphAlgorithms algo;

//   std::string InputFileName = "graph_2.txt";
//   graph.LoadGraphFromFile(InputFileName);
//   std::vector<std::pair<int, int>> edgesList = graph.getEdgesList();
//   std::cout << "EdgesList:\n";
//   for (int i = 0; i < edgesList.size(); ++i) {
//     std::cout << "(" << edgesList[i].first << ", " << edgesList[i].second <<
//     ")\n";
//   }
//   std::vector<std::vector<int>> adjacencyList = graph.getAdjacencyList();
//   std::cout << "AdjacencyList:\n";
//   for (int i = 0; i < adjacencyList.size(); ++i) {
//     std::cout << i << ": ";
//     for (int j = 0; j < adjacencyList[i].size(); ++j) {
//       std::cout << adjacencyList[i][j] << " ";
//     }
//     std::cout << "\n";
//   }
//    std::string outputFile = "output.dot";
//    graph.ExportGraphToDot(outputFile);

//    int start = 0;
//    std::list<int> visited_vertexes;
//     // visited_vertexes = algo.DepthFirstSearch(graph, start);

//    for(auto element : visited_vertexes) {
//     std::cout << element << " ";
//    }
//    std::cout << std::endl;
//   return 0;
// }

// int main() {
//   s21::s21_Graph graph;
//   std::string inputFile = "graph_1.txt";
//   std::string outputFile = "output.dot";
//   graph.LoadGraphFromFile(inputFile);
//   graph.ExportGraphToDot(outputFile);
//   return 0;
// }