#include <iostream>
#include <vector>
#include <map>
#include "DataInputAndOutput.h"

/**
 * Метод узнает, является ли поток консолью или файлом. Если консолью - то дополнительно с функционалом
 * выводит необходимые подсказки.
 * Метод запрашивает количество вершин (размер матрицы), а далее поэлементно ее заполняет значениями пользователя.
 * @param stream - Поток для ввода.
 * @return Матрица смежности.
 */
std::vector<std::vector<int>> AdjacencyMatrixInput(std::istream& stream) {
    int numberOfVertices, value;
    if (&stream == &std::cin) {
        std::cout << "Please enter the number of graph vertices:" << '\n';
        stream >> numberOfVertices;
        std::vector<std::vector<int>> matrix(numberOfVertices, std::vector<int>(numberOfVertices));
        std::cout << "Please enter an adjacency matrix for your graph for " << numberOfVertices << " vertices:" << '\n';
        for (int i = 0; i < numberOfVertices; ++i) {
            for (int j = 0; j < numberOfVertices; ++j) {
                stream >> value;
                matrix[i][j] = value;
            }
        }
        return matrix;
    } else {
        stream >> numberOfVertices;
        std::vector<std::vector<int>> matrix(numberOfVertices, std::vector<int>(numberOfVertices));
        for (int i = 0; i < numberOfVertices; ++i) {
            for (int j = 0; j < numberOfVertices; ++j) {
                stream >> value;
                matrix[i][j] = value;
            }
        }
        return matrix;
    }
}

/**
 * Метод узнает, является ли поток консолью или файлом. Если консолью - то дополнительно с функционалом
 * выводит необходимые подсказки.
 * Метод запрашивает количество вершин и вводимых рёбер (размеры матрицы), а далее поэлементно ее заполняет значениями пользователя.
 * @param stream - Поток для ввода.
 * @return Матрица инцидентности.
 */
std::vector<std::vector<int>> IncidenceMatrixInput(std::istream& stream) {
    int numberOfVertices, numberOfEdges, value;
    if (&stream == &std::cin) {
        std::cout << "Please enter the number of graph vertices:" << '\n';
        stream >> numberOfVertices;
        std::cout << "Please enter the number of graph edges:" << '\n';
        stream >> numberOfEdges;
        std::vector<std::vector<int>> matrix(numberOfVertices, std::vector<int>(numberOfEdges));
        std::cout << "Please enter an incidence matrix for your graph for " << numberOfVertices << " vertices and "
                  << numberOfEdges << " edges:" << '\n';
        for (int i = 0; i < numberOfVertices; ++i) {
            for (int j = 0; j < numberOfEdges; ++j) {
                stream >> value;
                matrix[i][j] = value;
            }
        }
        return matrix;
    }
    else {
        stream >> numberOfVertices;
        stream >> numberOfEdges;
        std::vector<std::vector<int>> matrix(numberOfVertices, std::vector<int>(numberOfEdges));
        for (int i = 0; i < numberOfVertices; ++i) {
            for (int j = 0; j < numberOfEdges; ++j) {
                stream >> value;
                matrix[i][j] = value;
            }
        }
        return matrix;
    }
}

/**
 * Метод узнает, является ли поток консолью или файлом. Если консолью - то дополнительно с функционалом
 * выводит необходимые подсказки.
 * Метод запрашивает количество вершин, а далее поочереди считывает значения для конкретной вершины, пока не
 * встретит ноль.
 * @param stream - Поток для ввода.
 * @return Список смежности.
 */
std::map<int, std::vector<int>> AdjacencyListInput(std::istream& stream) {
    int numberOfVertices, value;
    std::map<int, std::vector<int>> list;
    if (&stream == &std::cin) {
        std::cout << "Please enter the number of graph vertices:" << '\n';
        stream >> numberOfVertices;
        std::cout << "Please enter an adjacency list for your graph for " << numberOfVertices << " vertices:" << '\n';
        for (int i = 1; i < numberOfVertices + 1; ++i) {
            stream >> value;
            while (value != 0) {
                list[i].push_back(value);
                stream >> value;
            }
        }
    }
    else {
        stream >> numberOfVertices;
        for (int i = 1; i < numberOfVertices + 1; ++i) {
            stream >> value;
            while (value != 0) {
                list[i].push_back(value);
                stream >> value;
            }
        }
    }
    return list;
}

/**
 * Метод узнает, является ли поток консолью или файлом. Если консолью - то дополнительно с функционалом
 * выводит необходимые подсказки.
 * Метод узнаёт количество вводимых дуг, а потом поочереди считывает значения и заполняет ими матрицу.
 * @param stream - Поток для ввода.
 * @return Список дуг.
 */
std::vector<std::vector<int>> ListOfArcsInput(std::istream& stream) {
    int numberOfArcs, value;
    if (&stream == &std::cin) {
        std::cout << "Please enter the number of graph arcs:" << '\n';
        stream >> numberOfArcs;
        std::vector<std::vector<int>> list(numberOfArcs, std::vector<int>(2));
        std::cout << "Please enter a list of arcs for your graph for " << numberOfArcs << " arcs:" << '\n';
        for (int i = 0; i < numberOfArcs; ++i) {
            for (int j = 0; j < 2; ++j) {
                stream >> value;
                list[i][j] = value;
            }
        }
        return list;
    } else {
        stream >> numberOfArcs;
        std::vector<std::vector<int>> list(numberOfArcs, std::vector<int>(2));
        for (int i = 0; i < numberOfArcs; ++i) {
            for (int j = 0; j < 2; ++j) {
                stream >> value;
                list[i][j] = value;
            }
        }
        return list;
    }
}

/**
 * Метод проходится по всем значениям матрицы и выводит их в поток.
 * @param matrix - Матрица для вывода.
 * @param stream - Поток для вывода.
 */
void AdjIncidListOfArcsMatrixOutput(const std::vector<std::vector<int>>& matrix, std::ostream& stream) {
    for (const auto& vec : matrix) {
        for (const auto& el : vec) {
            stream << el << ' ';
        }
        stream << '\n';
    }
}

/**
 * Метод проходится по всем значениям словаря и выводит их в поток.
 * @param list - Список смежности
 * @param stream - Поток для вывода.
 */
void AdjacencyListOutput(const std::map<int, std::vector<int>>& list, std::ostream& stream) {
    for (const auto& [vertex, vec] : list) {
        stream << vertex << ": ";
        for (const auto& path : vec) {
            stream << path << "; ";
        }
        stream << '\n';
    }
}