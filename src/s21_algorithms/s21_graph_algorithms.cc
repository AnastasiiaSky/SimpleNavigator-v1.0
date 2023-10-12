/// \file

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

std::vector<int> s21::GraphAlgorithms::DepthFirstSearch(s21_Graph &graph, int start_vertex) {
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


/// @brief Метод поиска минимального пути между всеми вершинами графа.
/// Алгоритм Флойда-Уоршелла
/// Алгоритм метода таков: 1) Создаем матрицу смежности графа 
/// 2) Заменяем все "0" максимальным значением 3) В первом цикле путь проходит через
/// каждую промежуточную вершину V, начиная с положение, когда нет промежуточной 
/// вершины  V = 0 3) Находим минимальное значение между (Значением между двумя  
/// вершина в текущем положение  и Суммой значений между стартовой точкой и 
/// промежуточной V и значением между промежуточной вершиной V и конечной вершиной 
/// 4) Преобразуем результирующую матрицу: Заменяем максимальное значение 0 

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
  // Константы, вводятся самостоятельно
  const int ant = 500; // Количеству муравьев в колонии, при условии, что у нас их больше чем вершин

  // Расчетные константы
  const int size = graph.get_graph_size(); 

  // Создаем матрицу связностей графа
  std::vector<std::vector<int>> matrix_adjacency = graph.getAdjacencyMatrix();

  // Создаем матрицу ферамонов, равную 0
  std::vector<std::vector<double>> pheramone_matrix(size, std::vector<double>(size, 0.0));
  
  // Создаем результирующую структуру, стартовое расстояние макимально возможное
  TsmResult result_struct;
  result_struct.distance = std::numeric_limits<double>::max();

  
  
  
  // Цикл пока все муравье из колоние не пройдут по графу, каждый из своей вершины{
  // каждый последующий муравей выходит из новой вершины V = Z%size
  // Создаем текущее расстояние D
  int distance = 0;  // создаем здесь, чтоб каждый раз обновлялся
  
  // Зануляем временный путь, чтоб каждый новый муравей прокладывал свой собственны или лучше создаем его тут
    // Создаем временный путь {0}, зануляем, чтоб каждый новый муравей прокладывал свой путь
    std::vector<int> temp_path (size, 0);

    // Цикл похода одного муравья из текущей вершины, через все вершин, его путь {
    // Создаем лист вероятности, здесь, чтоб он удалялся после каждого цикла
    std::vector<std::vector<double>> pobability_list(size, std::vector<double>(size, 0.0));
    // Считаем вероятность прохождения муравья по всем доступным вершинам из текущей, сохраняем в листе
    // Выбираем в какую вершину он пошел из вероятно свободных  
    // V = SelectNextVertex (pobability_list);
    // 
    // Сохраняем вершину где были во временный путь
    // 
    // 
    // !!!  Рассмотреть случаи, когда у него его маршрут приводит в тупик, тггда надо все зачистить и идти дальше к следующей вершине
    // }

    // Пересчитываем матрицу феромонов c учетом нового проложенного маршрута
      RecalculatePheramoneMatrix (pheramone_matrix, distance);

    // Если все мы прошли все вершины и если новое расстояние короче, того, что в результирующей структуре: Перезаписываем стартовую вершину и расстояние
    // Если при заданном графе решение задачи невозможно, выведите ошибку.
  // }
    
  return TsmResult();
}
  // возможно сделать, чтоб сразу возвращала матрицу
  void s21::GraphAlgorithms::CreateProbabilityMatrix (std::vector<std::vector<double>> &pobability_list, // возможно не надо
    std::vector<std::vector<double>> pheramone_matrix, std::vector<std::vector<int>> matrix_adjacency){
    // Константы, вводятся самостоятельно
    const int a = 1;
    const int b = 1; 

    // Расчетные константы
    const int size = pobability_list.size(); 

    double feramont_distance = 0; // !!! Обязательно ли всегда занулять 
    double sum_feramont_distance = 0;
    // Сумма всех значений ферамонов всех ребер на 1 единицу пути
    for (int i = 0; i < size; i++){
      for (int j = 0; j < size; j++){
        sum_feramont_distance += pow(1/matrix_adjacency[i][j], b) * pow(pheramone_matrix[i][j], a);
      }
    }    
    for (int i = 0; i < size; i++){
      for (int j = 0; j < size; j++){
        feramont_distance = pow(1/matrix_adjacency[i][j], b) * pow(pheramone_matrix[i][j], a); // !!! А если у нас 0, то есть нет маршрута
        pobability_list[i][j] = feramont_distance / sum_feramont_distance; // возможно все пушим в лист
      }
    }    
  }

  int s21::GraphAlgorithms::Vertex_random(int min, int max) const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
  }

  int s21::GraphAlgorithms::SelectNextVertex (std::list<double> probability_list){ // !!! const // возможно надо подать матрицу вероятностей
      // Запускаем функцию рандома
      int random_c = Vertex_random(1, 100); // !!! обределиться вероятность 0,3  или 30%
      std::list<double>::iterator it = probability_list.begin();
      int sum_probability = *it;
      // Находим вершину, в которую упал наш рандом
        for(; it != probability_list.end() && sum_probability * 100 <= random_c; it++){
            sum_probability +=  *it;
        }
        return  *it + 1;
  }

  void s21::GraphAlgorithms::RecalculatePheramoneMatrix (std::vector<std::vector<double>> &pheramone_matrix, int distance){
    // Константы, вводятся самостоятельно
    const int q = 10; // Количество ферамонов у одного муравья 
    const double k = 0.7; // Коэффициент испарения ферамона 

    // Расчетные константы
    const double p = 1 - k; // Обратный коэфициент, умнажая на который предыдущее значение ферамоны уменьшается
    const int size = pheramone_matrix.size();  // Размер матрицы

    double feromon_const = q/distance;

    for (int i = 0; i < size; i++){
      for (int j = 0; j < size; j++){
        pheramone_matrix[i][j] = p*(pheramone_matrix[i][j] + feromon_const);
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