#include <iostream>
#include <valarray>
#include <cassert>

struct Triangle {
    std::pair<double, double> _first_coordinate;
    std::pair<double, double> _second_coordinate;
    std::pair<double, double> _third_coordinate;

    Triangle(const std::pair<double, double> &first_coordinate,
             const std::pair<double, double> &second_coordinate,
             const std::pair<double, double> &third_coordinate) {
        _first_coordinate = first_coordinate;
        _second_coordinate = second_coordinate;
        _third_coordinate = third_coordinate;
    }

    // returns distance between first and second coordinates
    auto findDistanceBetweenFirstAndSecondCoordinates(Triangle t) {
        auto distanceBetweenFirstAndSecondCoordinates = std::sqrt(std::pow(t._first_coordinate.first - t._second_coordinate.first, 2) +
                std::pow(t._first_coordinate.second - t._second_coordinate.second, 2));

        return distanceBetweenFirstAndSecondCoordinates;
    }

    // returns distance between second and third coordinates
    auto findDistanceBetweenSecondAndThirdCoordinates(Triangle t) {
        auto distanceBetweenSecondAndThirdCoordinates = std::sqrt(std::pow(t._second_coordinate.first - t._third_coordinate.first, 2) +
                std::pow(t._second_coordinate.second - t._third_coordinate.second, 2));

        return distanceBetweenSecondAndThirdCoordinates;
    }

    // returns distance between first and third coordinates
    auto findDistanceBetweenFirstAndThirdCoordinates(Triangle t) {
        auto distanceBetweenFirstAndThirdCoordinates = std::sqrt(std::pow(t._first_coordinate.first - t._third_coordinate.first, 2) +
                std::pow(t._first_coordinate.second - t._third_coordinate.second, 2));

        return distanceBetweenFirstAndThirdCoordinates;
    }

    // returns triangle t perimeter
    auto findTrianglePerimeter(Triangle t) {
        auto perimeter = findDistanceBetweenFirstAndSecondCoordinates(t) +
                findDistanceBetweenSecondAndThirdCoordinates(t) +
                findDistanceBetweenFirstAndThirdCoordinates(t);

        return perimeter;
    }

    // returns triangle t square
    auto findTriangleSquare(Triangle t) {
        // s = sqrt(p * (p - a) * (p - b) * (p - c))
        auto semi_perimeter = findTrianglePerimeter(t) / 2;
        auto square = std::sqrt
                (semi_perimeter * (semi_perimeter - findDistanceBetweenFirstAndSecondCoordinates(t)) *
                (semi_perimeter - findDistanceBetweenFirstAndThirdCoordinates(t)) *
                (semi_perimeter - findDistanceBetweenSecondAndThirdCoordinates(t)));

        return square;
    }

    // returns len median to side A
    // side A -> distance between first and second coordinates
    auto findLengthMedianToSideA(Triangle t) {
        auto lengthMedianToSideA = 0.5 *
                std::sqrt(2 * std::pow(findDistanceBetweenSecondAndThirdCoordinates(t), 2) +
                2 * std::pow(findDistanceBetweenFirstAndThirdCoordinates(t), 2) -
                std::pow(findDistanceBetweenFirstAndSecondCoordinates(t), 2));

        return lengthMedianToSideA;
    }

    // returns len median to side B
    // side B -> distance between second and third coordinates
    auto findLengthMedianToSideB(Triangle t) {
        auto lengthMedianToSideB = 0.5 *
                std::sqrt(2 * std::pow(findDistanceBetweenFirstAndThirdCoordinates(t), 2) +
                2 * std::pow(findDistanceBetweenFirstAndSecondCoordinates(t), 2) -
                std::pow(findDistanceBetweenSecondAndThirdCoordinates(t), 2));

        return lengthMedianToSideB;
    }

    // returns len median to side C
    // side C -> distance between first and third coordinates
    auto findLengthMedianToSideC(Triangle t) {
        auto lengthMedianToSideC = 0.5 *
                std::sqrt(2 * std::pow(findDistanceBetweenFirstAndSecondCoordinates(t), 2) +
                2 * std::pow(findDistanceBetweenSecondAndThirdCoordinates(t), 2) -
                std::pow(findDistanceBetweenFirstAndThirdCoordinates(t), 2));

        return lengthMedianToSideC;
    }

    // returns sum of medians of a triangle t
    auto findSumOfMedians(Triangle t) {
        return findLengthMedianToSideC(t) + findLengthMedianToSideA(t) + findLengthMedianToSideB(t);
    }

    void outputTriangle(Triangle &t) {
        std::cout << "Triangle coordinates: " << '{' << t._first_coordinate.first << ", " << t._first_coordinate.second
                  << "}; {" <<
                  t._second_coordinate.first << ", " << t._second_coordinate.second << "}; {" <<
                  t._third_coordinate.first << ", " << t._third_coordinate.second << "}\n";
    }
};

void test_findDistanceBetweenFirstAndSecondCoordinates_find1() {
    Triangle t({-1, 0}, {3, 0}, {3, 3});
    // sqrt((x1 - x2)^2 + (y1 - y2)^2)
    auto awaitedResult = std::sqrt(std::pow(-1 - 3, 2) + std::pow(0 - 0, 2));
    auto gottenResult = t.findDistanceBetweenFirstAndSecondCoordinates(t);

    assert(awaitedResult == gottenResult);
}

void test_findDistanceBetweenSecondAndThirdCoordinates_find1() {
    Triangle t({-1, 0}, {3, 0}, {3, 3});
    // sqrt((x2 - x3)^2 + (y2 - y3)^2)
    auto awaitedResult = std::sqrt(std::pow(3 - 3, 2) + std::pow(0 - 3, 2));
    auto gottenResult = t.findDistanceBetweenSecondAndThirdCoordinates(t);

    assert(awaitedResult == gottenResult);
}

void test_findDistanceBetweenFirstAndThirdCoordinates_find1() {
    Triangle t({-1, 0}, {3, 0}, {3, 3});
    // sqrt((x1 - x3)^2 + (y1 - y3)^2)
    auto awaitedResult = std::sqrt(std::pow(-1 - 3, 2) + std::pow(0 - 3, 2));
    auto gottenResult = t.findDistanceBetweenFirstAndThirdCoordinates(t);

    assert(awaitedResult == gottenResult);
}

void test_findDistanceFunc() {
    test_findDistanceBetweenFirstAndSecondCoordinates_find1();
    test_findDistanceBetweenSecondAndThirdCoordinates_find1();
    test_findDistanceBetweenFirstAndThirdCoordinates_find1();
}

void test_findTrianglePerimeter_find1() {
    Triangle t({-1, 0}, {3, 0}, {3, 3});
    // sum of all distances between everyone points
    auto awaitedResult = t.findDistanceBetweenFirstAndThirdCoordinates(t) +
            t.findDistanceBetweenFirstAndSecondCoordinates(t) +
            t.findDistanceBetweenSecondAndThirdCoordinates(t);
    // find distances functions already tested, why i cant use them? :)
    auto gottenResult = t.findTrianglePerimeter(t);

    assert(awaitedResult == gottenResult);
}

void test_findTrianglePerimeter_find2() {
    Triangle t({0, -2}, {3, 3}, {0, 3});
    auto awaitedResult = t.findDistanceBetweenFirstAndThirdCoordinates(t) +
                         t.findDistanceBetweenFirstAndSecondCoordinates(t) +
                         t.findDistanceBetweenSecondAndThirdCoordinates(t);
    auto gottenResult = t.findTrianglePerimeter(t);

    assert(awaitedResult == gottenResult);
}

void test_findTrianglePerimeter() {
    test_findTrianglePerimeter_find1();
    test_findTrianglePerimeter_find2();
}

void test_findTriangleSquare_find1() {
    Triangle t({-1, 0}, {3, 0}, {3, 3});
    // sqrt(p * (p - a) * (p - b) * (p - c)
    auto semi_perimeter = t.findTrianglePerimeter(t) / 2;
    auto awaitedResult = std::sqrt(semi_perimeter *
            (semi_perimeter - t.findDistanceBetweenFirstAndSecondCoordinates(t)) *
            (semi_perimeter - t.findDistanceBetweenFirstAndThirdCoordinates(t)) *
            (semi_perimeter - t.findDistanceBetweenSecondAndThirdCoordinates(t)));
    auto gottenResult = t.findTriangleSquare(t);

    assert(gottenResult == awaitedResult);
}

void test_findTriangleSquare_find2() {
    Triangle t({0, -2}, {3, 3}, {0, 3});
    auto semi_perimeter = t.findTrianglePerimeter(t) / 2;
    auto awaitedResult = std::sqrt(semi_perimeter *
            (semi_perimeter - t.findDistanceBetweenFirstAndSecondCoordinates(t)) *
            (semi_perimeter - t.findDistanceBetweenFirstAndThirdCoordinates(t)) *
            (semi_perimeter - t.findDistanceBetweenSecondAndThirdCoordinates(t)));
    auto gottenResult = t.findTriangleSquare(t);

    assert(gottenResult == awaitedResult);

}

void test_findTriangleSquare() {
    test_findTriangleSquare_find1();
    test_findTriangleSquare_find2();
}

void test_findLengthMedianToSideA_find1() {
    Triangle t({-1, 0}, {3, 0}, {3, 3});
    // 1/2 * sqrt(2b^2 + 2c^2 - a^2)
    auto awaitedResult = 0.5 *
            std::sqrt(2 * std::pow(t.findDistanceBetweenSecondAndThirdCoordinates(t), 2) +
            2 * std::pow(t.findDistanceBetweenFirstAndThirdCoordinates(t), 2) -
            std::pow(t.findDistanceBetweenFirstAndSecondCoordinates(t), 2));
    auto gottenResult = t.findLengthMedianToSideA(t);

    assert(gottenResult == awaitedResult);
}

void test_findLengthMedianToSideB_find1() {
    Triangle t({-1, 0}, {3, 0}, {3, 3});
    // 1/2 * sqrt(2a^2 + 2c^2 - b^2)
    auto awaitedResult = 0.5 *
            std::sqrt(2 * std::pow(t.findDistanceBetweenFirstAndSecondCoordinates(t), 2) +
            2 * std::pow(t.findDistanceBetweenFirstAndThirdCoordinates(t), 2) -
            std::pow(t.findDistanceBetweenSecondAndThirdCoordinates(t), 2));
    auto gottenResult = t.findLengthMedianToSideB(t);

    assert(gottenResult == awaitedResult);
}

void test_findLengthMedianToSideC_find1() {
    Triangle t({-1, 0}, {3, 0}, {3, 3});
    // 1/2 * sqrt(2a^2 + 2b^2 - c^2)
    auto awaitedResult = 0.5 *
            std::sqrt(2 * std::pow(t.findDistanceBetweenFirstAndSecondCoordinates(t), 2) +
            2 * std::pow(t.findDistanceBetweenSecondAndThirdCoordinates(t), 2) -
            std::pow(t.findDistanceBetweenFirstAndThirdCoordinates(t), 2));
    auto gottenResult = t.findLengthMedianToSideC(t);

    assert(gottenResult == awaitedResult);
}

void test_findLengthMedian() {
    test_findLengthMedianToSideA_find1();
    test_findLengthMedianToSideB_find1();
    test_findLengthMedianToSideC_find1();
}

void test_findSumOfMedians_find1() {
    Triangle t({-1, 0}, {3, 0}, {3, 3});
    auto awaitedResult = t.findLengthMedianToSideA(t) +
            t.findLengthMedianToSideB(t) +
            t.findLengthMedianToSideC(t);
    auto gottenResult = t.findSumOfMedians(t);

    assert(gottenResult == awaitedResult);
}

void test_findSumOfMedians_find2() {
    Triangle t({0, -2}, {3, 3}, {0, 3});
    auto awaitedResult = t.findLengthMedianToSideA(t) +
                         t.findLengthMedianToSideB(t) +
                         t.findLengthMedianToSideC(t);
    auto gottenResult = t.findSumOfMedians(t);

    assert(gottenResult == awaitedResult);
}

void test_findSumOfMedians() {
    test_findSumOfMedians_find1();
    test_findSumOfMedians_find2();
}

void testTriangleStruct() {
    test_findDistanceFunc();
    test_findTrianglePerimeter();
    test_findTriangleSquare();
    test_findLengthMedian();
    test_findSumOfMedians();
}

int main() {
    testTriangleStruct();

    return 0;
}