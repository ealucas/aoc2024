#include <iostream>
#include <vector>
#include <string>

enum GuardDirection {UP, RIGHT, DOWN, LEFT};

struct Guard {
    int x = 0;
    int y = 0;
    int direction = UP;
};

bool isValidGuardPosition(std::vector<std::string> &matrix, Guard& g){
    if (g.x >= 0 && g.x < matrix.size() 
       && g.y >= 0 && g.y < matrix[0].size()){
        return true;
       }
    else {
        return false;
    }
}

int walkGuard(std::vector<std::string> &matrix, Guard& g){
    int counter = 0;
    int verticalIncrements[] = {-1,0,1,0};
    int horizontalIncrements[] = {0,1,0,-1};

    
    matrix[g.x][g.y] = 'X';
    counter++;

    while(isValidGuardPosition(matrix, g)){

        if (matrix[g.x][g.y] != '#'){
            if (matrix[g.x][g.y] == '.'){
                matrix[g.x][g.y] = 'X';
                counter ++;
            }
            g.x += verticalIncrements[g.direction];
            g.y += horizontalIncrements[g.direction];
        }
        else {
            g.x -= verticalIncrements[g.direction];
            g.y -= horizontalIncrements[g.direction];
            g.direction = (g.direction + 1) % 4;
        }
    }
    return counter;
}
Guard findGuard(const std::vector<std::string> &matrix){
    Guard g;
    for (int i=0; i < matrix.size(); i++){
        for (int j=0; j < matrix[0].size(); j++){
            switch(matrix[i][j]){
                case '^':
                    g.direction = UP;
                    break;
                case 'v':
                    g.direction = DOWN;
                    break;
                case '<':
                    g.direction = LEFT;
                    break;
                case '>':
                    g.direction = RIGHT;
                    break;
                default:
                    continue;
            }
            g.x = i;
            g.y = j;
            return g;
        }
    }
    throw::std::runtime_error("No guard found, probably an input mistake? idk");
}
int main(){
    std::vector<std::string> matrix;
    std::string line;

    while (getline(std::cin, line)){
        matrix.push_back(line);
    }
    
    Guard g = findGuard(matrix);
    std::cout << walkGuard(matrix, g);
}