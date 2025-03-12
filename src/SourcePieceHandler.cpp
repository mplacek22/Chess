//
// Created by User on 10.03.2025.
//

#include "SourcePieceHandler.h"

bool SourcePieceHandler::handle(Move& move, const Board& board, const Color currentPlayer) {
    const auto piece = board.getPieceAt(move.source);
    if (!piece) {
        return false;
    }
    move.pieceType = piece->type();

    return Handler::handle(move, board, currentPlayer);
}