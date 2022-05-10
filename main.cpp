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
    // too late understood the meaning of the magic square (crutches) :c
    std::vector<int> amountsRows = amountsOfRows(m, nRows, nCols);
    std::vector<int> amountsCols = amountsOfCols(m, nRows, nCols);
    if (areAmountsOfRowsEqual(m, nRows, nCols) && areAmountsOfColsEqual(m, nRows, nCols) &&
        areAmountsOfDiagonalsEqual(m, nRows, nCols) &&
        amountOfMainDiagonal(m, nRows, nCols) == amountsRows.front() &&
        amountOfMainDiagonal(m, nRows, nCols) == amountsCols.front()) {
        return true;
    } else {
        return false;
    }
}

void test_areAmountsOfRowsEqual_areEqual() {
    std::vector<std::vector<int>> m = {{1, 2, 3},
                                       {3, 2, 1},
                                       {0, 0, 6}};
    bool awaitedAreAmountsOfRowsEqual = true;
    bool gottenResult = areAmountsOfRowsEqual(m, 3, 3);

    assert(awaitedAreAmountsOfRowsEqual == gottenResult);
}

void test_areAmountsOfRowsEqual_arentEqual() {
    std::vector<std::vector<int>> m = {{1, 4,  3},
                                       {3, 2,  1},
                                       {0, 24, 6}};
    bool awaitedAreAmountsOfRowsEqual = false;
    bool gottenResult = areAmountsOfRowsEqual(m, 3, 3);

    assert(awaitedAreAmountsOfRowsEqual == gottenResult);
}

void test_areAmountsOfRowsEqual() {
    test_areAmountsOfRowsEqual_areEqual();
    test_areAmountsOfRowsEqual_arentEqual();
}

void test_areAmountsOfColsEqual_areEqual() {
    std::vector<std::vector<int>> m = {{1, 2, 4},
                                       {3, 2, 4},
                                       {0, 0, -4}};
    bool awaitedAreAmountsOfColsEqual = true;
    bool gottenResult = areAmountsOfColsEqual(m, 3, 3);

    assert(awaitedAreAmountsOfColsEqual == gottenResult);
}

void test_areAmountsOfColsEqual_arentEqual() {
    std::vector<std::vector<int>> m = {{1,  2,  -4, 11},
                                       {3,  2,  4,  3},
                                       {15, 14, 19, 5},
                                       {0,  0,  0,  0}};
    bool awaitedAreAmountsOfRowsEqual = false;
    bool gottenResult = areAmountsOfRowsEqual(m, 4, 4);

    assert(awaitedAreAmountsOfRowsEqual == gottenResult);
}

void test_areAmountsOfColsEqual() {
    test_areAmountsOfColsEqual_areEqual();
    test_areAmountsOfColsEqual_arentEqual();
}

void test_areAmountsOfDiagonalsEqual_areEqual() {
    std::vector<std::vector<int>> m = {{1,  2,  -4, 3},
                                       {3,  2,  4,  3},
                                       {15, 14, 19, 5},
                                       {1,  3,  7,  0}};
    bool awaitedAreAmountsOfDiagonalEqual = true;
    bool gottenResult = areAmountsOfDiagonalsEqual(m, 4, 4);

    assert(awaitedAreAmountsOfDiagonalEqual == gottenResult);
}

void test_areAmountsOfDiagonalsEqual_arentEqual() {
    std::vector<std::vector<int>> m = {{1,  2,  -4, 1},
                                       {3,  2,  4,  3},
                                       {15, 14, 19, 5},
                                       {3,  3,  7,  0}};
    bool awaitedAreAmountsOfRowsEqual = false;
    bool gottenResult = areAmountsOfRowsEqual(m, 4, 4);

    assert(awaitedAreAmountsOfRowsEqual == gottenResult);
}

void test_areAmountsOfDiagonalsEqual() {
    test_areAmountsOfDiagonalsEqual_areEqual();
    test_areAmountsOfDiagonalsEqual_arentEqual();
}

void test_isMagicSquare_true() {
    std::vector<std::vector<int>> m = {{1, 6, 5},
                                       {8, 4, 0},
                                       {3, 2, 7}};
    bool awaitedIsMagicSquare = true;
    bool gottenResult = isMagicSquare(m, 3, 3);

    assert(awaitedIsMagicSquare == gottenResult);
}

void test_isMagicSquare_false() {
    std::vector<std::vector<int>> m = {{0, 6, 5},
                                       {8, 4, 0},
                                       {3, 2, 7}};
    bool awaitedIsMagicSquare = false;
    bool gottenResult = isMagicSquare(m, 3, 3);

    assert(awaitedIsMagicSquare == gottenResult);
}

void test_isMagicSquare() {
    test_isMagicSquare_true();
    test_isMagicSquare_false();
}

int main() {
    test_areAmountsOfRowsEqual();
    test_areAmountsOfColsEqual();
    test_areAmountsOfDiagonalsEqual();
    test_isMagicSquare();

    return 0;
}