/// \file

#include "s21_graph_algorithms.h"

/// @brief Метод поиска пути в глубину в графе.
/// Алгоритм метода таков: 1) Создаем списое пройденныйх точек типа
/// std::vector<int> 2) Создаем стэк для работы с точками. 3) Получаем список
/// смежности adjacency_list из класса s21_Graph 4) Добавляем в стэк первую
/// точку - start_vertex. 5) Далее в цикле, условием выхода из которого является
/// опустошение стэка, проверяем, является ли вершина с вершины стэка
/// посещенной, а так же удаляем эту вершину из стэка. 6) Если вершина уже
/// посещена, переходим к следующей итерации цикла, если не посещена, проверяем
/// список вершин для текщей вершины, проверяя, являются ли смежные вершины
/// посещенными, если не являются, добавляем их на вершину стэка

/// @param graph - текущий граф.
/// @param start_vertex - точка начала происка пути.
/// @return std::vector<int> visited_vertices - результатом работы метода
/// является вектор посещенных точек

std::vector<int> s21::GraphAlgorithms::DepthFirstSearch(s21_Graph graph,
                                                        int start_vertex) {
  if (start_vertex > graph.get_graph_size() || start_vertex < 0) {
    throw std::length_error("Start vertex is incorrect");
  }
  std::vector<int> visited_vertices;
  std::stack<int> vertex_stack;
  std::vector<std::vector<int>> adjacency_list = graph.getAdjacencyList();

  vertex_stack.push(start_vertex);

  while (!vertex_stack.empty()) {
    int current_vertex = vertex_stack.top();
    vertex_stack.pop();

    if (CheckVisited(visited_vertices, current_vertex) == false) {
      continue;
    }

    std::vector<int> adjacent_vertices = adjacency_list[current_vertex];
    visited_vertices.push_back(current_vertex);

    for (int it = adjacent_vertices.size() - 1; it >= 0; --it) {
      if (CheckVisited(visited_vertices, adjacent_vertices[it]) == true) {
        vertex_stack.push(adjacent_vertices[it]);
      }
    }
  }
  return visited_vertices;
}

/// @brief Метод поиска пути в ширину в графе.
/// Алгоритм метода таков: 1) Создаем списое пройденныйх точек типа
/// std::vector<int> 2) Создаем очередь для работы с точками. 3) Получаем список
/// смежности adjacency_list из класса s21_Graph 4) Добавляем в очередь первую
/// точку - start_vertex. 5) Далее в цикле, условием выхода из которого является
/// опустошение очереди, проверяем, является ли вершина с вершины очереди
/// посещенной, а так же удаляем эту вершину из очереди. 6) Если вершина еще 
/// не посещена была, пушим в пройденный путь. 7) В цикле поочереди забираем 
/// из листа смежности следующую вершину, если мы ее не посещали, то пушим в очередь.

/// @param graph - текущий граф.
/// @param start_vertex - точка начала происка пути.
/// @return std::vector<int> visited_vertices - результатом работы метода
/// является вектор посещенных точек

std::vector<int> s21::GraphAlgorithms::BreadthFirstSearch(s21_Graph graph, int start_vertex) {
  if (start_vertex > graph.get_graph_size() || start_vertex <= 0) {
    throw std::length_error("Start vertex is incorrect");
  }

  // std::cout << "Algorithm Breadth First Search" << std::endl;
  std::vector<int> visited_vertices;
  std::queue<int> queue_vertices_add;
  std::vector<std::vector<int>> adjacency_list = graph.getAdjacencyList();
  int adjacent_vertices;
  queue_vertices_add.push(start_vertex);
  while (!queue_vertices_add.empty()) {
     // Извлекаем из очереди текущую вершину
    int current_vertex = queue_vertices_add.front(); 
    queue_vertices_add.pop();
    if (CheckVisited(visited_vertices, current_vertex)) {
      visited_vertices.push_back(current_vertex);  // Пушим в вектор посещенных
    }
    // Ищем по листу проходим по смежным вершинам
    for (int j = 0; j < adjacency_list[current_vertex - 1].size(); j++) {  
      // Забираем из графа следующую вершину
      adjacent_vertices = adjacency_list[current_vertex - 1] [j];  
      // Если мы ее не посещали, то пушим ее в очередь
      if (CheckVisited(visited_vertices, adjacent_vertices)) {
        queue_vertices_add.push(adjacent_vertices);  
      }
    }
  }
  visited_vertices.shrink_to_fit(); // Освобождаем лишнюю память, при создание вектора 
  return visited_vertices;
}



/// @brief Метод проверки посещенных точек, в которм происходит итерация по
/// эллементам вектора посещенных точек и сравнение с текущей точкой.

/// @param visited_vertices - результатом работы алгоритмов,
/// вектор посещенных точек
/// @param current_vertix - текущая вершина графа.

bool s21::GraphAlgorithms::CheckVisited(std::vector<int> visited_vertices,
                                        int current_vertix) noexcept {
  for (int it = 0; it < visited_vertices.size(); ++it) {
    if (visited_vertices[it] == current_vertix) {
      return false;
    }
  }
  return true;
}

// bool s21::GraphAlgorithms::CheckViseted(std::vector<int> visited_vertices,
// int current_vertix)
// {
//   std::vector<int> copy_list = visited_vertices;

//   for(auto it = visited_vertices.begin(); it != visited_vertices.end(); ++it)
//   {
//       if(*it == current_vertix) {
//         return false;
//       }
//     }
//   return true;
// }


/// @brief Метод отображения пройденного пути в графе

/// @param visited_vertices - результатом работы алгоритмов,
/// вектор посещенных точек

void s21::GraphAlgorithms::PrintResultOfDepthFirstSearch(
    std::vector<int> visited_vertices) noexcept {
  for (int it = 0; it < visited_vertices.size(); ++it) {
    if (it == visited_vertices.size() - 1) {
      std::cout << visited_vertices[it] << std::endl;
    } else {
      std::cout << visited_vertices[it] << " " << "->" << " ";
    }
  }
}

// void s21::GraphAlgorithms::PrintResultOfDepthFirstSearch(std::vector<int>
// visited_vertices)
// {
//     for(auto it = visited_vertices.begin(); it != visited_vertices.end();
//     ++it) {
//       if(it == --visited_vertices.end()) {
//         std::cout << *it << " ";
//       } else {
//         std::cout << *it << " " << "->" << " ";
//       }
//     }
//     std::cout << std::endl;
// }
