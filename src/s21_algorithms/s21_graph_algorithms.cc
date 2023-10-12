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

    std::vector<int> adjacent_vertices = adjacency_list[current_vertex - 1];
    visited_vertices.push_back(current_vertex);

    for (int it = adjacent_vertices.size() - 1; it >= 0; --it) {
      if (CheckVisited(visited_vertices, adjacent_vertices[it]) == true) {
        vertex_stack.push(adjacent_vertices[it]);
      }
    }
  }
  return visited_vertices;
}

// std::vector<int>
// s21::GraphAlgorithms::DepthFirstSearch(std::vector<std::vector<int>>
// adjacency_list, int start_point)
// {
//   if (start_point > adjacency_list.size() || start_point < 0) {
//     throw std::length_error("Start vertex is incorrect");
//   }
//   std::vector<int> visited_vertices;
//   std::stack<int> vertex_stack;

//   vertex_stack.push(start_point);

//   while (!vertex_stack.empty()) {
//     int current_vertex = vertex_stack.top();
//     vertex_stack.pop();
//     if (CheckVisited(visited_vertices, current_vertex) == false) {
//       continue;
//     }

//     std::vector<int> adjacent_vertices = adjacency_list[current_vertex - 1];
//     visited_vertices.push_back(current_vertex);

//     for (int it = adjacent_vertices.size() - 1; it >= 0; --it) {
//       if (CheckVisited(visited_vertices, adjacent_vertices[it]) == true) {
//         vertex_stack.push(adjacent_vertices[it]);
//       }
//     }
//   }
//   return visited_vertices;
// }

/// @brief Метод поиска пути в ширину в графе.
/// Алгоритм метода таков: 1) Создаем списое пройденныйх точек типа
/// std::vector<int> 2) Создаем очередь для работы с точками. 3) Получаем список
/// смежности adjacency_list из класса s21_Graph 4) Добавляем в очередь первую
/// точку - start_vertex. 5) Далее в цикле, условием выхода из которого является
/// опустошение очереди, проверяем, является ли вершина с вершины очереди
/// посещенной, а так же удаляем эту вершину из очереди. 6) Если вершина еще
/// не посещена была, пушим в пройденный путь. 7) В цикле поочереди забираем
/// из листа смежности следующую вершину, если мы ее не посещали, то пушим в
/// очередь.

/// @param graph - текущий граф.
/// @param start_vertex - точка начала происка пути.
/// @return std::vector<int> visited_vertices - результатом работы метода
/// является вектор посещенных точек

std::vector<int> s21::GraphAlgorithms::BreadthFirstSearch(s21_Graph graph,
                                                          int start_vertex) {
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
      adjacent_vertices = adjacency_list[current_vertex - 1][j];
      // Если мы ее не посещали, то пушим ее в очередь
      if (CheckVisited(visited_vertices, adjacent_vertices)) {
        queue_vertices_add.push(adjacent_vertices);
      }
    }
  }
  visited_vertices
      .shrink_to_fit();  // Освобождаем лишнюю память, при создание вектора
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

/// @brief Метод отображения пройденного пути в графе

/// @param visited_vertices - результатом работы алгоритмов,
/// вектор посещенных точек

void s21::GraphAlgorithms::PrintResultOfDepthFirstSearch(
    std::vector<int> visited_vertices) noexcept {
  for (int it = 0; it < visited_vertices.size(); ++it) {
    if (it == visited_vertices.size() - 1) {
      std::cout << visited_vertices[it] << std::endl;
    } else {
      std::cout << visited_vertices[it] << " "
                << "->"
                << " ";
    }
  }
}

// bool s21::GraphAlgorithms::IsGraphConnected(std::vector<std::vector<int>>
// adjacency_list)
// {
//   std::vector<int> result_of_dfs = DepthFirstSearch(adjacency_list, 1);
//   if(result_of_dfs.size() < adjacency_list.size()) {
//     return false;
//   }
// return true;
// }

/// @brief Реализация алгоритма Прима.
/// В ходе работы алгоритма производится поиск минимального остовного дерева.
/// Если на вход поступает орикнтированный граф, мы преобразуем его в
/// неориентированный и продолжаем работу. Создаем структуру std::vector<bool>
/// visited_or_not для отслеживания посещенных и непосещенных точек,
/// std::vector<std::vector<int>>result_matrix для хранения матрицы минимального
/// остовного дерева, и std::vector<std::vector<int>> working_matrix для работы
/// с весами ребер. Устанавливаем первую посещенную вершину. Пока все вершины не
/// посещены выполняем следующие действия: 1) Для каждой посещенной вершины,
/// обновляем working_matrix соответствующими весами ребер, если эти вершины
/// связаны и не посещены. 2) Находим координаты ребра с минимальным весом в
/// working_matrix с помощью функции GetMinCoordinats. 3) Если вершина,
/// соответствующая минимальному ребру, уже посещена, установливаем вес этого
/// ребра в inf и находим новое минимальное ребро. 4) Если вершина,
/// соответствующая минимальному ребру, еще не посещена, добавляем это ребро в
/// result_matrix, устанавливаем вес этого ребра в inf в working_matrix, и
/// помечаем вершину как посещенную.
/// @param graph - объект класса граф.
/// @return std::vector<std::vector<int>> - возвращаемое значение матрица
/// смежности минимально оставного дерева графа.
std::vector<std::vector<int>> s21::GraphAlgorithms::GetLeastSpanningTree(
    s21_Graph& graph) {
  std::vector<std::vector<int>> graph_matrix = graph.getAdjacencyMatrix();
  graph_matrix = ConvertToUndirected(graph_matrix);
  std::vector<bool> visited_or_not(graph.get_graph_size(), false);
  std::vector<std::vector<int>> result_matrix(
      graph.get_graph_size(), std::vector<int>(graph.get_graph_size(), 0));
  std::vector<std::vector<int>> working_matrix(
      graph.get_graph_size(), std::vector<int>(graph.get_graph_size(), inf));

  int start_vertex = 0;
  visited_or_not[start_vertex] = true;
  while (!IsAllVisited(visited_or_not)) {
    for (int cur_vertex = 0; cur_vertex < graph.get_graph_size();
         ++cur_vertex) {
      if (visited_or_not[cur_vertex]) {
        for (int it = 0; it < graph.get_graph_size(); ++it) {
          if (graph_matrix[cur_vertex][it] != 0 && !visited_or_not[it]) {
            working_matrix[cur_vertex][it] = graph_matrix[cur_vertex][it];
          }
        }
      }
    }
    std::pair<int, int> min_coordinats = GetMinCoordinats(working_matrix);

    if (visited_or_not[min_coordinats.second] == true) {
      working_matrix[min_coordinats.first][min_coordinats.second] = inf;
      min_coordinats = GetMinCoordinats(working_matrix);
    }

    if (visited_or_not[min_coordinats.second] == false) {
      result_matrix[min_coordinats.first][min_coordinats.second] =
          working_matrix[min_coordinats.first][min_coordinats.second];
      result_matrix[min_coordinats.second][min_coordinats.first] =
          working_matrix[min_coordinats.first][min_coordinats.second];
      working_matrix[min_coordinats.first][min_coordinats.second] = inf;

      visited_or_not[min_coordinats.second] = true;
    }
  }
  return result_matrix;
}

/// @brief Данный метод IsAllVisited проверяет, все ли вершины графа были
/// посещены, на основе вектора visited_or_not, который содержит информацию о
/// посещении каждой вершины.
/// @param visited_of_not
/// @return true - если все вершины посещены, false - если еще не все вершины
/// посещены
bool s21::GraphAlgorithms::IsAllVisited(std::vector<bool> visited_of_not) {
  for (int it = 0; it < visited_of_not.size(); ++it) {
    if (visited_of_not[it] == false) {
      return false;
    }
  }
  return true;
}

/// @brief Данный метод ConvertToUndirected преобразует матрицу смежности
/// ориентированного графа в матрицу смежности неориентированного графа.
/// @param graph_matrix - исходная матрица
/// @return преобразованная матрица
std::vector<std::vector<int>> s21::GraphAlgorithms::ConvertToUndirected(
    const std::vector<std::vector<int>> graph_matrix) {
  int n = graph_matrix.size();
  std::vector<std::vector<int>> undirected_adj_matrix(n,
                                                      std::vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (graph_matrix[i][j] != 0) {
        undirected_adj_matrix[i][j] = undirected_adj_matrix[j][i] =
            graph_matrix[i][j];
      }
    }
  }

  return undirected_adj_matrix;
}

/// @brief Данный метод GetMinCoordinats находит координаты (индексы) элемента с
/// минимальным значением в матрице working_matrix и возвращает их в виде пары
/// значений.
/// @param working_matrix - матрица для работы с весами ребер.
/// @return пара значений в которой первый эллемент - i, а второй элемент - j;
std::pair<int, int> s21::GraphAlgorithms::GetMinCoordinats(
    std::vector<std::vector<int>> working_matrix) {
  int min = inf, res_i = 0, res_j = 0;
  for (int i = 0; i < working_matrix.size(); ++i) {
    for (int j = 0; j < working_matrix[0].size(); ++j) {
      if (working_matrix[i][j] < min) {
        min = working_matrix[i][j];
        res_i = i;
        res_j = j;
      }
    }
  }
  std::pair<int, int> result(res_i, res_j);
  return result;
}

/// @brief Метод вычисляет суммарный вес остовного дерева, представленного в
/// виде матрицы least_spanning_tree.
/// @param least_spanning_tree - матрица смежности минимального остовного дерева
/// @return суммарный вес остовного дерева
int s21::GraphAlgorithms::GetSpanningTreeWeigt(
    std::vector<std::vector<int>> least_spanning_tree) {
  int result = 0;
  for (int i = 0; i < least_spanning_tree.size(); ++i) {
    for (int j = 0; j < least_spanning_tree.size(); ++j) {
      result += least_spanning_tree[i][j];
    }
  }
  result /= 2;
  return result;
}
