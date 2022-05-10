#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int stringsNumber;
    std::cout << "Enter the number of lines ot text: ";
    std::cin >> stringsNumber;

    std::vector<std::string> text(stringsNumber);
    size_t maxLength = 0;
    std::string line;
    for (int i = 0; i < stringsNumber; i++) {
        std::getline(std::cin, line);
        text.at(i) = line;
        maxLength = std::max(maxLength, line.size());
    }

    for (auto &line: text) {
        std::cout << std::setw((maxLength + line.size() / 2));
        std::cout << std::right << line << '\n';
    }

    return 0;
}