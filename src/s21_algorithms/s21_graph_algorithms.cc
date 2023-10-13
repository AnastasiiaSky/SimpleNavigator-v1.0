/// \file
// !!! Нарушена последовательность алгоритмов

#include "s21_graph_algorithms.h"
using namespace std; //  !!!  Потом убрать
// std::vector<std::vector<int>> !!! Заменить на Matrix

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

std::vector<int> s21::GraphAlgorithms::DepthFirstSearch(s21_Graph &graph,
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

std::vector<std::vector<int>> s21::GraphAlgorithms::GetShortestPathsBetweenAllVertices(s21_Graph &graph)
{
  // std::cout << "FloydWarshall:" << std::endl;
  // !!! Проверка на связность и другие ограничения
  std::vector<std::vector<int>> min_distance = graph.getAdjacencyMatrix();
  // std::vector<std::vector<int>> copy_min_distance = min_distance; // временно

  const int size = graph.get_graph_size();  
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
  // !!!  Как поведет себя с отрицательными весами, может ли быть отрицательное количество ферамонов
  // Константы, вводятся самостоятельно
  const int ants = 20; // Количеству муравьев в колонии, при условии, что у нас их больше чем вершин
  

  // Расчетные константы
  const int size = graph.get_graph_size(); 
  // cout << size << endl;
  //  cout << endl;
  // Создаем матрицу связностей графа
  std::vector<std::vector<int>> matrix_adjacency = graph.getAdjacencyMatrix();
  std::vector<std::vector<int>> matrix_adjacency2 = graph.getAdjacencyMatrix(); // пока так дублирую, потом либо кпией, лтюо сохранить в векторо инт

  // Создаем матрицу ферамонов, равную 0
  std::vector<std::vector<double>> pheramone_matrix(size, std::vector<double>(size, 1.0));
  
  // Создаем результирующую структуру, стартовое расстояние макимально возможное
  TsmResult result_struct;
  result_struct.distance = inf;
  result_struct.vertices = 0;

  std::vector<int> res_path;
  // Создаем матрицу пройденного 

  int vertex; // Пока просто так 
  
  
  // Цикл пока все муравье из колоние не пройдут по графу, каждый из своей вершины{
    for (int one_ant = 0; one_ant <= ants; one_ant++){
      vertex = (one_ant % size) + 1;
      // cout << vertex << endl;
  // Создаем текущее расстояние D
  // int distance = 0;  // создаем здесь, чтоб каждый раз обновлялся
      int distance_tmp = 0;
  
  // Зануляем временный путь, чтоб каждый новый муравей прокладывал свой собственны или лучше создаем его тут
    // Создаем временный путь {0}, зануляем, чтоб каждый новый муравей прокладывал свой путь
  std::vector<std::vector<int>> temp_path (size, std::vector<int>(size, 0));
    
  //   // Цикл похода одного муравья из текущей вершины, через все вершин, его путь {
  for (int j = 0; j < size; j++){
    // Создаем лист вероятности, здесь, чтоб он удалялся после каждого цикла
    // std::vector<std::vector<double>> pobability_list(size, std::vector<double>(size, 0.0));
    std::vector <double> probability_list(size, 0.0);
    // Считаем вероятность прохождения муравья по всем доступным вершинам из текущей, сохраняем в листе
    // PrintResultOfDepthFirstSearch(probability_list);
    // PrintAdjacencyMatrix(pheramone_matrix);
    // PrintAdjacencyMatrix(matrix_adjacency);
    // cout<< "VERTEX _ : " << vertex << endl;
    // Выделить в отдельную функцию, удаления пути в вершины, которые мы посетили
      for (int i = 0; i < size; i++){
        matrix_adjacency[i][vertex - 1] = 0;
      }
    // PrintAdjacencyMatrix(matrix_adjacency);
    CreateProbabilityPath(probability_list, pheramone_matrix, matrix_adjacency, vertex);
    
    // Выбираем в какую вершину он пошел из вероятно свободных 
      //   // Сохраняем вершину где были во временный путь
    res_path.push_back(vertex);
    distance_tmp += matrix_adjacency2[vertex - 1][j]; // !!! Заменить посчитать
    vertex = SelectNextVertex (probability_list);
    temp_path[vertex - 1][j] = 1; //!!!  Возможно не правильно
    
    // distance_tmp += matrix_adjacency2[vertex - 1][j]; // !!! Заменить посчитать
    cout << vertex << j << "   distance _ " << distance_tmp << endl;
  //   // 
  //   // !!!  Рассмотреть случаи, когда у него его маршрут приводит в тупик, тггда надо все зачистить и идти дальше к следующей вершине
  //   // }

    // Пересчитываем матрицу феромонов c учетом нового проложенного маршрута
      cout << endl;
      RecalculatePheramoneMatrix (pheramone_matrix, temp_path, distance_tmp);
      // PrintAdjacencyMatrix(temp_path);
    // Считаем пройденный путь
      // distance_tmp = GetSpanningTreeWeigt(temp_path) * 2; // умнажаем 2 так как она написана для ненаправленного графа
  // distance_tmp = 2;
  //   // Если все мы прошли все вершины и если новое расстояние короче, того, что в результирующей структуре: Перезаписываем стартовую вершину и расстояние
     
    //  PrintResultOfDepthFirstSearch(probability_list);
     }
    //  result_struct.vertices = 5;
    cout << "distance2 _ " << distance_tmp << endl;
    cout << vertex << res_path.front() << endl;
    distance_tmp += matrix_adjacency2[vertex - 1][res_path.front()];
  cout << ")))) " <<  matrix_adjacency2[vertex - 1][res_path.front()]<< endl;
  

    if (distance_tmp < result_struct.distance){
          res_path.push_back(res_path.front());
          result_struct.distance = distance_tmp;
  // // Прибавлем в путь стартовую вершину, и + к дистанции
          result_struct.vertices = res_path.front(); // !!! Поменять vertex на такое написание
          result_struct.path = move (res_path);
     }

  //   // Если при заданном графе решение задачи невозможно, выведите ошибку.
  }

    
    PrintAdjacencyMatrix(pheramone_matrix);
    PrintResultOfDepthFirstSearch(res_path);
    
  return result_struct;
}
  // возможно сделать, чтоб сразу возвращала матрицу
  void s21::GraphAlgorithms::CreateProbabilityPath(std::vector<double> &probability_list, // возможно не надо
    std::vector<std::vector<double>> pheramone_matrix, std::vector<std::vector<int>> matrix_adjacency, int vertex){
    // Константы, вводятся самостоятельно
    const int a = 1;
    const int b = 1; 
  
    // Расчетные константы
    const int size = probability_list.size(); 
    // vertex = 11;
    double feramont_distance = 0; // !!! Обязательно ли всегда занулять 
    double sum_feramont_distance = 0;
    // Сумма всех значений ферамонов всех ребер на 1 единицу пути
    cout << "Test : " << pow(0, 1) << endl;
      for (int j = 0; j < size; j++){
        if (matrix_adjacency[vertex - 1][j] != 0) {
          sum_feramont_distance += std::pow(1.0/matrix_adjacency[vertex - 1][j], b) * std::pow(pheramone_matrix[vertex - 1][j], a);
          // sum_feramont_distance = 12;
        }       
      }
      // cout << "sum_feramont_distance " << sum_feramont_distance << endl;
  
      for (int j = 0; j < size; j++){
        if (matrix_adjacency[vertex - 1][j] != 0 && sum_feramont_distance != 0) {
            // double tmp = 1.0 / 2;
            // cout << "IIII " <<  tmp << endl;
            // cout << "UUU^2 " << std::pow(0.01238, 2) << endl;       
            // cout << "UUU " << 1/(matrix_adjacency[vertex - 1][j]) << endl; 
            // 
          feramont_distance = std::pow(1.0/matrix_adjacency[vertex - 1][j], b) * std::pow(pheramone_matrix[vertex - 1][j], a); // !!! А если у нас 0, то есть нет маршрута
          // cout << "UUU_щ " << feramont_distance << endl; 
          cout << sum_feramont_distance << endl; 
          // cout << "YYYY " << feramont_distance << endl;
          probability_list[j] = feramont_distance / sum_feramont_distance; // возможно все пушим в лист
          // probability_list[j] = 1;
          // cout << "Test2: " << probability_list[j] << endl;
        }
      }      
      // PrintResultOfDepthFirstSearch(probability_list);  
  }
  

  int s21::GraphAlgorithms::VertexRandom(int min, int max) const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
  }

  int s21::GraphAlgorithms::SelectNextVertex (std::vector<double> probability_list){ // !!! const // возможно надо подать матрицу вероятностей
      int vertex = 0;
      int size = probability_list.size();
      // Запускаем функцию рандома
      int random_c = VertexRandom(1, 100); // !!! обределиться вероятность 0,3  или 30% // Возможно перенести как аргумент
      // random_c = 51;
      // cout << "Random_ " << random_c << endl;
      if (random_c > 0 && random_c <= 100) {
        // std::list<double>::iterator it_b = probability_list.begin();
        // std::list<double>::iterator it_e = probability_list.end();
        double sum_probability = 0;
        // Находим вершину, в которую попал наш рандом
        for(int j = 0; j != size && sum_probability * 100 <= random_c; j++){
            sum_probability += probability_list[j];
            // cout << "sum_probability " << sum_probability << endl;
           vertex++;
        }
      }
        return  vertex;
  }

  void s21::GraphAlgorithms::RecalculatePheramoneMatrix(std::vector<std::vector<double>> &pheramone_matrix, std::vector<std::vector<int>> temp_path, int distance){ // may be not  list, but vector
    // Константы, вводятся самостоятельно //!!!  Возможно сделать как аргументами метода
    const int q = 10.0; // Количество ферамонов у одного муравья 
    const double k = 0.3; // Коэффициент испарения ферамона 

    // Расчетные константы
    const double p = 1 - k; // Обратный коэфициент, умнажая на который предыдущее значение ферамоны уменьшается
    const int size = pheramone_matrix.size();  // Размер матрицы
    if (distance != 0){
      double feromon_const = q / distance;    
      for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
          if (temp_path[i][j] != 0) { // == 1
            pheramone_matrix[i][j] = p*pheramone_matrix[i][j] + feromon_const;
          } else {
            pheramone_matrix[i][j] = p*(pheramone_matrix[i][j]);
          }
        }
      }
    }
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

void s21::GraphAlgorithms::PrintResultOfDepthFirstSearch(
    std::vector<double> visited_vertices) noexcept {
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



// !!! Нужно описание
void s21::GraphAlgorithms::PrintAdjacencyMatrix(std::vector<std::vector<int>> matrix) noexcept
{
  std::cout << "AdjacencyMatrix:" << std::endl;
  int size = matrix.size();
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

// !!! Нужно описание
void s21::GraphAlgorithms::PrintAdjacencyMatrix(std::vector<std::vector<double>> matrix) noexcept
{
  std::cout << "AdjacencyMatrix:" << std::endl;
  int size = matrix.size();
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
