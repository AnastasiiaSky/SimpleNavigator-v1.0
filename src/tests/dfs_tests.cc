#include <gtest/gtest.h>

namespace s21 {
    TEST(Test, test_DepthFirstSearch_simple_graph_size_3) {
        s21_Graph graph;
        s21::GraphAlgorithms algo;
        std::string InputFileName = "./examples/graph_3_vert_simply.txt";
        graph.LoadGraphFromFile(InputFileName);
        int start = 1;
        std::vector<int> visited_vertices;
        std::vector<int> result;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {1, 2, 3};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
  
        start = 2;
        visited_vertices.clear();
        result.clear();
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {2, 1, 3};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }

        start = 3;
        visited_vertices.clear();
        result.clear();
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {3, 1, 2};
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
        int start = 1;
        std::vector<int> visited_vertices;
        std::vector<int> result;
        visited_vertices = algo.DepthFirstSearch(graph, start);

        result = {1, 2, 4, 3, 12, 7, 8, 9, 13, 5, 6, 10, 11};

        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }

        start = 9;
        visited_vertices.clear();
        result.clear();
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {9, 1, 2, 4, 3, 12, 7, 8, 11, 13, 5, 6, 10};

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


    TEST(Test, test_DepthFirstSearch_directed_graph_8_vert) {
        s21_Graph graph;
        s21::GraphAlgorithms algo;
        std::string InputFileName = "./examples/graph_8_vert_direct.txt";
        graph.LoadGraphFromFile(InputFileName);
        int start = 2;
        std::vector<int> visited_vertices;
        std::vector<int> result;
        visited_vertices = algo.DepthFirstSearch(graph, start);

        result = {2, 3, 1, 4, 5, 7, 8, 6};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }

        start = 6;
        visited_vertices.clear();
        result.clear();
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {6, 5, 7, 1, 4, 8, 3, 2};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
    }


    TEST(Test, test_DepthFirstSearch_directed_graph_21_vert) {
        s21_Graph graph;
        s21::GraphAlgorithms algo;
        std::string InputFileName = "./examples/graph_21_vert_direct.txt";
        graph.LoadGraphFromFile(InputFileName);
        int start = 1;
        std::vector<int> visited_vertices;
        std::vector<int> result;
        visited_vertices = algo.DepthFirstSearch(graph, start);


        result = {1, 2, 12, 17, 11, 19, 18, 20, 14, 13, 16, 15, 3, 4, 5, 6, 7, 9, 8, 10, 21};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }

        start = 15;
        visited_vertices.clear();
        result.clear();
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {15, 3, 4, 5, 6, 11, 19, 18, 17, 14, 13, 16, 20, 12, 7, 9, 8, 10, 21};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }

        visited_vertices.clear();
        result.clear();
    }


    TEST(Test, test_DepthFirstSearch_weighted_graph_9_vert) {
        s21_Graph graph;
        s21::GraphAlgorithms algo;
        std::string InputFileName = "./examples/weighted_graph_9_vert.txt";
        graph.LoadGraphFromFile(InputFileName);
        int start = 9;
        std::vector<int> visited_vertices;
        std::vector<int> result;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {9, 1, 2, 3, 4, 5, 6, 7, 8};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 4;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {4, 1, 2, 3, 6, 5, 7, 8, 9};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 1;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
    }
   

    TEST(Test, test_DepthFirstSearch_weighted_directed_graph_8_vert) {
        s21_Graph graph;
        s21::GraphAlgorithms algo;
        std::string InputFileName = "./examples/weighted_directed_graph_8_vert.txt";
        graph.LoadGraphFromFile(InputFileName);
        int start = 1;
        std::vector<int> visited_vertices;
        std::vector<int> result;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {1, 2, 3, 6, 5, 4, 7, 8};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 2;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {2, 3, 6, 5, 4, 7};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 3;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {3, 6, 5, 4, 7};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 4;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {4, 3, 6, 5, 7};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 5;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {5, 4, 3, 6, 7};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 6;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {6, 5, 4, 3, 7};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 7;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {7, 4, 3, 6, 5};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 8;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {8, 7, 4, 3, 6, 5};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
    }
} // namespace s21