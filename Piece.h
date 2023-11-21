#ifndef PIECE_H
#define PIECE_H

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

#endif