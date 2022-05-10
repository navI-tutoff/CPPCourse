#include <iostream>

int main() {
    std::string z;
    std::cin >> z;

    int counter = 1;
    int maxLen = 0;
    for (int i = 0; i < z.size() - 1; i++) {
        if (z.at(i) != z.at(i + 1)) {
            counter++;
        } else {
            maxLen = counter;
            counter = 1;
        }
    }

    maxLen = std::max(maxLen, counter);
    std::cout << maxLen;

    return 0;
}