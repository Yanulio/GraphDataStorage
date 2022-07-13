#ifndef GRAPHDATA_DATAINPUT_H
#define GRAPHDATA_DATAINPUT_H

#endif //GRAPHDATA_DATAINPUT_H

#include <iostream>
#include <vector>
#include <map>

/**
 * Метод для ввода матрицы смежности.
 * @param stream - Поток для ввода.
 * @return Матрица смежности.
 */
std::vector<std::vector<int>> AdjacencyMatrixInput(std::istream & stream);

/**
 * Метод для ввода матрицы инцидентности.
 * @param stream - Поток для ввода.
 * @return Матрица инцидентности.
 */
std::vector<std::vector<int>> IncidenceMatrixInput(std::istream & stream);

/**
 * Метод для ввода списка смежности.
 * @param stream - Поток для ввода.
 * @return Список смежности.
 */
std::map<int, std::vector<int>> AdjacencyListInput(std::istream & stream);

/**
 * Метод для ввода списка дуг.
 * @param stream - Поток для ввода.
 * @return Список дуг.
 */
std::vector<std::vector<int>> ListOfArcsInput(std::istream & stream);

/**
 * Метод для вывода матрицы смежности, матрицы инцидентности или списка дуг.
 * @param matrix - Матрица для вывода.
 * @param stream - Поток для вывода.
 */
void AdjIncidListOfArcsMatrixOutput(const std::vector<std::vector<int>>& matrix, std::ostream& stream);

/**
 * Метод для вывода списка смежности.
 * @param list - Список смежности.
 * @param stream - Поток для вывода.
 */
void AdjacencyListOutput(const std::map<int, std::vector<int>>& list, std::ostream& stream);
