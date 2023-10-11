/// \file

#include "s21_graph_algorithms.h"
using namespace std; //  !!!  Потом убрать

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

std::vector<int> s21::GraphAlgorithms::BreadthFirstSearch(s21_Graph &graph, int start_vertex) {
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

/// @brief Метод для поиска кратчайшего пути между двумя вершинами в графе с
/// использованием алгоритма Дейкстры.
///
/// Алгоритм работает следующим образом:
/// 1. Проверяем корректность входных вершин (vertex1 и vertex2) и получаем
///    размер графа (graphSize).
/// 2. Инициализируем матрицу смежности (adjacencyMatrix) из объекта графа.
/// 3. Преобразуем индексы вершин vertex1 и vertex2 в 0
/// 4. Создаем массив distances для хранения расстояний от начальной вершины до
///    всех остальных вершин графа. Исходное расстояние до начальной вершины
///    устанавливается как 0, а до всех остальных вершин - как бесконечность
///    (inf).
/// 5. Создаем массив visited для отслеживания посещенных вершин. Начально все
///    вершины помечены как не посещенные.
/// 6. Создаем приоритетную очередь q для выбора вершины с наименьшим
/// расстоянием.
/// 7. Добавляем начальную вершину vertex1 в очередь q с расстоянием 0.
/// 8. Основной цикл алгоритма выполняется до тех пор, пока очередь q не пуста.
/// 9. Извлекаем вершину с наименьшим расстоянием из очереди q.
/// 10. Проверяем, если текущее расстояние до вершины v короче, чем сохраненное
///     расстояние в массиве distances, то продолжаем выполнение.
/// 11. Перебираем смежные вершины (to) и обновляем расстояния до них, если
///     новое расстояние короче текущего.
/// 12. Если кратчайший путь до вершины vertex2 равен бесконечности (inf), то
///     выбрасываем исключение с сообщением об отсутствии пути между вершинами.
/// 13. Возвращаем кратчайшее расстояние до вершины vertex2.
///
/// @param graph - ссылка на объект графа.
/// @param vertex1 - номер первой вершины
/// @param vertex2 - номер второй вершины
/// @return int - кратчайшее расстояние между вершинами vertex1 и vertex2.
/// @throw std::invalid_argument если vertex1, vertex2 не являются
/// допустимыми вершинами графа или отсутствует путь между ними.

int s21::GraphAlgorithms::GetShortestPathBetweenVertices(s21_Graph &graph,
                                                         int vertex1,
                                                         int vertex2) {
  int graphSize = graph.get_graph_size();
  if (vertex1 < 1 || vertex2 < 1 || vertex1 > graphSize ||
      vertex2 > graphSize) {
    throw std::invalid_argument("Incorrect input vertices");
  }

  std::vector<std::vector<int>> adjacencyMatrix = graph.getAdjacencyMatrix();
  // std::cout << "Adjacency Matrix:" << std::endl;
  // for (int i = 0; i < graphSize; ++i) {
  //   for (int j = 0; j < graphSize; ++j) {
  //     std::cout << adjacencyMatrix[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }
  // std::cout << vertex1 << " " << vertex2 << std::endl;
  vertex1--;  // в 0 чтобы использовать как индексы
  vertex2--;

  std::vector<int> distances(graphSize, inf);
  distances[vertex1] = 0;
  std::vector<bool> visited(graphSize, false);

  std::priority_queue<std::pair<int, int>> q;
  q.push({0, vertex1});

  while (!q.empty()) {
    // std::cout << q.top().first << std::endl;
    int len = -q.top().first;
    int v = q.top().second;
    q.pop();

    if (len > distances[v]) continue;

    for (int to = 0; to < graphSize; ++to) {
      int length = adjacencyMatrix[v][to];
      if (length > 0 && distances[to] > distances[v] + length) {
        distances[to] = distances[v] + length;
        q.push({-distances[to], to});
      }
    }
  }

  if (distances[vertex2] == inf) {
    throw std::invalid_argument("No path exists between the vertices");
  }
  // for (int i = 0; i < graphSize; ++i) {
  //   std::cout << distances[i] << " ";
  // }
  return distances[vertex2];
}


/// @brief Метод поиска минимального пути между всеми вершинами графа.
/// Алгоритм Флойда-Уоршелла
/// Алгоритм метода таков: 1) Создаем матрицу смежности графа 
/// 2) Заменяем все "0" максимальным значением 3) В первом цикле путь проходит через
/// каждую промежуточную вершину V, начиная с положение, когда нет промежуточной 
/// вершины  V = 0 3) Находим минимальное значение между (Значением между двумя  
/// вершина в текущем положение  и Суммой значений между стартовой точкой и 
/// промежуточной V и значением между промежуточной вершиной V и конечной вершиной 
/// 4) Преобразуем результирующую матрицу: Заменяем максимальное значени                                                                                                                                                                                                                                                                                                                                          е 0 

/// @param graph - текущий граф.
/// @return std::vector<std::vector<int>> min_distance - результатом работы метода 
/// в виде матрицы смежности
/// является вектор посещенных точек

std::vector<std::vector<int>> s21::GraphAlgorithms::GetShortestPathsBetweenAllVertices(s21_Graph &graph)
{
  // std::cout << "FloydWarshall:" << std::endl;
  std::vector<std::vector<int>> min_distance = graph.getAdjacencyMatrix();
  // std::vector<std::vector<int>> copy_min_distance = min_distance; // временно

  int size = graph.get_graph_size();  
  for (int v = 0; v <= size; v++){
    for (int i = 0; i < size; i++){
      for (int j = 0; j < size; j++){
        if (v == 0) {
          if(min_distance[i][j] == 0) {
            min_distance[i][j] = inf;         
          }
        } else {
          // !!! Возможно условие вывести в отдельную функцию
          if((i != j && (v - 1) != i && (v - 1) != j) && (min_distance[i][v - 1] != inf && min_distance[v - 1][j] != inf)) { 
            min_distance[i][j] = std::min(min_distance[i][j], min_distance[i][v - 1] + min_distance[v - 1][j]);
          }
        }
      }
    }

    // for (int i = 0; i < size; i++){  // !!! Для сдачи не нужен удалить
    //   for (int j = 0; j < size; j++){
    //       if(min_distance[i][j] == inf ) {
    //         copy_min_distance[i][j] = 0; 
    //       } else {
    //         copy_min_distance[i][j] = min_distance[i][j];
    //       }
    //   }
    // }
  }
  // Пребразует бесконечность в 0
  for (int i = 0; i < size; i++){
      for (int j = 0; j < size; j++){
          if(min_distance[i][j] == inf ) {
            min_distance[i][j] = 0; 
          }
      }
    }
  return min_distance;
}




s21::TsmResult s21::GraphAlgorithms::SolveTravelingSalesmanProblem(s21_Graph &graph)
{
  // Создаем матрицу связностей графа
  // Создаем матрицу ферамонов, равную 0
  // Создаем результирующую структуру, стартовое расстояние макимально возможное
  // Создаем временный путь {0}
  // Константа коэффициент изчезновения ферамона p = (1 - k), константы a и b
  
  // Cоздаем переменную = количеству муравьев в колонии, при условии, что у нас 
  // Цикл пока все муравье из колоние не пройдут по графу, каждый из своей вершины{
  // каждый последующий муравей выходит из новой вершины V = Z%size
  // Создаем текущее расстояние D
  // Зануляем временный путь, чтоб каждый новый муравей прокладывал свой собственны или лучше создаем его тут

    // Цикл похода одного муравья из текущей вершины, через все вершин, его путь {
    // Создаем лист вероятности, здесь, чтоб он удалялся после каждого цикла
    // Считаем вероятность прохождения муравья по всем доступным вершинам из текущей, сохраняем в листе
    // Выбираем в какую вершину он пошел из вероятно свободных  
    /*int SelectNextVertex (list<int> ProbabilityList) {
      // Запускаем функцию рандома
      int random_c = random(1, 100);
      int i = 0;
      int sum_probability = ProbabilityList[i];
        for(i <= ProbabilityList.size() && sum_probability <= random_c; i++){
            sum_probability +=  ProbabilityList[i];
        }
        return  i + 1;

    }*/
    // 
    // Сохраняем вершину где были во временный путь
    // 
    // 
    // !!!  Рассмотреть случаи, когда у него его маршрут приводит в тупик, тггда надо все зачистить и идти дальше к следующей вершине
    // }

    // Пересчитываем матрицу феромонов
    // Q - константа равна какому-то любому значению
    // for
    //   for
        // T[i][j] = p*T[i][j] + Q/ij матрицы смежномти// не точно проверить
    // Если все мы прошли все вершины и если новое расстояние короче, того, что в результирующей структуре: Перезаписываем стартовую вершину и расстояние
    // Если при заданном графе решение задачи невозможно, выведите ошибку.
  // }
  return TsmResult();
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



// !!! Нужно описание
void s21::GraphAlgorithms::PrintAdjacencyMatrix(std::vector<std::vector<int>> adjacency_matrix) noexcept
{
  std::cout << "AdjacencyMatrix:" << std::endl;
  int size = adjacency_matrix.size();
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      std::cout << adjacency_matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
