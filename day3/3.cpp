#include <iostream>
#include <sstream>
#include <regex>
#include <string>

void solveRightAway(std::istream& input) {
    std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    int total = 0;
    std::string line;

    while (std::getline(input, line)) { 
        std::sregex_iterator it(line.begin(), line.end(), pattern);
        std::sregex_iterator end;

        while (it != end) {
            std::smatch match = *it;

            if (match.size() > 2) { 
                int a = std::stoi(match[1].str());
                int b = std::stoi(match[2].str());
                total += a * b;
            }
            ++it;
        }
    }

    std::cout << total << std::endl;
}

void solveHandlingInputs(std::istream& input) {
    std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))");

    int total = 0;
    bool ignore = false;
    std::string line;
    
    
    while (std::getline(input, line)) { 
        std::sregex_iterator it(line.begin(), line.end(), pattern);
        std::sregex_iterator end;

        while (it != end) {
            std::smatch match = *it;
            std::string matchedStr = match.str();

            if (matchedStr == "don't()") ignore = true;
            else if (matchedStr == "do()") ignore = false;
            else if (!ignore && match.size() > 2) {
                int a = std::stoi(match[1].str());
                int b = std::stoi(match[2].str());
                total += a * b;
            }

            ++it;
        }
    } 
    std::cout << total << std::endl;
}

int main() {
    std::stringstream buffer;
    buffer << std::cin.rdbuf(); 


    solveRightAway(buffer);
    buffer.clear();  
    buffer.seekg(0); 
    solveHandlingInputs(buffer);

    return 0;
}
