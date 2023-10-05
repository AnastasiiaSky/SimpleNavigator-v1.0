#include "s21_graph_algorithms.h"
#include <stack>

void s21::s21_GraphAlgorithms::DepthFirstSearch(s21_Graph &graph, int start_vertex)
{
    int dimension = graph.getSize();
    // graph.getAdjacencyList();
    std::stack <int> StackforVertices;
    std::vector<std::vector<bool>> visited(dimension, std::vector<bool>(dimension, false));
    std::vector<std::vector<int>>  resultArr(dimension, std::vector<int>(dimension, -1));
    std::vector<std::vector<int>> AdjacencyList = graph.getAdjacencyList();
    // s21::s21_Graph resultArr;
    // forVertices.push(start_vertex);
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            StackforVertices.push(start_vertex);
            visited[i][j] = true;
            while(!StackforVertices.empty()) {
                int current_vertex = StackforVertices.top();
                 StackforVertices.pop(); 
            resultArr[i][j] = current_vertex;  //////////
            if (graph.getAdjacencyMatrix()[current_vertex][j] && visited[i][j] == false) {
                StackforVertices.push(j);
                visited[i][j] = true;
            }
        }
        std::cout << resultArr[i][j] << " ";
    }
    std::cout << std::endl;
    }
}


