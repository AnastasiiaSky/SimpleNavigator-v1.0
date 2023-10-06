#ifndef SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#define SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_
#include <stack>
#include <list>
#include <vector>
#include <queue>
#include <iostream>


#include "../s21_graph/s21_graph.h"


namespace s21 {
    class s21_Graph;
    class GraphAlgorithms {
        public:
            std::vector<int> visited_vertices;

            void DepthFirstSearch(s21_Graph graph, int start_vertex); // главный метод алгоритма поиска в глумину
            bool CheckVisited(std::list<int> visited_vertices, int current_vertix); // метод проверки посещенных точек
            bool CheckViseted(std::queue<int> visited_vertices, int current_vertix);
            void PrintResultOfDepthFirstSearch(std::vector<int> visited_vertices); // метод вывода результата
            void PrintResultOfDepthFirstSearch(std::list<int> visited_vertices); // метод вывода результата
            void BreadthFirstSearch(s21::s21_Graph graph, int start_vertex);

    };

} // namespace s21

#endif // SRC_S21_ALGORITHMS_S21_GRAPH_ALGORITHMS_H_


