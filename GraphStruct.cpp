#include <iostream>
#include <vector>
#include "GraphMethods.h"

/**
 * Метод проходится по матрице смежности и проверяет её на симметричность. Если симметрична - граф
 * не ориентированный.
 * @param matrix - Матрица смежности.
 * @return Значение, показывающее, является ли граф ориентированным.
 */
bool CheckDirectionalityOfAdjacencyMatrix(const std::vector<std::vector<int>>& matrix) {
    bool isDirected = false;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                isDirected = true;
                break;
            }
            if (isDirected) {
                break;
            }
        }
    }
    return isDirected;
}

/**
 * Метод выводит подсказки для пользователя и запрашивает ввод числа.
 * @return Выбранный номер пункта из меню.
 */
int ChoosingDataType() {
    std::cout << "How do you want to store the graph data?" << '\n' << "1. Adjacency Matrix" << '\n'
              << "2. Incidence Matrix" << '\n' << "3. Adjacency List" << '\n' << "4. List of Edges" << '\n';
    std::cout << "Please enter the number: " << '\n';
    int choice;
    std::cin >> choice;
    return choice;
}

/**
 * Метод выводит меню для пользователя и запрашивает ввод числа.
 * @return Метод выводит меню для пользователя и запрашивает ввод числа.
 */
int Menu() {
    std::cout << "What would you like to do next?" << '\n'
              << "1. Get the adjacency matrix of the graph." << '\n'
              << "2. Get the incidence matrix of the graph." << '\n'
              << "3. Get the adjacency list of the graph." << '\n'
              << "4. Get the list of arks/edges of the graph." << '\n'
              << "5. Get the number of arcs/edges." << '\n'
              << "6. Get the degrees of vertices." << '\n'
              << "7. Restart program." << '\n'
              << "8. Stop the program." << '\n'
              << "Please, enter the number: " << '\n';
    int choice;
    std::cin >> choice;
    return choice;
}