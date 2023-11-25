#include <iostream>
#include <vector>

struct Piece{
    int a;
    int b;
    int value;
};

int obtainMaxSellValue(int X, int Y, std::vector<Piece> piecesToSell, int numPieces);

int main(){
    int X, Y, n;
        
    std::cin >> X >> Y;
    std::cin.ignore();
    std::cin >> n;
    
    std::vector<Piece> piecesToSell(n);

    for(int i = 0; i < n; i++){
        std::cin >> piecesToSell[i].a;
        std::cin >> piecesToSell[i].b;
        std::cin >> piecesToSell[i].value;
    }

    std::cout << obtainMaxSellValue(X, Y, piecesToSell, n) << '\n';
    
    return 0;
}

int obtainMaxSellValue(int X, int Y, std::vector<Piece> piecesToSell, int numPieces){
    std::vector<std::vector<int>> maxValues(X+1, std::vector<int>(Y+1, 0));
    /*    
    for(int i = 0; i <= X; i++){
        for(int j = 0; j <= Y; j++){
            maxValues[i][j] = 0;
        }
    }
    */

    for(int row = 1; row <= X; row++){
        for(int col = 1; col <= Y; col++){
            for(int i = 0; i < numPieces; i++){
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
            }
        }     
    }

    return maxValues[X][Y];
}
