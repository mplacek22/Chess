//
// Created by User on 10.03.2025.
//

#ifndef HANDLER_H
#define HANDLER_H

#include <memory>
#include <Move.h>
#include <Board.h>
#include <Move.h>


class Handler {
protected:
    std::unique_ptr<Handler> nextHandler;

public:
    Handler() = default;

    void setNext(std::unique_ptr<Handler> next) {
        nextHandler = std::move(next);
    }

    virtual bool handle(Move& move, const Board& board, const Color currentPlayer) {
        if (nextHandler) {
            return nextHandler->handle(move, board, currentPlayer);
        }
        return true;
    }

    virtual ~Handler() = default;
};

#endif // HANDLER_H
