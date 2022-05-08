#include <iostream>
#include <vector>

// returns total equipment cost after markdown damagePercent percent
double countTotalEquipmentCostAfterMarkdown(const std::vector<double> &equipmentCost,
                                            const double &damagePercent) {
    double moneyDamage = 0;
    double sumOfEquipCost = 0;
    for (auto &spentMoneyPerYear: equipmentCost) {
        sumOfEquipCost += spentMoneyPerYear;
        moneyDamage += (sumOfEquipCost - moneyDamage) * (damagePercent / 100);
    }

    return sumOfEquipCost - moneyDamage;
}

int main() {
    int years, damagePercent;
    std::cin >> years >> damagePercent;

    std::vector<double> equipmentCost(years);
    for (auto &x: equipmentCost) {
        std::cin >> x;
    }

    auto costEquipAfterMarkdown = countTotalEquipmentCostAfterMarkdown(equipmentCost, damagePercent);
    std::cout << "Total equipment cost after " << damagePercent << "% markdown annually is " << costEquipAfterMarkdown << " leaves\n";

    return 0;
}