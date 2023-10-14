#include <gtest/gtest.h>

#include "../s21_algorithms/s21_graph_algorithms.h"
#include "../s21_graph/s21_graph.h"

TEST(GraphAlgorithmsTest, ShortestPathCase1) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_5_for_dijkstra.txt";
  graph.LoadGraphFromFile(InputFileName);

  int shortestDistance = algo.GetShortestPathBetweenVertices(graph, 1, 4);
  EXPECT_EQ(shortestDistance, 14);
}

TEST(GraphAlgorithmsTest, ShortestPathCase2) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_8_vert_direct.txt";
  graph.LoadGraphFromFile(InputFileName);

  int shortestDistance = algo.GetShortestPathBetweenVertices(graph, 2, 8);
  EXPECT_EQ(shortestDistance, 3);
}

TEST(GraphAlgorithmsTest, ShortestPathCase3) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_4_for_dijkstra.txt";
  graph.LoadGraphFromFile(InputFileName);

  int shortestDistance = algo.GetShortestPathBetweenVertices(graph, 1, 3);
  EXPECT_EQ(shortestDistance, 8);
}

TEST(GraphAlgorithmsTest, ShortestPathCase4) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_4_for_dijkstra.txt";
  graph.LoadGraphFromFile(InputFileName);

  int shortestDistance = algo.GetShortestPathBetweenVertices(graph, 4, 2);
  EXPECT_EQ(shortestDistance, 2);
}

TEST(GraphAlgorithmsTest, InvalidVertices) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_5_for_dijkstra.txt";
  graph.LoadGraphFromFile(InputFileName);

  EXPECT_THROW(algo.GetShortestPathBetweenVertices(graph, 1, 6),
               std::invalid_argument);
}

TEST(GraphAlgorithmsTest, InvalidVertices1) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_5_for_dijkstra.txt";
  graph.LoadGraphFromFile(InputFileName);

  EXPECT_THROW(algo.GetShortestPathBetweenVertices(graph, 0, 4),
               std::invalid_argument);
}

TEST(GraphAlgorithmsTest, ShortestPathCase5) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/weighted_graph_9_vert.txt";
  graph.LoadGraphFromFile(InputFileName);

  int shortestDistance = algo.GetShortestPathBetweenVertices(graph, 1, 5);
  EXPECT_EQ(shortestDistance, 14);
}

TEST(GraphAlgorithmsTest, ShortestPathCase6) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/weighted_graph_9_vert.txt";
  graph.LoadGraphFromFile(InputFileName);

  int shortestDistance = algo.GetShortestPathBetweenVertices(graph, 3, 7);
  EXPECT_EQ(shortestDistance, 13);
}

TEST(GraphAlgorithmsTest, ShortestPathCase7) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/weighted_directed_graph_8_vert.txt";
  graph.LoadGraphFromFile(InputFileName);

  int shortestDistance = algo.GetShortestPathBetweenVertices(graph, 8, 5);
  EXPECT_EQ(shortestDistance, 18);
}

TEST(GraphAlgorithmsTest, ShortestPathCase8) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_5_vert_simply.txt";
  graph.LoadGraphFromFile(InputFileName);

  int shortestDistance = algo.GetShortestPathBetweenVertices(graph, 1, 5);
  EXPECT_EQ(shortestDistance, 2);
}

TEST(GraphAlgorithmsTest, ShortestPathCase9) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/weighted_graph_50_vert.txt";
  graph.LoadGraphFromFile(InputFileName);

  int shortestDistance = algo.GetShortestPathBetweenVertices(graph, 33, 19);
  EXPECT_EQ(shortestDistance, 8);
}

TEST(GraphAlgorithmsTest, ShortestPathCase10) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/unconnected_graph_5.txt";
  graph.LoadGraphFromFile(InputFileName);

  EXPECT_THROW(algo.GetShortestPathBetweenVertices(graph, 1, 4),
               std::exception);
}

TEST(GraphAlgorithmsTest, InvalidVertices3) {
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/weighted_directed_graph_8_vert.txt";
  graph.LoadGraphFromFile(InputFileName);

  EXPECT_THROW(algo.GetShortestPathBetweenVertices(graph, 5, 8),
               std::exception);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}