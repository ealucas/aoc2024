#include <iostream>
#include <vector>
#include <string>


int countXMAS(std::vector<std::vector<char>>& matrix){
    const std::vector<char> ms{'M', 'S'};
    int totalXmas = 0;
    // these vectors indicate the 2 possible directions
    std::vector<int> iDirection{1, 1};
    std::vector<int> jDirection{-1, 1};

    for (int i=0; i<matrix.size(); i++){
        for (int j=0; j<matrix[0].size(); j++){
            
            if (matrix[i][j] != 'A')
                continue;
            std::cout << "(i,j) -> " << matrix[i][j] << std::endl;
                bool validIndexes = true;

            for (int k=0; k < iDirection.size(); k++){
               for (int l=1, m=0; m < 2; l *= -1, m++){
                if (i+iDirection[k]*l < 0 or i+iDirection[k]*l >= matrix.size() or j+iDirection[k]*l < 0 or j+jDirection[k]*l >= matrix[0].size())
                    validIndexes = false;
               }
            }

            if (!validIndexes)
                continue;

            int diagonalXmasFound = 0;
            for (int k=0; k < iDirection.size(); k++){
                if ((matrix[i+iDirection[k]][j+jDirection[k]] == 'M' and matrix[i+iDirection[k]*-1][j+jDirection[k]*-1] == 'S') or
                    (matrix[i+iDirection[k]][j+jDirection[k]] == 'S' and matrix[i+iDirection[k]*-1][j+jDirection[k]*-1] == 'M'))
                    diagonalXmasFound++;            
            }
            if (diagonalXmasFound == 2){
                totalXmas++;
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