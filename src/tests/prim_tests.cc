#include <gtest/gtest.h>

namespace s21 {
TEST(GraphAlgorithmsTest, test_GetLeastSpanningTree_working_with_simple_graph_compare_weights_results_and_matrix) {
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
    int weight = algo.GetGraphWeigt(spanning_tree) / 2;
        ASSERT_EQ(weight, 39);
    }
}

TEST(GraphAlgorithmsTest, test_GetLeastSpanningTree_2_workingwithdirected_graph_compare_weight_result_and_matrix) {
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
    int weight = algo.GetGraphWeigt(spanning_tree) / 2;
        ASSERT_EQ(weight, 39);
    }
}

TEST(GraphAlgorithmsTest, test_GetLeastSpanningTree_3_simple_graph_unweighted_compare_weight_result_and_matrix) {
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

    int weight = algo.GetGraphWeigt(spanning_tree) / 2;
        ASSERT_EQ(weight, 4);
    }
}

TEST(GraphAlgorithmsTest, test_GetLeastSpanningTree_3_simple_graph_simple_10_vert_for_check_tree) {
    s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "./examples/graph_simple_10_vert_for_check_tree.txt";
    graph.LoadGraphFromFile(InputFileName);
    std::vector<std::vector<int>> spanning_tree = algo.GetLeastSpanningTree(graph);
    std::vector<std::vector<int>> result {
            {0, 3, 0, 0, 4, 0, 0, 0, 0, 18},
            {3, 0, 4, 3, 0, 0, 0, 0, 0, 0},
            {0, 4, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
            {4, 0, 0, 0, 0, 3, 10, 11, 12, 0},
            {0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 10, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 11, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 12, 0, 0, 0, 0, 0},
            {18, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result.size(); ++j) {
        ASSERT_EQ(spanning_tree[i][j], result[i][j]);
        }

    int weight = algo.GetGraphWeigt(spanning_tree) / 2;
        ASSERT_EQ(weight, 68);
    }
}
} // namespace s21