//
// Created by User on 04.03.2025.
//

#ifndef KING_H
#define KING_H
#include "Piece.h"


class King : public Piece {
public:
    explicit King(Color color)
        : Piece(color) {
        type_ = PieceType::KING;

        if (color == Color::WHITE)
            name_ = 'k';
        else
            name_ = 'K';
    }
};


#endif //KING_H
