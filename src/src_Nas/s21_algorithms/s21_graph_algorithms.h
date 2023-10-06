#ifndef SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#define SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#include <stack>
#include <list>
#include <queue>
#include <vector>
#include <iostream>

#include "../s21_graph/s21_graph.h"
class s21_Graph;

namespace s21 {
    class GraphAlgorithms {
        public:
            void DepthFirstSearch(s21_Graph graph, int start_vertex);
            bool CheckViseted(std::list<int> visited_vertices, int current_vertix);
            bool CheckViseted(std::queue<int> visited_vertices, int current_vertix);
            void PrintResultOfDepthFirstSearch(std::list<int> visited_vertices);
            void BreadthFirstSearch(s21_Graph graph, int start_vertex);
    };

} // namespace s21

#endif // SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_


