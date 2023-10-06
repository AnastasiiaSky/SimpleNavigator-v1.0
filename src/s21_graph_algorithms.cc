#include "s21_graph_algorithms.h"
#include <stack>

std::vector<int> s21::s21_GraphAlgorithms::DepthFirstSearch(s21_Graph &graph, int start_vertex)
{
    int dimension = graph.getSize();
    // graph.getAdjacencyList();
    std::stack <int> StackforVertices;
    std::vector<int> visited;
    std::vector<int>  resultArr;
    std::vector<std::vector<int>> AdjacencyList = graph.getAdjacencyList();
    // s21::s21_Graph resultArr;
    // forVertices.push(start_vertex);
    for (int i = 0; i < dimension; i++) {
        // for (int j = 0; j < dimension; j++) {
            StackforVertices.push(start_vertex);
            visited[i]= true;
            while(!StackforVertices.empty()) {
                int current_vertex = StackforVertices.top();
                 StackforVertices.pop(); 
            resultArr[i] = current_vertex;  //////////
            if (AdjacencyList[current_vertex][i] && visited[i] == false) {
                StackforVertices.push(current_vertex);
                visited[i] = true;
            // }
              std::cout << resultArr[i]<< " ";
        }
        //  std::cout << std::endl;
    }
 
    }
    return visited;
}


