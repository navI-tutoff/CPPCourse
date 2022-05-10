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

// returns amounts of rows in matrix m
template<typename VT, typename CI>
std::vector<int> amountsOfRows(VT &m, CI nRows, CI nCols) {
    std::vector<int> resultAmounts;
    for (int i = 0; i < nRows; i++) {
        int sumOfRow = 0;
        for (int j = 0; j < nCols; j++) {
            sumOfRow += m.at(i).at(j);
        }
        resultAmounts.push_back(sumOfRow);
    }

    return resultAmounts;
}

// returns 'true' if amounts of rows are equal
// else - 'false'
template<typename VT, typename CI>
bool areAmountsOfRowsEqual(VT &m, CI nRows, CI nCols) {
    std::vector<int> v = amountsOfRows(m, nRows, nCols);
    bool areAmountsOfRowsEqual = true;
    for (int i = 0; i < v.size(); i++) {
        if (v.at(0) != v.at(i)) {
            areAmountsOfRowsEqual = false;
            return areAmountsOfRowsEqual;
        }
    }
    return areAmountsOfRowsEqual;
}

// returns amounts of cols in matrix m
template<typename VT, typename CI>
std::vector<int> amountsOfCols(VT &m, CI nRows, CI nCols) {
    std::vector<int> resultAmounts;
    for (int i = 0; i < nRows; i++) {
        int sumOfCol = 0;
        for (int j = 0; j < nCols; j++) {
            sumOfCol += m.at(j).at(i);
        }
        resultAmounts.push_back(sumOfCol);
    }

    return resultAmounts;
}

// returns 'true' if amounts of cols are equal
// else - 'false'
template<typename VT, typename CI>
bool areAmountsOfColsEqual(VT &m, CI nRows, CI nCols) {
    std::vector<int> v = amountsOfCols(m, nRows, nCols);
    bool areAmountsOfColsEqual = true;
    for (int i = 0; i < v.size(); i++) {
        if (v.at(0) != v.at(i)) {
            areAmountsOfColsEqual = false;
            return areAmountsOfColsEqual;
        }
    }
    return areAmountsOfColsEqual;
}

// returns sum of main diagonal
template<typename VT, typename CI>
int amountOfMainDiagonal(VT &m, CI nRows, CI nCols) {
    int mainDiagonalSum = 0;
    for (int i = 0, j = 0; i < nRows && j < nCols; i++, j++) {
        mainDiagonalSum += m.at(i).at(j);
    }

    return mainDiagonalSum;
}

// returns sum of secondary diagonal
template<typename VT, typename CI>
int amountOfSecondaryDiagonal(VT &m, CI nRows, CI nCols) {
    int secondaryDiagonalSum = 0;
    for (int i = 0, j = nCols - 1; i < nRows && j >= 0; i++, j--) {
        secondaryDiagonalSum += m.at(i).at(j);
    }

    return secondaryDiagonalSum;
}

// returns 'true' if main and secondary diagonals are equal
// else returns 'false'
template<typename VT, typename CI>
bool areAmountsOfDiagonalsEqual(VT &m, CI nRows, CI nCols) {
    return amountOfMainDiagonal(m, nRows, nCols) == amountOfSecondaryDiagonal(m, nRows, nCols);
}

// returns 'true' if matrix amounts of rows are equal, amounts of cols are equal,
// amounts of diagonals are equal, else returns 'false'
template<typename VT, typename CI>
bool isMagicSquare(VT &m, CI nRows, CI nCols) {
    if (areAmountsOfColsEqual(m, nRows, nCols) && areAmountsOfRowsEqual(m, nRows, nCols) &&
        areAmountsOfDiagonalsEqual(m, nRows, nCols)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int nRows, nCols;
    std::cin >> nRows >> nCols;

    std::vector<std::vector<int>> m;
    inputMatrix(m, nRows, nCols);

    bool result = isMagicSquare(m, nRows, nCols);
    if (result) {
        std::cout << "The matrix is magic square";
    } else {
        std::cout << "The matrix isn't magic square";
    }

    return 0;
}