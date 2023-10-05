#include "s21_graph_algorithms.h"

void s21::GraphAlgorithms::DepthFirstSearch(s21_Graph graph, int start_vertex)
{
  std::list<int> visited_vertices;
  std::stack<int> vertex_stack;
  vertex_stack.push(start_vertex);
  std::vector<std::vector<int>> adjacency_list = graph.getAdjacencyList();


    // std::cout << adjacency_list[0].size() << std::endl;
    // visited_vertices.push_front(start_vertex);

  vertex_stack.push(start_vertex);

  while (!vertex_stack.empty()) {

    // std::cout << visited_vertices.size() << std::endl;

    int current_vertex = vertex_stack.top();
    vertex_stack.pop();

    if(!CheckViseted(visited_vertices, current_vertex)) {
        continue;
    }

    visited_vertices.push_back(current_vertex);
        // std::cout << "current " << current_vertex << std::endl;

    std::vector<int> adjacent_vertices = adjacency_list[current_vertex];
        // std::cout << "adjacent_vertex " << adjacency_list[current_vertex].size() << std::endl;

    for (int it = 0; it < adjacent_vertices.size(); ++it) {
        std::cout << "adjacent_vertex " << adjacent_vertices[it] << std::endl;

      if (!CheckViseted(visited_vertices, adjacent_vertices[it])) {
        // std::cout << "adjacent_vertex " << adjacent_vertices[it] << std::endl;
        vertex_stack.push(adjacent_vertices[it]);
      }
    }
  }
    // std::cout << visited_vertices.front() << std::endl;
    // std::cout << visited_vertices.size() << std::endl;


  PrintResultOfDepthFirstSearch(visited_vertices);

}

bool s21::GraphAlgorithms::CheckViseted(std::list<int> visited_vertices, int current_vertix)
{
  std::list<int> copy_list = visited_vertices;

    while(!copy_list.empty()) {

    // std::cout << current_vertix << std::endl;

        if(copy_list.front() == current_vertix) {
          return false;
        }
        copy_list.pop_front();

  }
    return true; 
}

void s21::GraphAlgorithms::PrintResultOfDepthFirstSearch(std::list<int> visited_vertices)
{
  std::list<int> copy_list = visited_vertices;
  // int it = copy_list.size();
  while(!copy_list.empty()) {
        std::cout << copy_list.front() << " " << "->" << " ";
        copy_list.pop_front();

  }
    std::cout << std::endl;
}
