//
// Created by User on 09.03.2025.
//

#ifndef MOVE_H
#define MOVE_H
#include <Coordinate.h>
#include <Piece.h>

enum class MoveType {
    NORMAL,
    CAPTURE,
    PROMOTION,
    ENPASSANT,
    CASTLING
};

struct Move {
    Coordinate<> source;
    Coordinate<> destination;
    MoveType moveType = MoveType::NORMAL;
    PieceType pieceType;
    PieceType promotionPieceType;

    Move(const Coordinate<> source, const Coordinate<> destination): source(source),
        destination(destination) {
    }

    // void setMoveType(const MoveType moveType) {
    //     this->moveType = moveType;
    // }
};


#endif //MOVE_H
