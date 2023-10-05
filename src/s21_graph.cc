#include <vector>
#include <iostream>
#include <fstream>
#include "s21_graph.h"
 
std::vector<std::vector<int>> s21::s21_Graph::getAdjacencyMatrix()
{
    if (AdjacencyMatrix_.size() < 1) return std::vector<std::vector<int>>();
    return AdjacencyMatrix_;
}
std::vector<std::pair<int, int>> s21::s21_Graph::getEdgesList() {
  for (int i = 0; i < size_; ++i) {
    for (int j = 0; j < size_; ++j) {
      //go thru cells and see if they don't include '0'
      if (AdjacencyMatrix_[i][j] != 0) {
        // if (they): push the position number into the edgesList
        edgesList_.push_back(std::make_pair(i, j));
      }
    }
  }
  return edgesList_;
}

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

void s21::s21_Graph::LoadGraphFromFile(std::string filename) {
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    std::cout << "Error opening file";
    return;
  } 
  ifs >> size_; // read the graph size from file
  AdjacencyMatrix_.resize(size_, std::vector<int>(size_)); // change the matrix size
  for (int i = 0; i < size_; ++i) {
    for (int j = 0; j < size_; ++j) {
      ifs >> AdjacencyMatrix_[i][j]; // take the values from the files to the  matrix
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

bool s21::s21_Graph::isAdjacent(int vertex1, int vertex2) {
    return AdjacencyMatrix_[vertex1][vertex2] == 1;
}

