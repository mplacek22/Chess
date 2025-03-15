//
// Created by User on 10.03.2025.
//

#ifndef PIECEMOVEHANDLER_H
#define PIECEMOVEHANDLER_H
#include "Handler.h"

enum class Color;
class Board;
struct Move;

class SourcePieceHandler final : public Handler<Move &, const Board &, Color> {
public:
    bool handle(Move &move, const Board &board, Color currentPlayer) override;
};


#endif //PIECEMOVEHANDLER_H
