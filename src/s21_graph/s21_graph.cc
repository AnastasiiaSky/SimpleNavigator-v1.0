#include "s21_graph.h"

#include <fstream>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> s21::s21_Graph::getAdjacencyMatrix() {
  if (AdjacencyMatrix_.size() < 1) return std::vector<std::vector<int>>();
  return AdjacencyMatrix_;
}
/// \file

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
        adjacencyList_[i].push_back(j + 1);
      }
    }
    // std::cout << "Size_A " << adjacencyList_[i].size() << std::endl;
  }
  return adjacencyList_;
}

void s21::s21_Graph::LoadGraphFromFile(std::string filename) {
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    std::cout << "Error opening file";
    return;
  }
  ifs >> size_;  // read the graph size from file
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