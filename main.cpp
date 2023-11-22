#include <iostream>

class Piece{
    int _a;
    int _b;
    int _value;

public:
    Piece(){}

    Piece(int a, int b, int value){
        _a = a;
        _b = b;
        _value = value;
    }

    int getA(){
        return _a;
    }
    
    int getB(){
        return _b;
    }

    int getValue(){
        return _value;
    }
};

int obtainMaxSellValue(int X, int Y, Piece piecesToSell[], int numPieces);

int main(){
    int X, Y, n;
        
    std::cin >> X >> Y;
    std::cin.ignore();
    std::cin >> n;

    Piece piecesToSell[n];

    for(int i = 0; i < n; i++){
        int a, b, value;

        std::cin >> a;
        std::cin >> b;
        std::cin >> value;

        piecesToSell[i] = Piece(a, b, value);
    }

    std::cout << obtainMaxSellValue(X, Y, piecesToSell, n) << '\n';
    
    return 0;
}

int obtainMaxSellValue(int X, int Y, Piece piecesToSell[], int numPieces){
    int maxValues[X + 1][Y + 1];

    for(int i = 0; i <= X; i++){
        for(int j = 0; j <= Y; j++){
            maxValues[i][j] = 0;
        }
    }

    for(int row = 1; row <= X; row++){
        for(int col = 1; col <= Y; col++){
            for(int i = 0; i < numPieces; i++){
                int a = piecesToSell[i].getA();
                int b = piecesToSell[i].getB();
                int value = piecesToSell[i].getValue();
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
