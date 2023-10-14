#include <iostream>
#include <string>
#include "./s21_algorithms/s21_graph_algorithms.h"
#include "./s21_graph/s21_graph.h"

namespace s21 {
    class ConsoleMenuInterface {
        public:
            ConsoleMenuInterface(){}
            void Deploy();
            void ShowMenu();
        private:
            s21::s21_Graph graph_;
            s21::GraphAlgorithms GraphAlgorithms_;
    };
} // namespace s21