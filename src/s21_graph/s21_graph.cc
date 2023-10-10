/// \file
#include "s21_graph.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <errno.h>
/// @brief Метод-геттер
/// @param () Без параметров
/// @return Возвращает матрицу векторов из приватного поля AdjacencyMatrix_
std::vector<std::vector<int>> s21::s21_Graph::getAdjacencyMatrix() {
  if (AdjacencyMatrix_.size() < 1) return std::vector<std::vector<int>>();
  return AdjacencyMatrix_;
}

/// @brief Метод-геттер бежит по матрице смежности, создает  вектор
/// edgesList_, который состоит из сущностей-пар(иными словами двух вершин между которыми есть ребро). 
/// В такой паре - первое значение вершина, из которой выходит ребро, а второе значение - вторая вершина докуда идет ребро
/// @param () Без параметров
/// @return  Возвращает вектор из пар из приватного поля edgesList_
std::vector<std::pair<int, int>> s21::s21_Graph::getEdgesList() {
  for (int i = 0; i < size_; ++i) {
    for (int j = 0; j < size_; ++j) {
      // go thru cells and see if they don't include '0'
      if (AdjacencyMatrix_[i][j] != 0) {
        // if (they): push the position number into the edgesList
        edgesList_.push_back(std::make_pair(i + 1, j + 1));
      }
    }
  }
  return edgesList_;
}
/// @brief Метод-геттер, возвращающий размер графа
/// @param () Без параметров
/// @return  Возвращает размер графа из приватного поля size_
int s21::s21_Graph::get_graph_size() { return size_; }

/// @brief Метод-геттер, возвращающий список смежности (список вершин-соседей) для каждой из вершин 
/// в рамках этого метода создается матрица смежности  adjacencyList_ размером size_ 
/// пробегая по исходной матрице смежности находим ненулевые позиции, и для каждого ряда (то есть вершины) 
///  adjacencyList_ записываем номера непустых столбцов
/// получая такми образом список смежных вершин
/// @param () Без параметров
/// @return список смежности из приватного поля, матрицы adjacencyList_

std::vector<std::vector<int>> s21::s21_Graph::getAdjacencyList() {
  // std::cout << "Start " << std::endl;
  std::vector<std::vector<int>> adjacencyList_(size_);
  for (int i = 0; i < size_; ++i) {
    // std::cout << "Size_1 " << adjacencyList_[i].size() << std::endl;
    for (int j = 0; j < size_; ++j) {
      // std::cout << "Size_2 " << adjacencyList_[i].size() << std::endl;
      if (AdjacencyMatrix_[i][j] != 0) {
        adjacencyList_[i].push_back(j + 1);
      }
    }
    // std::cout << "Size_A " << adjacencyList_[i].size() << std::endl;
  }
  return adjacencyList_;
}

// void s21::s21_Graph::LoadGraphFromFile(std::string filename) {
//   std::ifstream ifs(filename);
//   if (!ifs.is_open()) {
//     std::cout << "Error opening file";
//     return;
//   }
//   ifs >> size_;  // read the graph size from file
//   // change the matrix size
//   AdjacencyMatrix_.resize(size_, std::vector<int>(size_));  
//   for (int i = 0; i < size_; ++i) {
//     for (int j = 0; j < size_; ++j) {
//       ifs >>
//       // take the values from the files to the  matrix
//           AdjacencyMatrix_[i][j];  
//     }
//   }
//   ifs.close();
// }
/// @brief метод checkFile открывает файл, из которого грузим матрицу смежности и проверяет на то, чтобы
/// 1) файл открылся, чтоб путь был правильный и имя 2) чтобы файл не содержал символов 
/// 3) матрица квадратная и соответствует указанной размерности 4) веса графа (если взвешенный) - не отрицательные
/// @param const std::string& filename - входящее имя файла, в формате "строка"
/// @param int dimention
/// переменная int dimention  принимает с помощью инструкции ifs >> dimension первую цифру над матрицей в файле 
/// dimension - int и если туда придет не число, то будет ошибка приведения типов,
///   по аналогии с dimentsion контроль типов остальных данных файла осуществляет переменная int value: в усвловии (ifs >> value && value >=0)
/// оно означает что будут приходить неотрицательные инты
/// Таким образом мы проверили п №2 выше
/// п3-4 проверяются следующим алгоритмом: заводим переменную, в которую принимаем данные value два счетчика col row
/// 1) начиная с нулевой колонки создаем пустой вектор. Находясь на текущем ряду
///  пушим  неотрицательные инты в текущий ряд, увеличивая сччетчик колонок +1; 
/// 2) как только счетчик сравнялся  с размерностью size_
/// мы его обнуляем и начинаем считать ряды, таким образом заполняя матрицу с нового ряда
/// который пустым сразу создаем в соответствии с условием col == 0 выше
/// 3) когда закончились значения в файле, мы сравниваем. сколько насчитали рядов
/// и если они не равны значению dimension, значит raw !=col: checkFile вернул  false 
/// @return список смежности из приватного поля, матрицы adjacencyList_

bool s21::s21_Graph::checkFile(const std::string& filename) {
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        std::cout << "Error opening file";
        return false;
    }

    int dimension = 0;
    if (!(ifs >> dimension)) {
        return false;
    }
    // else if (ifs >> dimension) {
    //   if (dimension < 0)
    //     return false;
    // }
    std::vector<std::vector<int>> matrix;
    int value;
    int row = 0;
    int col = 0;
    while (ifs >> value && value >= 0) {
    
        if (col == 0) {
            matrix.push_back(std::vector<int>());
        }
        matrix[row].push_back(value);
        col++;
        if (col == dimension) {
            col = 0;
            row++;
        }
    }
    if (col != 0 || row != dimension) {
        return false;
    }

    ifs.close();
    return true;
}
/// @brief Метод, выгружающий матрицу  из файла 
/// @param const std::string& filename - входящее имя файла, в формате "строка"
/// 3) чтобы размерность  матрицы была положительным и ненулевым значением выполняется проверка
/// if(size_ <= 0) { std::cout << "Dimension must be > 0"; return;}
/// @return  no
void s21::s21_Graph::LoadGraphFromFile(std::string filename) {
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    std::cout << "Error opening file";
    return;
  }
  if(!checkFile(filename)) {std::cout << "Error opening file";}
  ifs >> size_;  // read the graph size from file
  //3) чтобы размерность  матрицы была положительным и ненулевым значением
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

/// @brief Метод, загружающий матрицу в файл
/// @param const std::string& filename - входящее имя файла, в формате "строка"
/// @return  no
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