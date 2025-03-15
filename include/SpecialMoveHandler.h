//
// Created by User on 12.03.2025.
//

#ifndef SPECIALMOVEHANDLER_H
#define SPECIALMOVEHANDLER_H
#include <Move.h>

#include "Handler.h"


class Board;

class SpecialMoveHandler final : public Handler<Move &, const Board &, Color> {
public:
    bool handle(Move &move, const Board &board, Color currentPlayer) override;

private:
    bool isEnPassant(Move &move, const Board &board);

    static bool isPromotion(const Move &move, Color currentPlayer);

    static bool isCastling(Move &move, const Board &board, Color currentPlayer);
};


#endif //SPECIALMOVEHANDLER_H
