#include <gtest/gtest.h>

#include "../s21_algorithms/s21_graph_algorithms.h"
#include "../s21_graph/s21_graph.h"

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
  s21::s21_Graph graph(5);
  s21::GraphAlgorithms algo;
  std::string InputFileName = "./examples/graph_4_for_dijkstra.txt";
  graph.LoadGraphFromFile(InputFileName);

  int shortestDistance = algo.GetShortestPathBetweenVertices(graph, 5, 2);
  EXPECT_EQ(shortestDistance, 5);
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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
