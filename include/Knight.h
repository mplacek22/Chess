//
// Created by User on 04.03.2025.
//

#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Knight : public Piece {
public:
    explicit Knight(Color color)
        : Piece(color) {
        type_ = PieceType::KNIGHT;
        if (color == Color::WHITE)
            name_ = 'N';
        else
            name_ = 'n';
    }
};


#endif //KNIGHT_H
