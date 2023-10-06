#include <gtest/gtest.h>

#include "./s21_graph/s21_graph.cc"
#include "./s21_algorithms/s21_graph_algorithms.cc"


namespace s21 {
    TEST(Test, test_DepthFirstSearch_simple_graph_size_3) {
        s21_Graph graph;
        s21::GraphAlgorithms algo;
        std::string InputFileName = "./examples/graph_3_vert_simply.txt";
        graph.LoadGraphFromFile(InputFileName);
        int start = 0;
        std::vector<int> visited_vertices;
        std::vector<int> result;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {0, 1, 2};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
  
        start = 1;
        visited_vertices.clear();
        result.clear();
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {1, 0, 2};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }

        start = 2;
        visited_vertices.clear();
        result.clear();
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {2, 0, 1};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }

        visited_vertices.clear();
        start = -1;
        ASSERT_ANY_THROW(visited_vertices = algo.DepthFirstSearch(graph, start));

        visited_vertices.clear();
        start = 7;
        ASSERT_ANY_THROW(visited_vertices = algo.DepthFirstSearch(graph, start));
    }

    TEST(Test, test_DepthFirstSearch_simple_graph_size_13) {
        s21_Graph graph;
        s21::GraphAlgorithms algo;
        std::string InputFileName = "./examples/graph_13_vert_simply.txt";
        graph.LoadGraphFromFile(InputFileName);
        int start = 0;
        std::vector<int> visited_vertices;
        std::vector<int> result;
        visited_vertices = algo.DepthFirstSearch(graph, start);

        result = {0, 1, 3, 2, 11, 6, 7, 8, 12, 4, 5, 9, 10};

        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }


        start = 8;
        visited_vertices.clear();
        result.clear();
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {8, 0, 1, 3, 2, 11, 6, 7, 10, 12, 4, 5, 9};

        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }

        visited_vertices.clear();
        start = -10;
        ASSERT_ANY_THROW(visited_vertices = algo.DepthFirstSearch(graph, start));

        visited_vertices.clear();
        start = 7777;
        ASSERT_ANY_THROW(visited_vertices = algo.DepthFirstSearch(graph, start));

    }

    // TEST(Test, test_DepthFirstSearch_3) {

    // }

    // TEST(Test, test_DepthFirstSearch_4) {

    // }

    // TEST(Test, test_DepthFirstSearch_5) {

    // }

    // TEST(Test, test_DepthFirstSearch_6) {

    // }


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

} // namespace s21
