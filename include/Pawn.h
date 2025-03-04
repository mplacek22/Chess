//
// Created by User on 04.03.2025.
//

#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"


class Pawn : public Piece{
public:
    explicit Pawn(const Color color)
        : Piece(color) {
        if (color == Color::WHITE)
            name_ = 'P';
        else
            name_ = 'p';
    }
};



#endif //PAWN_H
