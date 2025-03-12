//
// Created by User on 10.03.2025.
//

#ifndef OWNERSHIPVALIDATIONHANDLER_H
#define OWNERSHIPVALIDATIONHANDLER_H
#include "Handler.h"

class OwnershipValidationHandler final : public Handler {
public:
    bool handle(Move& move, const Board& board, const Color currentPlayer) override {
        const auto piece = board.getPieceAt(move.source);
        if (!piece || piece->color() != currentPlayer) {
            return false;
        }
        move.pieceType = piece->type();

        return Handler::handle(move, board, currentPlayer);
    }
};
#endif //OWNERSHIPVALIDATIONHANDLER_H
