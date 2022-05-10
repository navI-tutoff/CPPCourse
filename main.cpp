#include <iostream>
#include <vector>

bool isDivisibleByEachOfItsDigits(const int n) {
    int copyN = n;
    bool flag = true;
    while (copyN && flag) {
        if (copyN % 10 == 0 || copyN % (copyN % 10) != 0) {
            flag = false;
        } else {
            copyN /= 10;
        }
    }

    return flag;
}

// returns vector with all numbers with divisible by each of its digits
std::vector<int> getAllNumbersWithDivisibleByEachOfItsDigits(const int n) {
    std::vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (isDivisibleByEachOfItsDigits(i)) {
            res.push_back(i);
        }
    }

    return res;
}

int main() {
    int n;
    std::cin >> n;

    auto res = getAllNumbersWithDivisibleByEachOfItsDigits(n);
    for (auto &x: res) {
        std::cout << x << ' ';
    }

    return 0;
}