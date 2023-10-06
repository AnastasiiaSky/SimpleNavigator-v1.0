#include <vector>
#include <iostream>
#include <fstream>
#include "s21_graph.h"
 
std::vector<std::vector<int>> s21::s21_Graph::getAdjacencyMatrix()
{
    if (AdjacencyMatrix.size() < 1) return std::vector<std::vector<int>>();
    return AdjacencyMatrix;
}

void s21::s21_Graph::LoadGraphFromFile(std::string filename) {
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    std::cout << "Error opening file";
    return; // может ф-я, должна возвращать)).
  }

  ifs >> size; // read the graph size from file
  AdjacencyMatrix.resize(size, std::vector<int>(size)); // change the matrix size
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      ifs >> AdjacencyMatrix[i][j]; // take the values from the files to the  matrix
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
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      if (AdjacencyMatrix[i][j] != 0) {
        ofs << "  " << i << " -> " << j << ";\n";
      }
    }
  }
  ofs << "}\n";

  ofs.close();
}
 
int main() {
  s21::s21_Graph graph;
  std::string inputFile = "graph_1.txt";
  std::string outputFile = "output.dot";
  graph.LoadGraphFromFile(inputFile);
  graph.ExportGraphToDot(outputFile);
  return 0;
}