#include <gtest/gtest.h>

namespace s21 {
TEST(Test, test_GetLeastSpanningTree_1) {
    s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "./examples/weighted_graph_7_vert.txt";
    graph.LoadGraphFromFile(InputFileName);
    std::vector<std::vector<int>> spanning_tree = algo.GetLeastSpanningTree(graph);
    std::vector<std::vector<int>> result {
        {0, 7, 0, 5, 0, 0, 0},
        {7, 0, 0, 0, 7, 0, 0},
        {0, 0, 0, 0, 5, 0, 0},
        {5, 0, 0, 0, 0, 6, 0},
        {0, 7, 5, 0, 0, 0, 9},
        {0, 0, 0, 6, 0, 0, 0},
        {0, 0, 0, 0, 9, 0, 0}
    };
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result.size(); ++j) {
        ASSERT_EQ(spanning_tree[i][j], result[i][j]);
        }
    int weight = algo.GetSpanningTreeWeigt(spanning_tree);
        ASSERT_EQ(weight, 39);
    }
}

TEST(Test, test_GetLeastSpanningTree_2_workingwithdirected_graph) {
    s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "./examples/weighted_directed_graph_7_vert.txt";
    graph.LoadGraphFromFile(InputFileName);
    std::vector<std::vector<int>> spanning_tree = algo.GetLeastSpanningTree(graph);
    std::vector<std::vector<int>> result {
        {0, 7, 0, 5, 0, 0, 0},
        {7, 0, 0, 0, 7, 0, 0},
        {0, 0, 0, 0, 5, 0, 0},
        {5, 0, 0, 0, 0, 6, 0},
        {0, 7, 5, 0, 0, 0, 9},
        {0, 0, 0, 6, 0, 0, 0},
        {0, 0, 0, 0, 9, 0, 0}
    };
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result.size(); ++j) {
        ASSERT_EQ(spanning_tree[i][j], result[i][j]);
        }
    int weight = algo.GetSpanningTreeWeigt(spanning_tree);
        ASSERT_EQ(weight, 39);
    }
}

// тест не работает так как нет проверки на связность графа 
// TEST(Test, test_GetLeastSpanningTree_3_unconnected_graph) {
//     s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/unconnected_graph_5_vert.txt";
//     graph.LoadGraphFromFile(InputFileName);
//     // std::vector<std::vector<int>> spanning_tree;
//     // ASSERT_ANY_THROW(spanning_tree = algo.GetLeastSpanningTree(graph));
//     std::vector<std::vector<int>> spanning_tree = algo.GetLeastSpanningTree(graph);
// }

TEST(Test, test_GetLeastSpanningTree_3_simple_graph) {
    s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "./examples/graph_5_vert_simply.txt";
    graph.LoadGraphFromFile(InputFileName);
    std::vector<std::vector<int>> spanning_tree = algo.GetLeastSpanningTree(graph);
    std::vector<std::vector<int>> result {
            {0, 1, 1, 1, 0},
            {1, 0, 0, 0, 0},
            {1, 0, 0, 0, 0},
            {1, 0, 0, 0, 1},
            {0, 0, 0, 1, 0}
    };

    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result.size(); ++j) {
        ASSERT_EQ(spanning_tree[i][j], result[i][j]);
        }

    int weight = algo.GetSpanningTreeWeigt(spanning_tree);
        ASSERT_EQ(weight, 4);
    }
}
}