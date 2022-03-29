#include <fstream>
#include <iostream>
#include <stdexcept>

long long getSum(const std::string &filename) {
    std::ifstream inputFile(filename);

    if (!inputFile) {
        throw std::runtime_error("File doesn't exist");
    }

    long long sum = 0;
    int x;
    while (inputFile >> x) {
        sum += x;
    }

    return sum;
}

int max(const int a, const int b) {
    return a > b ? a : b;
}

long long getSumOfMaxesInRows(const std::string &filename) {
    std::fstream inputFile(filename);

    if (!inputFile) {
        throw std::runtime_error("File doesn't exist");
    }

    int sumOfMaxesInRows = 0;
    int height, width;
    inputFile >> height;   // считываем первые два значения
    inputFile >> width;    // для установления размеров матрицы

    for (int i = 0; i < height; i++) {
        int maxInRow;
        inputFile >> maxInRow;
        for (int j = 1; j < width; j++) {
            int value;
            inputFile >> value;
            maxInRow = max(value, maxInRow);
        }
        sumOfMaxesInRows += maxInRow;
    }

    return sumOfMaxesInRows;
}

int main() {
    std::cout << getSumOfMaxesInRows("input.txt");

    return 0;
}



//// вывод осуществляется в поток, связанный с логами
//#define TIME_TEST(testCode, message) { \
//    clock_t start_time = clock (); \
//    testCode                           \
//    clock_t end_time = clock ();       \
//    clock_t sort_time = end_time - start_time; \
//    std::clog << message << ": " << (double) sort_time/CLOCKS_PER_SEC << std::endl;\
//}
//
//int main() {
//    const char *filename = "tmp.txt";
//    std::ofstream file(filename);
//
//    TIME_TEST({
//                  for (int i = 0; i < 1000000; i++) {
//                      file << 'a' << std::endl;
//                  }
//              }, "Often buffer reset");
//
//    TIME_TEST({
//                  for (int i = 0; i < 1000000; i++) {
//                      file << 'a' << '\n';
//                  }
//              }, "Buffer opt");
//
//    file.close();
//    std::remove(filename);
//
//    return 0;
//}