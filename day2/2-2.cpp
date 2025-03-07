#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

bool validDifference(int difference) {
    return !(std::abs(difference) > 3 || difference == 0);
}

bool isSafe(const std::vector<int>& v) {
    bool allIncreasing = true;
    bool allDecreasing = true;

    for (int i = 0; i < v.size() - 1; i++) {
        int difference = v[i] - v[i + 1];

        if (!validDifference(difference)) {
            return false;
        }

        difference < 0 ? allDecreasing = false : allIncreasing = false;
        if (!allDecreasing && !allIncreasing) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string line;
    int safeCounter = 0;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::vector<int> numbers;

        int num;
        while (iss >> num) {
            numbers.push_back(num);
        }

        if (isSafe(numbers)) {
            safeCounter++;
        } else {
            for (int i = 0; i < numbers.size(); i++) {
                std::vector<int> lessNumbers = numbers;
                lessNumbers.erase(lessNumbers.begin() + i);

                if (isSafe(lessNumbers)) {
                    safeCounter++;
                    break; 
                }
            }
        }
    }

    std::cout << safeCounter << std::endl;
    return 0;
}