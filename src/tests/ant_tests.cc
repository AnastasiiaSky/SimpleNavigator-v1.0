#include <gtest/gtest.h>

namespace s21 {
  TEST(Test, FloidWarshall_weighted_graph_with_loops) {
  s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/weighted_graph_6_vert_with_loops.txt";
  graph.LoadGraphFromFile(InputFileName);
  std::vector<std::vector<int>> minimum_distance =
      algo.GetShortestPathsBetweenAllVertices(graph);
  std::vector<std::vector<int>> result{
      {0, 5, 12, 9, 16, 21}, {5, 0, 7, 14, 21, 16}, {12, 7, 0, 21, 18, 9},
      {9, 14, 21, 0, 7, 16}, {16, 21, 18, 7, 0, 9}, {21, 16, 9, 16, 9, 0}};

  for (int it = 0; it < minimum_distance.size(); ++it) {
    for (int j = 0; j < minimum_distance.size(); ++j) {
      std::cout << minimum_distance[it][j] << " ";
    }
    std::cout << std::endl;
  }
  ASSERT_EQ(minimum_distance, result);
  // algo.PrintAdjacencyMatrix(minimum_distance);
}

TEST(AntTest, weighted_graph_4_vert_1) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;

  std::string InputFileName = "./examples/weighted_graph_4_vert.txt";
  graph.LoadGraphFromFile(InputFileName);
  int distance = 10;
  TsmResult result_struct = algo.SolveTravelingSalesmanProblem(graph);
  const int size = graph.get_graph_size();
  std::vector<int> previer_path{1, 2, 4, 3, 1};

  ASSERT_EQ(12, result_struct.distance);
  // algo.PrintResultOfDepthFirstSearch(result_struct.path);
  // ASSERT_EQ(1, result_struct.path.front());
}

// TEST(AntTest, weighted_graph_11_vert) {
//   s21::s21_Graph graph;
//   s21::GraphAlgorithms algo;

//   std::string InputFileName = "./examples/weighted_graph_11_vert.txt";
//   graph.LoadGraphFromFile(InputFileName);
//   int distance = 10;
//   TsmResult result_struct = algo.SolveTravelingSalesmanProblem(graph);
//   const int size = graph.get_graph_size();
//   ASSERT_EQ(true, abs(result_struct.distance - 253) < 10);
//   // algo.PrintResultOfDepthFirstSearch(result_struct.path);
// }

// TEST(AntTest, Vertex_random) {
// s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/graph_3_vert_simply.txt";
//     graph.LoadGraphFromFile(InputFileName);
//     int number = algo.VertexRandom(1, 100);
//     int i = 1;
//     if (number < 100 && number > 0) {
//         i = 0;
//     }
//     ASSERT_EQ(0, i);
// }

// TEST(AntTest, SelectNextVertex) {
//     std::vector<double> probability_list {0.15, 0.35, 0.50};
//     s21::GraphAlgorithms algo;
//     int size = probability_list.size();
//     int vertex = algo.SelectNextVertex(probability_list);
//     // cout << "VERTEX " << vertex << endl;
//     int i = 1;
//     if (vertex <= size && vertex > 0) {
//         i = 0;
//     }
//     ASSERT_EQ(0, i);
// }

// TEST(AntTest, SelectNextVertex_2) {
//     std::vector<double> probability_list {0, 0.15, 0.35, 0, 0.50};
//     s21::GraphAlgorithms algo;
//     int size = probability_list.size();
//     int vertex = algo.SelectNextVertex(probability_list);
//     cout << "VERTEX " << vertex << endl;
//     int i = 1;
//     if (vertex <= size && vertex > 0) {
//         i = 0;
//     }
//     ASSERT_EQ(0, i);
// }

// TEST(AntTest, SelectNextVertex_3) {
//     std::vector<double> probability_list {0, 0.15, 0.35, 0, 0.50, 0, 0, 0};
//     s21::GraphAlgorithms algo;
//     int size = probability_list.size();
//     int vertex = algo.SelectNextVertex(probability_list);
//     cout << "VERTEX " << vertex << endl;
//     int i = 1;
//     if (vertex <= size && vertex > 0) {
//         i = 0;
//     }
//     ASSERT_EQ(0, i);
// }

// // TEST(AntTest, RecalculatePheramoneMatrix) {
// //     s21::s21_Graph graph;
// //     s21::GraphAlgorithms algo;
// //     std::string InputFileName = "./examples/graph_3_vert_simply.txt";
// //     graph.LoadGraphFromFile(InputFileName);
// //     int distance = 10;
// //     const int size = graph.get_graph_size();
// //     std::vector<std::vector<double>> pheramone_matrix(size,
// std::vector<double>(size, 1.0));
// //     std::vector<std::vector<int>> temp_path = graph.getAdjacencyMatrix();
// //     algo.RecalculatePheramoneMatrix(pheramone_matrix, temp_path,
// distance);
// //     for (int i = 0; i < size; i++){
// //         for (int j = 0; j < size; j++){
// //             if (temp_path[i][j] == 1) {
// //             ASSERT_EQ(1.7, pheramone_matrix[i][j]);
// //             } else {
// //             ASSERT_EQ(1, pheramone_matrix[i][j]);
// //             }
// //         }
// //     }
// //     algo.PrintAdjacencyMatrix(pheramone_matrix);
// // }

// TEST(AntTest, CreateProbabilityPath) {
//     s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/graph_3_vert_simply.txt";
//     graph.LoadGraphFromFile(InputFileName);
//     const int size = graph.get_graph_size();
//     int distance = 10;
//     int vertex = 1;
//     std::vector<std::vector<double>> pheramone_matrix(size,
//     std::vector<double>(size, 1.0)); std::vector<std::vector<int>>
//     adjacency_matrix = graph.getAdjacencyMatrix(); std::vector <double>
//     probability_list(size, 0.0);

//     // int size = probability_list.size();
//     int err = algo.CreateProbabilityPath(probability_list, pheramone_matrix,
//     adjacency_matrix, vertex);
//     algo.PrintResultOfDepthFirstSearch(probability_list);

//     for (int j = 1; j < size; j++){
//        ASSERT_EQ(0.5, probability_list[j]);
//     }
//     ASSERT_EQ(probability_list, probability_list);
//     ASSERT_EQ(0, err);
// }

// TEST(AntTest, CreateProbabilityPath_2) {
//     s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName =
//     "./examples/weighted_directed_graph_8_vert.txt";
//     graph.LoadGraphFromFile(InputFileName);
//     const int size = graph.get_graph_size();
//     int distance = 10;
//     int vertex = 4;
//     std::vector<std::vector<double>> pheramone_matrix(size,
//     std::vector<double>(size, 1.0)); std::vector<std::vector<int>>
//     adjacency_matrix = graph.getAdjacencyMatrix(); std::vector <double>
//     probability_list(size, 0.0); std::vector <double> reference_list{0, 0,
//     0.625, 0, 0, 0.375, 0, 0};

//     int err = algo.CreateProbabilityPath(probability_list, pheramone_matrix,
//     adjacency_matrix, vertex);
//     algo.PrintResultOfDepthFirstSearch(probability_list);

//     ASSERT_EQ(probability_list, probability_list);
//     ASSERT_EQ(0, err);
// }

//    TEST(AntTest, CreateProbabilityPath_3) {
//     s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     std::string InputFileName = "./examples/weighted_graph_11_vert.txt";
//     graph.LoadGraphFromFile(InputFileName);
//     const int size = graph.get_graph_size();
//     int distance = 10;
//     int vertex = 11;
//     std::vector<std::vector<double>> pheramone_matrix(size,
//     std::vector<double>(size, 1.0)); std::vector<std::vector<int>>
//     adjacency_matrix = graph.getAdjacencyMatrix(); std::vector <double>
//     probability_list(size, 0.0);
//     // std::vector <double> reference_list{0, 0, 0.625, 0, 0, 0.375, 0, 0};

//     for (int i = 0; i < size; i++){
//       adjacency_matrix[i][vertex - 1] = 0;
//     }
//     vertex = 10;
//     for (int i = 0; i < size; i++){
//       adjacency_matrix[i][vertex - 1] = 0;
//     }

//     vertex = 9;
//     for (int i = 0; i < size; i++){
//       adjacency_matrix[i][vertex - 1] = 0;
//     }

//     int err = algo.CreateProbabilityPath(probability_list, pheramone_matrix,
//     adjacency_matrix, vertex);
//     algo.PrintResultOfDepthFirstSearch(probability_list);

//     // ASSERT_EQ(probability_list, probability_list);
//     // ASSERT_EQ(0, err);
// }

//  TEST(AntTest, CreateProbabilityPath_4) {
//     s21::s21_Graph graph;
//     s21::GraphAlgorithms algo;
//     // std::string InputFileName = "./examples/graph_3_vert_simply.txt";
//     std::string InputFileName = "./examples/weighted_graph_11_vert.txt";
//     graph.LoadGraphFromFile(InputFileName);
//     const int size = graph.get_graph_size();
//     int distance = 10;
//     int vertex = 11;
//     std::vector<std::vector<double>> pheramone_matrix(size,
//     std::vector<double>(size, 1.0)); std::vector<std::vector<int>>
//     adjacency_matrix = graph.getAdjacencyMatrix(); std::vector <double>
//     probability_list(size, 0.0);
//     // std::vector <double> reference_list{0, 0, 0.625, 0, 0, 0.375, 0, 0};

//     for (int i = 0; i < size; i++){
//       adjacency_matrix[i][vertex - 1] = 0;
//     }
//     // algo.PrintAdjacencyMatrix(adjacency_matrix);
//     // cout << "R "  << endl;
//     algo.CreateProbabilityPath(probability_list, pheramone_matrix,
//     adjacency_matrix, vertex);
//     algo.PrintResultOfDepthFirstSearch(probability_list);
//     vertex = algo.SelectNextVertex(probability_list);

//     // cout << "VERTEX " << vertex << endl;

//     for (int i = 0; i < size; i++){
//       adjacency_matrix[i][vertex - 1] = 0;
//     }
//     // cout << "R2 "  << endl;
//     // algo.PrintAdjacencyMatrix(adjacency_matrix);
//     std::vector <double> probability_list2(size, 0.0);
//     // cout << "R3 "  << endl;
//     algo.CreateProbabilityPath(probability_list2, pheramone_matrix,
//     adjacency_matrix, vertex);
//     algo.PrintResultOfDepthFirstSearch(probability_list2);
//     vertex = algo.SelectNextVertex(probability_list2);

//     cout << "VERTEX " << vertex << endl;
//     for (int i = 0; i < size; i++){
//       adjacency_matrix[i][vertex - 1] = 0;
//     }
//     // algo.PrintAdjacencyMatrix(adjacency_matrix);

//     // ASSERT_EQ(probability_list, probability_list);
//     // ASSERT_EQ(0, err);
// }

}  // namespace s21