#include <iostream>

#define THREE_MONTHS_INVESTMENTS 3
#define SIX_MONTHS_INVESTMENTS 6
#define ONE_YEAR_INVESTMENTS 12

double countProfit(double startSum, double percent, int months) {
    double profit = 0;
    while (months--) {
        profit += startSum * percent / 100;
    }

    return profit;
}

int main() {
    int inputMoney;
    std::cin >> inputMoney;

    int percentForThreeMonths, percentForSixMonths, percentForOneYear;
    std::cin >> percentForThreeMonths >> percentForSixMonths >> percentForOneYear;


    auto profitByThreeMonths = countProfit(inputMoney, percentForThreeMonths, THREE_MONTHS_INVESTMENTS);
    auto profitBySixMonths = countProfit(inputMoney, percentForSixMonths, SIX_MONTHS_INVESTMENTS);
    auto profitByOneYear = countProfit(inputMoney, percentForOneYear, ONE_YEAR_INVESTMENTS);

    if (profitByOneYear == std::max(std::max(profitByOneYear, profitBySixMonths), profitByThreeMonths)) {
        std::cout << "Deposit for one year is more profitable\n";
        std::cout << "Your profit will be " << profitByOneYear << " leaves";
    } else if (profitBySixMonths == std::max(std::max(profitByOneYear, profitBySixMonths), profitByThreeMonths)) {
        std::cout << "Deposit for six months is more profitable\n";
        std::cout << "Your profit will be " << profitBySixMonths << " leaves";
    } else {
        std::cout << "Deposit for three months is more profitable\n";
        std::cout << "Your profit will be " << profitByThreeMonths << " leaves";
    }

    return 0;
}