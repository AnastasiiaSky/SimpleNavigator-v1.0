#ifndef SRC_S21_GRAPH_H_
#define SRC_S21_GRAPH_H_
#include <iostream>
#include <cstring>
#include <vector>

namespace s21 {
    class s21_Graph {
    public:
        s21_Graph() = default;
        s21_Graph(int size) {this->size_ = size;}
        ~s21_Graph() = default;
        std::vector<std::vector<int>> getAdjacencyMatrix();
        std::vector<std::vector<int>> getAdjacencyList();
        std::vector<std::pair<int, int>> getEdgesList();

        void LoadGraphFromFile(std::string filename);
        void ExportGraphToDot(std::string filename);

    private:
        int size_;
        std::vector<std::vector<int>> AdjacencyMatrix_;
        std::vector<std::pair<int, int>> edgesList_;
        std::vector<std::vector<int>> adjacencyList_;
    };

} //namespace s21

#endif  // SRC_S21_GRAPH_H_