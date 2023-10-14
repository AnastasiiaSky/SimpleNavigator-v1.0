#include "consolemenu.h"

namespace s21 {

    void ConsoleMenuInterface::Deploy()
    {    
        std::string pathToFile;
        s21::s21_Graph graph;
        s21::GraphAlgorithms algo;
        int number = 0;
        while(number !=8) {
        ShowMenu();
        std::cin >> number;
        std::cout << std::endl;
        switch (number)
        {
        case 1:  
            std::cout << "specify the path to the file:" << std::endl;
            std::cin >> pathToFile;
            if(graph_.checkFile(pathToFile)) { 
                graph_.LoadGraphFromFile(pathToFile);
                if(graph_.IsGraphConnected(graph_, pathToFile)) {
                    GraphAlgorithms_.PrintAdjacencyMatrix(graph_.getAdjacencyMatrix());
                } else {
                    std::cout << "This graph is not connected. Try another" << std::endl; 
                }
            }
            break;
        case 2: {
            std::cout << "Graph breadth search: "; 
            std::vector<int> result = GraphAlgorithms_.BreadthFirstSearch(graph_, 1);
            algo.PrintResultOfDepthFirstSearch(result);
            break; }
        case 3: {
            std::cout << "Graph deapth search: "; 
            std::vector<int> result1 = GraphAlgorithms_.DepthFirstSearch(graph_, 1);
            algo.PrintResultOfDepthFirstSearch(result1);
            break; }
        case 4: {
            int vertex1; int vertex2; 
            std::cout << "Specify your vertices: ";
            std::cin >> vertex1 >> vertex2;
            std::cout << "Search for the shortest path between any two vertices: "; 
            int shortestDistance = algo.GetShortestPathBetweenVertices(graph_, vertex1, vertex2);
            std::cout << "Shortest Distance from Vertex " << vertex1 << " to Vertex "
            << vertex2 << ": " << shortestDistance << std::endl;
            break;}
        case 5: {
            std::vector<std::vector<int>> minimum_distance = algo.FloydWarshall(graph_);
            algo.PrintAdjacencyMatrix(minimum_distance);
            break;}
            }
        }
    }
    void ConsoleMenuInterface::ShowMenu()
    {
        std::cout << std::endl << "What do you want to do?" << std::endl;
        std::cout << "1. Load the original graph from a file" << std::endl;
        std::cout << "2. Traverse graph in breadth with output of the result to the console" << std::endl;
        std::cout << "3. Traverse graph in depth with output of the result to the console" << std::endl;
        std::cout << "4. Search for the shortest path between any two vertices and display the result to the console" << std::endl;
        std::cout << "5. Search for the shortest paths between all pairs of vertices in the graph with the output of the resulting matrix to the console" << std::endl;
        std::cout << "6. Search for the minimal spanning tree in the graph with the output of the resulting adjacency matrix to the console" << std::endl;
        std::cout << "7. Solve the salesman problem with the output of the resulting route and its length to the console" << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cout << ">";
    }
} // namespace s21