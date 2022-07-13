#include <iostream>
#include <fstream>
#include "GraphMethods.h"

/**
 *  Основной метод программы, вызывающий все необходимые методы по очереди.
Реализован с помощью двух циклов while (для повтора решения и выхода из программы)
и switch - кейса. (Извиняюсь за длинный метод, но так вышло из-за свич кейса, не бейте, пожалуйста ^-^)
 * @return Код завершения программы.
 */
int main() {
    while (true) {
        bool endProgram = false;
        std::cout << "Welcome, my dear friend!" << '\n';
        Graph mainGraph = Graph();
        //Очистка файла вывода.
        std::ofstream fileStream("../GraphOutput.txt", std::ofstream::out | std::ofstream::trunc);
        fileStream.close();
        while (true) {
            bool restartProgram = false;
            int choice = Menu();
            switch (choice) {
                case 1:
                    fileStream.open("../GraphOutput.txt", std::ios_base::app);
                    mainGraph.fileChoice == 1
                    ? (AdjIncidListOfArcsMatrixOutput(mainGraph.adjacencyMatrix, std::cout), std::cout << '\n')
                    : (AdjIncidListOfArcsMatrixOutput(mainGraph.adjacencyMatrix, fileStream), fileStream << '\n');
                    fileStream.close();
                    break;
                case 2:
                    fileStream.open("../GraphOutput.txt", std::ios_base::app);
                    mainGraph.fileChoice == 1
                    ? (AdjIncidListOfArcsMatrixOutput(mainGraph.incidenceMatrix, std::cout), std::cout << '\n')
                    : (AdjIncidListOfArcsMatrixOutput(mainGraph.incidenceMatrix, fileStream), fileStream << '\n');
                    fileStream.close();
                    break;
                case 3:
                    fileStream.open("../GraphOutput.txt", std::ios_base::app);
                    mainGraph.fileChoice == 1
                    ? (AdjacencyListOutput(mainGraph.adjacencyList, std::cout), std::cout << '\n')
                    : (AdjacencyListOutput(mainGraph.adjacencyList, fileStream), fileStream << '\n');
                    fileStream.close();
                    break;
                case 4:
                    fileStream.open("../GraphOutput.txt", std::ios_base::app);
                    mainGraph.fileChoice == 1
                    ? (AdjIncidListOfArcsMatrixOutput(mainGraph.listOfArcs, std::cout), std::cout << '\n')
                    : (AdjIncidListOfArcsMatrixOutput(mainGraph.listOfArcs, fileStream), fileStream << '\n');
                    fileStream.close();
                    break;
                case 5:
                    fileStream.open("../GraphOutput.txt", std::ios_base::app);
                    mainGraph.fileChoice == 1
                    ? std::cout << "Number of edges (or arcs):" << '\n' << mainGraph.CountNumberOfEdges() << '\n'
                    : fileStream << "Number of edges (or arcs):" << '\n' << mainGraph.CountNumberOfEdges() << '\n';
                    fileStream.close();
                    break;
                case 6:
                    fileStream.open("../GraphOutput.txt", std::ios_base::app);
                    mainGraph.fileChoice == 1 ? mainGraph.CountDegrees(std::cout)
                    : mainGraph.CountDegrees(fileStream);
                    fileStream.close();
                    break;
                case 7:
                    restartProgram = true;
                    break;
                case 8:
                    endProgram = true;
                    break;
            }
            if (endProgram || restartProgram) break;
        }
        if (endProgram) break;
    }
}