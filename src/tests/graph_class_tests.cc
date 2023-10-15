#include <gtest/gtest.h>


namespace s21 {
// // std::cout << "Class Graph" << std::endl;
// !!! Добавить тест и пример на не связный граф  где
// - 2 графа полноценных
// - где второй граф только 1 вершина
// - когда все вершина направлены в одну вершину
// - когда 2 вершины и ребра из одного графа направлены во второй граф

// TEST(Graph, getAjacencyMatrix) {
// s21::s21_Graph graph;

//     // Ïîëó÷åíèå ìàòðèöû ñìåæíîñòè èç ãðàôà
//     std::vector<std::vector<int>> adjacencyMatrix =
//     graph.getAdjacencyMatrix(); std::vector<std::vector<int>> expected {{0,
//     1, 1}, {1, 0, 1}, {1, 1, 0}};
//     //  std::vector<int> expected = {0, 1, 3, 4, 2, 5, 6};
//     ASSERT_EQ(adjacencyMatrix, expected);
// }

TEST(GraphAlgorithmsTest, getEdgeList) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_3_vert_simply.txt";
  graph.LoadGraphFromFile(InputFileName);
  std::vector<std::pair<int, int>> GetedgesList = graph.getEdgesList();
  std::vector<std::pair<int, int>> expected{{1, 2}, {1, 3}, {2, 1},
                                            {2, 3}, {3, 1}, {3, 2}};
  ASSERT_EQ(GetedgesList, expected);
}

TEST(GraphAlgorithmsTest, errorOpeningFile) {  // !!! Возможно тест работает неккоректно
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_155_vert_simply.txt";
  EXPECT_ANY_THROW(graph.LoadGraphFromFile(InputFileName));
}

TEST(GraphAlgorithmsTest, DOT) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_3_vert_simply.txt";
  graph.LoadGraphFromFile(InputFileName);
  std::string outputFile = "output.dot";
  graph.ExportGraphToDot(outputFile);
}

TEST(GraphAlgorithmsTest, Graph_DOTerror_Test) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_3_vert_simply.txt";
  // graph.LoadGraphFromFile(InputFileName);
  std::string outputFile = "output1.dot";
  graph.ExportGraphToDot(outputFile);
}

// TEST(Graph, getAjacencyMatrix) {
// s21::s21_Graph graph;

//     // Ïîëó÷åíèå ìàòðèöû ñìåæíîñòè èç ãðàôà
//     std::vector<std::vector<int>> adjacencyMatrix =
//     graph.getAdjacencyMatrix(); std::vector<std::vector<int>> expected {{0,
//     1, 1}, {1, 0, 1}, {1, 1, 0}};
//     //  std::vector<int> expected = {0, 1, 3, 4, 2, 5, 6};
//     ASSERT_EQ(adjacencyMatrix, expected);
// }

TEST(GraphAlgorithmsTest, ExportGraphToDot_ErrorOpeningFile) {
  // Создание объекта графа
  s21::s21_Graph graph;

  // Вызов метода ExportGraphToDot с несуществующим именем файла
  testing::internal::CaptureStdout();
  graph.ExportGraphToDot("DD:/nonexistent_file.dot");
  std::string captured_stdout = testing::internal::GetCapturedStdout();

  // Проверка, что сообщение об ошибке выводится в stdout
  EXPECT_TRUE(captured_stdout.find("Error opening file") != std::string::npos);
}

// TEST(Graph, Graph_DOTerror_Test) {
// s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/graph_3_vert_simply.txt";
//     // graph.LoadGraphFromFile(InputFileName);
//     std::string outputFile = "output1.dot";
//     graph.ExportGraphToDot(outputFile);
// }

// TEST(GraphAlgorithmsTest, CheckFile1) {
//   s21::s21_Graph graph;
//   s21::GraphAlgorithms algo;
//    std::string InputFileName = "./examples/graph_2_DIM_NOT_NUM.txt";
//   // std::string InputFileName = "./examples/graph_2_vert_char.txt"; //
//   // graph.LoadGraphFromFile(InputFileName);
//   // bool result = graph.CheckFile(InputFileName);
//   // bool expected = false;
//   // ASSERT_EQ(result, expected);
//   ASSERT_ANY_THROW(graph.CheckFile(InputFileName););
// }

// TEST(Graph, CheckFile2) {
// s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/graph_2_vert_dimNE.txt"; //
//     //graph_2_vert_R_NE_C //graph_2_vert_simply
//     graph.LoadGraphFromFile(InputFileName);
//     bool result = graph.CheckFile(InputFileName);
//     bool expected = false;
//     ASSERT_EQ(result, expected);
// }

// TEST(Graph, CheckFile3) {
// s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/graph_2_vert_R_NE_C.txt"; //
//     //graph_2_vert_simply graph.LoadGraphFromFile(InputFileName); 
//     bool result = graph.CheckFile(InputFileName); bool expected = false;
//     ASSERT_EQ(result, expected);
// }

// TEST(Graph, CheckFile4) {
// s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/graph_2_vert_simply.txt"; //  //
//     graph.LoadGraphFromFile(InputFileName);
//     bool result = graph.CheckFile(InputFileName);
//     bool expected = false;
//     ASSERT_EQ(result, expected);
// }

TEST(Graph, CheckFile5) {
s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "DDD:/graph_2_vert_simply.txt"; //  //
    // graph.LoadGraphFromFile(InputFileName);
    // bool result = graph.CheckFile(InputFileName);
    // bool expected = false;
    // ASSERT_EQ(result, expected);
    ASSERT_ANY_THROW(graph.LoadGraphFromFile(InputFileName););
}

TEST(Graph, CheckFile6) {
s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "./examples/graph_2_DIM_NOT_NUM.txt"; //  //
    // graph.LoadGraphFromFile(InputFileName);
    // bool result = graph.CheckFile(InputFileName);
    // bool expected = false;
    // ASSERT_EQ(result, expected);
    // ASSERT_ANY_THROW( graph.LoadGraphFromFile(InputFileName));
 ASSERT_ANY_THROW(graph.CheckFile(InputFileName));
}

TEST(Graph, CheckFile10) {
  s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "./examples/graph_13_vert_simply.txt"; //  //
    graph.LoadGraphFromFile(InputFileName);
    bool result = graph.IsGraphConnected(graph, InputFileName);
    bool expected = true;
    ASSERT_EQ(result, expected);
    // ASSERT_ANY_THROW( graph.LoadGraphFromFile(InputFileName));
  // ASSERT_ANY_THROW(graph.IsGraphConnected(InputFileName));
}

// TEST(GraphAlgorithmsTest, SizeNotNumber) {
//   s21::s21_Graph graph;
//   s21::GraphAlgorithms algo;
//   // Необходимо отловить работу функции контроля правильности данных файла при
//   // вызове LoadGraphFromFile
//   // testing::internal::CaptureStdout();
//   std::string InputFileName = "./examples/graph_2_DIM_NOT_NUM.txt";
//   // graph.LoadGraphFromFile(InputFileName);
//   // std::string captured_stdout = testing::internal::GetCapturedStdout();
//   // Проверка, что сообщение об ошибке выводится в stdout
//   // EXPECT_TRUE(captured_stdout.find("Error opening file") != std::string::npos);
//   ASSERT_ANY_THROW(graph.LoadGraphFromFile(InputFileName));
// }



TEST(Graph, DIM_NEGATIVE) {
s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "./examples/graph_2_DIM_NOT_NUM.txt";
    // bool result = graph.CheckFile(InputFileName);
    // bool expected = false;
    // ASSERT_EQ(result, expected);
    ASSERT_ANY_THROW(graph.CheckFile(InputFileName));
}

TEST(Graph, DIM_NEGATIVE_2) {
s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
    // отловить работу функции контроля правильности данных файла при вызове
    // testing::internal::CaptureStdout(); 
    std::string InputFileName = "./examples/graph_3_DIM_LE_ZERO.txt";
    // graph.LoadGraphFromFile(InputFileName);
    // std::string captured_stdout = testing::internal::GetCapturedStdout();
    // // Проверка, что сообщение об ошибке выводится в stdout
    // EXPECT_TRUE(captured_stdout.find("Dimension must be > 0") !=
    // std::string::npos);
    ASSERT_ANY_THROW(graph.LoadGraphFromFile(InputFileName));
}

TEST(Graph, FILE_EMPTY) {
s21::s21_Graph graph;
    s21::GraphAlgorithms algo;
    std::string InputFileName = "./examples/graph_2__empty.txt";
    // bool result = graph.CheckFile(InputFileName);
    // bool expected = false;
    // ASSERT_EQ(result, expected);
    ASSERT_ANY_THROW(graph.CheckFile(InputFileName));
}

    TEST(Graph, Graph_connectivity) {
    s21::s21_Graph graph;
        s21::GraphAlgorithms algo; //graph_4_vert_simply
        //  std::string InputFileName = "./examples/graph_5_vert_simply.txt";
        std::string InputFileName = "./examples/unconnected_graph_5_vert.txt"; // graph_2_vert_R_NE_C //graph_2_vert_simply
        
        //  std::string InputFileName = "./examples/weighted_directed_graph_8_vert.txt";
        graph.LoadGraphFromFile(InputFileName);
        bool result = graph.IsGraphConnected(graph, InputFileName);
        // bool result = graph.CheckFile(InputFileName);
        bool expected = false;
    
        ASSERT_EQ(result, expected);
        // EXPECT_THROW(graph.LoadGraphFromFile(InputFileName), std::invalid_argument); 
    }

        TEST(Graph, Graph_connectivity_2) {
        s21::s21_Graph graph;
        s21::GraphAlgorithms algo; //graph_4_vert_simply
        //  std::string InputFileName = "./examples/graph_5_vert_simply.txt";
        // std::string InputFileName = "./examples/unconnected_graph_5_vert.txt"; // graph_2_vert_R_NE_C //graph_2_vert_simply
        
         std::string InputFileName = "./examples/weighted_directed_graph_8_vert.txt";
        graph.LoadGraphFromFile(InputFileName);
        bool result = graph.IsGraphConnected(graph, InputFileName);
        // bool result = graph.CheckFile(InputFileName);
        bool expected = true;
    
        ASSERT_EQ(result, expected);
        // EXPECT_THROW(graph.LoadGraphFromFile(InputFileName), std::invalid_argument); 
    }
        TEST(Graph, Graph_connectivity_3) {
    s21::s21_Graph graph;
        s21::GraphAlgorithms algo; //graph_4_vert_simply
         std::string InputFileName = "./examples/graph_5_vert_simply.txt";
        // std::string InputFileName = "./examples/unconnected_graph_5_vert.txt"; // graph_2_vert_R_NE_C //graph_2_vert_simply
        
        //  std::string InputFileName = "./examples/weighted_directed_graph_8_vert.txt";
        graph.LoadGraphFromFile(InputFileName);
        bool result = graph.IsGraphConnected(graph, InputFileName);
        // bool result = graph.CheckFile(InputFileName);
        bool expected = true;
        ASSERT_EQ(result, expected);
        // EXPECT_THROW(graph.LoadGraphFromFile(InputFileName), std::invalid_argument); 
    }



} // namespace s21