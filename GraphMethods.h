#ifndef GRAPHDATA_GRAPHMETHODS_H
#define GRAPHDATA_GRAPHMETHODS_H

#endif //GRAPHDATA_GRAPHMETHODS_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "DataInputAndOutput.h"
#include "DataConverter.h"

/**
 * Метод, проверяющий, является ли граф направленным или ненаправленным.
 * @param matrix - Матрица смежности
 * @return Значение, показывающее, является ли граф ориентированным.
 */
bool CheckDirectionalityOfAdjacencyMatrix(const std::vector<std::vector<int>>& matrix);

/**
 * Метод, позволяющий пользователю выбрать тип хранения графа.
 * @return Выбранный номер пункта из меню.
 */
int ChoosingDataType();

/**
 * Метод, показывающий пользователю меню и позволяющий выбрать один из вариантов.
 * @return Выбранный номер пункта из меню.
 */
int Menu();

/**
 * Структура, хранящая данные введенного графа.
 */
struct Graph {
    std::vector<std::vector<int>> adjacencyMatrix;
    std::vector<std::vector<int>> incidenceMatrix;
    std::map<int, std::vector<int>> adjacencyList;
    std::vector<std::vector<int>> listOfArcs;
    bool isDirected;
    int fileChoice = 0;

    /**
     * Конструктор класса, запрашивающий, откуда будет браться информация для графа, в каком виде,
     * и далее заполняющий все типы данных соответствующими представлениями графа.
     */
    Graph() {
        std::cout << "Are you going to use console or file to enter your graph?" << '\n' <<
        "1. Console." << '\n' << "2. File" << '\n' << "Please, enter a number: " << '\n';
        int choice;
        std::cin >> fileChoice;
        choice = ChoosingDataType();
        std::ifstream fileStream("../GraphInput.txt");
        switch (choice) {
            case 1:
                adjacencyMatrix = fileChoice == 1 ? AdjacencyMatrixInput(std::cin) : AdjacencyMatrixInput(fileStream);
                incidenceMatrix = ConvertAdjacencyMatrixToIncidence(adjacencyMatrix);
                adjacencyList = ConvertAdjacencyMatrixToList(adjacencyMatrix);
                listOfArcs = ConvertAdjacencyMatrixToListOfArcs(adjacencyMatrix);
                break;
            case 2:
                incidenceMatrix = fileChoice == 1 ? IncidenceMatrixInput(std::cin) : IncidenceMatrixInput(fileStream);
                adjacencyMatrix = ConvertIncidenceToAdjacency(incidenceMatrix);
                adjacencyList = ConvertAdjacencyMatrixToList(adjacencyMatrix);
                listOfArcs = ConvertAdjacencyMatrixToListOfArcs(adjacencyMatrix);
                break;
            case 3:
                adjacencyList = fileChoice == 1 ? AdjacencyListInput(std::cin) : AdjacencyListInput(fileStream);
                adjacencyMatrix = ConvertAdjacencyListToMatrix(adjacencyList);
                incidenceMatrix = ConvertAdjacencyMatrixToIncidence(adjacencyMatrix);
                listOfArcs = ConvertAdjacencyMatrixToListOfArcs(adjacencyMatrix);
                break;
            case 4:
                listOfArcs =  fileChoice == 1 ? ListOfArcsInput(std::cin) : ListOfArcsInput(fileStream);
                adjacencyMatrix = ConvertListOfArcsToMatrix(listOfArcs);
                incidenceMatrix = ConvertAdjacencyMatrixToIncidence(adjacencyMatrix);
                adjacencyList = ConvertAdjacencyMatrixToList(adjacencyMatrix);
                break;
        }
        isDirected = CheckDirectionalityOfAdjacencyMatrix(adjacencyMatrix);
        std::cout << "Your graph data has been successfully saved!" << '\n';
        fileStream.close();
    }

    /**
     * Метод, считающий количество ребер, если граф не ориентированный и количество дуг, если граф
     * ориентированный, проходясь по матрице смежности и считая количество единиц.
     * @return Количество рёбер.
     */
    int CountNumberOfEdges() {
        int countOfArcs = 0;
        for (auto & i : adjacencyMatrix) {
            for (size_t j = 0; j < adjacencyMatrix.size(); ++j) {
                if (i[j] == 1) {
                    ++countOfArcs;
                }
            }
        }
        if (isDirected) {
            return countOfArcs;
        } else {
            return countOfArcs / 2;
        }
    }

    /**
     * Метод, выводящий стпени вершин, если граф не ориентированный и полустепени вершин, если
     * граф ориентированный. Метод проходится по матрице смежности и считает количество единиц у вершин.
     * @param stream - Поток для вывода степеней.
     */
    void CountDegrees(std::ostream& stream) {
        if (!isDirected) {
            stream << "Vertices degrees: " << '\n' << '(';
            for (auto [vertex, list] : adjacencyList) {
                stream << list.size() << "; ";
            }
            stream << ')' << '\n';
        } else {
            int count;
            stream << "Vertices outdegrees: " << '\n' << '(';
            //Подсчет полустепеней исхода
            for (auto & i : adjacencyMatrix) {
                count = 0;
                for (auto & j :i) {
                    if (j == 1) {
                        ++count;
                    }
                }
                stream << count << "; ";
            }
            stream << ')' << '\n';
            //Подсчет полустепеней захода
            stream << "Vertices indegrees: " << '\n' << '(';
            for (size_t j = 0; j < adjacencyMatrix.size(); ++j) {
                count = 0;
                for (auto & vec : adjacencyMatrix) {
                    if (vec[j] == 1) {
                        ++count;
                    }
                }
                stream << count << "; ";
            }
            stream << ')' << '\n';
        }
    }
};