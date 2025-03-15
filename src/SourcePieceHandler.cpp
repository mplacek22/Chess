//
// Created by User on 10.03.2025.
//

#include "SourcePieceHandler.h"

#include <Board.h>

bool SourcePieceHandler::handle(Move& move, const Board& board, Color currentPlayer) {
    const auto piece = board.getPieceAt(move.source);
    if (!piece) {
        return false;
    }
    move.pieceType = piece->type();

    return Handler::handle(move, board, currentPlayer);
}