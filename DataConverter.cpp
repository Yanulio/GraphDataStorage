#include <vector>
#include <map>
#include "DataConverter.h"

/**
 * Метод проходится по матрице инцидентности и смотрит, если у дуги две единицы,
 * то в матрицу смежности значения добавляются симметрично, если 1 и -1, то только в одно место.
 * @param matrix - Матрица инцидентности.
 * @return Матрица смежности.
 */
std::vector<std::vector<int>> ConvertIncidenceToAdjacency(const std::vector<std::vector<int>>& matrix) {
    size_t columns = matrix[0].size();
    int start = -1, end = -1;
    bool bothEnds = false;
    std::vector<std::vector<int>> newMatrix(matrix.size(), std::vector<int>(matrix.size()));
    for (size_t i = 0; i < columns; ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            if (matrix[j][i] == 1 && start == -1) {
                start = static_cast<int>(j);
            } else if (matrix[j][i] == 1 && start != -1) {
                bothEnds = true;
                end = static_cast<int>(j);
            } else if (matrix[j][i] == -1) {
                end = static_cast<int>(j);
            }
        }
        if (bothEnds) {
            newMatrix[start][end] = 1;
            newMatrix[end][start] = 1;
        } else {
            newMatrix[start][end] = 1;
        }
        start = end = -1;
        bothEnds = false;
    }
    return newMatrix;
}

/**
 * Метод проходится по списку смежности и добавляет в матрицу смежности значения на соответствующие
 * пересечения вершин.
 * @param matrix - Список смежности.
 * @return Матрица смежности.
 */
std::vector<std::vector<int>> ConvertAdjacencyListToMatrix(const std::map<int, std::vector<int>>& matrix) {
    std::vector<std::vector<int>> newMatrix(matrix.size(), std::vector<int>(matrix.size()));
    for (auto el : matrix) {
        for (int i = 0; i < el.second.size(); ++i) {
            newMatrix[el.first - 1][el.second[i] - 1] = 1;
        }
    }
    return newMatrix;
}

/**
 * Метод сначала считает количество вершин (максимальное число в переданном списке), а после
 * добавляет в матрицу смежности значения на соответствующие пересечения вершин.
 * @param matrix - Список дуг.
 * @return Матрица смежности.
 */
std::vector<std::vector<int>> ConvertListOfArcsToMatrix(const std::vector<std::vector<int>>& matrix) {
    int numberOfVertices = 0;
    //Подсчёт количества вершин.
    for (const auto & i : matrix) {
        if (i[0] > numberOfVertices) {
            numberOfVertices = i[0];
        }
    }
    std::vector<std::vector<int>> newMatrix(numberOfVertices, std::vector<int>(numberOfVertices));
    for (const auto & i : matrix) {
        newMatrix[i[0] - 1][i[1] - 1] = 1;
    }
    return newMatrix;
}

/**
 * Метод считает количество различных дуг (т.е. не приходящих и исходящих из одинаковых вершин),
 * создаёт матрицу с соответствующими размерами, и заполняет её в соответствии с направлением дуг.
 * @param matrix - Матрица смежности.
 * @return Матрица инцидентности.
 */
std::vector<std::vector<int>> ConvertAdjacencyMatrixToIncidence(const std::vector<std::vector<int>>& matrix) {
    int numberOfVertices = static_cast<int>(matrix.size()), countOfArcs = 0, numberOfSameEdges = 0;
    //Узнаём, сколько рёбер (или дуг) будет в матрице.
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            if (matrix[i][j] == 1) {
                ++countOfArcs;
                if (matrix[j][i] == 1) {
                    ++numberOfSameEdges;
                }
            }
        }
    }
    countOfArcs = countOfArcs - numberOfSameEdges / 2;
    std::vector<std::vector<int>> newMatrix(matrix.size(), std::vector<int>(countOfArcs));
    int pathNum = 0;
    for (int i = 0; i < numberOfVertices; ++i) {
        for (int j = 0; j < numberOfVertices; ++j) {
            if (matrix[i][j] == 1 && matrix[j][i] != 1) {
                newMatrix[i][pathNum] = 1;
                newMatrix[j][pathNum] = -1;
                ++pathNum;
            } else if (matrix[i][j] == 1 && matrix[j][i] == 1 && i < j) {
                newMatrix[i][pathNum] = 1;
                newMatrix[j][pathNum] = 1;
                ++pathNum;
            }
        }
    }
    return newMatrix;
}

/**
 * Метод проходится по матрице смежности и добавляет в map для ключа-вершины значения
 * смежных с ней вершин.
 * @param matrix - Матрица смежности.
 * @return Список смежности.
 */
std::map<int, std::vector<int>> ConvertAdjacencyMatrixToList(const std::vector<std::vector<int>>& matrix) {
    std::map<int, std::vector<int>> list;
    int numberOfVertices = static_cast<int>(matrix.size());
    for (int i = 0; i < numberOfVertices; ++i) {
        for (int j = 0; j < numberOfVertices; ++j) {
            if (matrix[i][j] == 1) {
                list[i+1].push_back(j+1);
            }
        }
    }
    return list;
}

/**
 * Метод считает количество дуг, а потом заполняет список (матрицу) вершинами,
 * соответствующими этим дугам.
 * @param matrix - Матрица смежности.
 * @return Список дуг.
 */
std::vector<std::vector<int>> ConvertAdjacencyMatrixToListOfArcs(const std::vector<std::vector<int>>& matrix) {
    int countOfArcs = 0;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            if (matrix[i][j] == 1) {
                ++countOfArcs;
            }
        }
    }
    std::vector<std::vector<int>> list(countOfArcs, std::vector<int>(2));
    int position = 0;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            if (matrix[i][j] == 1) {
                list[position][0] = static_cast<int>(i) + 1;
                list[position][1] = static_cast<int>(j) + 1;
                ++position;
            }
        }
    }
    return list;
}