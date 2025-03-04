//
// Created by User on 04.03.2025.
//

#ifndef ROOT_H
#define ROOT_H
#include "Piece.h"


class Root : public Piece{
public:
    explicit Root(const Color color)
        : Piece(color) {
        if (color == Color::WHITE)
            name_ = 'R';
        else
            name_ = 'r';
    }
};



#endif //ROOT_H
