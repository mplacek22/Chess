//
// Created by User on 10.03.2025.
//

#ifndef PIECEMOVEHANDLER_H
#define PIECEMOVEHANDLER_H
#include "Handler.h"

class SourcePieceHandler final : public Handler {
public:
    bool handle(Move& move, const Board& board, const Color currentPlayer) override;
};


#endif //PIECEMOVEHANDLER_H
