#include <gtest/gtest.h>

namespace s21 {

    TEST(GraphAlgorithmsTest, FloidWarshall_graph_3_vert_simply) {
        s21_Graph graph;
        s21::GraphAlgorithms algo;
        std::string InputFileName = "./examples/weight_graph_4_vert.txt";
        graph.LoadGraphFromFile(InputFileName);
        std::vector<std::vector<int>> minimum_distance = algo.GetShortestPathsBetweenAllVertices(graph);
        std::vector<std::vector<int>> result {{0, 2, 3, 3}, {2, 0, 5, 1}, {3, 5, 0, 6}, {3, 1, 6, 0}};
        ASSERT_EQ(minimum_distance, result);
    }


    TEST(Test, FloidWarshall_weighted_directed_graph_4_vert) {
        s21_Graph graph;
        s21::GraphAlgorithms algo;
        std::string InputFileName = "./examples/weighted_directed_graph_4_vert.txt";
        graph.LoadGraphFromFile(InputFileName);
        std::vector<std::vector<int>> minimum_distance = algo.GetShortestPathsBetweenAllVertices(graph);
        std::vector<std::vector<int>> result {
            {0, 1, 4, 1}, 
            {7, 0, 3, 8}, 
            {4, 5, 0, 5}, 
            {8, 9, 4, 0}, 
        }; 
        ASSERT_EQ(minimum_distance, result);
    }
     

     TEST(GraphAlgorithmsTest, FloidWarshall_weighted_directed_graph_3_vert) {
        s21_Graph graph;
        s21::GraphAlgorithms algo;
        std::string InputFileName = "./examples/weighted_directed_graph_3_vert.txt";
        graph.LoadGraphFromFile(InputFileName);
        std::vector<std::vector<int>> minimum_distance = algo.GetShortestPathsBetweenAllVertices(graph);
        std::vector<std::vector<int>> result {
            {0, 4, 6}, 
            {0, 0, 3}, 
            {0, 0, 0} 
        }; 
        ASSERT_EQ(minimum_distance, result);
    }


    TEST(GraphAlgorithmsTest, FloidWarshall_weighted_directed_graph_8_vert) {
        s21_Graph graph;
        s21::GraphAlgorithms algo;
        std::string InputFileName = "./examples/weighted_directed_graph_8_vert.txt";
        graph.LoadGraphFromFile(InputFileName);
        std::vector<std::vector<int>> minimum_distance = algo.GetShortestPathsBetweenAllVertices(graph);
        std::vector<std::vector<int>> result {
            {0, 3, 6, 13, 16, 13, 6, 3},  // сыпиться здесь
            {0, 0, 3, 16, 13, 10, 13, 0}, 
            {0, 0, 0, 13, 10, 7, 10, 0}, 
            {0, 0, 3, 0, 8, 5, 8, 0}, 
            {0, 0, 6, 3, 0, 8, 11, 0}, 
            {0, 0, 9, 6, 3, 0, 3, 0}, 
            {0, 0, 10, 7, 15, 12, 0, 0}, 
            {0, 0, 13, 10, 18, 15, 3, 0}
        }; 
        ASSERT_EQ(minimum_distance, result);
    }


    TEST(GraphAlgorithmsTest, FloidWarshall_graph_21_vert_direct) {
        s21_Graph graph;
        s21::GraphAlgorithms algo;
        std::string InputFileName = "./examples/graph_21_vert_direct.txt";
        graph.LoadGraphFromFile(InputFileName);
        std::vector<std::vector<int>> minimum_distance = algo.GetShortestPathsBetweenAllVertices(graph);
        std::vector<std::vector<int>> result {
            {0, 1, 3, 4, 5, 6, 5, 7, 6, 4, 4, 2, 1, 4, 2, 2, 3, 6, 5, 5, 5}, 
            {0, 0, 2, 3, 4, 5, 4, 6, 5, 3, 3, 1, 4, 3, 1, 5, 2, 5, 4, 4, 4}, 
            {0, 0, 0, 1, 2, 3, 2, 4, 3, 1, 2, 4, 7, 6, 9, 8, 5, 4, 3, 3, 2}, 
            {0, 0, 4, 0, 1, 2, 1, 3, 2, 3, 2, 4, 7, 6, 9, 8, 5, 4, 3, 3, 4}, 
            {0, 0, 6, 2, 0, 1, 3, 5, 4, 5, 1, 3, 6, 5, 8, 7, 4, 3, 2, 2, 6}, 
            {0, 0, 5, 1, 2, 0, 2, 4, 3, 4, 3, 5, 8, 7, 10, 9, 6, 5, 4, 4, 5}, 
            {0, 0, 3, 4, 5, 6, 0, 2, 1, 2, 3, 5, 8, 7, 10, 9, 6, 5, 4, 4, 3}, 
            {0, 0, 1, 2, 3, 4, 3, 0, 4, 2, 3, 5, 8, 7, 10, 9, 6, 5, 4, 4, 3}, 
            {0, 0, 2, 3, 4, 5, 4, 1, 0, 1, 2, 4, 7, 6, 9, 8, 5, 4, 3, 3, 2}, 
            {0, 0, 4, 5, 6, 7, 6, 3, 2, 0, 1, 3, 6, 5, 8, 7, 4, 3, 2, 2, 1}, 
            {0, 0, 8, 9, 10, 11, 10, 12, 11, 9, 0, 2, 5, 4, 7, 6, 3, 2, 1, 1, 10}, 
            {0, 0, 6, 7, 8, 9, 8, 10, 9, 7, 2, 0, 3, 2, 5, 4, 1, 4, 3, 3, 8}, 
            {0, 0, 3, 4, 5, 6, 5, 7, 6, 4, 5, 7, 0, 9, 2, 1, 8, 7, 6, 6, 5}, 
            {0, 0, 4, 5, 6, 7, 6, 8, 7, 5, 6, 8, 1, 0, 3, 2, 9, 8, 7, 7, 6}, 
            {0, 0, 1, 2, 3, 4, 3, 5, 4, 2, 3, 5, 8, 7, 0, 9, 6, 5, 4, 4, 3}, 
            {0, 0, 2, 3, 4, 5, 4, 6, 5, 3, 4, 6, 9, 8, 1, 0, 7, 6, 5, 5, 4}, 
            {0, 0, 5, 6, 7, 8, 7, 9, 8, 6, 1, 3, 2, 1, 4, 3, 0, 3, 2, 2, 7}, 
            {0, 0, 6, 7, 8, 9, 8, 10, 9, 7, 2, 4, 3, 2, 5, 4, 1, 0, 3, 3, 8}, 
            {0, 0, 7, 8, 9, 10, 9, 11, 10, 8, 3, 5, 4, 3, 6, 5, 2, 1, 0, 4, 9}, 
            {0, 0, 7, 8, 9, 10, 9, 11, 10, 8, 3, 1, 4, 3, 6, 5, 2, 5, 4, 0, 9}, 
            {0, 0, 3, 4, 5, 6, 5, 2, 1, 2, 3, 5, 8, 7, 10, 9, 6, 5, 4, 4, 0} 
        }; 
        ASSERT_EQ(minimum_distance, result);
    }
}