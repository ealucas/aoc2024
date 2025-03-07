#include <iostream>
#include <vector>
#include <string>


int countXMAS(std::vector<std::vector<char>>& matrix){
    const std::vector<char> mas{'M', 'A', 'S'};
    int totalXmas = 0;
    // these vectors indicate the 8 possible directions
    std::vector<int> iDirection{0, 0, -1, 1, -1, -1, 1, 1};
    std::vector<int> jDirection{1, -1, 0, 0, -1, 1, -1, 1};

    for (int i=0; i<matrix.size(); i++){
        for (int j=0; j<matrix[0].size(); j++){
        
            if (matrix[i][j] != 'X')
                continue;
                            
            for (int k = 0; k < iDirection.size(); k++){
                int l = 1;    
                while (l <= mas.size() and 0 <= i + iDirection[k]*l && i + iDirection[k]*l < matrix.size() and 0 <= j + jDirection[k]*l && j + jDirection[k]*l < matrix.size()){
                    if (matrix[i+iDirection[k]*l][j+jDirection[k]*l] != mas[l-1])
                        break;
                    else
                        l++;
                }
                if (l == mas.size()+1)
                    ++totalXmas;
            } 
            
        }
    }

    return totalXmas;
}



int main() { 
    std::vector<std::vector<char>> matrix;
    std::string line;

    while(std::getline(std::cin, line)){
        std::vector<char> row(line.begin(), line.end());
        matrix.push_back(row);
    }

     int totalXmas = countXMAS(matrix);
     std::cout << totalXmas << std::endl;
}