#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

#define INCREASING 1
#define DECREASING -1
#define NOT_DEFINED 0

int main() {
    std::string line;
    
    // Read input line by line
    int safeCounter = 0;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        int prevNumber;
        int newNumber;
        int sequenceOrder = NOT_DEFINED;
        iss >> prevNumber;
        iss >> newNumber;


        int result = prevNumber - newNumber;

        if (std::abs(result) == 0 or std::abs(result) > 3){
          continue;} // unsafe -> differnece is 0 or greater than 3
        if (result < 0){sequenceOrder = INCREASING;}
        else {sequenceOrder = DECREASING;}

        prevNumber = newNumber;

        bool safe = true;
        
        while(iss >> newNumber){
          result = prevNumber - newNumber;
          if (std::abs(result) == 0 or std::abs(result) > 3){
            safe = false;
            break;
          }
          if (result < 0 && sequenceOrder == DECREASING){
            safe = false;
            break;
          }
          if (result > 0 && sequenceOrder == INCREASING){
            safe = false;
            break;
          }

          prevNumber = newNumber;
        }

        if (safe){safeCounter++;};
    }
        
    std::cout << safeCounter << std::endl;
    return 0;
}