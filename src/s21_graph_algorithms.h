#ifndef SRC_S21_GRAPH_ALGORITHMS_H_
#define SRC_S21_GRAPH_ALGORITHMS_H_
#include <iostream>
#include <cstring>
#include <vector>
#include "s21_graph.h"
#include "./s21_Containers/s21_list.h"
#include "./s21_Containers/s21_stack.h"
#include "./s21_Containers/s21_queue.h"
#include "./s21_Containers/s21_array.h"

namespace s21 {
    class s21_GraphAlgorithms {
    public:
    struct TsmResult {
    int* vertices;    // массив с искомым маршрутом (с порядком обхода вершин). Вместо int* можно использовать std::vector<int>
    double distance;  // длина этого маршрута
};
    void DepthFirstSearch(s21_Graph &graph, int start_vertex);

    };

} //namespace s21

#endif  // SRC_S21_GRAPH_ALGORITHMS_H_