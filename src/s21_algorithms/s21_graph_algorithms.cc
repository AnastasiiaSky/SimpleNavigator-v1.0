#include "s21_graph_algorithms.h"

void s21::GraphAlgorithms::DepthFirstSearch(s21_Graph graph, int start_vertex)
{
  std::list<int> visited_vertices; // создаем пустой список пройденных точек
  std::stack<int> vertex_stack; // создаем пустой стэк для работы с точками
  // vertex_stack.push(start_vertex); 
  std::vector<std::vector<int>> adjacency_list = graph.getAdjacencyList(); // получаем список смежных вершин из класса Graph


  vertex_stack.push(start_vertex); // добавляем в стэе стартовую точку с которой начинаем обход по графц


  while (!vertex_stack.empty()) { // пока стэе не пуст проверяем точки
    int current_vertex = vertex_stack.top(); // берем текущую точку из стэка
    vertex_stack.pop(); // удаляем ее из стэка

    if(CheckVisited(visited_vertices, current_vertex) == false) { // если текущая точка уже посещена переходим к следующей итерации цикла
        continue;
    }

    std::vector<int> adjacent_vertices = adjacency_list[current_vertex]; // создаем свектор со смежными точками для текущей точки
    visited_vertices.push_back(current_vertex); // если не посещена добавляем текущую точку в список песещенных точек


    for (int it = adjacent_vertices.size()-1; it >= 0; --it) { // проходим в цикле по вектору смежных вершин 
      if (CheckVisited(visited_vertices, adjacent_vertices[it]) == true) { // и если в векторе смежных вершин имеются еще не посещенные ранее точки
        vertex_stack.push(adjacent_vertices[it]); // добавляем их в стэк
        std::cout << "adjacent_vertex in if  " << adjacent_vertices[it] << std::endl;
      } 
    }
  }
  PrintResultOfDepthFirstSearch(visited_vertices); // после всех предыдущих манипуляций печатаем результат
}

bool s21::GraphAlgorithms::CheckVisited(std::list<int> visited_vertices, int current_vertix)
{
  std::list<int> copy_list = visited_vertices;

    while(!copy_list.empty()) {
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
  while(!copy_list.empty()) {
      if(copy_list.size() == 1) {
          std::cout << copy_list.front() << std::endl;
          copy_list.pop_front();
      } else {
        std::cout << copy_list.front() << " " << "->" << " ";
        copy_list.pop_front();
      }
  }
}





    // std::cout << adjacency_list[0].size() << std::endl;
    // visited_vertices.push_front(start_vertex);


    // std::cout << visited_vertices.size() << std::endl;



        // std::cout << "current " << current_vertex << std::endl;


        // std::cout << "adjacent_vertex " << adjacency_list[current_vertex].size() << std::endl;

        // std::cout << "adjacent_vertex " << adjacent_vertices[it] << std::endl;



            // std::cout << visited_vertices.front() << std::endl;
    // std::cout << visited_vertices.size() << std::endl;

