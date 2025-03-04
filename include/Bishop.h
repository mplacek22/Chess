//
// Created by User on 04.03.2025.
//

#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"


class Bishop : public Piece {
public:
    explicit Bishop(const Color color)
        : Piece(color) {
        if (color == Color::WHITE)
            name_ = 'B';
        else
            name_ = 'b';
    }
};


#endif //BISHOP_H
