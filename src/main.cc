#include <iostream>
#include <list>
#include <stack>
#include <vector>

#include "./s21_algorithms/s21_graph_algorithms.h"
#include "./s21_graph/s21_graph.h"

using namespace s21;
int main() {
  s21_Graph graph;
  s21::GraphAlgorithms algo;

  std::string InputFileName = "./examples/graph_3_vert_simply.txt";
  graph.LoadGraphFromFile(InputFileName);
  std::vector<std::pair<int, int>> edgesList = graph.getEdgesList();
  std::cout << "EdgesList:\n";
  for (int i = 0; i < edgesList.size(); ++i) {
    std::cout << "(" << edgesList[i].first << ", " << edgesList[i].second
              << ")\n";
  }
  std::vector<std::vector<int>> adjacencyList = graph.getAdjacencyList();
  std::cout << "AdjacencyList:\n";
  for (int i = 0; i < adjacencyList.size(); ++i) {
    std::cout << i << ": ";
    for (int j = 0; j < adjacencyList[i].size(); ++j) {
      std::cout << adjacencyList[i][j] << " ";
    }
    std::cout << "\n";
  }
  // std::string outputFile = "output.dot";
  // graph.ExportGraphToDot(outputFile);

  int start = 2;
  std::vector<int> visited_vertices = algo.DepthFirstSearch(graph, start);
  algo.PrintResultOfDepthFirstSearch(visited_vertices);
  return 0;
}

// ./s21_graph/examples/graph_3_vert_simply.txt
// ./s21_graph/examples/graph_4_vert_simply.txt
// ./s21_graph/examples/graph_5_vert_simply.txt
// ./s21_graph/examples/graph_7_vert_simply.txt
