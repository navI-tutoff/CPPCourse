#include <iostream>
#include <vector>
#include <cassert>

template<typename VT, typename CI>
void inputMatrix(VT &m, CI nRows, CI nCols) {
    for (int i = 0; i < nRows; i++) {
        std::vector<int> vectorCols(nCols);
        for (int j = 0; j < nCols; j++) {
            std::cin >> vectorCols.at(j);
        }
        m.push_back(vectorCols);
    }
}

template<typename VT, typename CI>
void outputMatrix(VT &m, CI nRows, CI nCols) {
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            std::cout << m.at(i).at(j) << ' ';
        }
        std::cout << '\n';
    }
}

std::vector<std::vector<int>> transposeMatrix(std::vector<std::vector<int>> &m) {
    int nRows = m.size();
    int nCols = m.at(0).size();
    std::vector<std::vector<int>> newMatrix(nCols, std::vector<int>(nRows)); // transpose
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            newMatrix.at(j).at(i) = m.at(i).at(j);
        }
    }

    return newMatrix;
}

std::vector<std::vector<int>> multiplyMatrices(std::vector<std::vector<int>> &m1,
                                               std::vector<std::vector<int>> &m2) {
    int m1NRows = m1.size();
    int m1NCols = m1.at(0).size();
    int m2NCols = m2.at(0).size();
    std::vector<std::vector<int>> newMatrix(m1NRows, std::vector<int>(m2NCols));

    for (int i = 0; i < m1NRows; i++)  {
        for (int j = 0; j < m2NCols; j++) {
            for (int k = 0; k < m1NCols; k++) {
                newMatrix.at(i).at(j) += m1.at(i).at(k) * m2.at(k).at(j);
            }
        }
    }

    return newMatrix;
}

std::vector<std::vector<int>> calculateValueOfTheQuadraticForm(std::vector<std::vector<int>> &m1,
                                                               std::vector<std::vector<int>> &m2) {
    std::vector<std::vector<int>> tm1 = transposeMatrix(m1);
    std::vector<std::vector<int>> firstMove = multiplyMatrices(tm1, m2);

    return multiplyMatrices(firstMove, m1);
}

int main() {
    int nRows, nCols;
    std::cin >> nRows >> nCols;


    std::vector<std::vector<int>> vector_x;
    inputMatrix(vector_x, nRows, 1);

    std::vector<std::vector<int>> matrix;
    inputMatrix(matrix, nRows, nCols);

    std::vector<std::vector<int>> resMatrix = calculateValueOfTheQuadraticForm(vector_x, matrix);

    outputMatrix(resMatrix, 1, 1);

    return 0;
}