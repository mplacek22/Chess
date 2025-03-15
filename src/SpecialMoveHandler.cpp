//
// Created by User on 12.03.2025.
//

#include "SpecialMoveHandler.h"

#include <Board.h>


bool SpecialMoveHandler::handle(Move& move, const Board& board, Color currentPlayer) {
    if (isPromotion(move, currentPlayer)) {
        move.moveType = MoveType::PROMOTION;
    } else if (isCastling(move, board, currentPlayer)) {
        move.moveType = MoveType::CASTLING;
    } else if (isEnPassant(move, board)) {
        move.moveType = MoveType::ENPASSANT;
    }
    return Handler::handle(move, board, currentPlayer);
}

bool SpecialMoveHandler::isEnPassant(Move& move, const Board& board) {
    if (move.pieceType != PieceType::PAWN) {
        return false;
    }
}

bool SpecialMoveHandler::isPromotion(const Move& move, const Color currentPlayer) {
    if (move.pieceType != PieceType::PAWN) {
        return false;
    }
    if (const int promotionRank = (currentPlayer == Color::WHITE) ? Board::BOARD_SIZE - 1 : 0;
        move.destination.rank() != promotionRank) {
        return false;
    }
    return true;
}

bool SpecialMoveHandler::isCastling(Move& move, const Board& board, const Color currentPlayer) {
    if (move.pieceType != PieceType::KING) {
        return false;
    }
    const int castlingRank = (currentPlayer == Color::WHITE) ? 0 : Board::BOARD_SIZE - 1;
    if (move.source != Coordinate<>(4, castlingRank)
    ) {
        return false;
    }

    return true;
}

