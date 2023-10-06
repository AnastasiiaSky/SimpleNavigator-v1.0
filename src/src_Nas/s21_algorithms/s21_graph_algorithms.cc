#include "s21_graph_algorithms.h"
using namespace std;

bool CheckViseted(std::queue<int> visited_vertices, int current_vertix){
  for (auto it = 0; it < visited_vertices.size(); it++){
    if(visited_vertices.emplace() == current_vertix){
      continue;
    } else {
      return false;
    }
    return true;
  }
}

void s21::GraphAlgorithms::BreadthFirstSearch(s21_Graph graph, int start_vertex)
{
  
  // std::list<int> visited_vertices;
  // std::stack<int> vertex_stack;
  queue<int> queue_vertices_add;
  queue<int> visited_vertices;
  std::vector<std::vector<int>> adjacency_list = graph.getAdjacencyList();
  queue_vertices_add.push(start_vertex);
  while(!queue_vertices_add.empty()){
    int current_vertex = queue_vertices_add.front();  //извлекаем из очереди текущую вершину
        queue_vertices_add.pop();
    if(CheckViseted(queue_vertices_add, current_vertex)) {
        continue;
    }

  }

}


void s21::GraphAlgorithms::DepthFirstSearch(s21_Graph graph, int start_vertex)
{
  std::list<int> visited_vertices;
  std::stack<int> vertex_stack;
  vertex_stack.push(start_vertex);
  std::vector<std::vector<int>> adjacency_list = graph.getAdjacencyList();

  while (!vertex_stack.empty()) {
    int current_vertex = vertex_stack.top();
    vertex_stack.pop();

    if(CheckViseted(visited_vertices, current_vertex)) {
        continue;
    }

    visited_vertices.push_back(current_vertex);

    std::vector<int> adjacent_vertices = adjacency_list[current_vertex];
    for (int adjacent_vertex : adjacent_vertices) {
      if (!CheckViseted(visited_vertices, adjacent_vertex)) {
        vertex_stack.push(adjacent_vertex);
      }
    }
  }

}

bool s21::GraphAlgorithms::CheckViseted(std::list<int> visited_vertices, int current_vertix)
{
    for(auto it = visited_vertices.begin(); it != visited_vertices.end(); ++it) {
        if(*it == current_vertix) {
            continue;
        } else {
            return false;
        }
    }
    return true; 
}



void s21::GraphAlgorithms::PrintResultOfDepthFirstSearch(std::list<int> visited_vertices)
{
    for(auto it = visited_vertices.begin(); it != visited_vertices.end(); ++it) {
        std::cout << *it << " " << "->" << " ";
    }
    std::cout << std::endl;
}


