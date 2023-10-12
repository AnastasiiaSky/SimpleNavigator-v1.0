#include <gtest/gtest.h>

#include "../s21_graph/s21_graph.cc"
#include "../s21_algorithms/s21_graph_algorithms.cc"
using namespace std;

namespace s21 {

    TEST(AntTest, Vertex_random) {
    s21::s21_Graph graph;
        s21::GraphAlgorithms algo;
        std::string InputFileName = "./examples/graph_3_vert_simply.txt";
        graph.LoadGraphFromFile(InputFileName);
        int number = algo.Vertex_random(1, 100);
        int i = 1;
        if (number < 100 && number > 0) {
            i = 0;
        }
        ASSERT_EQ(0, i);
    }

  int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

} // namespace s21