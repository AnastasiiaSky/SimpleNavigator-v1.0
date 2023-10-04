#ifndef SRC_S21_GRAPH_H_
#define SRC_S21_GRAPH_H_
#include <iostream>
#include <cstring>

namespace s21 {

    class s21_Graph {
        public:
        s21_Graph() = default;
        s21_Graph(int size) {}
        ~s21_Graph() = default;

        void LoadGraphFromFile(std::string filename);
        void ExportGraphToDot(std::string filename);

        private:
        int size;
        std::vector<std::vector<int>> AdjMatrix;
    }

}

#endif  // SRC_S21_GRAPH_H_