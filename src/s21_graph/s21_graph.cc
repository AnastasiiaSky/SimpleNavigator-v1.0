/// \file
#include "s21_graph.h"

#include <errno.h>

#include <fstream>
#include <iostream>
#include <vector>
#include <errno.h>
#include <stdexcept>
/// @brief �����-������
/// @param () ��� ����������
/// @return ���������� ������� �������� �� ���������� ���� AdjacencyMatrix_
std::vector<std::vector<int>> s21::s21_Graph::getAdjacencyMatrix() {
  if (AdjacencyMatrix_.size() < 1) return std::vector<std::vector<int>>();
  return AdjacencyMatrix_;
}

/// @brief �����-������ ����� �� ������� ���������, �������  ������
/// edgesList_, ������� ������� �� ���������-���(����� ������� ���� ������ �����
/// �������� ���� �����). � ����� ���� - ������ �������� �������, �� �������
/// ������� �����, � ������ �������� - ������ ������� ������ ���� �����
/// @param () ��� ����������
/// @return  ���������� ������ �� ��� �� ���������� ���� edgesList_
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
/// @brief �����-������, ������������ ������ �����
/// @param () ��� ����������
/// @return  ���������� ������ ����� �� ���������� ���� size_
int s21::s21_Graph::get_graph_size() { return size_; }

/// @brief �����-������, ������������ ������ ��������� (������ ������-�������)
/// ��� ������ �� ������ � ������ ����� ������ ��������� ������� ���������
/// adjacencyList_ �������� size_ �������� �� �������� ������� ��������� �������
/// ��������� �������, � ��� ������� ���� (�� ���� �������)
///  adjacencyList_ ���������� ������ �������� ��������
/// ������� ����� ������� ������ ������� ������
/// @param () ��� ����������
/// @return ������ ��������� �� ���������� ����, ������� adjacencyList_

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
/// @brief ����� checkFile ��������� ����, �� �������� ������ ������� ���������
/// � ��������� �� ��, ����� 1) ���� ��������, ���� ���� ��� ���������� � ��� 2)
/// ����� ���� �� �������� �������� 3) ������� ���������� � �������������
/// ��������� ����������� 4) ���� ����� (���� ����������) - �� �������������
/// @param const std::string& filename - �������� ��� �����, � ������� "������"
/// @param int dimention
/// ���������� int dimention  ��������� � ������� ���������� ifs >> dimension
/// ������ ����� ��� �������� � ����� dimension - int � ���� ���� ������ ��
/// �����, �� ����� ������ ���������� �����,
///   �� �������� � dimentsion �������� ����� ��������� ������ �����
///   ������������ ���������� int value: � �������� (ifs >> value && value >=0)
/// ��� �������� ��� ����� ��������� ��������������� ����
/// ����� ������� �� ��������� � �2 ����
/// �3-4 ����������� ��������� ����������: ������� ����������, � �������
/// ��������� ������ value ��� �������� col row 1) ������� � ������� �������
/// ������� ������ ������. �������� �� ������� ����
///  �����  ��������������� ���� � ������� ���, ���������� �������� ������� +1;
/// 2) ��� ������ ������� ���������  � ������������ size_
/// �� ��� �������� � �������� ������� ����, ����� ������� �������� ������� �
/// ������ ���� ������� ������ ����� ������� � ������������ � �������� col == 0
/// ���� 3) ����� ����������� �������� � �����, �� ����������. ������� ���������
/// ����� � ���� ��� �� ����� �������� dimension, ������ raw !=col: checkFile
/// ������ �false
/// @return ������ ��������� �� ���������� ����, ������� adjacencyList_

// bool s21::s21_Graph::checkFile(const std::string& filename) {
//     std::ifstream ifs(filename);
//     try {
//         if (!ifs.is_open()) {
//             throw std::runtime_error("Error opening file");
//         }

//         if (ifs.peek() == std::ifstream::traits_type::eof()) {
//             throw std::runtime_error("File is empty: " + filename);
//         }

//         int dimension = 0;
//         if (!(ifs >> dimension)) {
//             throw std::runtime_error("Error reading dimension from file");
//         }
        
//         std::vector<std::vector<int>> matrix;
//         int value;
//         int row = 0;
//         int col = 0;
//         while (ifs >> value && value >= 0) {
//             if (col == 0) {
//                 matrix.push_back(std::vector<int>());
//             }
//             matrix[row].push_back(value);
//             col++;
//             if (col == dimension) {
//                 col = 0;
//                 row++;
//             }
//         }
        
//         if (col != 0 || row != dimension) {
//             throw std::runtime_error("Invalid column or row count");
//         }

//         ifs.close();
//         return true;

//     } catch (const std::exception& e) {
//         std::cout << "Exception occurred: " << e.what() << std::endl;
//         // ifs.close();
//         return false;
//     }
// }

bool s21::s21_Graph::checkFile(const std::string& filename) {
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    // std::cout << "Error opening file";
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
    // if (!IsGraphConnected()) {
    //     std::cout << "Graph is not connected";
    //      return false;
    // }
    ifs.close();
    return true;
}
/// @brief �����, ����������� �������  �� �����
/// @param const std::string& filename - �������� ��� �����, � ������� "������"
/// 3) ����� �����������  ������� ���� ������������� � ��������� ���������
/// ����������� �������� if(size_ <= 0) { std::cout << "Dimension must be > 0";
/// return;}
/// @return  no

void s21::s21_Graph::LoadGraphFromFile(std::string filename) {
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    std::cout << "Error opening file";
    return;
  }
  if (!checkFile(filename)) {
    std::cout << "Error opening file";
  }
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
    //   if (!IsGraphConnected(graph, filename)) {
    //   std::cout << "Graph is not connected"; // message: user should pick another graph
      
    //   // return false;
    // }

}


// void s21::s21_Graph::LoadGraphFromFile(std::string filename) {
//   std::ifstream ifs(filename);
//   if (!ifs.is_open()) {
//     std::cout << "Error opening file";
//     return;
//   }
//   if(!checkFile(filename)) {std::cout << "Error opening file";}
//   ifs >> size_;  // read the graph size from file
//   if(size_ <= 0) { std::cout << "Dimension must be > 0"; return;}
//   AdjacencyMatrix_.resize(size_,
//                           std::vector<int>(size_));  // change the matrix size
//   for (int i = 0; i < size_; ++i) {
//     for (int j = 0; j < size_; ++j) {
//       ifs >>  AdjacencyMatrix_[i][j];  // take the values from the files to the  matrix
//     }
//   }
//     // s21_Graph temp;
//     // for (int i = 0; i < size_; ++i) {
//     //   for (int j = 0; j < size_; ++j) {
//     //   temp.AdjacencyMatrix_[i][j] = this->AdjacencyMatrix_[i][j];  
//     //   if(temp.AdjacencyMatrix_[i][j] != temp.AdjacencyMatrix_[j][i]) {
//     //     temp.AdjacencyMatrix_[j][i] = temp.AdjacencyMatrix_[i][j];
//     //   }
//     //        std::vector<int> visited = this->FindPath(temp, 0);
//     //        for (int isVisited : visited) {
//     //           if (isVisited == 0) {
//     //         std::cout << "Graph is not connected";;  // ���� �� �������
//     //     }
//     // }


//     // }
//   // }
//   ifs.close();
// }

std::vector<int> s21::s21_Graph::FindPath(s21_Graph &graph, int start_vertex) {
  // if (start_vertex >= tmp.size() || start_vertex < 0) {
  //   throw std::out_of_range("Start vertex is out of range");
  // }
  
  std::vector<int> visited_vertices;
  std::stack<int> vertex_stack;
  std::vector<std::vector<int>> adjacency_list = graph.getAdjacencyList();

  vertex_stack.push(start_vertex);

  while (!vertex_stack.empty()) {
    int current_vertex = vertex_stack.top();
    vertex_stack.pop();

    if (std::find(visited_vertices.begin(), visited_vertices.end(), current_vertex) != visited_vertices.end()) {
      continue;
    }

    visited_vertices.push_back(current_vertex);

    std::vector<int> adjacent_vertices = adjacency_list[current_vertex - 1];
    for (int it = adjacent_vertices.size() - 1; it >= 0; --it) {
      int adjacent_vertex = adjacent_vertices[it];
      if (std::find(visited_vertices.begin(), visited_vertices.end(), adjacent_vertex) == visited_vertices.end()) {
        vertex_stack.push(adjacent_vertex);
      }
    }
  }
  return visited_vertices;
}

void s21::s21_Graph::MakeMatrixUndirected(s21::s21_Graph &graph)
{
  for(int i = 0; i < size_/2; ++i) {
    for(int j = 0; j < size_/2; ++j) {
      this->AdjacencyMatrix_[j][i] = this->AdjacencyMatrix_[i][j];
      // if(AdjacencyMatrix[i][j] != AdjacencyMatrix[j][i]) {
      //   return true;
      // }
    }
  }
}

bool s21::s21_Graph::IsDerrected(std::vector<std::vector<int>> AdjacencyMatrix)
{
  for(int i = 0; i < size_; ++i) {
  for(int j = 0; j < size_; ++j) {
    if(AdjacencyMatrix[i][j] != AdjacencyMatrix[j][i]) {
      return true;
    }
  }

  }
  return false;
}


bool s21::s21_Graph::IsGraphConnected(s21_Graph &graph, std::string filename)  {
  if(IsDerrected(graph.AdjacencyMatrix_) == false) {
    std::vector<int> visited = FindPath(graph, 3);
    if(visited.size() == size_) {
      std::cout << " graph connected ";
      return true;
    } else {std::cout << " graph NOT connected ";}
  } else {
    MakeMatrixUndirected(graph);
    std::vector<int> visited = FindPath(graph, 3);
    if(visited.size() == size_) {
      std::cout << " graph connected ";
      graph.LoadGraphFromFile(filename);
      return true;
    } else {std::cout << " graph NOT connected ";}
  }
  return false;  // 
}


// std::vector<int> s21::s21_Graph::FindPath(s21_Graph &graph,
//                                                         int start_vertex) {
//   if (start_vertex > graph.get_graph_size() || start_vertex < 0) {
//     throw std::length_error("Start vertex is incorrect");
//   }
//   std::vector<int> visited_vertices;
//   std::stack<int> vertex_stack;
//   std::vector<std::vector<int>> adjacency_list = graph.getAdjacencyList();

//   vertex_stack.push(start_vertex);

//   while (!vertex_stack.empty()) {
//     int current_vertex = vertex_stack.top();
//     vertex_stack.pop();
//      if(find(visited_vertices.begin(), visited_vertices.end(), current_vertex) !=visited_vertices.end()) {
//       continue;
//     }

//     std::vector<int> adjacent_vertices = adjacency_list[current_vertex - 1];
//     visited_vertices.push_back(current_vertex);

//     for (int it = adjacent_vertices.size() - 1; it >= 0; --it) {
//       if (!(find(visited_vertices.begin(), visited_vertices.end(), adjacent_vertices[it]) !=visited_vertices.end()))
//       {
//         vertex_stack.push(adjacent_vertices[it]);
//       }
//     }
//   }
//   return visited_vertices;
// }
 
// bool s21::s21_Graph::IsGraphConnected() const {
//   s21::s21_Graph result;
//     for(int i = //     for (int j = 0; j < size_; j++) {
//       if(result.AdjacencyMatrix_[i][j] !=result.AdjacencyMatrix_[j][i]) {
//         result.AdjacencyMatrix_[j][i] = result.AdjacencyMatrix_[i][j];
//       } 
//     }
//   }0; i < size_; i++) {

//   std::vector<int> visited(size_, 0);
//   visited = result.FindPath(result, 0);
//     // ��������� ����� � ������� �� ������ �������
//     // ���������, ���� �� ��� ������� ��������
//     for (int isVisited : visited) {
//         if (isVisited == 0) {
//             return false;  // ���� �� �������
//         }
//     }
//     return true;  // ���� �������
// }


// void s21::s21_Graph::LoadGraphFromFile(std::string filename) {
//   std::ifstream ifs(filename);
//   if (!ifs.is_open()) {
//     std::cout << "Error opening file";
//     return;
//   }
//   if(!checkFile(filename)) {std::cout << "Error opening file";}
//   ifs >> size_;  // read the graph size from file
//   if(size_ <= 0) { std::cout << "Dimension must be > 0"; return;}
//   AdjacencyMatrix_.resize(size_,
//                           std::vector<int>(size_));  // change the matrix size
//   for (int i = 0; i < size_; ++i) {
//     for (int j = 0; j < size_; ++j) {
//       ifs >>  AdjacencyMatrix_[i][j];  // take the values from the files to the  matrix
//     }
//   }
//     // s21_Graph temp;
//     // for (int i = 0; i < size_; ++i) {
//     //   for (int j = 0; j < size_; ++j) {
//     //   temp.AdjacencyMatrix_[i][j] = this->AdjacencyMatrix_[i][j];  
//     //   if(temp.AdjacencyMatrix_[i][j] != temp.AdjacencyMatrix_[j][i]) {
//     //     temp.AdjacencyMatrix_[j][i] = temp.AdjacencyMatrix_[i][j];
//     //   }
//     //        std::vector<int> visited = this->FindPath(temp, 0);
//     //        for (int isVisited : visited) {
//     //           if (isVisited == 0) {
//     //         std::cout << "Graph is not connected";;  // ���� �� �������
//     //     }
//     // }


//     // }
//   // }
//   ifs.close();
// }

// std::vector<int> s21::s21_Graph::FindPath(s21_Graph &graph, int start_vertex) {
//   // if (start_vertex >= tmp.size() || start_vertex < 0) {
//   //   throw std::out_of_range("Start vertex is out of range");
//   // }
  
//   std::vector<int> visited_vertices;
//   std::stack<int> vertex_stack;
//   std::vector<std::vector<int>> adjacency_list = graph.getAdjacencyList();

//   vertex_stack.push(start_vertex);

//   while (!vertex_stack.empty()) {
//     int current_vertex = vertex_stack.top();
//     vertex_stack.pop();

//     if (std::find(visited_vertices.begin(), visited_vertices.end(), current_vertex) != visited_vertices.end()) {
//       continue;
//     }

//     visited_vertices.push_back(current_vertex);

//     std::vector<int> adjacent_vertices = adjacency_list[current_vertex - 1];
//     for (int it = adjacent_vertices.size() - 1; it >= 0; --it) {
//       int adjacent_vertex = adjacent_vertices[it];
//       if (std::find(visited_vertices.begin(), visited_vertices.end(), adjacent_vertex) == visited_vertices.end()) {
//         vertex_stack.push(adjacent_vertex);
//       }
//     }
//   }
//   return visited_vertices;
// }

// void s21::s21_Graph::MakeMatrixUndirected(s21::s21_Graph &graph)
// {
//   for(int i = 0; i < size_/2; ++i) {
//     for(int j = 0; j < size_/2; ++j) {
//       this->AdjacencyMatrix_[j][i] = this->AdjacencyMatrix_[i][j];
//       // if(AdjacencyMatrix[i][j] != AdjacencyMatrix[j][i]) {
//       //   return true;
//       // }
//     }
//   }
// }

// bool s21::s21_Graph::IsDerrected(std::vector<std::vector<int>> AdjacencyMatrix)
// {
//   for(int i = 0; i < size_; ++i) {
//   for(int j = 0; j < size_; ++j) {
//     if(AdjacencyMatrix[i][j] != AdjacencyMatrix[j][i]) {
//       return true;
//     }
//   }

//   }
//   return false;
// }


// bool s21::s21_Graph::IsGraphConnected(s21_Graph &graph, std::string filename)  {
//   if(IsDerrected(graph.AdjacencyMatrix_) == false) {
//     std::vector<int> visited = FindPath(graph, 3);
//     if(visited.size() == size_) {
//       std::cout << " graph connected ";
//       return true;
//     } else {std::cout << " graph NOT connected ";}
//   } else {
//     MakeMatrixUndirected(graph);
//     std::vector<int> visited = FindPath(graph, 3);
//     if(visited.size() == size_) {
//       std::cout << " graph connected ";
//       graph.LoadGraphFromFile(filename);
//       return true;
//     } else {std::cout << " graph NOT connected ";}
//   }
//   return false;  // 
// }


// std::vector<int> s21::s21_Graph::FindPath(s21_Graph &graph,
//                                                         int start_vertex) {
//   if (start_vertex > graph.get_graph_size() || start_vertex < 0) {
//     throw std::length_error("Start vertex is incorrect");
//   }
//   std::vector<int> visited_vertices;
//   std::stack<int> vertex_stack;
//   std::vector<std::vector<int>> adjacency_list = graph.getAdjacencyList();

//   vertex_stack.push(start_vertex);

//   while (!vertex_stack.empty()) {
//     int current_vertex = vertex_stack.top();
//     vertex_stack.pop();
//      if(find(visited_vertices.begin(), visited_vertices.end(), current_vertex) !=visited_vertices.end()) {
//       continue;
//     }

//     std::vector<int> adjacent_vertices = adjacency_list[current_vertex - 1];
//     visited_vertices.push_back(current_vertex);

//     for (int it = adjacent_vertices.size() - 1; it >= 0; --it) {
//       if (!(find(visited_vertices.begin(), visited_vertices.end(), adjacent_vertices[it]) !=visited_vertices.end()))
//       {
//         vertex_stack.push(adjacent_vertices[it]);
//       }
//     }
//   }
//   return visited_vertices;
// }
 
// bool s21::s21_Graph::IsGraphConnected() const {
//   s21::s21_Graph result;
//     for(int i = //     for (int j = 0; j < size_; j++) {
//       if(result.AdjacencyMatrix_[i][j] !=result.AdjacencyMatrix_[j][i]) {
//         result.AdjacencyMatrix_[j][i] = result.AdjacencyMatrix_[i][j];
//       } 
//     }
//   }0; i < size_; i++) {

//   std::vector<int> visited(size_, 0);
//   visited = result.FindPath(result, 0);
//     // ��������� ����� � ������� �� ������ �������
//     // ���������, ���� �� ��� ������� ��������
//     for (int isVisited : visited) {
//         if (isVisited == 0) {
//             return false;  // ���� �� �������
//         }
//     }
//     return true;  // ���� �������
// }

/// @brief �����, ����������� ������� � ����
/// @param const std::string& filename - �������� ��� �����, � ������� "������"
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