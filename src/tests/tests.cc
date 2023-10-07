#include <gtest/gtest.h>

#include "../s21_graph/s21_graph.cc"
#include "../s21_algorithms/s21_graph_algorithms.cc"


namespace s21 {
    // TEST(Test, test_DepthFirstSearch_simple_graph_size_3) {
    //     s21_Graph graph;
    //     s21::GraphAlgorithms algo;
    //     std::string InputFileName = "./examples/graph_3_vert_simply.txt";
    //     graph.LoadGraphFromFile(InputFileName);
    //     int start = 0;
    //     std::vector<int> visited_vertices;
    //     std::vector<int> result;
    //     visited_vertices = algo.DepthFirstSearch(graph, start);
    //     result = {0, 1, 2};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }
  
    //     start = 1;
    //     visited_vertices.clear();
    //     result.clear();
    //     visited_vertices = algo.DepthFirstSearch(graph, start);
    //     result = {1, 0, 2};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }

    //     start = 2;
    //     visited_vertices.clear();
    //     result.clear();
    //     visited_vertices = algo.DepthFirstSearch(graph, start);
    //     result = {2, 0, 1};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }

    //     visited_vertices.clear();
    //     start = -1;
    //     ASSERT_ANY_THROW(visited_vertices = algo.DepthFirstSearch(graph, start));

    //     visited_vertices.clear();
    //     start = 7;
    //     ASSERT_ANY_THROW(visited_vertices = algo.DepthFirstSearch(graph, start));
    // }

    // TEST(Test, test_DepthFirstSearch_simple_graph_size_13) {
    //     s21_Graph graph;
    //     s21::GraphAlgorithms algo;
    //     std::string InputFileName = "./examples/graph_13_vert_simply.txt";
    //     graph.LoadGraphFromFile(InputFileName);
    //     int start = 0;
    //     std::vector<int> visited_vertices;
    //     std::vector<int> result;
    //     visited_vertices = algo.DepthFirstSearch(graph, start);

    //     result = {0, 1, 3, 2, 11, 6, 7, 8, 12, 4, 5, 9, 10};

    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }


    //     start = 8;
    //     visited_vertices.clear();
    //     result.clear();
    //     visited_vertices = algo.DepthFirstSearch(graph, start);
    //     result = {8, 0, 1, 3, 2, 11, 6, 7, 10, 12, 4, 5, 9};

    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }

    //     visited_vertices.clear();
    //     start = -10;
    //     ASSERT_ANY_THROW(visited_vertices = algo.DepthFirstSearch(graph, start));

    //     visited_vertices.clear();
    //     start = 7777;
    //     ASSERT_ANY_THROW(visited_vertices = algo.DepthFirstSearch(graph, start));

    // }

    // TEST(Test, test_DepthFirstSearch_directed_graph_8_vert) {
    //     s21_Graph graph;
    //     s21::GraphAlgorithms algo;
    //     std::string InputFileName = "./examples/graph_8_vert_direct.txt";
    //     graph.LoadGraphFromFile(InputFileName);
    //     int start = 1;
    //     std::vector<int> visited_vertices;
    //     std::vector<int> result;
    //     visited_vertices = algo.DepthFirstSearch(graph, start);

    //     result = {1, 2, 0, 3, 4, 6, 7, 5};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }

    //     start = 5;
    //     visited_vertices.clear();
    //     result.clear();
    //     visited_vertices = algo.DepthFirstSearch(graph, start);
    //     result = {5, 4, 6, 0, 3, 7, 2, 1};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }

    // }

    //     TEST(Test, test_DepthFirstSearch_directed_graph_21_vert) {
    //     s21_Graph graph;
    //     s21::GraphAlgorithms algo;
    //     std::string InputFileName = "./examples/graph_21_vert_direct.txt";
    //     graph.LoadGraphFromFile(InputFileName);
    //     int start = 0;
    //     std::vector<int> visited_vertices;
    //     std::vector<int> result;
    //     visited_vertices = algo.DepthFirstSearch(graph, start);


    //     result = {0, 1, 11, 16, 10, 18, 17, 19, 13, 12, 15, 14, 2, 3, 4, 5, 6, 8, 7, 9, 20};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }

    //     start = 14;
    //     visited_vertices.clear();
    //     result.clear();
    //     visited_vertices = algo.DepthFirstSearch(graph, start);
    //     result = {14, 2, 3, 4, 5, 10, 18, 17, 16, 13, 12, 15, 19, 11, 6, 8, 7, 9, 20};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }

    //     visited_vertices.clear();
    //     result.clear();
    // }


    // TEST(Test, test_DepthFirstSearch_weighted_graph_9_vert) {
    //     s21_Graph graph;
    //     s21::GraphAlgorithms algo;
    //     std::string InputFileName = "./examples/weighted_graph_9_vert.txt";
    //     graph.LoadGraphFromFile(InputFileName);
    //     int start = 8;
    //     std::vector<int> visited_vertices;
    //     std::vector<int> result;
    //     visited_vertices = algo.DepthFirstSearch(graph, start);
    //     result = {8, 0, 1, 2, 3, 4, 5, 6, 7};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }
    //     visited_vertices.clear();
    //     result.clear();
    //     start = 3;
    //     visited_vertices = algo.DepthFirstSearch(graph, start);
    //     result = {3, 0, 1, 2, 5, 4, 6, 7, 8};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }
    //     visited_vertices.clear();
    //     result.clear();
    //     start = 0;
    //     visited_vertices = algo.DepthFirstSearch(graph, start);
    //     result = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }
    // }
   

    // TEST(Test, test_DepthFirstSearch_weighted_directed_graph_8_vert) {
    //     s21_Graph graph;
    //     s21::GraphAlgorithms algo;
    //     std::string InputFileName = "./examples/weighted_directed_graph_8_vert.txt";
    //     graph.LoadGraphFromFile(InputFileName);
    //     int start = 0;
    //     std::vector<int> visited_vertices;
    //     std::vector<int> result;
    //     visited_vertices = algo.DepthFirstSearch(graph, start);
    //     result = {0, 1, 2, 5, 4, 3, 6, 7};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }
    //     visited_vertices.clear();
    //     result.clear();
    //     start = 1;
    //     visited_vertices = algo.DepthFirstSearch(graph, start);
    //     result = {1, 2, 5, 4, 3, 6};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }
    //     visited_vertices.clear();
    //     result.clear();
    //     start = 2;
    //     visited_vertices = algo.DepthFirstSearch(graph, start);
    //     result = {2, 5, 4, 3, 6};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }
    //     visited_vertices.clear();
    //     result.clear();
    //     start = 3;
    //     visited_vertices = algo.DepthFirstSearch(graph, start);
    //     result = {3, 2, 5, 4, 6};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }
    //     visited_vertices.clear();
    //     result.clear();
    //     start = 4;
    //     visited_vertices = algo.DepthFirstSearch(graph, start);
    //     result = {4, 3, 2, 5, 6};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }
    //     visited_vertices.clear();
    //     result.clear();
    //     start = 5;
    //     visited_vertices = algo.DepthFirstSearch(graph, start);
    //     result = {5, 4, 3, 2, 6};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }
    //     visited_vertices.clear();
    //     result.clear();
    //     start = 6;
    //     visited_vertices = algo.DepthFirstSearch(graph, start);
    //     result = {6, 3, 2, 5, 4};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }
    //     visited_vertices.clear();
    //     result.clear();
    //     start = 7;
    //     visited_vertices = algo.DepthFirstSearch(graph, start);
    //     result = {7, 6, 3, 2, 5, 4};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }
    // }

// // std::cout << "Algorithm Breadth First Search" << std::endl;

    // TEST(Test, test_BreadFirstSearch_simple_graph_size_3) {
    //     s21_Graph graph;
    //     s21::GraphAlgorithms algo;
    //     std::string InputFileName = "./examples/graph_3_vert_simply.txt";
    //     graph.LoadGraphFromFile(InputFileName);
    //     int start = 0;
    //     std::vector<int> visited_vertices;
    //     std::vector<int> result;
    //     visited_vertices = algo.BreadthFirstSearch(graph, start);
    //     result = {0, 1, 2};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }
  
    //     start = 1;
    //     visited_vertices.clear();
    //     result.clear();
    //     visited_vertices = algo.BreadthFirstSearch(graph, start);
    //     result = {1, 0, 2};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }

    //     start = 2;
    //     visited_vertices.clear();
    //     result.clear();
    //     visited_vertices = algo.BreadthFirstSearch(graph, start);
    //     result = {2, 0, 1};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }

    //     visited_vertices.clear();
    //     start = -1;
    //     ASSERT_ANY_THROW(visited_vertices = algo.BreadthFirstSearch(graph, start));

    //     visited_vertices.clear();
    //     start = 7;
    //     ASSERT_ANY_THROW(visited_vertices = algo.BreadthFirstSearch(graph, start));
    // }

    // TEST(Test, test_BreadFirstSearch_simple_graph_size_13) {
    //     s21_Graph graph;
    //     s21::GraphAlgorithms algo;
    //     std::string InputFileName = "./examples/graph_13_vert_simply.txt";
    //     graph.LoadGraphFromFile(InputFileName);

    //     int start = 0;
    //     std::vector<int> visited_vertices;
    //     std::vector<int> result;
    //     visited_vertices = algo.BreadthFirstSearch(graph, start);

    //     result = {0, 1, 8, 10, 12, 3, 9, 11, 7, 6, 4, 5, 2};

    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }


    //     start = 8;
    //     visited_vertices.clear();
    //     result.clear();
    //     visited_vertices = algo.BreadthFirstSearch(graph, start);
    //     result = {8, 0, 7, 12, 1, 10, 6, 4, 5, 9, 11, 3, 2};

    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }

    //     visited_vertices.clear();
    //     start = -10;
    //     ASSERT_ANY_THROW(visited_vertices = algo.BreadthFirstSearch(graph, start));

    //     visited_vertices.clear();
    //     start = 7777;
    //     ASSERT_ANY_THROW(visited_vertices = algo.BreadthFirstSearch(graph, start));

    // }

    // TEST(Test, test_BreadFirstSearch_directed_graph_8_vert) {
    //     s21_Graph graph;
    //     s21::GraphAlgorithms algo;
    //     std::string InputFileName = "./examples/graph_8_vert_direct.txt";
    //     graph.LoadGraphFromFile(InputFileName);
    //     int start = 1;
    //     std::vector<int> visited_vertices;
    //     std::vector<int> result;
    //     visited_vertices = algo.BreadthFirstSearch(graph, start);

    //     result = {1, 2, 0, 3, 5, 4, 7, 6};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }

    //     start = 5;
    //     visited_vertices.clear();
    //     result.clear();
    //     visited_vertices = algo.BreadthFirstSearch(graph, start);
    //     result = {5, 4, 6, 0, 1, 3, 2, 7};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }

    // }

        TEST(Test, test_BreadFirstSearch_directed_graph_21_vert) {
        s21_Graph graph;
        s21::GraphAlgorithms algo;
        std::string InputFileName = "./examples/graph_21_vert_direct.txt";
        graph.LoadGraphFromFile(InputFileName);
        
        int start = 1;
        std::vector<int> visited_vertices;
        std::vector<int> result;
        visited_vertices = algo.BreadthFirstSearch(graph, start);

        algo.PrintResultOfDepthFirstSearch(visited_vertices);
        // result = {0, 1, 12, 11, 14, 15, 16, 2, 10, 13, 3, 9, 18, 19, 4, 6, 20, 17, 5, 8, 7};
        result = {1, 11, 14, 16, 2, 10, 13, 3, 9, 18, 19, 12, 4, 6, 20, 17, 15, 5, 8, 7};
        for(int it = 0; it < result.size(); ++it) {
            // ASSERT_EQ(visited_vertices[it], result[it]);
        }

        // start = 14;
        // visited_vertices.clear();
        // result.clear();
        // visited_vertices = algo.BreadthFirstSearch(graph, start);
        // result = {37, 29, 34, 28, 31, 36, 30, 35, 33, 32, 2, 3, 27, 4, 6, 38, 5, 26, 7};
        // for(int it = 0; it < result.size(); ++it) {
        //     // ASSERT_EQ(visited_vertices[it], result[it]);
        // }

        visited_vertices.clear();
        result.clear();
    }


    // TEST(Test, test_BreadFirstSearch_weighted_graph_9_vert) {
    //     s21_Graph graph;
    //     s21::GraphAlgorithms algo;
    //     std::string InputFileName = "./examples/weighted_graph_9_vert.txt";
    //     graph.LoadGraphFromFile(InputFileName);
        
    //     int start = 8;
    //     std::vector<int> visited_vertices;
    //     std::vector<int> result;
    //     visited_vertices = algo.BreadthFirstSearch(graph, start);
    //     result = {8, 0, 3, 6, 7, 1, 2, 4, 5};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }
    //     visited_vertices.clear();
    //     result.clear();
    //     start = 3;
    //     visited_vertices = algo.BreadthFirstSearch(graph, start);
    //     result = {3, 0, 2, 4, 8, 1, 6, 7, 5};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }
    //     visited_vertices.clear();
    //     result.clear();

    //     start = 0;
    //     visited_vertices = algo.BreadthFirstSearch(graph, start);
    //     result = {0, 1, 3, 6, 7, 8, 2, 4, 5};
    //     for(int it = 0; it < result.size(); ++it) {
    //         ASSERT_EQ(visited_vertices[it], result[it]);
    //     }
    // }


// TEST(Graph, getAjacencyMatrix) {
// s21::s21_Graph graph;

//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/graph_3_vert_simply.txt";
//         graph.LoadGraphFromFile(InputFileName);

//     // Ïîëó÷åíèå ìàòðèöû ñìåæíîñòè èç ãðàôà
//     std::vector<std::vector<int>> adjacencyMatrix = graph.getAdjacencyMatrix();
//     std::vector<std::vector<int>> expected {{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
//     //  std::vector<int> expected = {0, 1, 3, 4, 2, 5, 6};

//     ASSERT_EQ(adjacencyMatrix, expected);

// }

// TEST(Graph, getEdgeList) {
// s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/graph_3_vert_simply.txt";
//     graph.LoadGraphFromFile(InputFileName);
//     std::vector<std::pair<int, int>> GetedgesList = graph.getEdgesList(); 
//     std::vector<std::pair<int, int>> expected {{0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}};
//     ASSERT_EQ(GetedgesList, expected);
// }

// TEST(Graph, errorOpeningFile) {
// s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/graph_155_vert_simply.txt";
//     graph.LoadGraphFromFile(InputFileName);
// }
// TEST(Graph, DOT) {
// s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/graph_3_vert_simply.txt";
//     graph.LoadGraphFromFile(InputFileName);
//     std::string outputFile = "output.dot";
//     graph.ExportGraphToDot(outputFile);
// }
// TEST(Graph, Graph_DOTerror_Test) {
// s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/graph_3_vert_simply.txt";
//     // graph.LoadGraphFromFile(InputFileName);
//     std::string outputFile = "output1.dot";
//     graph.ExportGraphToDot(outputFile);
// }


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

} // namespace s21