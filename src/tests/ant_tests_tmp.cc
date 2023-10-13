#include <gtest/gtest.h>

#include "../s21_graph/s21_graph.cc"
#include "../s21_algorithms/s21_graph_algorithms.cc"
using namespace std;

namespace s21 {

     TEST(AntTest, weighted_graph_4_vert) {
        s21::s21_Graph graph;
        s21::GraphAlgorithms algo;
        
        std::string InputFileName = "./examples/weighted_graph_4_vert.txt";
        graph.LoadGraphFromFile(InputFileName);
        int distance = 10;
        TsmResult result_struct = algo.SolveTravelingSalesmanProblem(graph);
        const int size = graph.get_graph_size(); 
   
                // ASSERT_EQ(253, result_struct.distance);
                // ASSERT_EQ(1, *result_struct.vertices);

    
    }

    // TEST(AntTest, weighted_graph_11_vert) {
    //     s21::s21_Graph graph;
    //     s21::GraphAlgorithms algo;
        
    //     std::string InputFileName = "./examples/weighted_graph_11_vert.txt";
    //     graph.LoadGraphFromFile(InputFileName);
    //     int distance = 10;
    //     TsmResult result_struct = algo.SolveTravelingSalesmanProblem(graph);
    //     const int size = graph.get_graph_size(); 
   
    //             // ASSERT_EQ(253, result_struct.distance);
    //             // ASSERT_EQ(1, *result_struct.vertices);

    
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
    //     std::list<double> probability_list {0, 0.15, 0.35, 0, 0.50};
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

    // TEST(AntTest, RecalculatePheramoneMatrix) {
    //     s21::s21_Graph graph;
    //     s21::GraphAlgorithms algo;
    //     std::string InputFileName = "./examples/graph_3_vert_simply.txt";
    //     graph.LoadGraphFromFile(InputFileName);
    //     int distance = 10;
    //     const int size = graph.get_graph_size(); 
    //     std::vector<std::vector<double>> pheramone_matrix(size, std::vector<double>(size, 1.0));
    //     std::vector<std::vector<int>> temp_path = graph.getAdjacencyMatrix();
    //     // int size = probability_list.size();
    //     algo.RecalculatePheramoneMatrix(pheramone_matrix, temp_path, distance);
    //     for (int i = 0; i < size; i++){
    //         for (int j = 0; j < size; j++){
    //             if (temp_path[i][j] == 1) {
    //             ASSERT_EQ(1.7, pheramone_matrix[i][j]);
    //             } else {
    //             ASSERT_EQ(1, pheramone_matrix[i][j]);
    //             }
    //         }
    //     }
    // }

    // TEST(AntTest, CreateProbabilityPath) {
    //     s21::s21_Graph graph;
    //     s21::GraphAlgorithms algo;
    //     // std::string InputFileName = "./examples/graph_3_vert_simply.txt";
    //     std::string InputFileName = "./examples/graph_3_vert_simply.txt";
    //     graph.LoadGraphFromFile(InputFileName);
    //     const int size = graph.get_graph_size(); 
    //     int distance = 10;
    //     int vertex = 1;
    //     std::vector<std::vector<double>> pheramone_matrix(size, std::vector<double>(size, 1.0));
    //     std::vector<std::vector<int>> matrix_adjacency = graph.getAdjacencyMatrix();
    //     std::vector <double> probability_list(size, 0.0);

    //     // int size = probability_list.size();
    //     algo.CreateProbabilityPath(probability_list, pheramone_matrix, matrix_adjacency, vertex);
    //     algo.PrintResultOfDepthFirstSearch(probability_list);  

    //     for (int j = 1; j < size; j++){
    //        ASSERT_EQ(0.5, probability_list[j]);
    //     }
    // }

   


  int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

} // namespace s21