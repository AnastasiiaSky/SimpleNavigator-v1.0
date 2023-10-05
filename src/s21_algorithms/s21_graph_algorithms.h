#ifndef SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#define SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#include <stack>
#include <list>
#include <vector>
#include <iostream>

#include "../s21_graph/s21_graph.h"


namespace s21 {
     class s21_Graph;
    class GraphAlgorithms {
        public:
            void DepthFirstSearch(s21_Graph graph, int start_vertex);
            bool CheckViseted(std::list<int> visited_vertices, int current_vertix);
            void PrintResultOfDepthFirstSearch(std::list<int> visited_vertices);

    };

} // namespace s21

#endif // SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_


