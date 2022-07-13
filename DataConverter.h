#ifndef GRAPHDATA_DATACONVERTER_H
#define GRAPHDATA_DATACONVERTER_H

#endif //GRAPHDATA_DATACONVERTER_H

#include <iostream>
#include <vector>
#include <map>

/**
 * Метод, переводящий матрицу инцидентности в матрицу смежности.
 * @param matrix - Матрица инцидентности.
 * @return Матрица смежности.
 */
std::vector<std::vector<int>> ConvertIncidenceToAdjacency(const std::vector<std::vector<int>>& matrix);

/**
 * Метод, переводящий список смежности в матрицу смежности.
 * @param matrix - Список смежности.
 * @return Матрица смежности.
 */
std::vector<std::vector<int>> ConvertAdjacencyListToMatrix(const std::map<int, std::vector<int>>& matrix);

/**
 * Метод, переводящий список дуг в матрицу смежности.
 * @param matrix - Список дуг.
 * @return Матрица смежности.
 */
std::vector<std::vector<int>> ConvertListOfArcsToMatrix(const std::vector<std::vector<int>>& matrix);

/**
 * Метод, переводящий матрицу смежности в матрицу инцидентности.
 * @param matrix - Матрица смежности.
 * @return Матрица инцидентности.
 */
std::vector<std::vector<int>> ConvertAdjacencyMatrixToIncidence(const std::vector<std::vector<int>>& matrix);

/**
 * Метод, переводящий матрицу смежности в список смежности.
 * @param matrix - Матрица смежности.
 * @return Список смежности.
 */
std::map<int, std::vector<int>> ConvertAdjacencyMatrixToList(const std::vector<std::vector<int>>& matrix);

/**
 * Метод, переводящий матрицу смежности в список дуг.
 * @param matrix - Матрица смежности.
 * @return Список дуг.
 */
std::vector<std::vector<int>> ConvertAdjacencyMatrixToListOfArcs(const std::vector<std::vector<int>>& matrix);