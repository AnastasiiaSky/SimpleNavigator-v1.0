#include <gtest/gtest.h>

namespace s21 {

TEST(Test, FloidWarshall_weighted_directed_graph_4_vert) {
  s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/weighted_directed_graph_4_vert.txt";
  graph.LoadGraphFromFile(InputFileName);
  std::vector<std::vector<int>> minimum_distance =
      algo.GetShortestPathsBetweenAllVertices(graph);
  std::vector<std::vector<int>> result{
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
  std::vector<std::vector<int>> minimum_distance =
      algo.GetShortestPathsBetweenAllVertices(graph);
  std::vector<std::vector<int>> result{{0, 4, 6}, {0, 0, 3}, {0, 0, 0}};
  ASSERT_EQ(minimum_distance, result);
}

TEST(GraphAlgorithmsTest, FloidWarshall_weighted_directed_graph_8_vert) {
  s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/weighted_directed_graph_8_vert.txt";
  graph.LoadGraphFromFile(InputFileName);
  std::vector<std::vector<int>> minimum_distance =
      algo.GetShortestPathsBetweenAllVertices(graph);
  std::vector<std::vector<int>> result{
      {0, 3, 6, 13, 16, 13, 6, 3}, {0, 0, 3, 16, 13, 10, 13, 0},
      {0, 0, 0, 13, 10, 7, 10, 0}, {0, 0, 3, 0, 8, 5, 8, 0},
      {0, 0, 6, 3, 0, 8, 11, 0},   {0, 0, 9, 6, 3, 0, 3, 0},
      {0, 0, 10, 7, 15, 12, 0, 0}, {0, 0, 13, 10, 18, 15, 3, 0}};
  ASSERT_EQ(minimum_distance, result);
}

TEST(GraphAlgorithmsTest, FloidWarshall_graph_21_vert_direct) {
  s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_21_vert_direct.txt";
  graph.LoadGraphFromFile(InputFileName);
  std::vector<std::vector<int>> minimum_distance =
      algo.GetShortestPathsBetweenAllVertices(graph);
  std::vector<std::vector<int>> result{
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
      {0, 0, 3, 4, 5, 6, 5, 2, 1, 2, 3, 5, 8, 7, 10, 9, 6, 5, 4, 4, 0}};
  ASSERT_EQ(minimum_distance, result);
}

TEST(GraphAlgorithmsTest, FloidWarshall_very_big_graph) {
  s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/very_big_graph.txt";
  graph.LoadGraphFromFile(InputFileName);
  std::vector<std::vector<int>> minimum_distance =
      algo.GetShortestPathsBetweenAllVertices(graph);
  std::vector<std::vector<int>> result{
      {0,  14, 10, 14, 10, 20, 27, 30, 44, 45, 31, 43, 65, 20, 36, 20, 30,
       70, 54, 52, 69, 85, 57, 49, 72, 50, 40, 66, 90, 82, 67, 58, 40, 44,
       25, 72, 88, 84, 83, 76, 95, 88, 81, 63, 36, 26, 15, 30, 22, 28},
      {14, 0,  24, 28, 24, 20, 13, 30, 30, 31, 17, 29, 51, 6,  22, 7,  16,
       56, 40, 38, 55, 71, 43, 35, 58, 41, 26, 52, 76, 68, 53, 58, 40, 44,
       39, 72, 74, 70, 69, 62, 81, 74, 67, 54, 27, 17, 28, 44, 36, 42},
      {10, 24, 0,  6,  10, 20, 27,  30, 44, 45, 41, 53,  65, 30, 36, 30, 40,
       80, 64, 62, 79, 95, 67, 59,  82, 60, 50, 76, 100, 82, 67, 58, 40, 44,
       25, 72, 98, 84, 83, 86, 105, 98, 91, 73, 46, 36,  25, 32, 12, 20},
      {14, 28, 6,  0,  4,  14, 21,  24, 38, 39, 39, 51, 59, 28, 30, 34, 38,
       78, 62, 60, 77, 93, 65, 57,  80, 64, 48, 74, 98, 76, 61, 52, 34, 38,
       19, 66, 96, 78, 77, 84, 103, 96, 89, 77, 50, 40, 29, 38, 11, 14},
      {10, 24, 10, 4,  0,  10, 17, 20, 34, 35, 35, 47, 55, 24, 26, 30, 34,
       74, 58, 56, 73, 89, 61, 53, 76, 60, 44, 70, 94, 72, 57, 48, 30, 34,
       15, 62, 92, 74, 73, 80, 99, 92, 85, 73, 46, 36, 25, 40, 15, 18},
      {20, 20, 20, 14, 10, 0,  7,  10, 24, 25, 25, 37, 45, 14, 16, 27, 24,
       64, 48, 46, 63, 79, 51, 43, 66, 54, 34, 60, 84, 62, 47, 38, 20, 24,
       25, 52, 82, 64, 63, 70, 89, 82, 75, 65, 47, 37, 35, 50, 25, 28},
      {27, 13, 27, 21, 17, 7,  0,  17, 17, 18, 18, 30, 38, 7,  9,  20, 17,
       57, 41, 39, 56, 72, 44, 36, 59, 47, 27, 53, 77, 55, 40, 45, 27, 31,
       32, 59, 75, 57, 56, 63, 82, 75, 68, 58, 40, 30, 41, 57, 32, 35},
      {30, 30, 30, 24, 20, 10, 17, 0,  22, 15, 35, 43, 43, 24, 24, 37, 34,
       70, 58, 52, 65, 81, 61, 53, 76, 64, 44, 70, 87, 60, 37, 28, 10, 14,
       27, 42, 84, 54, 53, 80, 99, 92, 85, 75, 57, 47, 45, 60, 35, 38},
      {44, 30, 44, 38, 34, 24, 17, 22, 0,  7,  19, 21, 21, 24, 8,  37, 32,
       48, 42, 30, 43, 59, 59, 37, 61, 52, 28, 56, 65, 38, 29, 44, 26, 36,
       49, 58, 62, 46, 45, 63, 85, 77, 70, 59, 57, 47, 58, 74, 49, 52},
      {45, 31, 45, 39, 35, 25, 18, 15, 7,  0,  23, 28, 28, 25, 9,  38, 35,
       55, 46, 37, 50, 66, 62, 41, 65, 56, 32, 60, 72, 45, 22, 37, 19, 29,
       42, 51, 69, 39, 38, 70, 89, 81, 74, 63, 58, 48, 59, 75, 50, 53},
      {31, 17, 41, 39, 35, 25, 18, 35, 19, 23, 0,  12, 40, 11, 14, 23, 13,
       39, 23, 21, 38, 54, 40, 18, 42, 33, 9,  37, 60, 55, 45, 60, 42, 49,
       50, 74, 57, 62, 61, 54, 66, 58, 51, 40, 43, 33, 44, 61, 50, 53},
      {43, 29, 53, 51, 47, 37, 30, 43, 21, 28, 12, 0,  42, 23, 26, 35, 25,
       27, 35, 9,  26, 42, 47, 30, 54, 45, 21, 49, 48, 43, 50, 65, 47, 57,
       62, 79, 45, 52, 66, 42, 78, 70, 63, 52, 55, 45, 56, 73, 62, 65},
      {65, 51, 65, 59, 55, 45, 38,  43, 21, 28, 40, 42, 0,  45, 29, 58, 53,
       58, 63, 40, 22, 38, 77, 58,  82, 73, 49, 77, 44, 17, 40, 65, 47, 57,
       70, 79, 41, 26, 41, 63, 100, 98, 91, 80, 78, 68, 79, 95, 70, 73},
      {20, 6,  30, 28, 24, 14, 7,  24, 24, 25, 11, 23, 45, 0,  16, 13, 10,
       50, 34, 32, 49, 65, 37, 29, 52, 40, 20, 46, 70, 62, 47, 52, 34, 38,
       39, 66, 68, 64, 63, 56, 75, 68, 61, 51, 33, 23, 34, 50, 39, 42},
      {36, 22, 36, 30, 26, 16, 9,  24, 8,  9,  14, 26, 29, 16, 0,  29, 26,
       53, 37, 35, 51, 67, 53, 32, 56, 47, 23, 51, 73, 46, 31, 46, 28, 38,
       41, 60, 70, 48, 47, 68, 80, 72, 65, 54, 49, 39, 50, 66, 41, 44},
      {20, 7,  30, 34, 30, 27, 20, 37, 37, 38, 23, 35, 58, 13, 29, 0,  10,
       57, 36, 40, 58, 74, 37, 31, 52, 34, 22, 46, 70, 75, 60, 65, 47, 51,
       45, 79, 77, 77, 76, 56, 75, 68, 61, 47, 20, 10, 21, 50, 42, 48},
      {30, 16, 40, 38, 34, 24, 17, 34, 32, 35, 13, 25, 53, 10, 26, 10, 0,
       47, 36, 30, 48, 64, 27, 31, 42, 30, 22, 36, 60, 65, 57, 62, 44, 48,
       49, 76, 67, 74, 73, 46, 65, 58, 51, 47, 30, 20, 31, 60, 49, 52},
      {70, 56,  80, 78, 74, 64, 57, 70, 48, 55, 39, 27, 58, 50,  53, 57, 47,
       0,  54,  18, 36, 44, 20, 48, 35, 64, 48, 29, 53, 53, 76,  92, 74, 84,
       89, 106, 55, 62, 77, 39, 58, 51, 44, 71, 77, 67, 78, 100, 89, 92},
      {54, 40, 64, 62, 58, 48, 41, 58, 42, 46, 23, 35, 63, 34, 37, 36, 36,
       54, 0,  44, 61, 77, 34, 22, 19, 10, 14, 25, 67, 78, 68, 83, 65, 72,
       73, 97, 80, 85, 84, 53, 43, 35, 28, 17, 24, 34, 45, 82, 73, 76},
      {52, 38, 62, 60, 56, 46, 39, 52, 30, 37, 21, 9,  40, 32, 35, 40, 30,
       18, 44, 0,  18, 34, 38, 39, 53, 54, 30, 47, 40, 35, 58, 74, 56, 66,
       71, 88, 37, 44, 59, 33, 70, 69, 62, 61, 60, 50, 61, 82, 71, 74},
      {69, 55, 79, 77, 73, 63, 56, 65, 43, 50, 38, 26, 22, 49, 51, 58, 48,
       36, 61, 18, 0,  16, 55, 56, 70, 71, 47, 64, 22, 17, 40, 75, 69, 79,
       88, 89, 19, 26, 41, 41, 78, 86, 79, 78, 78, 68, 79, 99, 88, 91},
      {85,  71,  95, 93, 89, 79, 72, 81, 59, 66, 54, 42, 38, 65,  67,  74, 64,
       44,  77,  34, 16, 0,  64, 72, 79, 87, 63, 73, 38, 33, 56,  91,  85, 95,
       104, 105, 35, 42, 57, 57, 94, 95, 88, 94, 94, 84, 95, 115, 104, 107},
      {57, 43,  67, 65, 61, 51, 44, 61, 59, 62, 40, 47, 77, 37, 53, 37, 27,
       20, 34,  38, 55, 64, 0,  28, 15, 44, 37, 9,  33, 72, 84, 89, 71, 75,
       76, 103, 55, 81, 96, 19, 38, 31, 24, 51, 57, 47, 58, 87, 76, 79},
      {49, 35, 59, 57, 53, 43, 36, 53, 37, 41, 18, 30, 58, 29, 32, 31, 31,
       48, 22, 39, 56, 72, 28, 0,  25, 32, 9,  19, 61, 73, 63, 78, 60, 67,
       68, 92, 75, 80, 79, 47, 49, 41, 34, 39, 46, 41, 52, 79, 68, 71},
      {72, 58,  82, 80, 76,  66, 59, 76, 61, 65, 42, 54, 82, 52,  56,  52, 42,
       35, 19,  53, 70, 79,  15, 25, 0,  29, 33, 6,  48, 87, 87,  102, 84, 90,
       91, 116, 70, 96, 103, 34, 24, 16, 9,  36, 43, 53, 64, 101, 91,  94},
      {50, 41,  60, 64, 60, 54, 47, 64, 52, 56, 33, 45, 73, 40, 47, 34, 30,
       64, 10,  54, 71, 87, 44, 32, 29, 0,  24, 35, 77, 88, 78, 92, 74, 78,
       75, 106, 90, 95, 94, 63, 53, 45, 38, 17, 14, 24, 35, 72, 72, 78},
      {40, 26, 50, 48, 44, 34, 27, 44, 28, 32, 9,  21, 49, 20, 23, 22, 22,
       48, 14, 30, 47, 63, 37, 9,  33, 24, 0,  28, 69, 64, 54, 69, 51, 58,
       59, 83, 66, 71, 70, 56, 57, 49, 42, 31, 38, 32, 43, 70, 59, 62},
      {66, 52,  76, 74, 70, 60, 53, 70, 56, 60, 37, 49, 77, 46, 51, 46, 36,
       29, 25,  47, 64, 73, 9,  19, 6,  35, 28, 0,  42, 81, 82, 97, 79, 84,
       85, 111, 64, 90, 98, 28, 30, 22, 15, 42, 49, 56, 67, 96, 85, 88},
      {90,  76,  100, 98, 94, 84, 77, 87, 65, 72, 60, 48, 44, 70,  73,  70, 60,
       53,  67,  40,  22, 38, 33, 61, 48, 77, 69, 42, 0,  39, 62,  97,  91, 101,
       109, 111, 22,  48, 63, 19, 56, 64, 57, 84, 90, 80, 91, 120, 109, 112},
      {82, 68, 82, 76, 72, 62, 55, 60,  38, 45, 55, 43, 17, 62,  46, 75, 65,
       53, 78, 35, 17, 33, 72, 73, 87,  88, 64, 81, 39, 0,  23,  58, 56, 67,
       87, 72, 36, 9,  24, 58, 95, 103, 96, 95, 95, 85, 96, 112, 87, 90},
      {67, 53, 67, 61, 57, 47, 40,  37,  29, 22, 45, 50, 40, 47, 31, 60, 57,
       76, 68, 58, 40, 56, 84, 63,  87,  78, 54, 82, 62, 23, 0,  35, 33, 44,
       64, 49, 48, 17, 16, 81, 111, 103, 96, 85, 80, 70, 81, 97, 72, 75},
      {58, 58, 58, 52, 48, 38,  45,  28,  44,  37,  60, 65, 65, 52, 46, 65, 62,
       92, 83, 74, 75, 91, 89,  78,  102, 92,  69,  97, 97, 58, 35, 0,  18, 29,
       55, 14, 83, 52, 51, 107, 126, 118, 111, 100, 85, 75, 73, 88, 63, 66},
      {40, 40, 40, 34, 30, 20, 27,  10,  26, 19, 42, 47, 47, 34, 28, 47, 44,
       74, 65, 56, 69, 85, 71, 60,  84,  74, 51, 79, 91, 56, 33, 18, 0,  11,
       37, 32, 81, 50, 49, 89, 108, 100, 93, 82, 67, 57, 55, 70, 45, 48},
      {44, 44, 44, 38, 34, 24, 31,  14,  36, 29, 49, 57,  57, 38, 38, 51, 48,
       84, 72, 66, 79, 95, 75, 67,  90,  78, 58, 84, 101, 67, 44, 29, 11, 0,
       33, 39, 92, 61, 60, 94, 113, 106, 99, 89, 71, 61,  59, 74, 49, 46},
      {25, 39, 25,  19, 15,  25, 32,  27,  49,  42, 50, 62,  70, 39, 41, 45, 49,
       89, 73, 71,  88, 104, 76, 68,  91,  75,  59, 85, 109, 87, 64, 55, 37, 33,
       0,  69, 107, 81, 80,  95, 114, 107, 100, 88, 61, 51,  40, 55, 26, 13},
      {72,  72,  72,  66,  62,  52, 59, 42, 58,  51,  74, 79,  79,
       66,  60,  79,  76,  106, 97, 88, 89, 105, 103, 92, 116, 106,
       83,  111, 111, 72,  49,  14, 32, 39, 69,  0,   97, 66,  65,
       121, 140, 132, 125, 114, 99, 89, 87, 102, 77,  80},
      {88,  74, 98, 96, 92, 82, 75, 84, 62, 69, 57, 45, 41, 68,  70,  77, 67,
       55,  80, 37, 19, 35, 55, 75, 70, 90, 66, 64, 22, 36, 48,  83,  81, 92,
       107, 97, 0,  31, 46, 41, 78, 86, 79, 97, 97, 87, 98, 118, 107, 110},
      {84, 70, 84, 78, 74, 64, 57,  54,  46,  39,  62, 52, 26, 64,  48, 77, 74,
       62, 85, 44, 26, 42, 81, 80,  96,  95,  71,  90, 48, 9,  17,  52, 50, 61,
       81, 66, 31, 0,  15, 67, 104, 112, 105, 102, 97, 87, 98, 114, 89, 92},
      {83, 69, 83, 77, 73, 63, 56,  53,  45,  38,  61, 66, 41, 63,  47, 76, 73,
       77, 84, 59, 41, 57, 96, 79,  103, 94,  70,  98, 63, 24, 16,  51, 49, 60,
       80, 65, 46, 15, 0,  82, 119, 119, 112, 101, 96, 86, 97, 113, 88, 91},
      {76, 62,  86, 84, 80, 70, 63, 80, 63, 70, 54, 42, 63, 56,  68,  56, 46,
       39, 53,  33, 41, 57, 19, 47, 34, 63, 56, 28, 19, 58, 81,  107, 89, 94,
       95, 121, 41, 67, 82, 0,  37, 45, 43, 70, 76, 66, 77, 106, 95,  98},
      {95, 81, 105, 103, 99,  89,  82,  99,  85,  89,  66, 78,  100,
       75, 80, 75,  65,  58,  43,  70,  78,  94,  38,  49, 24,  53,
       57, 30, 56,  95,  111, 126, 108, 113, 114, 140, 78, 104, 119,
       37, 0,  8,   33,  60,  67,  77,  88,  125, 114, 117},
      {88, 74, 98, 96,  92,  82,  75,  92,  77,  81,  58, 70,  98,
       68, 72, 68, 58,  51,  35,  69,  86,  95,  31,  41, 16,  45,
       49, 22, 64, 103, 103, 118, 100, 106, 107, 132, 86, 112, 119,
       45, 8,  0,  25,  52,  59,  69,  80,  117, 107, 110},
      {81,  67,  91, 89,  85,  75, 68, 85, 70, 74, 51, 63, 91, 61,  65,  61, 51,
       44,  28,  62, 79,  88,  24, 34, 9,  38, 42, 15, 57, 96, 96,  111, 93, 99,
       100, 125, 79, 105, 112, 43, 33, 25, 0,  29, 52, 62, 73, 110, 100, 103},
      {63, 54,  73, 77,  73,  65, 58, 75, 59, 63, 40, 52, 80, 51, 54,  47, 47,
       71, 17,  61, 78,  94,  51, 39, 36, 17, 31, 42, 84, 95, 85, 100, 82, 89,
       88, 114, 97, 102, 101, 70, 60, 52, 29, 0,  27, 37, 48, 85, 85,  91},
      {36, 27, 46, 50, 46, 47, 40, 57, 57, 58, 43, 55, 78, 33, 49, 20, 30,
       77, 24, 60, 78, 94, 57, 46, 43, 14, 38, 49, 90, 95, 80, 85, 67, 71,
       61, 99, 97, 97, 96, 76, 67, 59, 52, 27, 0,  10, 21, 58, 58, 64},
      {26, 17, 36, 40, 36, 37, 30, 47, 47, 48, 33, 45, 68, 23, 39, 10, 20,
       67, 34, 50, 68, 84, 47, 41, 53, 24, 32, 56, 80, 85, 70, 75, 57, 61,
       51, 89, 87, 87, 86, 66, 77, 69, 62, 37, 10, 0,  11, 48, 48, 54},
      {15, 28, 25, 29, 25, 35, 41, 45, 58, 59, 44, 56, 79, 34, 50, 21, 31,
       78, 45, 61, 79, 95, 58, 52, 64, 35, 43, 67, 91, 96, 81, 73, 55, 59,
       40, 87, 98, 98, 97, 77, 88, 80, 73, 48, 21, 11, 0,  37, 37, 43},
      {30,  44,  32,  38,  40,  50, 57, 60, 74,  75,  61,  73,  95,
       50,  66,  50,  60,  100, 82, 82, 99, 115, 87,  79,  101, 72,
       70,  96,  120, 112, 97,  88, 70, 74, 55,  102, 118, 114, 113,
       106, 125, 117, 110, 85,  58, 48, 37, 0,   44,  52},
      {22, 36, 12,  11, 15,  25, 32,  35,  49,  50, 50, 62,  70, 39, 41, 42, 49,
       89, 73, 71,  88, 104, 76, 68,  91,  72,  59, 85, 109, 87, 72, 63, 45, 49,
       26, 77, 107, 89, 88,  95, 114, 107, 100, 85, 58, 48,  37, 44, 0,  13},
      {28, 42, 20,  14, 18,  28, 35,  38,  52,  53, 53, 65,  73, 42, 44, 48, 52,
       92, 76, 74,  91, 107, 79, 71,  94,  78,  62, 88, 112, 90, 75, 66, 48, 46,
       13, 80, 110, 92, 91,  98, 117, 110, 103, 91, 64, 54,  43, 52, 13, 0}

  };
  ASSERT_EQ(minimum_distance, result);
}

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
}
}  // namespace s21