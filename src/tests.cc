#include <gtest/gtest.h>

#include "./s21_graph/s21_graph.cc"
#include "./s21_graph/s21_graph.h" 
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
        algo.PrintResultOfDepthFirstSearch(visited_vertices);
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

    TEST(Test, test_DepthFirstSearch_directed_graph_8_vert) {
        s21_Graph graph;
        s21::GraphAlgorithms algo;
        std::string InputFileName = "./examples/graph_8_vert_direct.txt";
        graph.LoadGraphFromFile(InputFileName);
        int start = 1;
        std::vector<int> visited_vertices;
        std::vector<int> result;
        visited_vertices = algo.DepthFirstSearch(graph, start);

        result = {1, 2, 0, 3, 4, 6, 7, 5};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }

        start = 5;
        visited_vertices.clear();
        result.clear();
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {5, 4, 6, 0, 3, 7, 2, 1};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }

    }

        TEST(Test, test_DepthFirstSearch_directed_graph_21_vert) {
        s21_Graph graph;
        s21::GraphAlgorithms algo;
        std::string InputFileName = "./examples/graph_21_vert_direct.txt";
        graph.LoadGraphFromFile(InputFileName);
        int start = 0;
        std::vector<int> visited_vertices;
        std::vector<int> result;
        visited_vertices = algo.DepthFirstSearch(graph, start);


        result = {0, 1, 11, 16, 10, 18, 17, 19, 13, 12, 15, 14, 2, 3, 4, 5, 6, 8, 7, 9, 20};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }

        start = 14;
        visited_vertices.clear();
        result.clear();
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {14, 2, 3, 4, 5, 10, 18, 17, 16, 13, 12, 15, 19, 11, 6, 8, 7, 9, 20};
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
        int start = 8;
        std::vector<int> visited_vertices;
        std::vector<int> result;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {8, 0, 1, 2, 3, 4, 5, 6, 7};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 3;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {3, 0, 1, 2, 5, 4, 6, 7, 8};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 0;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
    }
   

    TEST(Test, test_DepthFirstSearch_weighted_directed_graph_8_vert) {
        s21_Graph graph;
        s21::GraphAlgorithms algo;
        std::string InputFileName = "./examples/weighted_directed_graph_8_vert.txt";
        graph.LoadGraphFromFile(InputFileName);
        int start = 0;
        std::vector<int> visited_vertices;
        std::vector<int> result;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {0, 1, 2, 5, 4, 3, 6, 7};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 1;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {1, 2, 5, 4, 3, 6};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 2;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {2, 5, 4, 3, 6};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 3;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {3, 2, 5, 4, 6};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 4;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {4, 3, 2, 5, 6};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 5;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {5, 4, 3, 2, 6};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 6;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {6, 3, 2, 5, 4};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
        visited_vertices.clear();
        result.clear();
        start = 7;
        visited_vertices = algo.DepthFirstSearch(graph, start);
        result = {7, 6, 3, 2, 5, 4};
        for(int it = 0; it < result.size(); ++it) {
            ASSERT_EQ(visited_vertices[it], result[it]);
        }
    }

TEST(Graph, getAjacencyMatrix) {
s21::s21_Graph graph;

    s21::GraphAlgorithms algo;
    std::string InputFileName = "./examples/graph_3_vert_simply.txt";
        graph.LoadGraphFromFile(InputFileName);

    // Получение матрицы смежности из графа
    std::vector<std::vector<int>> adjacencyMatrix = graph.getAdjacencyMatrix();
    std::vector<std::vector<int>> expected {{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
    ASSERT_EQ(adjacencyMatrix, expected);
}

TEST(Graph, getEdgeList) {
s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "./examples/graph_3_vert_simply.txt";
    graph.LoadGraphFromFile(InputFileName);
    std::vector<std::pair<int, int>> GetedgesList = graph.getEdgesList(); 
    std::vector<std::pair<int, int>> expected {{0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}};
    ASSERT_EQ(GetedgesList, expected);
}


TEST(GraphTest, ExportGraphToDot_ErrorOpeningFile) {
    // Создание объекта графа
    s21::s21_Graph graph;

    // Вызов метода ExportGraphToDot с несуществующим именем файла
    testing::internal::CaptureStdout();
    graph.ExportGraphToDot("DD:/nonexistent_file.dot");
    std::string captured_stdout = testing::internal::GetCapturedStdout();

    // Проверка, что сообщение об ошибке выводится в stdout
    EXPECT_TRUE(captured_stdout.find("Error opening file") != std::string::npos);
}

TEST(Graph, errorOpeningFile) {
s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
      // Вызов метода LoadGraphFromFile с несуществующим именем файла
    testing::internal::CaptureStdout();
    std::string InputFileName = "./examples/graph_155_vert_simply.txt";
     graph.LoadGraphFromFile(InputFileName);
     std::string captured_stdout = testing::internal::GetCapturedStdout();
      // Проверка, что сообщение об ошибке выводится в stdout
    EXPECT_TRUE(captured_stdout.find("Error opening file") != std::string::npos);
}

TEST(Graph, DOT) {
s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "./examples/graph_3_vert_simply.txt";
    graph.LoadGraphFromFile(InputFileName);
    std::string outputFile = "output.dot";
    graph.ExportGraphToDot(outputFile);
}

TEST(Graph, CheckFile1) {
s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "./examples/graph_2_vert_char.txt";
    graph.LoadGraphFromFile(InputFileName);
    bool result = graph.checkFile(InputFileName);
    bool expected = false;
    ASSERT_EQ(result, expected);
}
TEST(Graph, CheckFile2) {
s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "./examples/graph_2_vert_dimNE.txt"; // graph_2_vert_R_NE_C //graph_2_vert_simply
    graph.LoadGraphFromFile(InputFileName);
    bool result = graph.checkFile(InputFileName);
    bool expected = false;
    ASSERT_EQ(result, expected);
}
TEST(Graph, CheckFile3) {
s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "./examples/graph_2_vert_R_NE_C.txt"; //  //graph_2_vert_simply
    graph.LoadGraphFromFile(InputFileName);
    bool result = graph.checkFile(InputFileName);
    bool expected = false;
    ASSERT_EQ(result, expected);
}
TEST(Graph, CheckFile4) {
s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "./examples/graph_2_vert_simply.txt"; //  //
    graph.LoadGraphFromFile(InputFileName);
    bool result = graph.checkFile(InputFileName);
    bool expected = false;
    ASSERT_EQ(result, expected);
}
TEST(Graph, CheckFile5) {
s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "DDD:/graph_2_vert_simply.txt"; //  //
    graph.LoadGraphFromFile(InputFileName);
    bool result = graph.checkFile(InputFileName);
    bool expected = false;
    ASSERT_EQ(result, expected);
}

TEST(Graph, CheckFile6) {
s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "./examples/graph_2_DIM_NOT_NUM.txt"; //  //
    graph.LoadGraphFromFile(InputFileName);
    bool result = graph.checkFile(InputFileName);
    bool expected = false;
    ASSERT_EQ(result, expected);
}

TEST(Graph, SizeNotNumber) {
s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
      // Необходимо отловить работу функции контроля правильности данных файла при вызове LoadGraphFromFile
    testing::internal::CaptureStdout();
    std::string InputFileName = "./examples/graph_2_DIM_NOT_NUM.txt";
     graph.LoadGraphFromFile(InputFileName);
     std::string captured_stdout = testing::internal::GetCapturedStdout();
      // Проверка, что сообщение об ошибке выводится в stdout
    EXPECT_TRUE(captured_stdout.find("Error opening file") != std::string::npos);
}

TEST(Graph, DIM_NEGATIVE) {
s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "./examples/graph_3_DIM_LE_ZERO.txt"; 
    bool result = graph.checkFile(InputFileName);
    std::cout << result << " !!!! ";
    bool expected = false;
    ASSERT_EQ(result, expected);
}

TEST(Graph, DIM_NEGATIVE_2) {
s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
      // отловить работу функции контроля правильности данных файла при вызове LoadGraphFromFile
    testing::internal::CaptureStdout();
    std::string InputFileName = "./examples/graph_2_DIM_NOT_NUM.txt";
     graph.LoadGraphFromFile(InputFileName);
     std::string captured_stdout = testing::internal::GetCapturedStdout();
      // Проверка, что сообщение об ошибке выводится в stdout
    EXPECT_TRUE(captured_stdout.find("Dimension must be > 0") != std::string::npos);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int result = RUN_ALL_TESTS();
  free(__cxxabiv1::__cxa_get_globals());
  return result;
}

} // namespace s21
