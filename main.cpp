#include <iostream>
#include <vector>
#include <cmath>


int obtainMaxSellValue(int X, int Y, std::vector<std::vector<int>>& maxValues);
int obtainMaxCutValue(int row, int col, std::vector<std::vector<int>>& maxValues);


int main(){
    int X, Y, n, firstSize, secondSize;
 
    std::cin >> firstSize >> secondSize;
    std::cin.ignore();
    std::cin >> n;

    X = std::min(firstSize, secondSize);
    Y = std::max(firstSize, secondSize);
    
    std::vector<std::vector<int>> maxValues(X+1, std::vector<int>(Y+1, 0));

    for(int i = 0; i < n; i++){
        int a, b, value;

        scanf("%d %d %d", &a, &b, &value);

        if(a <= X && b <= Y)
            maxValues[a][b] = std::max(value, maxValues[a][b]);
        if(a <= Y && b <= X)
            maxValues[b][a] = std::max(value, maxValues[b][a]);
    }

    std::cout << obtainMaxSellValue(X, Y, maxValues) << '\n';
    
    return 0;
}

int obtainMaxSellValue(int X, int Y, std::vector<std::vector<int>>& maxValues){
    for(int row = 1, colCounter = 0; row <= X; row++, colCounter++){
        for(int col = 1 + colCounter; col <= Y; col++){
            maxValues[row][col] = std::max(maxValues[row][col], obtainMaxCutValue(row, col, maxValues));

            if(col <= X)
                maxValues[col][row] = maxValues[row][col];
        }     
    }

    return maxValues[X][Y];
}

int obtainMaxCutValue(int row, int col, std::vector<std::vector<int>>& maxValues){
    int max = 0;
    for(int i = row-1; i >= ceil(row/2); i--){
        max = std::max(max, maxValues[i][col] + maxValues[row-i][col]);
    }
    for(int i = col-1; i >= ceil(col/2); i--){
        max = std::max(max, maxValues[row][i] + maxValues[row][col-i]);
    }
    return max;
}





























/*for(int i = 0; i < numPieces; i++){
    int a = piecesToSell[i].a;
    int b = piecesToSell[i].b;
    int value = piecesToSell[i].value;
    int maxValueNormalPiece = 0;
    int maxValueRotatedPiece = 0;
    
    // Normal piece
    if(a <= row && b <= col){
        int horVertCut = value + maxValues[row-a][col] + maxValues[a][col-b];
        int vertHorCut = value + maxValues[row][col-b] + maxValues[row-a][b];
        maxValueNormalPiece = std::max(horVertCut, vertHorCut);
    }
    // Rotated piece
    if(b <= row && a <= col){
        int horVertCut = value + maxValues[row-b][col] + maxValues[b][col-a];
        int vertHorCut = value + maxValues[row][col-a] + maxValues[row-b][a];

        maxValueRotatedPiece = std::max(horVertCut, vertHorCut);
    }

    maxValues[row][col] = std::max(maxValues[row][col],
            std::max(maxValueNormalPiece, maxValueRotatedPiece));
}*/