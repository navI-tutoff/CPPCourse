#include <iostream>
#include <fstream>
#include <ctime>

void infinitivePause() {
    while (true) {}
}

#include <iostream>

int main() {
    bool smthPrettyImportant = true;

    if (!(10 < 5)) {
        smthPrettyImportant = false;
    }

    if (!smthPrettyImportant) {
        std::clog << "Fatal Error" << '\n';
        std::cerr << "Self-destruct in 3...";
    }

    infinitivePause();

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