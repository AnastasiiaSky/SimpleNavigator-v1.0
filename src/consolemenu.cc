/// \file
#include "consolemenu.h"

namespace s21 {

void ConsoleMenuInterface::Deploy() {
  std::string pathToFile;
  s21::s21_Graph graph;
  s21::GraphAlgorithms algo;
  int number = 0;
  while (number != 8) {
    ShowMenu();
    std::string input = "\0";
    std::cin >> input;
    try {
      number = std::stoi(input);
    } catch (const std::exception& e) {
      std::cout << "(Use simple numbers from 1 to 8)." << std::endl;
    }
    std::cout << std::endl;
    if(number < 1 || number > 8) {
      std::cout << "Plese, choose from menu!" << std::endl;
      ShowMenu();
    }
    switch (number) {
      case 1:
        CallGraphLoading(pathToFile);
        break;
      case 2: {
        if(graph_.get_graph_size() < 1) {
          std::cout << "* Warning!!! Plese, load a graph before using algorithms!" << std::endl;
          break;
        }
        CallBFS();
        break;
      }
      case 3: {
                if(graph_.get_graph_size() < 1) {
          std::cout << "* Warning!!! Plese, load a graph before using algorithms!" << std::endl;
          break;
        }
        CallDFS();
        break;
      }
      case 4: {
                if(graph_.get_graph_size() < 1) {
          std::cout << "* Warning!!! Plese, load a graph before using algorithms!" << std::endl;
          break;
        }
        CallDeikstra();
        break;
      }
      case 5: {
                if(graph_.get_graph_size() < 1) {
          std::cout << "* Warning!!! Plese, load a graph before using algorithms!" << std::endl;
          break;
        }
        CallFloid();
        break;
      }
      case 6: {
                if(graph_.get_graph_size() < 1) {
          std::cout << "* Warning!!! Plese, load a graph before using algorithms!" << std::endl;
          break;
        }
        CallPrim();
         break;
      }
      case 7: {
        if(graph_.get_graph_size() < 1) {
          std::cout << "* Warning!!! Plese, load a graph before using algorithms!" << std::endl;
          break;
        }
        CallAnt();
          break;
      }
    }
  }
}
void ConsoleMenuInterface::ShowMenu() {
  std::cout << "..............................................................."
               "........................................................."
            << std::endl;
  std::cout << ".                       WELCOME TO SIMPLE NAVIGATOR! WHAT DO "
               "YOU WANT TO DO?                                           ."
            << std::endl;
  std::cout << "..............................................................."
               "........................................................."
            << std::endl;
  std::cout << ".  1. Load the original graph from a file                      "
               "                                                        ."
            << std::endl;
  std::cout << "..............................................................."
               "........................................................."
            << std::endl;
  std::cout << ".  2. Go thru graph in Breadth and print the result            "
               "                                                        ."
            << std::endl;
  std::cout << "..............................................................."
               "........................................................."
            << std::endl;
  std::cout << ".  3. Go thru graph in Depth and print the result              "
               "                                                        ."
            << std::endl;
  std::cout << "..............................................................."
               "........................................................."
            << std::endl;
  std::cout << ".  4. Find the shortest path between any two vertices and "
               "print the result                                             ."
            << std::endl;
  std::cout << "..............................................................."
               "........................................................."
            << std::endl;
  std::cout << ".  5. Find the shortest paths between all pairs of vertices in "
               "the graph and print the resulting matrix                ."
            << std::endl;
  std::cout << "..............................................................."
               "........................................................."
            << std::endl;
  std::cout << ".  6. Find the minimal spanning tree in the graph and print "
               "the resulting adjacency matrix and the tree weight         ."
            << std::endl;
  std::cout << "..............................................................."
               "........................................................."
            << std::endl;
  std::cout << ".  7. Solve the salesman problem and print the resulting route "
               "and its length                                          ."
            << std::endl;
  std::cout << "..............................................................."
               "........................................................."
            << std::endl;
  std::cout << ".  8. EXIT                                                     "
               "                                                        ."
            << std::endl;
  std::cout << "..............................................................."
               "........................................................."
            << std::endl;
  std::cout << std::endl;
  std::cout << ">";
}

void ConsoleMenuInterface::CallGraphLoading(std::string pathToFile) {
  std::cout << "specify the path to the file:" << std::endl;
  std::cin >> pathToFile;
  RemoveSrcPrefix(pathToFile);
  if (graph_.CheckFile(pathToFile)) {
    graph_.LoadGraphFromFile(pathToFile);
    if (graph_.IsGraphConnected(graph_, pathToFile)) {
      std::cout << "                                                     "
                   "                                                     "
                   "              "
                << std::endl;
      std::cout << "                               Adjacency matrix for "
                   "loaded graph                                         "
                   "               "
                << std::endl;
      std::cout << "                              "
                   "...................................."
                << std::endl;
      GraphAlgorithms_.PrintAdjacencyMatrix(graph_.getAdjacencyMatrix());
      std::cout << std::endl;
      std::cout << "Graph size is    " << graph_.get_graph_size() << std::endl;

      std::cout << std::endl;

    } else {
      std::cout << std::endl;
      std::cout << "                             Oooops.... This graph "
                   "is not connected. Try another "
                << std::endl;
      std::cout << "                           "
                   "........................................................."
                << std::endl;
    }
  }
}
void ConsoleMenuInterface::CallBFS() {
  s21::GraphAlgorithms algo;
  int start_for_bfs = GetNumForAlgo();
  std::cout << std::endl;
  std::cout << "Graph breadth search result:" << std::endl;
  std::cout << "............................" << std::endl;
  std::cout << std::endl;
  std::vector<int> result =
      GraphAlgorithms_.BreadthFirstSearch(graph_, start_for_bfs);
  algo.PrintResultWay(result);
  std::cout << std::endl;
}

void ConsoleMenuInterface::CallDFS() {
  s21::GraphAlgorithms algo;
  int start_for_dfs = GetNumForAlgo();
  std::cout << std::endl;
  std::cout << "Graph deapth search result: " << std::endl;
  std::cout << "..........................." << std::endl;
  std::cout << std::endl;
  std::vector<int> result1 =
      GraphAlgorithms_.DepthFirstSearch(graph_, start_for_dfs);
  algo.PrintResultWay(result1);
  std::cout << std::endl;
}

int ConsoleMenuInterface::GetNumForAlgo() {
  int vertex = 0;
  std::string input = "\0";
  while (vertex < 1 || vertex > graph_.get_graph_size()) {
    std::cout << "Please select a vertex to start with. (It must be less "
                 "then count of vertices in current graph.)"
              << std::endl;
    std::cin >> input;
    try {
      vertex = std::stoi(input);
    } catch (const std::exception& e) {
      std::cout << "(Use simple numbers)." << std::endl;
    }
  }
  return vertex;
}
int ConsoleMenuInterface::GetNumForAlgoB() {
  int vertex = 0;
  std::string input = "\0";
  while (vertex < 1 || vertex > graph_.get_graph_size()) {
    std::cout << "Please select a vertex to finish (It must be less "
                 "then count of vertices in current graph.)"
              << std::endl;
    std::cin >> input;
    try {
      vertex = std::stoi(input);
    } catch (const std::exception& e) {
      std::cout << "(Use simple numbers)." << std::endl;
    }
  }
  return vertex;
}

void ConsoleMenuInterface::CallDeikstra() {
  s21::GraphAlgorithms algo;
  int vertex1 = GetNumForAlgo();
  int vertex2 = GetNumForAlgoB();
  std::cout << std::endl;

  std::cout << "Search for the shortest path between any two vertices: "
            << std::endl;
  std::cout << "......................................................"
            << std::endl;
  std::cout << std::endl;

  int shortestDistance =
      algo.GetShortestPathBetweenVertices(graph_, vertex1, vertex2);
  std::cout << "Shortest Distance from Vertex    " << vertex1
            << "   to Vertex    " << vertex2 << "  :  " << shortestDistance
            << std::endl;
}

void ConsoleMenuInterface::CallFloid() {
  s21::GraphAlgorithms algo;
  std::cout << std::endl;
  std::cout << "The result of algorithm Floid_Uolshera : " << std::endl;
  std::cout << "......................................." << std::endl;
  std::cout << std::endl;

  std::vector<std::vector<int>> minimum_distance =
      algo.GetShortestPathsBetweenAllVertices(graph_);
  algo.PrintAdjacencyMatrix(minimum_distance);

  std::cout << std::endl;
}

void ConsoleMenuInterface::CallPrim() {
  s21::GraphAlgorithms algo;

  std::cout << std::endl;
  std::cout << "The result of algorithm Prima : " << std::endl;
  std::cout << "............................." << std::endl;
  std::cout << std::endl;

  std::vector<std::vector<int>> result = algo.GetLeastSpanningTree(graph_);
  algo.PrintAdjacencyMatrix(result);
  int weight = algo.GetGraphWeigt(result);
  std::cout << std::endl;

  std::cout << "Spanning Tree Weight = " << weight / 2 << std::endl;
}

void ConsoleMenuInterface::CallAnt() {
  s21::GraphAlgorithms algo;

  std::cout << std::endl;
  std::cout << "The result of algorithm of Salesman Problem : " << std::endl;
  std::cout << "............................................." << std::endl;
  std::cout << std::endl;
  std::vector<int> way;
  double distance;
  s21::TsmResult result = algo.SolveTravelingSalesmanProblem(graph_);
  way = result.path;
  distance = result.distance;

  std::cout << "Way is  -  ";
  for(int it = 0; it < way.size(); ++it) {
    if(it != way.size() - 1) {
    std::cout << way[it] << " -> ";
    } else {
    std::cout << way[it] << std::endl;;

    }
  }

  std::cout << "Distance is   -  " << distance << std::endl;

}


std::string ConsoleMenuInterface::RemoveSrcPrefix(const std::string& path) {
  std::string srcPrefix = "src/";
  if (path.substr(0, srcPrefix.size()) == srcPrefix) {
    return path.substr(srcPrefix.size());
  }
  return path;
}


}  // namespace s21
