#include "s21_graph_algorithms.h"

/// @brief Метод проверки посещенных точек, в которм происходит итерация по
///        эллементам вектора посещенных точек и сравнение с текущей точкой.
/// @param visited_vertices - результатом работы алгоритмов,
///        вектор посещенных точек
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

int s21::GraphAlgorithms::Vertex_random(int min, int max) const {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distribution(min, max);
  return distribution(gen);
}

/// @brief Метод отображения пройденного пути в графе
/// @param visited_vertices - результатом работы алгоритмов,
///        вектор посещенных точек

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

/// @brief Данный метод ConvertToUndirected преобразует матрицу смежности
///        ориентированного графа в матрицу смежности неориентированного графа.
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
///        минимальным значением в матрице working_matrix и возвращает их в виде
///        пары значений.
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
///        виде матрицы least_spanning_tree.
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

/// @brief Данный метод IsAllVisited проверяет, все ли вершины графа были
///        посещены, на основе вектора visited_or_not, который содержит
///        информацию о посещении каждой вершины.
/// @param visited_of_not
/// @return true - если все вершины посещены, false - если еще не все вершины
///         посещены.
bool s21::GraphAlgorithms::IsAllVisited(std::vector<bool> visited_of_not) {
  for (int it = 0; it < visited_of_not.size(); ++it) {
    if (visited_of_not[it] == false) {
      return false;
    }
  }
  return true;
}

/// @brief Метод s21::GraphAlgorithms::PrintAdjacencyMatrix() используется для
/// вывода матрицы смежности на консоль.
///        Он принимает параметр adjacency_matrix, который представляет собой
///        двумерный вектор (матрицу) целых чисел - матрицу смежности.
/// @param adjacency_matrix
void s21::GraphAlgorithms::PrintAdjacencyMatrix(
    std::vector<std::vector<int>> adjacency_matrix) noexcept {
  std::cout << "AdjacencyMatrix:" << std::endl;
  int size = adjacency_matrix.size();
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      std::cout << adjacency_matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int s21::GraphAlgorithms::SelectNextVertex(
    std::list<double> probability_list) {  // !!! const // возможно надо подать
                                           // матрицу вероятностей
  // Запускаем функцию рандома
  int random_c =
      Vertex_random(1, 100);  // !!! обределиться вероятность 0,3  или 30%
  std::list<double>::iterator it = probability_list.begin();
  int sum_probability = *it;
  // Находим вершину, в которую упал наш рандом
  for (; it != probability_list.end() && sum_probability * 100 <= random_c;
       it++) {
    sum_probability += *it;
  }
  return *it + 1;
}

// возможно сделать, чтоб сразу возвращала матрицу
void s21::GraphAlgorithms::CreateProbabilityMatrix(
    std::vector<std::vector<double>> &pobability_list,  // возможно не надо
    std::vector<std::vector<double>> pheramone_matrix,
    std::vector<std::vector<int>> matrix_adjacency) {
  // Константы, вводятся самостоятельно
  const int a = 1;
  const int b = 1;

  // Расчетные константы
  const int size = pobability_list.size();

  double feramont_distance = 0;  // !!! Обязательно ли всегда занулять
  double sum_feramont_distance = 0;
  // Сумма всех значений ферамонов всех ребер на 1 единицу пути
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      sum_feramont_distance +=
          pow(1 / matrix_adjacency[i][j], b) * pow(pheramone_matrix[i][j], a);
    }
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      feramont_distance = pow(1 / matrix_adjacency[i][j], b) *
                          pow(pheramone_matrix[i][j],
                              a);  // !!! А если у нас 0, то есть нет маршрута
      pobability_list[i][j] =
          feramont_distance /
          sum_feramont_distance;  // возможно все пушим в лист
    }
  }
}

void s21::GraphAlgorithms::RecalculatePheramoneMatrix(
    std::vector<std::vector<double>> &pheramone_matrix, int distance) {
  // Константы, вводятся самостоятельно
  const int q = 10;  // Количество ферамонов у одного муравья
  const double k = 0.7;  // Коэффициент испарения ферамона

  // Расчетные константы
  const double p = 1 - k;  // Обратный коэфициент, умнажая на который предыдущее
                           // значение ферамоны уменьшается
  const int size = pheramone_matrix.size();  // Размер матрицы

  double feromon_const = q / distance;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      pheramone_matrix[i][j] = p * (pheramone_matrix[i][j] + feromon_const);
    }
  }
}
