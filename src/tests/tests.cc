#include <gtest/gtest.h>

#include "../s21_algorithms/s21_graph_algorithms.cc"
#include "../s21_graph/s21_graph.cc"
// !!! Закинуть ссылку на сайт с алгоритмами

namespace s21 {

// // std::cout << "Class Graph" << std::endl;
// !!! Добавить тест и пример на не связный граф  где
// - 2 графа полноценных  не связный
// - где второй граф только 1 вершина
// - когда все вершина направлены в одну вершину
// - когда 1 вершины и 2 ребра из одной вершины направлены во вторую

// TEST(Graph, getAjacencyMatrix) {
// s21::s21_Graph graph;

//     // Ïîëó÷åíèå ìàòðèöû ñìåæíîñòè èç ãðàôà
//     std::vector<std::vector<int>> adjacencyMatrix =
//     graph.getAdjacencyMatrix(); std::vector<std::vector<int>> expected {{0,
//     1, 1}, {1, 0, 1}, {1, 1, 0}};
//     //  std::vector<int> expected = {0, 1, 3, 4, 2, 5, 6};
//     ASSERT_EQ(adjacencyMatrix, expected);
// }

TEST(Graph, getEdgeList) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_3_vert_simply.txt";
  graph.LoadGraphFromFile(InputFileName);
  std::vector<std::pair<int, int>> GetedgesList = graph.getEdgesList();
  std::vector<std::pair<int, int>> expected{{1, 2}, {1, 3}, {2, 1},
                                            {2, 3}, {3, 1}, {3, 2}};
  ASSERT_EQ(GetedgesList, expected);
}

TEST(Graph, errorOpeningFile) {  // !!! Возможно тест работает неккоректно
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_155_vert_simply.txt";
  graph.LoadGraphFromFile(InputFileName);
}

TEST(Graph, DOT) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_3_vert_simply.txt";
  graph.LoadGraphFromFile(InputFileName);
  std::string outputFile = "output.dot";
  graph.ExportGraphToDot(outputFile);
}

TEST(Graph, Graph_DOTerror_Test) {
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

// TEST(Graph, Graph_DOTerror_Test) {
// s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/graph_3_vert_simply.txt";
//     // graph.LoadGraphFromFile(InputFileName);
//     std::string outputFile = "output1.dot";
//     graph.ExportGraphToDot(outputFile);
// }

TEST(Graph, CheckFile1) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_2_vert_char.txt";
  graph.LoadGraphFromFile(InputFileName);
  bool result = graph.checkFile(InputFileName);
  bool expected = false;
  ASSERT_EQ(result, expected);
}

// TEST(Graph, CheckFile2) {
// s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/graph_2_vert_dimNE.txt"; //
//     graph_2_vert_R_NE_C //graph_2_vert_simply
//     graph.LoadGraphFromFile(InputFileName);
//     bool result = graph.checkFile(InputFileName);
//     bool expected = false;
//     ASSERT_EQ(result, expected);
// }

// TEST(Graph, CheckFile3) {
// s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/graph_2_vert_R_NE_C.txt"; //
//     //graph_2_vert_simply graph.LoadGraphFromFile(InputFileName); bool result
//     = graph.checkFile(InputFileName); bool expected = false;
//     ASSERT_EQ(result, expected);
// }

// TEST(Graph, CheckFile4) {
// s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/graph_2_vert_simply.txt"; //  //
//     graph.LoadGraphFromFile(InputFileName);
//     bool result = graph.checkFile(InputFileName);
//     bool expected = false;
//     ASSERT_EQ(result, expected);
// }

// TEST(Graph, CheckFile5) {
// s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "DDD:/graph_2_vert_simply.txt"; //  //
//     graph.LoadGraphFromFile(InputFileName);
//     bool result = graph.checkFile(InputFileName);
//     bool expected = false;
//     ASSERT_EQ(result, expected);
// }

// TEST(Graph, CheckFile6) {
// s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/graph_2_DIM_NOT_NUM.txt"; //  //
//     graph.LoadGraphFromFile(InputFileName);
//     bool result = graph.checkFile(InputFileName);
//     bool expected = false;
//     ASSERT_EQ(result, expected);
// }

TEST(Graph, SizeNotNumber) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  // Необходимо отловить работу функции контроля правильности данных файла при
  // вызове LoadGraphFromFile
  testing::internal::CaptureStdout();
  std::string InputFileName = "./examples/graph_2_DIM_NOT_NUM.txt";
  graph.LoadGraphFromFile(InputFileName);
  std::string captured_stdout = testing::internal::GetCapturedStdout();
  // Проверка, что сообщение об ошибке выводится в stdout
  EXPECT_TRUE(captured_stdout.find("Error opening file") != std::string::npos);
}

// TEST(Graph, DIM_NEGATIVE) {
// s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/graph_3_DIM_LE_ZERO.txt";
//     bool result = graph.checkFile(InputFileName);
//     std::cout << result << " !!!! ";
//     bool expected = false;
//     ASSERT_EQ(result, expected);
// }

// TEST(Graph, DIM_NEGATIVE_2) {
// s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     // отловить работу функции контроля правильности данных файла при вызове
//     LoadGraphFromFile testing::internal::CaptureStdout(); std::string
//     InputFileName = "./examples/graph_2_DIM_NOT_NUM.txt";
//     graph.LoadGraphFromFile(InputFileName);
//     std::string captured_stdout = testing::internal::GetCapturedStdout();
//     // Проверка, что сообщение об ошибке выводится в stdout
//     EXPECT_TRUE(captured_stdout.find("Dimension must be > 0") !=
//     std::string::npos);
// }

// // std::cout << "Algorithm Depth First Search" << std::endl;.

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
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }

  start = 2;
  visited_vertices.clear();
  result.clear();
  visited_vertices = algo.DepthFirstSearch(graph, start);
  result = {2, 1, 3};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }

  start = 3;
  visited_vertices.clear();
  result.clear();
  visited_vertices = algo.DepthFirstSearch(graph, start);
  result = {3, 1, 2};
  for (int it = 0; it < result.size(); ++it) {
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

  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }

  start = 9;
  visited_vertices.clear();
  result.clear();
  visited_vertices = algo.DepthFirstSearch(graph, start);
  result = {9, 1, 2, 4, 3, 12, 7, 8, 11, 13, 5, 6, 10};

  for (int it = 0; it < result.size(); ++it) {
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
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }

  start = 6;
  visited_vertices.clear();
  result.clear();
  visited_vertices = algo.DepthFirstSearch(graph, start);
  result = {6, 5, 7, 1, 4, 8, 3, 2};
  for (int it = 0; it < result.size(); ++it) {
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

  result = {1,  2, 12, 17, 11, 19, 18, 20, 14, 13, 16,
            15, 3, 4,  5,  6,  7,  9,  8,  10, 21};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }

  start = 15;
  visited_vertices.clear();
  result.clear();
  visited_vertices = algo.DepthFirstSearch(graph, start);
  result = {15, 3,  4,  5,  6, 11, 19, 18, 17, 14,
            13, 16, 20, 12, 7, 9,  8,  10, 21};
  for (int it = 0; it < result.size(); ++it) {
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
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }
  visited_vertices.clear();
  result.clear();
  start = 4;
  visited_vertices = algo.DepthFirstSearch(graph, start);
  result = {4, 1, 2, 3, 6, 5, 7, 8, 9};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }
  visited_vertices.clear();
  result.clear();
  start = 1;
  visited_vertices = algo.DepthFirstSearch(graph, start);
  result = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (int it = 0; it < result.size(); ++it) {
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
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }
  visited_vertices.clear();
  result.clear();
  start = 2;
  visited_vertices = algo.DepthFirstSearch(graph, start);
  result = {2, 3, 6, 5, 4, 7};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }
  visited_vertices.clear();
  result.clear();
  start = 3;
  visited_vertices = algo.DepthFirstSearch(graph, start);
  result = {3, 6, 5, 4, 7};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }
  visited_vertices.clear();
  result.clear();
  start = 4;
  visited_vertices = algo.DepthFirstSearch(graph, start);
  result = {4, 3, 6, 5, 7};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }
  visited_vertices.clear();
  result.clear();
  start = 5;
  visited_vertices = algo.DepthFirstSearch(graph, start);
  result = {5, 4, 3, 6, 7};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }
  visited_vertices.clear();
  result.clear();
  start = 6;
  visited_vertices = algo.DepthFirstSearch(graph, start);
  result = {6, 5, 4, 3, 7};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }
  visited_vertices.clear();
  result.clear();
  start = 7;
  visited_vertices = algo.DepthFirstSearch(graph, start);
  result = {7, 4, 3, 6, 5};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }
  visited_vertices.clear();
  result.clear();
  start = 8;
  visited_vertices = algo.DepthFirstSearch(graph, start);
  result = {8, 7, 4, 3, 6, 5};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }
}

// // std::cout << "Algorithm Breadth First Search" << std::endl;

TEST(Test, test_th_simple_graph_size_3) {
  s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_3_vert_simply.txt";
  graph.LoadGraphFromFile(InputFileName);
  int start = 1;
  std::vector<int> visited_vertices;
  std::vector<int> result;
  visited_vertices = algo.BreadthFirstSearch(graph, start);
  result = {1, 2, 3};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }

  start = 2;
  visited_vertices.clear();
  result.clear();
  visited_vertices = algo.BreadthFirstSearch(graph, start);
  result = {2, 1, 3};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }

  start = 3;
  visited_vertices.clear();
  result.clear();
  visited_vertices = algo.BreadthFirstSearch(graph, start);
  result = {3, 1, 2};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }

  visited_vertices.clear();
  start = -1;
  ASSERT_ANY_THROW(visited_vertices = algo.BreadthFirstSearch(graph, start));

  visited_vertices.clear();
  start = 0;
  ASSERT_ANY_THROW(visited_vertices = algo.BreadthFirstSearch(graph, start));

  visited_vertices.clear();
  start = 4;
  ASSERT_ANY_THROW(visited_vertices = algo.BreadthFirstSearch(graph, start));
}

TEST(Test, test_th_simple_graph_size_13) {
  s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_13_vert_simply.txt";
  graph.LoadGraphFromFile(InputFileName);

  int start = 1;
  std::vector<int> visited_vertices;
  std::vector<int> result;
  visited_vertices = algo.BreadthFirstSearch(graph, start);
  result = {1, 2, 9, 11, 13, 4, 10, 12, 8, 7, 5, 6, 3};

  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }

  start = 9;
  visited_vertices.clear();
  result.clear();
  visited_vertices = algo.BreadthFirstSearch(graph, start);
  result = {9, 1, 8, 13, 2, 11, 7, 5, 6, 10, 12, 4, 3};

  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }

  visited_vertices.clear();
  start = -10;
  ASSERT_ANY_THROW(visited_vertices = algo.BreadthFirstSearch(graph, start));

  visited_vertices.clear();
  start = 7777;
  ASSERT_ANY_THROW(visited_vertices = algo.BreadthFirstSearch(graph, start));
}

TEST(Test, test_th_directed_graph_8_vert) {
  s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_8_vert_direct.txt";
  graph.LoadGraphFromFile(InputFileName);
  int start = 2;
  std::vector<int> visited_vertices;
  std::vector<int> result;
  visited_vertices = algo.BreadthFirstSearch(graph, start);

  result = {2, 3, 1, 4, 6, 5, 8, 7};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }

  start = 6;
  visited_vertices.clear();
  result.clear();
  visited_vertices = algo.BreadthFirstSearch(graph, start);
  algo.PrintResultOfDepthFirstSearch(visited_vertices);
  result = {6, 5, 7, 1, 2, 4, 3, 8};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }
}

TEST(Test, test_th_directed_graph_21_vert) {
  s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_21_vert_direct.txt";
  graph.LoadGraphFromFile(InputFileName);

  int start = 1;
  std::vector<int> visited_vertices;
  std::vector<int> result;
  visited_vertices = algo.BreadthFirstSearch(graph, start);
  algo.PrintResultOfDepthFirstSearch(visited_vertices);
  result = {1,  2,  13, 12, 15, 16, 17, 3, 11, 14, 4,
            10, 19, 20, 5,  7,  21, 18, 6, 9,  8};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }

  start = 14;
  visited_vertices.clear();
  result.clear();
  visited_vertices = algo.BreadthFirstSearch(graph, start);
  algo.PrintResultOfDepthFirstSearch(visited_vertices);
  result = {14, 13, 16, 15, 3,  4, 10, 5,  7, 11,
            21, 6,  9,  19, 20, 8, 18, 12, 17};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }

  visited_vertices.clear();
  result.clear();
}

TEST(Test, test_BreadthFirstSearch_weighted_graph_9_vert) {
  s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/weighted_graph_9_vert.txt";
  graph.LoadGraphFromFile(InputFileName);

  int start = 9;
  std::vector<int> visited_vertices;
  std::vector<int> result;
  visited_vertices = algo.BreadthFirstSearch(graph, start);
  result = {9, 1, 4, 7, 8, 2, 3, 5, 6};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }
  visited_vertices.clear();
  result.clear();
  start = 4;
  visited_vertices = algo.BreadthFirstSearch(graph, start);
  result = {4, 1, 3, 5, 9, 2, 7, 8, 6};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }
  visited_vertices.clear();
  result.clear();

  start = 1;
  visited_vertices = algo.BreadthFirstSearch(graph, start);
  result = {1, 2, 4, 7, 8, 9, 3, 5, 6};
  for (int it = 0; it < result.size(); ++it) {
    ASSERT_EQ(visited_vertices[it], result[it]);
  }
}

TEST(GraphAlgorithmsTest, ShortestPathCase1) {
  s21::s21_Graph graph(5);
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_5_for_dijkstra.txt";
  graph.LoadGraphFromFile(InputFileName);

  int shortestDistance = algo.GetShortestPathBetweenVertices(graph, 1, 4);
  EXPECT_EQ(shortestDistance, 14);
}

TEST(GraphAlgorithmsTest, ShortestPathCase2) {
  s21::s21_Graph graph(5);
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_5_for_dijkstra.txt";
  graph.LoadGraphFromFile(InputFileName);

  int shortestDistance = algo.GetShortestPathBetweenVertices(graph, 1, 3);
  EXPECT_EQ(shortestDistance, 10);
}

TEST(GraphAlgorithmsTest, ShortestPathCase3) {
  s21::s21_Graph graph(5);
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_4_for_dijkstra.txt";
  graph.LoadGraphFromFile(InputFileName);

  int shortestDistance = algo.GetShortestPathBetweenVertices(graph, 1, 3);
  EXPECT_EQ(shortestDistance, 8);
}

TEST(GraphAlgorithmsTest, ShortestPathCase4) {
  s21::s21_Graph graph(4);
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_4_for_dijkstra.txt";
  graph.LoadGraphFromFile(InputFileName);

  int shortestDistance = algo.GetShortestPathBetweenVertices(graph, 4, 2);
  EXPECT_EQ(shortestDistance, 2);
}

TEST(GraphAlgorithmsTest, InvalidVertices) {
  s21::s21_Graph graph(5);
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_5_for_dijkstra.txt";
  graph.LoadGraphFromFile(InputFileName);

  EXPECT_THROW(algo.GetShortestPathBetweenVertices(graph, 1, 6),
               std::invalid_argument);
}

TEST(GraphAlgorithmsTest, InvalidVertices1) {
  s21::s21_Graph graph(5);
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_5_for_dijkstra.txt";
  graph.LoadGraphFromFile(InputFileName);

  EXPECT_THROW(algo.GetShortestPathBetweenVertices(graph, 0, 4),
               std::invalid_argument);
}

// 0, 3, 5, 0, 0,
// 3, 0, 3, 5, 3,
// 5, 3, 0, 2, 0,
// 0, 5, 2, 0, 7,
// 0, 3, 0, 7, 0,

TEST(Test, test_GetLeastSpanningTree_1) {
  s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/weighted_graph_7_vert.txt";
  graph.LoadGraphFromFile(InputFileName);
  std::vector<std::vector<int>> spanning_tree =
      algo.GetLeastSpanningTree(graph);
  std::vector<std::vector<int>> result{
      {0, 7, 0, 5, 0, 0, 0}, {7, 0, 0, 0, 7, 0, 0}, {0, 0, 0, 0, 5, 0, 0},
      {5, 0, 0, 0, 0, 6, 0}, {0, 7, 5, 0, 0, 0, 9}, {0, 0, 0, 6, 0, 0, 0},
      {0, 0, 0, 0, 9, 0, 0}};
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result.size(); ++j) {
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
  std::vector<std::vector<int>> spanning_tree =
      algo.GetLeastSpanningTree(graph);
  std::vector<std::vector<int>> result{
      {0, 7, 0, 5, 0, 0, 0}, {7, 0, 0, 0, 7, 0, 0}, {0, 0, 0, 0, 5, 0, 0},
      {5, 0, 0, 0, 0, 6, 0}, {0, 7, 5, 0, 0, 0, 9}, {0, 0, 0, 6, 0, 0, 0},
      {0, 0, 0, 0, 9, 0, 0}};
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result.size(); ++j) {
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
//     std::vector<std::vector<int>> spanning_tree =
//     algo.GetLeastSpanningTree(graph);
// }

TEST(Test, test_GetLeastSpanningTree_3_simple_graph) {
  s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_5_vert_simply.txt";
  graph.LoadGraphFromFile(InputFileName);
  std::vector<std::vector<int>> spanning_tree =
      algo.GetLeastSpanningTree(graph);
  std::vector<std::vector<int>> result{{0, 1, 1, 1, 0},
                                       {1, 0, 0, 0, 0},
                                       {1, 0, 0, 0, 0},
                                       {1, 0, 0, 0, 1},
                                       {0, 0, 0, 1, 0}};

  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result.size(); ++j) {
      ASSERT_EQ(spanning_tree[i][j], result[i][j]);
    }

    int weight = algo.GetSpanningTreeWeigt(spanning_tree);
    ASSERT_EQ(weight, 4);
  }
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
}  // namespace s21
